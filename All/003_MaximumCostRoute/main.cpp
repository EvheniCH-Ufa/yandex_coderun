#include <iostream>
#include <vector>
//#include <string>

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
            if(result[i-1][j] > result[i][j-1])
            {
                result[i][j] = result[i-1][j] + matrix[i][j];
            }
            else
            {
                result[i][j] = result[i][j-1] + matrix[i][j];
            }
        }
    }

/*    std::string route{""};
    route.reserve(std::max(N, M)*2);

    int i{0}, j{0};
    for(int step = 0; step < std::max(N, M) - 1; ++step)
    {
        if(result[i+1][j] > result[i][j+1])
        {
            //                route.push_back('D');
                    //        route.push_back(' ');
//            route.push_back('R');
    //        route.push_back(' ');

        }
        else
        {

        }

        for(int j = 0; j < M-1; ++j)
        {
            std::cout << result[i][j] << ' ';
        }
        std::cout << '\n';
    }
    */

    std::vector<char>route(N + M - 2);

    int i{N-1}, j{M-1};
    for(int step = (N + M - 2); step > 0;  --step)
    {
        if(i == 0)
        {
            route[step - 1] = 'R';
            --j;
        }
        else if(j == 0)
        {
            route[step - 1] = 'D';
            --i;
        }
        else if (result[i - 1][j] > result[i][j-1])
        {
            route[step - 1] = 'D';
            --i;
        }
        else
        {
            route[step - 1] = 'R';
            --j;
        }
    }

//tydheuty

  //  route.pop_back();
    std::cout << result[N-1][M-1] << std::endl;

    std::cout << route[0];
    for (int i = 1; i < route.size(); ++i)
    {
        std::cout << ' ' << route[i];
    }
    std::cout << std::endl;

/*
    std::cout << "\n\n" << std::endl;

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            std::cout << result[i][j] << ' ';
        }
        std::cout << '\n';
    }*/

}
