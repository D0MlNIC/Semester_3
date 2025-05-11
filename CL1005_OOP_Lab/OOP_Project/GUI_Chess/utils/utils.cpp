#include "./utils.hpp"

namespace chess {

std::vector<std::string> splitString(const std::string &str, char delimiter) {
  std::vector<std::string> tokens;
  std::stringstream ss(str);
  std::string token;
  while (std::getline(ss, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}

string trim(const string str) {
  string ret = str;
  return ret.substr(ret.find_first_not_of(' '), ret.find_last_not_of(' ') + 1);
}

} 
