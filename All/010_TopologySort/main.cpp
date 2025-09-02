#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>

std::vector<int> KSS(int N, std::vector<int>& input_counts,
                     std::vector<std::vector<int>>& links)
{
    std::deque<int> dq;
    for (int i = 1; i <= N; ++i)
    {
        if(input_counts[i] == 0)
        {
            dq.push_back(i);
            input_counts[i] = -1;
        }
    }

    std::vector<int> result;
    result.reserve(N);
    while (!dq.empty())
    {
        int curr_index = dq.front();
        dq.pop_front();
        result.push_back(curr_index);
        input_counts[curr_index] = -1;


        for (const auto vertex_index : links[curr_index])
        {
            input_counts[vertex_index]--;
            if (input_counts[vertex_index] == 0)
            {
                input_counts[vertex_index] = -1;
                dq.push_back(vertex_index);
            }
        }
    }

    if(result.size() != N)
    {
        result.clear();
    }
    return result;
}


int main()
{
 // start:

//    std::cout << "---------------------------\n";

    int N, M;
    std::cin >> N >> M;

    std::vector<int> input_counts(N+1, 0);
    std::vector<std::vector<int>> links(N+1);
    for (int i = 0; i < M; ++i)
    {
        int from, to;
        std::cin >> from >> to;

        links[from].push_back(to); //pishem detei
        input_counts[to]++;
    }

    auto res = KSS(N, input_counts, links);

    if (res.empty())
    {
        std::cout << -1 << std::endl;
        return 0;
    }

    bool is_first = true;
    for (int index : res)
    {
        if (!is_first)
        {
            std::cout << ' ';
        }
        is_first = false;
        std::cout << index;
    }
    std::cout << std::endl;

    //goto start;
}
