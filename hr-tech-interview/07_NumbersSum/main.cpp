#include <iostream>
#include <vector>

int main()
{
    int N, K, segments_count{0}, start_segment{0}, segment{0};
    std::cin >> N >> K;

    std::vector<int> nums(N);

    for (int i=0; i < N; ++i)
    {
        std::cin >> nums[i];

        segment += nums[i];

        while (segment > K)
        {
            segment -= nums[start_segment];
            ++start_segment;
        }

        if (segment == K)
        {
            ++segments_count;
        }
    }
    std::cout << segments_count << std::endl;
}
