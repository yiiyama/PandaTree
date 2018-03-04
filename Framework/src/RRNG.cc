#include "PandaTree/Framework/interface/RRNG.h"
#include "Math/QuantFuncMathCore.h"
#include "TString.h"
#include <iostream>
#include <stdexcept>
#include <cassert>

using namespace std;
using namespace panda;

int RRNG::_default_idx;

RRNG::RRNG(int seed, int maxEntropy): 
  _rng(seed),
  _maxEntropy(maxEntropy)
{
  assert(_maxEntropy > 0);
  _default_idx = -1;
  _x = new double[_maxEntropy];
  _available = new bool[_maxEntropy];
  generate();
}

RRNG::RRNG(RRNG const& other): 
  _rng(other._rng),
  _maxEntropy(other._maxEntropy)
{
  _x = new double[_maxEntropy];
  _available = new bool[_maxEntropy];
  generate();
}

void RRNG::generate() 
{
  _rng.RndmArray(_maxEntropy, _x);
  for (int i = 0; i != _maxEntropy; ++i) 
    _available[i] = true;
}

int RRNG::_nextAvailable(int start)
{
  for (int i = start; i != _maxEntropy; ++i) {
    if (_available[i])
      return i;
  }
  return -1;
}

double RRNG::_requestNumber(int& idx) 
{
  int idx_;
  if (idx >= _maxEntropy) {
    throw out_of_range(Form("RRNG::_requestNumber accessing RN %i/%i", idx, _maxEntropy));
  } 
  if (idx >= 0 && !_available[idx]) {
    throw runtime_error(Form("RRNG::_requestNumber already accessed %i", idx));
  }
  
  while ((idx_ = _nextAvailable(TMath::Max(0,idx))) < 0) {
#if RRNG_DEBUG
    cerr << "RRNG::_requestNumber forced to re-generate numbers because we ran out!" << endl;
#endif
    generate();
  }

  _available[idx_] = false;
  if (idx >= 0) {
    idx = _nextAvailable(idx_); // potentially the next one we could access
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
