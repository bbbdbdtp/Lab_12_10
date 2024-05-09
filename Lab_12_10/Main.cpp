#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

struct Node
{
    int info;
    Node* left;
    Node* right;
};

Node* CreateBalancedTree(int values[], int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;
    Node* newNode = new Node;
    newNode->info = values[mid];
    newNode->left = CreateBalancedTree(values, start, mid - 1);
    newNode->right = CreateBalancedTree(values, mid + 1, end);
    return newNode;
}

void PrintLevelOrder(Node* root, int level)
{
    if (root == nullptr)
        return;

    if (level == 0)
        cout << root->info << " ";
    else
    {
        PrintLevelOrder(root->left, level - 1);
        PrintLevelOrder(root->right, level - 1);
    }
}


int CountNodesAtLevel(Node* root, int level)
{
    if (root == nullptr)
        return 0;
    if (level == 0)
        return 1;
    else
        return CountNodesAtLevel(root->left, level - 1) + CountNodesAtLevel(root->right, level - 1);
}

int main()
{
    ifstream inputFile("tree_values.txt");
    if (!inputFile)
    {
        cerr << "Unable to open file";
        return 1;
    }

    int nodeCount;
    cout << "Enter the number of nodes in the tree: ";
    cin >> nodeCount;

    int* values = new int[nodeCount];
    for (int i = 0; i < nodeCount; ++i)
        inputFile >> values[i];

    Node* root = CreateBalancedTree(values, 0, nodeCount - 1);

    cout << "Binary Tree:" << endl;
    // Виводимо дерево у вигляді рівнів
    for (int i = 0; i < nodeCount; ++i)
    {
        cout << "Level " << i << ": ";
        PrintLevelOrder(root, i);
        cout << endl;
    }

    int levelToCount;
    cout << "Enter the level to count nodes: ";
    cin >> levelToCount;

    int nodesAtLevel = CountNodesAtLevel(root, levelToCount);
    cout << "Number of nodes at level " << levelToCount << ": " << nodesAtLevel << endl;

    cout << "Values at level " << levelToCount << ": ";
    PrintLevelOrder(root, levelToCount);
    cout << endl;

    delete[] values;
    inputFile.close();

    return 0;
}