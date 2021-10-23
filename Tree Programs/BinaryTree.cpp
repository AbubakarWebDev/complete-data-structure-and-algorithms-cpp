/**********************************************************
Tree Data Structure:
A tree is a non linear data structure that simulates a hierarchical tree structure with a root value and sub trees of children with parent node, represented as set of linked nodes.

Tree terms:
1) Node: A node is an entity that contains a key or value and pointers to its child nodes. The last nodes of each path are called leaf nodes or external nodes that do not contain a link/pointer to child nodes. The node having at least a child node is called an internal node.
2) Root: Root is a special node in a tree. The entire tree is referenced through it. It does not have a parent.
3) Parent Node: Parent node is an immediate predecessor of a node.
4) Child Node: All immediate successors of a node are its children.
5) Sibling Nodes: Nodes with the same parent are called Siblings.
6) Leaf Node: Last node (External node) is any node that does not have any child nodes.
5) Internal Node: An internal node is any node of a tree that has child nodes.
8) Path: Path is a number of successive edges from source node to destination node.
7) Edge: Edge is a connection between one node to another. It is a line between two nodes.
9) Ancestor: All Predecessor Nodes on the path from root to that Node are called Ancestors of that node.
10) Decendent: All Decessor Nodes on the path from that Node to leaf Node are called Decendents of that node.


        Tree
       ------
          1    <-- root
        /  \
       2    3  
     /  \    \     <-- Edge
    4    5    6    
   / \  / \   \
  7  8 9  10   9   <-- Leaf (Singular) or leaves (Plural)


Tree terms / properties:
Tree can be termed as a RECURSIVE data structure. In a valid tree for N Nodes we have N-1 Edges/Links.
1) Depth of Node: Depth of a node represents the number of edges from the tree’s root node to the node.
2) Height of Node: Height of a node is the number of edges on the longest path between that node and a leaf.
3) Height of Tree: Height of tree represents the height of its root node.
4) Forest: A collection of disjoint trees is called a forest.

Types of Trees:
1) General Tree
2) Binary Tree
3) Binary Search Tree
4) AVL Tree
5) Spanning Tree
6) B-Tree
7) B+ Tree
8) Heap

Applications of Tree Data Structure:
1) Store hierarchical data, like folder structure, organization structure data.
2) Binary Search Tree is a tree that allows fast search, insert, delete on a sorted data.
3) Heap is a tree data structure which is implemented using arrays and used to implement priority queues.
4) B-Tree and B+ Tree are used to implement indexing in databases.
5) Used to store router-tables in routers.
6) Used by compilers to build syntax trees.
7) Used to implement expression parsers and expression solvers.

Why Tree Data Structure?
Other data structures such as arrays, linked list, stack, and queue are linear data structures that store data sequentially. In order to perform any operation in a linear data structure, the time complexity increases with the increase in the data size. But, it is not acceptable in today's computational world. Different tree data structures allow quicker and easier access to the data as it is a non-linear data structure.

-----------------------------------------------------------
Binary Tree Data Structure:
A binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child(LC) and the right child(RC).

Important Binary Tree Terms & Properties:
1) Maximum number of nodes possible at a given level ‘x’ = 2^x.
2) Maximum number of nodes possible with height h = 2^(h+1) – 1.
3) Minimum number of nodes possible with height h = (h + 1). 
3) Minimum height 'h' of tree possible with Maximum number of nodes 'n' is h = log (n + 1) - 1 (Here the base of log is 2).
4) Maximum height 'h' of tree possible with Minimum number of nodes 'n' is h = (n - 1).

Types of Binary Tree:
1) A binary tree is called FULL/STRICT/PROPER binary tree when each node has 2 or 0 children.

         18
       /   \   
     15     20    
    /  \       
   40   50   
  /  \
 30  50

2) A binary tree is called COMPLETE binary tree if all levels except the last level are completely filled and all nodes of last level are as left as possible.

            18
       /         \  
     15           30  
    /  \         /  \
  40    50     100   40
 /  \   /
8   7  9

3) A binary tree is called PERFECT binary tree if all internal nodes are completely filled with 2 children each and all leaf nodes are present at the same level. 
        
          18  
       /     \  
     15      30  
    /  \    /  \
  40    50 100  40

5) A binary tree is called BALANCE binary tree, if the difference between the height of left subtree and right subtree for every node is not more than 1. For determining the height-balanced binary tree check the height of every node and make sure that is not more than 1.

        18
       /  \   
     15   30     
    /  \      
   40   50  

6) A degenerate (or pathological) tree: A Tree where every internal node has one child. Such trees are performance-wise same as linked list. 

        18
       /      
     15        
    /        
   40     
  /  
 30 


Representation of binary trees:
1) Linked List representation:
Binary trees in linked representation are stored in the memory as linked lists. These lists have nodes that aren’t stored at adjacent or neighboring memory locations and are linked to each other through the parent-child relationship associated with trees. 

In this representation, each node has three different parts:

1) pointer that points towards the right node, 
1) pointer that points towards the left node, 
1) data element.

class Node {
    int data;
    Node* left;
    Node* right;
}

This is the more common representation. All binary trees consist of a root pointer that points in the direction of the root node. When you see a root node pointing towards null or 0, you should know that you are dealing with an empty binary tree. The right and left pointers store the address of the right and left children of the tree. 

2) Sequential representation:
Although it is simpler than linked representation, its inefficiency makes it a less preferred binary tree representation of the two. The inefficiency lies in the amount of space it requires for the storage of different tree elements. The sequential representation uses an array for the storage of tree elements.

The maximum number of nodes on binary tree has defines the size of the array being used So, the Maximum number of nodes possible with height h = 2^(h+1) – 1. The root node of the binary tree lies at the array’s first index. The index at which a particular node is stored will define the indices at which the right and left children of the node will be stored. An empty tree has null or 0 as its first. index. 

The position of a root of the tree will be in '0' index of the array. We can define the position of every other node in the tree recursively.
The position of a left child of any node at position n is at position 2n + 1.
The position of a right child of any node at position n is at position 2n + 2.
The position of a parent of any child node at position n is at position (n - 1)/2.



Binary Tree Traversal (inorder, preorder, postorder and levelorder):
In this tutorial, you will learn about different Four traversal techniques. Also, you will find working examples of different tree traversal methods in C++. Traversing a tree means visiting every node in the tree. You might, for instance, want to add all the values in the tree or find the largest one. For all these operations, you will need to visit each node of the tree. Linear data structures like arrays, stacks, queues, and linked list have only one way to read the data. 

Remember that our goal is to visit each node, so we need to visit all the nodes in the subtree, visit the root node and visit all the nodes in the right subtree as well. Depending on the order in which we do this, there can be three types of traversal.

Inorder traversal:
First, visit all the nodes in the left subtree. Then the root node. And last, Visit all the nodes in the right subtree.
inorder(root->left)
display(root->data)
inorder(root->right)

Preorder traversal:
First, visit the root node. Then visit all the nodes in the left subtree. And Last, visit all the nodes in the right subtree.
display(root->data)
preorder(root->left)
preorder(root->right)

Postorder traversal:
First, Visit all the nodes in the left subtree. Then Visit all the nodes in the right subtree. And Last, Visit the root node.
postorder(root->left)
postorder(root->right)
display(root->data)

LevelOrder Traversal:
It is a Traversel in Which we print every node of a binary tree from first level to last level one by one.
Visit the root, So while traversing level L, keep all the elements at Level (L + 1) in queue.
Go to Next Level deque the previous level and visit all the nodes at that level. 
Repeat both above steps until all level are completed.


In All the Below Example We use this Tree:

        Tree
       ------
          1
        /   \
       2     4  
       \    / \
        3  5   7    
          /   / \
         6   8   9 


LevelOrder = {1 2 4 - 3 5 7 - - - - 6 - 8 9}
InOrder {2 3 1 6 5 4 8 7 9}

*******************************************************************/ 




