#include <sstream>
#include <string>
#include <vector>

#include "../board/board.hpp"

namespace chess {
using std::string, std::vector, std::stringstream;

vector<string> splitString(const std::string &str, char delimiter);
string trim(const std::string str);

string serializeBoardToJson(const Cell *board);

} 
