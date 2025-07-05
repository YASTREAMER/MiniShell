#include <string>
#include <regex>
#include <sstream>
#include <vector>

using namespace std;

vector<string> parse(const string& input)
{
    vector<string> parsedString;
    istringstream iss(input);
    string word;

    while(iss >> word)
        {
            if(regex_search(word, regex("\\\\")))
                {
                    word = regex_replace(word, regex("\\\\"), " ");
                }
            else
                {
                    parsedString.push_back(word);
                }
        }

    return parsedString;
}
