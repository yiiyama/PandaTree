#ifndef PandaTree_Interface_RefResolver_h
#define PandaTree_Interface_RefResolver_h

namespace panda {
  namespace utils {

    template<class T>
    class RefResolver {
    public:
      RefResolver(T& t) : treeEntry_(t) {}
      
    };
  }
}

#endif
