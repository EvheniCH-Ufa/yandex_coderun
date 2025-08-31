#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    std::unordered_map<std::string, int> know_langs;
    std::unordered_set<std::string> all_langs;

    int count;
    std::cin >> count;

    for(int i = 0; i < count; ++i)
    {
        int langs_count;
        std::cin >> langs_count;
        for(int j = 0; j < langs_count; ++j)
        {
            std::string language;
            std::cin >> language;
            all_langs.insert(language);
            ++know_langs[language];
        }
    }

    std::vector<string> all_know_langs;
    for(const auto [lang, curr_count] : know_langs)
    {
        if (curr_count == count)
        {
            all_know_langs.push_back(lang);
        }
    }

    std::cout << all_know_langs.size() << std::endl;
    for(const auto lang : all_know_langs)
    {
        std::cout << lang << std::endl;
    }

    std::cout << all_langs.size() << std::endl;
    for(const auto lang : all_langs)
    {
        std::cout << lang << std::endl;
    }
}
