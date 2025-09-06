#include <iostream>
#include <set>
#include <vector>

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> links(N+1);

    for(int i = 0; i < M; ++i)
    {
        int v1, v2;
        std::cin >> v1 >> v2;

        links[v1].push_back(v2);
        links[v2].push_back(v1);
    }

    std::vector<std::set<int>> results;

    std::vector<bool> visited(N+1, false);
    for(int start_vertex = 1; start_vertex <= N; ++start_vertex)
      {
        if (visited[start_vertex])
        {
            continue;
        }

        std::set<int> futur_vertex;
        futur_vertex.insert(start_vertex);
        visited[start_vertex] = true;

        std::set<int> result;  // promegutochny resul ili polny

        while (! futur_vertex.empty())
        {
            int curr_vertex = *(futur_vertex.begin());
            futur_vertex.erase(futur_vertex.begin());
            visited[curr_vertex] = true;
            result.insert(curr_vertex);

            for (const int link_vertex : links[curr_vertex])
            {
                if (!visited[link_vertex]) // ne byli
                {
                    futur_vertex.insert(link_vertex);
                }
            }
        }

        results.push_back(std::move(result));
    }

    std::cout << results.size() << std::endl;

    for(const auto& result : results)
    {
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
    }
}
