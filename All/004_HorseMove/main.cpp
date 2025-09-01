#include <iostream>
#include <vector>

int main() 
{
	int N, M;
	std::cin >> N >> M;
	std::vector<std::vector<int>> result(N, std::vector<int>(M, 0));

	result[0][0] = 1;

	for(int i = 1; i < N; ++i)
	{
		result[i][0] = 0;
	}

	for(int j = 1; j < M; ++j)
	{
		result[0][j] = 0;
	}

	for(int i = 1; i < N; ++i)
	{
		for(int j = 1; j < M; ++j)
		{
			int prev_left, prev_up;

			prev_left = j-2 >=0 ? result[i-1][j-2] : 0;
			prev_up   = i-2 >=0 ? result[i-2][j-1] : 0;

			result[i][j] = prev_left + prev_up;
		}
	}

	std::cout << result[N-1][M-1];
	return 0;
}