// Implementation of Binary Tree using Linked List in c++:

#include <iostream>
#include <queue>
using namespace std;

class TreeNode
{
    int value;
    TreeNode *left, *right;

public:
    TreeNode(int value)
    {
        this->value = value;
        left = right = NULL;
    }

    TreeNode *getLeft()
    {
        return left;
    }

    TreeNode *getRight()
    {
        return right;
    }

    int getValue()
    {
        return value;
    }

    void setValue(int value)
    {
        this->value = value;
    }

    void setLeft(TreeNode *left)
    {
        this->left = left;
    }

    void setRight(TreeNode *right)
    {
        this->right = right;
    }
};


// This Function Recursively Build Tree and when tree is Completed. It returns the address of root
TreeNode *buildTree() 
{
    int value;
    cout << "Enter Node Value: ";
    cin >> value;

    if (value == -1)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(value);
    root->setLeft(buildTree());
    root->setRight(buildTree());
    return root;
}

void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->getLeft());
    cout << root->getValue() << " ";
    inorder(root->getRight());
}

int main()
{
    TreeNode *root = buildTree();
    inorder(root);
    return 0;
}





// C++ implementation of tree using array
const int size = 15;
char tree[size];
void set_root(char key)
{
    if (tree[0] != '\0')
        cout << "Tree already had root";
    else
        tree[0] = key;
}

void set_left(char key, int parent)
{
    if (tree[parent] == '\0')
        cout << "\nCan't set child at " << (parent * 2) + 1 << ", No parent found";
    else
        tree[(parent * 2) + 1] = key;
}

void set_right(char key, int parent)
{
    if (tree[parent] == '\0')
        cout << "\nCan't set child at " << (parent * 2) + 2 << ", No parent found";
    else
        tree[(parent * 2) + 2] = key;
}

