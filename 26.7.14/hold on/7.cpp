#include <iostream>
#include <string>
using namespace std;

string greet(string form, string lastname, string title, string::size_type pos, int length)
{
    string result = form;
    string::size_type idx;
    idx = result.find("Ms");
    if(idx != string::npos)
        result.replace(idx, 2, title.substr(pos, length));
    idx = result.find("Daisy");
    if(idx != string::npos)
        result.replace(idx, 5, lastname);
    return result;
}