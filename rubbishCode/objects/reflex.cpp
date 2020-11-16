#include <string>
#include <map>
using std::string;

template <class T>
class Reflex{
private:
  std::map<string,T> reflexMapping;
  T createTypeInstance(string typename) {
    if(reflexMapping.find(typename)!=reflexMapping.end()) {
      return reflexMapping[typename];
    }else {
      throw "no type";
    }
  }
};
