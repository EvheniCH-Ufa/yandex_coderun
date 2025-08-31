#include <iostream>
#include <vector>
#include <vector>

int main()
{
  //  DDD:
 //   std::cout << "Start" <<std::endl;

    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> vertexes(N);

    for (int i = 0; i < N; ++i)
    {
        std::cin >> vertexes[i].first >> vertexes[i].second;
    }

    std::vector<int> heigst_forv(N), heigst_revers(N);

    for (int i = 1; i < N; ++i)
    {
        heigst_forv[i] = heigst_forv[i-1] + (vertexes[i].second > vertexes[i-1].second ? vertexes[i].second - vertexes[i-1].second : 0);

        heigst_revers[N - i - 1] = heigst_revers[N - i] + (vertexes[N - i - 1].second > vertexes[N - i].second ? vertexes[N - i - 1].second - vertexes[N - i].second : 0);
    }

    int M;
    std::cin >> M;

    std::vector<std::pair<int, int>> trasses(M);

    for (int i = 0; i < M; ++i)
    {
        std::cin >> trasses[i].first >> trasses[i].second;
    }

    for (int i = 0; i < M; ++i)
    {
        int result = 0;

        if (trasses[i].second > trasses[i].first)
        {
            result = heigst_forv[trasses[i].second - 1] - heigst_forv[trasses[i].first - 1];
        }

        if (trasses[i].second < trasses[i].first)
        {
            result = heigst_revers[trasses[i].second - 1] - heigst_revers[trasses[i].first - 1];
        }
        std::cout << result <<std::endl;
    }

   // goto DDD;
}