void print_tree()
{
    cout << "\n\n";
    for (int i = 0; i < size; i++)
    {
        if (tree[i] != '\0')
            cout << tree[i] << " ";
        else
            cout << "- ";
    }
    cout << "\n";
}

int main()
{
    set_root('1');     // At index 0
    set_left('2', 0);  // At index 1
    set_right('4', 0); // At index 2
    set_right('3', 1); // At index 4
    set_left('5', 2);  // At index 5
    set_right('7', 2); // At index 6
    set_left('6', 5); // At index 11
    set_left('8', 6); // At index 13
    set_right('9', 6); // At index 14
    print_tree();
    return 0;
}




// CPP program to construct binary tree from given array in level order fashion Tree Node
class TreeNode
{
    int value;
    TreeNode *left, *right;

public:
    TreeNode(int value)
    {
        this->value = value;
        left = right = NULL;
    }

    TreeNode *getLeft()
    {
        return left;
    }

    TreeNode *getRight()
    {
        return right;
    }

    int getValue()
    {
        return value;
    }

    void setValue(int value)
    {
        this->value = value;
    }

    void setLeft(TreeNode *left)
    {
        this->left = left;
    }

    void setRight(TreeNode *right)
    {
        this->right = right;
    }
};

// Function to insert Treenodes in level order
TreeNode *insertLevelOrder(int arr[], TreeNode *root, int i, int size)
{
    // Base case for recursion
    if (i < size)
    {
        if (arr[i] == -1)
        {
            root = new TreeNode(arr[i]);

            // insert left child
            root->setLeft(insertLevelOrder(arr, root->getLeft(), 2 * i + 1, size));

            // insert right child
            root->setRight(insertLevelOrder(arr, root->getRight(), 2 * i + 2, size));
        }
    }
    return root;
}

void inOrder(TreeNode *root)
{
    if (root != NULL)
    {
        inOrder(root->getLeft());
        cout << root->getValue() << " ";
        inOrder(root->getRight());
    }
}

int main()
{
    int arr[] = {1, 2, 4, -1, 3, 5, 7, -1, -1, -1, -1, 6, -1, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    TreeNode *root = insertLevelOrder(arr, root, 0, size);
    inOrder(root);
}


// Implementation of Binary Tree Traversel in c++:

class TreeNode
{
    int value;
    TreeNode *left, *right;

public:
    TreeNode(int value)
    {
        this->value = value;
        left = right = NULL;
    }

    TreeNode *getLeft()
    {
        return left;
    }

    TreeNode *getRight()
    {
        return right;
    }

    int getValue()
    {
        return value;
    }

    void setValue(int value)
    {
        this->value = value;
    }

    void setLeft(TreeNode *left)
    {
        this->left = left;
    }

    void setRight(TreeNode *right)
    {
        this->right = right;
    }
};

TreeNode *buildTree()
{
    int value;
    cout << "Enter TreeNode Value: ";
    cin >> value;

    if (value == -1)
        return NULL;

    TreeNode *root = new TreeNode(value);
    root->setLeft(buildTree());
    root->setRight(buildTree());
    return root;
}

void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->getLeft());
    cout << root->getValue() << " ";
    inorder(root->getRight());
}

void preorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->getValue() << " ";
    preorder(root->getLeft());
    preorder(root->getRight());
}

void postorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->getLeft());
    postorder(root->getRight());
    cout << root->getValue() << " ";
}

void levelorder(TreeNode *root, queue<TreeNode *> que)
{
    TreeNode *temp;

    if (root == NULL)
        return;

    que.push(root);

    while (!que.empty())
    {
        temp = que.front();
        que.pop();
        cout << temp->getValue() << " ";

        if (temp->getLeft() != NULL)
            que.push(temp->getLeft());

        if (temp->getRight() != NULL)
            que.push(temp->getRight());
    }
}

int main()
{
    TreeNode *root = buildTree();
 
    queue<TreeNode *> que;
 
    levelorder(root, que);
    return 0;
}

/*
In the Above Example If You Add the Following Input:
1, 2, -1, 3, -1, -1, 4, 5, 6, -1, -1, -1, 7, 8, -1, -1, 9, -1, -1

Then you get this output in Inorder Traversel that given below:
Inorder: 2, 3, 1, 6, 5, 4, 8, 7, 9
LevelOrder = 1, 2, 4, 3, 5, 7, 6, 8, 


If you are given two traversal sequences, can you construct the binary tree?
Therefore, following combination can uniquely identify a tree. It depends on what traversals are given. If one of the traversal methods is Inorder then the tree can be constructed, otherwise not.

Inorder and Preorder.
Inorder and Postorder.
Inorder and Level-order.

And following do not.
Postorder and Preorder.
Preorder and Level-order.
Postorder and Level-order.
*/