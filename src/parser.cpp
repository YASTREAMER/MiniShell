#include <stack>
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
    string combinedword = "";
    bool isSpecial = false;
    stack<string> pairs;

    while(iss >> word)
        {
            if(regex_search(word, regex("\\\\")))
                {
                    word = regex_replace(word, regex("\\\\"), " ");
                    combinedword = combinedword + word;
                    isSpecial = true;
                }
            else if(regex_search(word, regex("\"")))
                {
                    word = regex_replace(word, regex("\""), "");
                    combinedword = combinedword + " " + word;
                    if(pairs.empty())
                        {
                            pairs.push("\"");
                            isSpecial = true;
                        }
                    else
                        {
                            parsedString.push_back(combinedword);
                            isSpecial = false;
                        }
                }
            else if(!pairs.empty())
                {
                    combinedword = combinedword + " " + word;
                }
            else if(isSpecial)
                {
                    combinedword = combinedword + word;
                    parsedString.push_back(combinedword);
                    combinedword = "";
                }
            else { parsedString.push_back(word); }
        }

    return parsedString;
}

