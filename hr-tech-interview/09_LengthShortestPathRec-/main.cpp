#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>

int SearchShortestPathRecurs(const std::unordered_map<int, std::set<int>>& links, int start_vertex, int end_vertex, std::unordered_set<int>& previs_vertex)
{
    auto it_links = links.find(start_vertex);
    if (it_links == links.end())
    {
        return 999'999;
    }

    const std::set<int>& futur_vertex = it_links->second;

    int min_len_path = 9'999'999;

    previs_vertex.insert(start_vertex);
    for(const auto vertex : futur_vertex)
    {
        if (vertex == end_vertex)
        {
            return 1;
        }

        if (previs_vertex.find(vertex) != previs_vertex.end())
        {
            continue;
        }

        int curr_len_path = SearchShortestPathRecurs(links, vertex, end_vertex, previs_vertex);

        min_len_path = curr_len_path < min_len_path ? curr_len_path : min_len_path;

        if (min_len_path < 10001)
        {
            return min_len_path;
        }

    }
    previs_vertex.erase(start_vertex);

    return min_len_path + 1;
}


int main()
{
    int N;
     std::cin >> N;

    std::unordered_map<int, std::set<int>> links;

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            int lnk;
            std::cin >> lnk;
            if (lnk)
            {
                links[i].insert(j);
            }
        }
    }

    std::set<int> all_vertex;
    for(int i = 1; i <= N; ++i)
    {
        all_vertex.insert(i);
    }

    int start, end;
    std::cin >> start >> end;
    --start;
    --end;

    int result = 0;
    if (start != end)
    {
        std::unordered_set<int> previs_vertex;
        result = SearchShortestPathRecurs(links, start, end, previs_vertex);

        result = result > 10001 ? -1 : result;
    }

    std::cout << result << std::endl;
}
