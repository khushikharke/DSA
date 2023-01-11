#include <iostream>
#include <deque>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
// cd dsa_course/stacks and queues -->> relative path
// /se start hho toh -->> absolute path
// . is curr directory
// .. is parent directory
// ././ makes no sense while //// also but ..//..// means par directory

// test case: i/p
// "/a/./" ->>a ; "/a/b/.."  jump from b to a ; //// =/ ;
// example /a/./b../../c/
string simplifyPath(string path)
{
    // 1. tokenisation and filtering
    istringstream iss(path);
    vector<string> tokens;
    string token;
    while (getline(iss, token, '/'))
    {
        if (token == "." or token == "")
        {
            continue;
        }
        tokens.push_back(token);
    }

    // 2. handle  ..
    vector<string> stack;
    // abs path
    if (path[0] == '/')
    {
        stack.push_back("");
    }

    for (string token : tokens)
    {

        if (token == "..")
        {
            // 2 cases abs and rel
            if (stack.size() == 0 or stack[stack.size() - 1] == "..")
            {
                stack.push_back("..");
            }
            else if (stack[stack.size() - 1] != "")
            {
                stack.pop_back();
            }
        }
        else
        {
            stack.push_back(token);
        }
    }
    // 3. combine ans
    if (stack.size() == 1 and stack[0] == "")
    {
        return "/";
    }

    ostringstream oss;
    int i = 0;
    for (auto token : stack)
    {
        if (i != 0)
        {
            oss << "/";
        }
        i++;
        oss << token;
    }
    return oss.str();

    return "";
}
int main()
{
    khushi();
    string path = "/../x/y/../z/././w/a///../../c/./";
    cout << simplifyPath(path);
    return 0;
}