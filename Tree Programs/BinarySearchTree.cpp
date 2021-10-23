/*********************************************************************************
Binary Search Tree:
Binary search tree (BST) is a binary tree data structure, in which the values in the left sub-trees of every node are smaller and the values in the right sub-trees of every node are larger.

Standard Binary search tree (BST) Operations: 
InsertNode(): Add item to the queue from the REAR.
SearchNode(): Check if queue is full or not.
DeleteNode(): Remove item from the queue from the FRONT.
PerOrderTraversel(): Check if queue empty or not.
PostOrderTraversel(): Check if queue empty or not.
InOrderTraversel(): Check if queue empty or not.
LevelOrderTraversel(): Check if queue empty or not.

Advantages of BST are:
1) we can always keep the cost of insert(), delete(), lookup() to O(logN) where N is the number of nodes in the tree. So the benefit really is that lookups can be done in logarithmic time which matters a lot when N is large.

2) We have an ordering of keys stored in the tree. Any time we need to traverse the increasing (or decreasing) order of keys, we just need to do the in-order (and reverse in-order) traversal on the tree.

3) We can implement order statistics with binary search tree - Nth smallest, Nth largest element. This is because it is possible to look at the data structure as a sorted array. We can also do range queries - find keys between N and M (N <= M).

4) BST can also be used in the design of memory allocators to speed up the search of free blocks (chunks of memory), and to implement best fit algorithms where we are interested in finding the smallest free chunk with size greater than or equal to size specified in allocation request.

Disadvantages of using BST are:
1) The main disadvantage is that we should always implement a balanced binary search tree - AVL tree, Red-Black tree, Splay tree. Otherwise the cost of operations may not be logarithmic and degenerate into a linear search on an array.

Process of Insertion In Binary Search Tree: 
1. Start from the root. 
2. Compare the inserting element with root, if less than root, then recurse for left, else recurse for right. 
3. After reaching the end, just insert that node at left(if less than current) else right. 

Process of Deletion In Binary Search Tree: When we delete a node from a Binary Search Tree, three possibilities arises:

1) Node to be deleted is leaf: Simply remove from the tree. 

              50                            50
           /     \         delete(20)      /   \
          30      70       --------->    30     70 
         /  \    /  \                     \    /  \ 
       20   40  60   80                   40  60   80


2) Node to be deleted has only one child: Replace the child to the node that you want to be delete and then delete the child Node.

              50                            50
           /     \         delete(30)      /   \
          30      70       --------->    40     70 
            \    /  \                          /  \ 
            40  60   80                       60   80

3) Node to be deleted has two children: Find inorder successor (minimum value Node in the right subtree) of the node that you want to be delete. Replace the inorder successor with the node that you want to be delete and delete the inorder successor.
 

              50                            60
           /     \         delete(50)      /   \
          40      70       --------->    40    70 
                 /  \                            \ 
                60   80                           80

The important thing to note is, inorder successor is needed only when right child is not empty. When right child is empty we gone to the second case.

*************************************************************************************/ 

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

class BinarySearchTree
{
    TreeNode *root;
    int height;

public:

    BinarySearchTree(int height = 10)
    {
        root = NULL;
        this->height = height;
    }

    ~BinarySearchTree()
    {
        deleteAllNode(root);
        root = NULL;
    }

    bool isEmpty()
    {
        return (root == NULL);
    }

    TreeNode *getRoot()
    {
        return root;
    }

    void setRoot(TreeNode *root)
    {
        this->root = root;
    }

    bool insertNode_iterative(int value)
    {
        TreeNode *new_node = new TreeNode(value);

        if (isEmpty())
        {
            root = new_node;
        }
        else
        {
            TreeNode *current = root;

            while (current != NULL)
            {
                if (new_node->getValue() == current->getValue())
                {
                    cout << "\nDuplicate Value are Not Allowed\n";
                    return false;
                }
                else if ((new_node->getValue() < current->getValue()) && (current->getLeft() == NULL))
                {
                    current->setLeft(new_node);
                    break;
                }
                else if (new_node->getValue() < current->getValue())
                {
                    current = current->getLeft();
                }
                else if ((new_node->getValue() > current->getValue()) && (current->getRight() == NULL))
                {
                    current->setRight(new_node);
                    break;
                }
                else
                {
                    current = current->getRight();
                }
            }
        }
        return true;
    }

    TreeNode *insertNode_recursive(TreeNode *root, TreeNode *new_node)
    {
        if (root == NULL)
        {
            root = new_node;
            return root;
        }

        if (new_node->getValue() < root->getValue())
        {
            root->setLeft(insertNode_recursive(root->getLeft(), new_node));
        }
        else if (new_node->getValue() > root->getValue())
        {
            root->setRight(insertNode_recursive(root->getRight(), new_node));
        }
        else
        {
            cout << "\nDuplicate Value are Not Allowed\n";
            return root;
        }

        return root;
    }

