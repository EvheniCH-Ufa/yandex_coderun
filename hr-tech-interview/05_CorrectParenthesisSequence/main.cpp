#include <iostream>
#include <string>
#include <stack>

bool isValid(const std::string& str)
{
    std::stack<char> stck;
    for (const auto ch : str)
    {
        if (ch == '(')
        {
            stck.push(')');
        }
        else if (ch == '[')
        {
            stck.push(']');
        }
        else if (ch == '{')
        {
            stck.push('}');
        }

        else if (!stck.empty() && ch == stck.top())
        {
            stck.pop();
        }
        else
        {
            return false;
        }
    }
    return stck.empty();
}


int main()
{
    std::string s;
    std::cin >> s;

    if (isValid(s))
    {
        std::cout << "yes" << std::endl;
    }
    else
    {
        std::cout << "no" << std::endl;
    }
}
