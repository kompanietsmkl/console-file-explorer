#include "utils/PathUtils.hpp"
#include <sstream>

namespace PathUtils{
  bool is_valid_name(const std::string &arg){
    if (arg.empty()) return false;
  
    char slash = (arg.find('\\') != std::string::npos) ? '\\' : '/';
  
    std::stringstream ss(arg);
    std::string name;
  
    while(std::getline(ss, name, slash)){
      if(name.empty() || name == "." || name == "..") return false;
      
      #ifdef _WIN32
        std::string forbidden = "<>?:\"/\\|*";
        for(const char &ch: name){
          if(ch < 32 || forbidden.find(ch) != std::string::npos) return false;
        }
      #else
        for (const char &ch : name) {
          if (ch == '/' || ch == '\0')
            return false;
        }
      #endif
    }
  
    return true;
  }
}