    void printInorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        printInorder(root->getLeft());
        cout << root->getValue() << " ";
        printInorder(root->getRight());
    }

    void printPreorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        cout << root->getValue() << " ";
        printPreorder(root->getLeft());
        printPreorder(root->getRight());
    }

    void printPostorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        printPostorder(root->getLeft());
        printPostorder(root->getRight());
        cout << root->getValue() << " ";
    }

    void printLevelOrder_iterative()
    {
        TreeNode *temp;
        queue <TreeNode *> que; // using queue data Structure

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

    // Print nodes at a given level
    void printGivenLevel(TreeNode *root, int level)
    {
        if (root == NULL)
            return;

        else if (level == 0)
            cout << root->getValue() << " ";

        else
        {
            printGivenLevel(root->getLeft(), level - 1);
            printGivenLevel(root->getRight(), level - 1);
        }
    }

    int binarytree_height_recursive(TreeNode *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        else
        {
            int leftHeight = binarytree_height_recursive(root->getLeft());
            int rightHeight = binarytree_height_recursive(root->getRight());

            if (leftHeight > rightHeight)
                return (leftHeight + 1);
            else
                return (rightHeight + 1);
        }
    }

    void printLevelOrder_recursive(TreeNode *root)
    {
        int height = binarytree_height_recursive(root);

        for (int i = 0; i <= height; i++)
            printGivenLevel(root, i);
    }

    // Print two-dimensional view of a binary tree using reverse inorder traversal
    void printTwoDimentionalOrder(TreeNode *root, int space)
    {
        // Base case
        if (root == NULL)
            return;

        // increase distance between levels
        space += height;

        // print right child first
        printTwoDimentionalOrder(root->getRight(), space);
        cout << endl;

        // print current node after padding with spaces
        for (int i = height; i < space; i++)
            cout << " ";
        cout << root->getValue() << "\n";

        // print left child
        printTwoDimentionalOrder(root->getLeft(), space);
    }

    TreeNode *searchNode_iterative(int value)
    {
        if (root == NULL)
        {
            return root;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (value == temp->getValue())
                {
                    return temp;
                }
                else if (value < temp->getValue())
                {
                    temp = temp->getLeft();
                }
                else
                {
                    temp = temp->getRight();
                }
            }
            return NULL;
        }
    }

    TreeNode *searchNode_recursive(TreeNode *root, int value)
    {
        if (root == NULL || root->getValue() == value)
            return root;

        else if (value < root->getValue())
            return searchNode_recursive(root->getLeft(), value);

        else
            return searchNode_recursive(root->getRight(), value);
    }

    int countAllNodes_recursive(TreeNode *root)
    {
        if (isEmpty())
        {
            return 0;
        }
        else
        {
            int count = 1;
            if (root->getLeft() != NULL)
            {
                count += countAllNodes_recursive(root->getLeft());
            }
            if (root->getRight() != NULL)
            {
                count += countAllNodes_recursive(root->getRight());
            }
            return count;
        }
    }

    TreeNode *minimum_node_iterative(TreeNode *root)
    {
        while (root->getLeft() != NULL)
        {
            root = root->getLeft();
        }
        return root;
    }

    TreeNode *maximum_node_iterative(TreeNode *root)
    {
        while (root->getRight() != NULL)
        {
            root = root->getRight();
        }
        return root;
    }

    TreeNode *deleteNode_recursive(TreeNode *root, int value)
    {
        // Base Condition of Recursion
        if (root == NULL)
        {
            return root;
        }

        // If value is smaller, so value is present on left subtree. And we have to traverse left subtree
        else if (value < root->getValue())
        {
            root->setLeft(deleteNode_recursive(root->getLeft(), value));
        }

        // If value is greater, so value is present on Right subtree. And, we have to traverse Right subtree
        else if (value > root->getValue())
        {
            root->setRight(deleteNode_recursive(root->getRight(), value));
        }

        // When we go to the else part then the location of Node that we want to delete is found successfully.
        else
        {
            // When Node with only right child or No Child
            if (root->getLeft() == NULL)
            {
                TreeNode *temp = root->getRight();
                delete root;
                return temp;
            }

            // When Node with only left child
            else if (root->getRight() == NULL)
            {
                TreeNode *temp = root->getLeft();
                delete root;
                return temp;
            }

            // When Node that we want to delete with Both Left and Right Child
            else
            {
                // find minimum value Node from right sub tree of that Node that we want to be deleted and store this min value on temp Node
                TreeNode *temp = minimum_node_iterative(root->getRight());

                // Replace the value of Node that we want to be deleted With the value of minimum Node From Right Sub Tree of That Node.
                root->setValue(temp->getValue());

                // And At Last Delete Minimum value Node From Right Sub Tree of That Node that we want to be deleted.
                root->setRight(deleteNode_recursive(root->getRight(), temp->getValue()));
            }
        }
        return root;
    }

    void deleteAllNode(TreeNode *root)
    {
        if (root == NULL)
            return;

        deleteAllNode(root->getLeft());
        deleteAllNode(root->getRight());
        delete root;
    }
};

