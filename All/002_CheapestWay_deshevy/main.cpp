#include <iostream>
#include <vector>

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> matrix(N, std::vector<int>(M));

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<std::vector<int>> result(N, std::vector<int>(M));

    result[0][0] = matrix[0][0];

    for(int i = 1; i < N; ++i)
    {
        result[i][0] = result[i-1][0] + matrix[i][0];
    }

    for(int j = 1; j < M; ++j)
    {
        result[0][j] = result[0][j-1] + matrix[0][j];
    }


    for(int i = 1; i < N; ++i)
    {
        for(int j = 1; j < M; ++j)
        {
            result[i][j] = std::min(result[i-1][j], result[i][j-1]) + matrix[i][j];
        }
    }

    std::cout << result[N-1][M-1] << std::endl;
}
