#include <iostream>

struct Node
{
    Node(int x) : value(x) {}

    int InsertNode(Node* &root, int x)
    {
        if (!root)
        {
            root = new Node(x);
            return 1;
        }

        if (x == root->value)
        {
            return -999'999;
        }

        if (x < root->value)
        {
            return (InsertNode(root->left, x) + 1);
        }
        else
        {
            return (InsertNode(root->right, x) + 1);
        }

        return 1;
    }

    int value;
    Node* left = nullptr;
    Node* right = nullptr;
};



int main()
{
 //   std::cout << "Insert" << std::endl;
    int x, max_heiht = 1;
    std::cin >> x;
    if (x == 0)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    Node root_node = Node(x);
    Node* root_node_ptr = &root_node;

    while (std::cin >> x && x != 0)
    {
        int curr_heigt = root_node_ptr->InsertNode(root_node_ptr, x);
        if (curr_heigt > max_heiht)
        {
            max_heiht = curr_heigt;
        }
    }

    std::cout << max_heiht << std::endl;
}
