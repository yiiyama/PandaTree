#ifndef PANDATREE_RRNG
#define PANDATREE_RRNG

#include "TRandom3.h"
#include "TMath.h"
#include <vector>
#include <utility>

#define RRNG_DEBUG 0


namespace panda {
  class RRNG {
  public:
    RRNG(int maxEntropy = 50, ULong64_t seed = 0, const ULong64_t* seedAddress = nullptr);
    RRNG(RRNG const& other);
    RRNG(RRNG&& other);
    ~RRNG() {}
    RRNG& operator=(const RRNG& other);
    
    void setSize(int maxEntropy);
    void setFixedSeed(ULong64_t seed) { _seedAddress = nullptr; _editSeed(seed); }
    void setSeedAddress(const ULong64_t* seedAddress) { _seedAddress = seedAddress; }
    void generate(); 
    void generate(ULong64_t seed) { setFixedSeed(seed); generate(); }
    double uniform(int& idx = _default_idx);
    void normal(double& x1, double& x2, int& idx = _default_idx);
    double normal(int& idx = _default_idx);
    double landau(double mu, double sigma, int& idx = _default_idx);
    double exp(double alpha, int& idx = _default_idx);
    int poisson(double mu, int& idx = _default_idx);

  private:
    static int _default_idx;

    void _editSeed(ULong64_t seed) { _rng.SetSeed(seed); _currentSeed = seed; }
    double _requestNumber(int& idx);
    int _nextAvailable(int start) const;

    TRandom3 _rng;
    int _maxEntropy;
    const ULong64_t* _seedAddress{nullptr};
    ULong64_t _currentSeed{0};
    std::vector<std::pair<double,bool>> _x;
  };
}


#endif
