#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int count;
    std::cin >> count;

    std::vector<int> nums(count);

    for(int i = 0; i < count; ++i)
    {
        std::cin >> nums[i];
    }

    int searhc_num;
    std::cin >> searhc_num;

    if (nums.empty())
    {
        return 0;
    }

    int result = nums[0];

    for(int i = 1; i < nums.size(); ++i)
    {
        if (std::abs(nums[i] - searhc_num) < std::abs(result - searhc_num))
        {
            result  = nums[i];
        }
    }
    std::cout << result;
}
