#include "PandaTree/Utils/interface/RRNG.h"
#include "Math/QuantFuncMathCore.h"
#include "TString.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int RRNG::_default_idx;

RRNG::RRNG(int seed, int maxEntropy): 
  _rng(seed),
  _maxEntropy(maxEntropy)
{
  _default_idx = -1;
  _x = new double[2 * maxEntropy];
  generate();
}

void RRNG::generate() 
{
  _usedEntropy = 0;
  _rng.RndmArray(_maxEntropy * 2, _x);
}

double RRNG::_requestNumber(int& idx) 
{
  int idx_;
  if (idx >= _maxEntropy) {
    throw out_of_range(Form("RRNG::_requestNumber accessing RN %i/%i", idx, _maxEntropy));
  } else if (idx < 0) {
    if (_usedEntropy >= _maxEntropy) {
#if RRNG_DEBUG
      cerr << "RRNG::_requestNumber forced to re-generate numbers because we ran out!" << endl;
#endif
      generate();
    }
    idx_ = _usedEntropy++;
  } else {
    idx_ = idx;
    idx++;
    if (idx >= _maxEntropy) { // we forced it to go over, so don't throw an exception
      idx = 0;
#if RRNG_DEBUG
      cerr << "RRNG::_requestNumber forced to re-generate numbers because we ran out!" << endl;
#endif
      generate();
    }
  }

  return _x[idx_];
}

double RRNG::uniform(int& idx) 
{
  double x = _requestNumber(idx);
  return x;
}

// Box-Muller
void RRNG::normal(double& x1, double& x2, int& idx)
{
  double u = _requestNumber(idx);
  double v = _requestNumber(idx);

  u = TMath::Sqrt(-2 * TMath::Log(u));
  v = 2 * TMath::Pi() * v;

  x1 = u * TMath::Cos(v);
  x2 = u * TMath::Sin(v);  
}

// note that this requires two RNs even though it retuRNs only one
double RRNG::normal(int& idx) 
{
  double x1, x2;
  normal(x1, x2, idx);
  return x1;
}

double RRNG::landau(double mu, double sigma, int& idx)
{
  if (sigma <= 0) 
    return 0;
  double x = _requestNumber(idx);
  return mu + ROOT::Math::landau_quantile(x, sigma);
}

double RRNG::exp(double alpha, int& idx)
{
  double x = _requestNumber(idx);
  return - TMath::Log(x) / alpha;
}

// this RV may use an arbitrary number of RNs!
int RRNG::poisson(double mu, int& idx)
{
  if (mu <= 0)
    return 0;

  double prod = 1;
  double threshold = TMath::Exp(-mu);
  int N = 0; 

  while (prod > threshold) {
    prod *= _requestNumber(idx);
    N += 1;
  }
   
 return N; 
}
