#include <iostream>
#include <vector>

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> nums(n);

    for(int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }

    int min_segm{nums[0]}, index_min{0};

    for(int i = 0; i < (n-k + 1); ++i)
    {
        int start{i}, end{i+k};

        if (index_min < i)
        {
            index_min = i;
            min_segm = nums[i];
        }
        else
        {
            start = index_min + 1;
        }

        for(; start < end; ++start)
        {
            if (min_segm > nums[start])
            {
                min_segm = nums[start];
                index_min = start;
            }
        }
        std::cout << min_segm << std::endl;
    }
}
