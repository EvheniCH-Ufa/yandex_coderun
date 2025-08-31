#include <iostream>
#include <vector>
#include <deque>

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> nums(n);
    std::deque<int> indexes;

    std::vector<int> result;
    result.reserve(n-k+1);


    for(int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];

        while(!indexes.empty() && nums[indexes.back()] >= nums[i])
        {
            indexes.pop_back();
        }


        while(!indexes.empty() && indexes.front() <= (i-k))
        {
            indexes.pop_front();
        }

        indexes.push_back(i);

        if (i < k-1)
        {
            continue;
        }

        result.push_back(nums[indexes.front()]);
    }

    for(const int num : result)
    {
        std::cout << num << std::endl;

    }


   /* int min_segm{nums[0]}, index_min{0};

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
    }*/
}
