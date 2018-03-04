#ifndef PANDATREE_RRNG
#define PANDATRE_RRNG

#include "TRandom3.h"
#include "TMath.h"

#define RRNG_DEBUG 0

class RRNG {
public:
  RRNG(int seed  = 0, int maxEntropy = 50);
  ~RRNG() { delete[] _x; }
  
  void generate(); 
  void generate(int seed) { _rng.SetSeed(seed); generate(); }
  double uniform(int& idx = _default_idx);
  void normal(double& x1, double& x2, int& idx = _default_idx);
  double normal(int& idx = _default_idx);
  double landau(double mu, double sigma, int& idx = _default_idx);
  double exp(double alpha, int& idx = _default_idx);
  int poisson(double mu, int& idx = _default_idx);

private:
  static int _default_idx;
  double _requestNumber(int& idx);
  TRandom3 _rng;
  const int _maxEntropy;
  int _usedEntropy{0}; 
  double* _x;
};


#endif
