#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::unordered_map<int, std::set<int>> links;

    for(int i = 0; i < M; ++i)
    {
        int v1, v2;
        std::cin >> v1 >> v2;

        links[v1].insert(v2);
        links[v2].insert(v1);
    }

    std::set<int> all_vertex;
    for(int i = 1; i <= N; ++i)
    {
        all_vertex.insert(i);
    }


//    while (! all_vertex.empty())
  //  {

        int start_vertex = 1;

        std::set<int> futur_vertex;
        futur_vertex.insert(start_vertex);

        std::set<int> result;  // promegutochny resul ili polny
        std::unordered_set<int> previs_vertex;

        while (! futur_vertex.empty())
        {
            int curr_vertex = *(futur_vertex.begin());
            futur_vertex.erase(futur_vertex.begin());
            previs_vertex.insert(curr_vertex);
            result.insert(curr_vertex);

            for (const int link_vertex : links[curr_vertex])
            {
                if (previs_vertex.find(link_vertex) == previs_vertex.end()) // ne byli
                {
                    futur_vertex.insert(link_vertex);
                }
            }
        }

        std::cout << result.size() << std::endl;

        bool first = true;
        for(const auto ver : result)
        {
            if (!first)
            {
                std::cout << ' ';
            }
            first = false;

            std::cout << ver;
           // all_vertex.erase(ver);
        }
        std::cout << std::endl;
//    }
}
