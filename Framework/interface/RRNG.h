#ifndef PANDATREE_RRNG
#define PANDATREE_RRNG

#include "TRandom3.h"
#include "TMath.h"

#define RRNG_DEBUG 0

namespace panda {
  class RRNG {
  public:
    RRNG(int seed  = 0, int maxEntropy = 50);
    RRNG(RRNG const& other);
    ~RRNG() { delete[] _x; delete[] _available; }
    
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
    int _nextAvailable(int start);
    TRandom3 _rng;
    const int _maxEntropy;
    double* _x;
    bool* _available;
  };
}


#endif