int main()
{
    BinarySearchTree BST;
    TreeNode *Node;
    int value;
    bool check = true;

    while (check)
    {
        system("cls");
        int choice;
        cout << "\n\n|============= BINARY SEARCH TREE =============|\n"
             << "Please Select the Operation that you want to perform With the Given Options: \n"
             << "1 : Insert a Node on Binary Search Tree using Iterative Approach\n"
             << "2 : Insert a Node on Binary Search Tree using Recursive Approach\n"
             << "3 : Search a Specific Nodes In a Binary Search Tree using Iterative Approach\n"
             << "4 : Search a Specific Nodes In a Binary Search Tree using Recursive Approach\n"
             << "5 : Find The Height of the Binary Search Tree\n"
             << "6 : Find The Height of the Particular Node of a Binary Search Tree\n"
             << "7 : Find the Minimum Value Node in a Binary Search Tree\n"
             << "8 : Find the Maximum Value Node in a Binary Search Tree\n"
             << "9 : Count All Nodes In a Binary Search Tree\n"
             << "10 : Delete a Node from a Binary Search Tree\n"
             << "11 : Delete All Nodes from a Binary Search Tree\n"
             << "12 : Print Complete Binary Search Tree In PreOrder\n"
             << "13 : Print Complete Binary Search Tree In PostOrder\n"
             << "14 : Print Complete Binary Search Tree In InOrder\n"
             << "15 : Print All Nodes On a Given Level of a Binary Search Tree\n"
             << "16 : Print Complete Binary Search Tree In LevelOrder using Iterative Approach\n"
             << "17 : Print Complete Binary Search Tree In LevelOrder using Recursive Approach\n"
             << "18 : Print Complete Binary Search Tree In Two-Dimensional(2D) Order\n"
             << "19 : Exit This Application\n"
             << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Value that you want to insert on Binary Search Tree: ";
            cin >> value;
            BST.insertNode_iterative(value);
            break;

        case 2:
            cout << "Enter Value that you want to insert on Binary Search Tree: ";
            cin >> value;
            Node = new TreeNode(value);
            BST.setRoot(BST.insertNode_recursive(BST.getRoot(), Node));
            break;

        case 3:
            cout << "Enter Value that you want to Searches on Binary Search Tree: ";
            cin >> value;
            Node = BST.searchNode_iterative(value);

            if (Node != NULL)
                cout << "Value found" << endl;
            else
                cout << "Value NOT found" << endl;
            break;

        case 4:
            cout << "Enter Value that you want to Searches on Binary Search Tree: ";
            cin >> value;
            Node = BST.searchNode_recursive(BST.getRoot(), value);

            if (Node != NULL)
                cout << "Value found" << endl;
            else
                cout << "Value NOT found" << endl;
            break;

        case 5:
            cout << "Height of a Tree is: " << BST.binarytree_height_recursive(BST.getRoot());
            break;

        case 6:
            cout << "Enter Node Value that you want to Find Height on Binary Search Tree: ";
            cin >> value;
            Node = BST.searchNode_recursive(BST.getRoot(), value);
            cout << "Height of a Particular Node is: " << BST.binarytree_height_recursive(Node);
            break;

        case 7:
            cout << "Minimum Node of a Tree is: " << BST.minimum_node_iterative(BST.getRoot())->getValue();
            break;

        case 8:
            cout << "Minimum Node of a Tree is: " << BST.maximum_node_iterative(BST.getRoot())->getValue();
            break;

        case 9:
            cout << "Total Nodes in a Tree is: " << BST.countAllNodes_recursive(BST.getRoot());
            break;

        case 10:
            cout << "Enter Value of Node that you want to Delete on Binary Search Tree: ";
            cin >> value;
            BST.deleteNode_recursive(BST.getRoot(), value);
            cout << "Node Deleted Successfully From Binary Search Tree";
            break;

        case 11:
            BST.deleteAllNode(BST.getRoot());
            BST.setRoot(NULL);
            cout << "Successfully Delete All Nodes of a Binary Tree!";
            break;

        case 12:
            cout << "\nPreOrder Traversal: ";
            BST.printPreorder(BST.getRoot());
            cout << "\n";
            break;

        case 13:
            cout << "\nPostOrder Traversal: ";
            BST.printPostorder(BST.getRoot());
            cout << "\n";
            break;

        case 14:
            cout << "\nInOrder Traversal: ";
            BST.printInorder(BST.getRoot());
            cout << "\n";
            break;

        case 15:
            cout << "Enter the Level That You Want To Print All Node On a Binary Search Tree: ";
            cin >> value;
            BST.printGivenLevel(BST.getRoot(), value);
            break;

        case 16:
            cout << "\nlevelOrder Traversal: ";
            BST.printLevelOrder_iterative();
            cout << "\n";
            break;

        case 17:
            cout << "\nlevelOrder Traversal: ";
            BST.printLevelOrder_recursive(BST.getRoot());
            cout << "\n";
            break;

        case 18:
            BST.printTwoDimentionalOrder(BST.getRoot(), 5);
            break;

        case 19:
            check = false;
            cout << "\nThank You Very Much For Using This Application\n";
            break;

        default:
            cout << "Error : Invalid Value Detected!\n";
            break;
        }

        cout << "\n";
        system("pause");
    }

    return 0;
}