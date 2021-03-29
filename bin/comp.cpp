#include <string>
#include <boost/tokenizer.hpp>
#include <vector>

using namespace std;
using namespace boost;

int main() {
    vector<int> intList
    string text = "(-5,3,0,1,-2)";
    char_separator<char> sep(",");
    tokenizer<char_separator<char>> tokens(text, sep);
    for (const auto& t : tokens) 
          intList.push_back(std::stoi(t));

}