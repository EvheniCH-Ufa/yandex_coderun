#include <deque>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>

int SearchShortestPath(const std::unordered_map<int, std::set<int>>& links, int start_vertex, int end_vertex)
{
    int vawe_num = 0;
    std::deque<int> futur_vertex;
    std::unordered_set<int> previs_vertex;
    futur_vertex.push_back(start_vertex);
    int see_count = 1;

    while(!futur_vertex.empty())
    {
        for (int i = 0; i < see_count; ++i)
        {
            int curr_vertex = futur_vertex[i];
            if (previs_vertex.find(curr_vertex) != previs_vertex.end())
            {
                continue;
            }

            previs_vertex.insert(curr_vertex);

            if (futur_vertex[i] == end_vertex)
            {
                return vawe_num;
            }

            auto it_vert = links.find(futur_vertex[i]);
            if (it_vert == links.end())
            {
                continue;
            }

            for (const auto vertex : it_vert->second)
            {
                if (previs_vertex.find(vertex) == previs_vertex.end())
                {
                    futur_vertex.push_back(vertex);
                }
            }
        }

        for (int i = 0; i < see_count; ++i)
        {
            futur_vertex.pop_front();
        }
        see_count = futur_vertex.size();

        ++vawe_num;
    }

    return -1;

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
        result = SearchShortestPath(links, start, end);
    }

    std::cout << result << std::endl;
}
