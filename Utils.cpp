#include "Utils.h"

vector<string> string_split(string str,char ch)
{
    vector<string> temp;
    size_t loc;
    while ((loc = str.find(ch)) != string::npos)
    {
        temp.push_back(str.substr(0,loc));
        str = str.substr(loc + 1,str.length());
    }
    temp.push_back(str);
    return temp;
}