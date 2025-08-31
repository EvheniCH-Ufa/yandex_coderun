#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


using namespace std;

int main()
{
    std::unordered_map<std::string, std::string> lib;

    int count;
    std::cin >> count;

    for(int i = 0; i < count; ++i)
    {
        std::string word1, word2;
        std::cin >> word1 >> word2;
        lib.insert({word1, word2});
        lib.insert({word2, word1});
    }

    std::string request;
    std::cin >> request;

    auto it_res = lib.find(request);
    if (it_res != lib.end())
    {
        std::cout << it_res->second;
    }
}
