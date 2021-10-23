/*******************************************************************************************
AVL Tree:
AVL tree is a self-balancing Binary Search Tree (BST) where the difference between heights of left and right subtrees cannot be more than one for every nodes. This difference is called the Balance Factor. So, the balance factor contains (-1, 0, 1). An Example Tree that is an AVL Tree are:

                 12
               /   \
              8    18
            / \    /
           5  11  17
          /
         4

The above tree is AVL because differences between heights of left and right subtrees for every node is less than or equal to 1. An Example Tree that is NOT an AVL Tree 

                 12
               /   \
              8    18
            / \    /
           5  11  17
          / \
         4   7
        /
       2

Why AVL Trees?
Most of the BST operations (e.g., search, max, min, insert, delete etc) take O(h) time where h is the height of the BST. The cost of these operations may become O(n) for a skewed Binary tree. If we make sure that height of the tree remains O(Logn) after every insertion and deletion, then we can guarantee an upper bound of O(Logn) for all these operations. The height of an AVL tree is always O(Logn) where n is the number of nodes in the tree. Since AVL tree is nothing but a Balanced Binary Search Tree, the Time complexity of the operations is always more efficient as compared to regular BST.

Insertion:
Insertion in AVL tree is performed in the same way as it is performed in a binary search tree. The new node is added into AVL tree as the leaf node. Rotation is required only if, the balance factor of any node is disturbed upon inserting the new node, otherwise the rotation is not required. Depending upon the type of insertion, the Rotations are categorized into four categories:

1) LEFT LEFT Imbalance/case (RIGHT Rotation): When the new node is inserted to the left sub-tree of left sub-tree of critical node. So, we perform RIGHT Rotation on it.

2) RIGHT RIGHT Imbalance/case (LEFT Rotation): When the new node is inserted to the right sub-tree of the right sub-tree of the critical node. So, we perform LEFT Rotation on it. 

3) LEFT RIGHT Imbalance/case (LEFT RIGHT Rotation): When the new node is inserted to the right sub-tree of the left sub-tree of the critical node. So, we perform LEFT Rotation and then RIGHT Rotation on it.

4) RIGHT LEFT Imbalance/case (RIGHT LEFT Rotation): When the new node is inserted to the left sub-tree of the right sub-tree of the critical node. So, we perform RIGHT Rotation and then LEFT Rotation on it.


How to Perform Rotation:
To perform the rotation, it is neccessary to identify a specific Node 'A' Where Balance factor (BF) is neither -1, 0, 1 and which is the nearest ancestor to the inserted node on the path from the inserted node to the root.

Left Rotation:
If a tree becomes unbalanced, when a node is inserted into the right subtree of the right subtree, then we perform a single left rotation

           A                       Balance Factor (BC) of A = 2
            \
             B                     Balance Factor (BC) of B = 1
              \
               C                   Balance Factor (BC) of C = 0

In our example, node A has become unbalanced as a node is inserted in the right subtree of A's right subtree. We perform the left rotation by making A the left-subtree of B

                 B                 Balance Factor (BC) of B = 0   
               /  \
              A    C               Balance Factor (BC) of A = 0; Balance Factor (BC) of C = 0 



Right Rotation:
If a tree becomes unbalanced, when a node is inserted into the Left subtree of the Left subtree, then we perform a single Right rotation

                 C                 Balance Factor (BC) of C = 2
                /
               B                   Balance Factor (BC) of B = 1
              /
             A                     Balance Factor (BC) of A = 0

In our example, node C has become unbalanced as a node is inserted in the left subtree of C's left subtree. We perform the Right rotation by making C the Right-subtree of B

                 B                 Balance Factor (BC) of B = 0   
               /  \
              A    C               Balance Factor (BC) of A = 0; Balance Factor (BC) of C = 0 


 
Left-Right Rotation:
Double rotations are slightly complex version of already explained versions of rotations. To understand them better, we should take note of each action performed while rotation. Let's first check how to perform Left-Right rotation. A left-right rotation is a combination of left rotation followed by right rotation.

                C                  Balance Factor (BC) of C = 2
               /
              A                    Balance Factor (BC) of A = 1
               \
                B                  Balance Factor (BC) of B = 0

A node has been inserted into the right subtree of the left subtree of C. This makes C an unbalanced node. These scenarios cause AVL tree to perform left-right rotation. So We first perform the left rotation on the left subtree of C. This makes the 'A', is the left subtree of B.

                 C                 Balance Factor (BC) of C = 2
                /
               B                   Balance Factor (BC) of B = 1
              /
             A                     Balance Factor (BC) of A = 0

Node C is still unbalanced, however now, it is because of the left-subtree of the left-subtree.	We shall now right-rotate the tree, making B the new root node of this subtree. C now becomes the right subtree of its own left subtree.

                 B                 Balance Factor (BC) of B = 0   
               /  \
              A    C               Balance Factor (BC) of A = 0; Balance Factor (BC) of C = 0 



Right-Left Rotation:
The second type of double rotation is Right-Left Rotation. It is a combination of right rotation followed by left rotation.

                A                  Balance Factor (BC) of A = 2
                 \      
                  C                Balance Factor (BC) of C = 1
                 /
                B                  Balance Factor (BC) of B = 0

A node has been inserted into the left subtree of the right subtree. This makes A, an unbalanced node with balance factor 2. First, we perform the right rotation along C node, making C the right subtree of its own left subtree B. Now, B becomes the right subtree of A.

                A                  Balance Factor (BC) of A = 2
                 \
                  B                Balance Factor (BC) of B = 1
                   \
                    C              Balance Factor (BC) of C = 0

Node A is still unbalanced because of the right subtree of its right subtree and requires a left rotation.  A left rotation is performed by making B the new root node of the subtree. A becomes the left subtree of its right subtree B

                 B                 Balance Factor (BC) of B = 0   
               /  \
              A    C               Balance Factor (BC) of A = 0; Balance Factor (BC) of C = 0 

Important Point: We apply rotation on a binary tree because it is unbalanced and we want to make it balanced tree as well as binary search tree. So the time complexity of tree is reduces.


Deletion In AVL Tree:
Deleting a node from an AVL tree is similar to that in a binary search tree. Deletion may disturb the balance factor of an AVL tree and therefore the tree needs to be rebalanced in order to maintain the AVLness. For this purpose, we need to perform rotations. To maintain the balance in AVL tree after deletion, we perform Rotations. Depending on different imbalance cases, we have 4 basic types of rotations:

1) LEFT LEFT Imbalance/case (RIGHT Rotation): When the new node is inserted to the left sub-tree of left sub-tree of critical node. So, we perform RIGHT Rotation on it.

2) RIGHT RIGHT Imbalance/case (LEFT Rotation): When the new node is inserted to the right sub-tree of the right sub-tree of the critical node. So, we perform LEFT Rotation on it. 

3) LEFT RIGHT Imbalance/case (LEFT RIGHT Rotation): When the new node is inserted to the right sub-tree of the left sub-tree of the critical node. So, we perform LEFT Rotation and then RIGHT Rotation on it.

4) RIGHT LEFT Imbalance/case (RIGHT LEFT Rotation): When the new node is inserted to the left sub-tree of the right sub-tree of the critical node. So, we perform RIGHT Rotation and then LEFT Rotation on it.

*********************************************************************************************/ 

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

class AVLBinaryTree
{
    TreeNode *root;
    int height;

public:
    AVLBinaryTree(int height = 10)
    {
        root = NULL;
        this->height = height;
    }

    ~AVLBinaryTree()
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

    int balanceFactor(TreeNode *root)
    {
        if (root == NULL)
            return -1;
        else
            return (binarytree_height_recursive(root->getLeft()) - binarytree_height_recursive(root->getRight()));
    }

    TreeNode *rightRotate(TreeNode *y)
    {
        TreeNode *x = y->getLeft();
        TreeNode *tree = x->getRight();

        // Perform rotation
        x->setRight(y);
        y->setLeft(tree);

        return x;
    }

    TreeNode *leftRotate(TreeNode *x)
    {
        TreeNode *y = x->getRight();
        TreeNode *tree = y->getLeft();

        // Perform rotation
        y->setLeft(x);
        x->setRight(tree);

        return y;
    }

    TreeNode *insertNode_recursive(TreeNode *root, TreeNode *new_node)
    {
        if (root == NULL)
        {
            root = new_node;
            return root;
        }

        if (new_node->getValue() > root->getValue())
        {
            root->setRight(insertNode_recursive(root->getRight(), new_node));
        }

        else if (new_node->getValue() < root->getValue())
        {
            root->setLeft(insertNode_recursive(root->getLeft(), new_node));
        }
        
        else
        {
            cout << "\nDuplicate Value are Not Allowed\n";
            return root;
        }

        // finding balance Factor of Current Node
        int bf = balanceFactor(root);

        // Left Left Case
        if (bf > 1 && new_node->getValue() < root->getLeft()->getValue())
            return rightRotate(root);

        // Right Right Case
        if (bf < -1 && new_node->getValue() > root->getRight()->getValue())
            return leftRotate(root);

        // Left Right Case
        if (bf > 1 && new_node->getValue() > root->getLeft()->getValue())
        {
            root->setLeft(leftRotate(root->getLeft()));
            return rightRotate(root);
        }

        // Right Left Case
        if (bf < -1 && new_node->getValue() < root->getRight()->getValue())
        {
            root->setRight(rightRotate(root->getRight()));
            return leftRotate(root);
        }

        // return the (unchanged) node pointer
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
        queue<TreeNode *> que;

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

        int bf = balanceFactor(root);

        // Left Left Imbalance/Case or Right rotation
        if (bf == 2 && balanceFactor(root->getLeft()) >= 0)
            return rightRotate(root);

        // Left Right Imbalance/Case or LR rotation
        else if (bf == 2 && balanceFactor(root->getLeft()) == -1)
        {
            root->setLeft(leftRotate(root->getLeft()));
            return rightRotate(root);
        }

        // Right Right Imbalance/Case or Left rotation
        else if (bf == -2 && balanceFactor(root->getRight()) <= -0)
            return leftRotate(root);

        // Right Left Imbalance/Case or RL rotation
        else if (bf == -2 && balanceFactor(root->getRight()) == 1)
        {
            root->setRight(rightRotate(root->getRight()));
            return leftRotate(root);
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
    AVLBinaryTree AVL;
    TreeNode *Node;
    int value;
    bool check = true;

    while (check)
    {
        system("cls");
        int choice;
        cout << "\n\n|============= AVL BINARY TREE =============|\n"
             << "Please Select the Operation that you want to perform With the Given Options: \n"
             << "1 : Insert a Node on AVL Binary Tree\n"
             << "2 : Search a Specific Nodes In a AVL Binary Tree using Iterative Approach\n"
             << "3 : Search a Specific Nodes In a AVL Binary Tree using Recursive Approach\n"
             << "4 : Find The Height of the AVL Binary Tree\n"
             << "5 : Find The Height of the Particular Node of a AVL Binary Tree\n"
             << "6 : Find The Balance Factor of the Particular Node of a AVL Binary Tree\n"
             << "7 : Find the Minimum Value Node in a AVL Binary Tree\n"
             << "8 : Find the Maximum Value Node in a AVL Binary Tree\n"
             << "9 : Count All Nodes In a AVL Binary Tree\n"
             << "10 : Delete a Node from a AVL Binary Tree\n"
             << "11 : Delete All Nodes from a AVL Binary Tree\n"
             << "12 : Print Complete AVL Binary Tree In PreOrder\n"
             << "13 : Print Complete AVL Binary Tree In PostOrder\n"
             << "14 : Print Complete AVL Binary Tree In InOrder\n"
             << "15 : Print All Nodes On a Given Level of a AVL Binary Tree\n"
             << "16 : Print Complete AVL Binary Tree In LevelOrder using Iterative Approach\n"
             << "17 : Print Complete AVL Binary Tree In LevelOrder using Recursive Approach\n"
             << "18 : Print Complete AVL Binary Tree In Two-Dimensional(2D) Order\n"
             << "19 : Exit This Application\n"
             << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Value that you want to insert on AVL Binary Tree: ";
            cin >> value;
            Node = new TreeNode(value);
            AVL.setRoot(AVL.insertNode_recursive(AVL.getRoot(), Node));
            break;

        case 2:
            cout << "Enter Value that you want to Searches on AVL Binary Tree: ";
            cin >> value;
            Node = AVL.searchNode_iterative(value);

            if (Node != NULL)
                cout << "Value found" << endl;
            else
                cout << "Value NOT found" << endl;
            break;

        case 3:
            cout << "Enter Value that you want to Searches on AVL Binary Tree: ";
            cin >> value;
            Node = AVL.searchNode_recursive(AVL.getRoot(), value);

            if (Node != NULL)
                cout << "Value found" << endl;
            else
                cout << "Value NOT found" << endl;
            break;

        case 4:
            cout << "Height of a Tree is: " << AVL.binarytree_height_recursive(AVL.getRoot());
            break;

        case 5:
            cout << "Enter Node Value that you want to Find Height on AVL Binary Tree: ";
            cin >> value;
            Node = AVL.searchNode_recursive(AVL.getRoot(), value);
            cout << "Height of a Particular Node is: " << AVL.binarytree_height_recursive(Node);
            break;

        case 6:
            cout << "Enter Node Value that you want to Find Balance Factor on AVL Binary Tree: ";
            cin >> value;
            Node = AVL.searchNode_recursive(AVL.getRoot(), value);
            cout << "Balance Factor of a Particular Node is: " << AVL.balanceFactor(Node);
            break;

        case 7:
            cout << "Minimum Node of a Tree is: " << AVL.minimum_node_iterative(AVL.getRoot())->getValue();
            break;

        case 8:
            cout << "Minimum Node of a Tree is: " << AVL.maximum_node_iterative(AVL.getRoot())->getValue();
            break;

        case 9:
            cout << "Total Nodes in a Tree is: " << AVL.countAllNodes_recursive(AVL.getRoot());
            break;

        case 10:
            cout << "Enter Value of Node that you want to Delete on AVL Binary Tree: ";
            cin >> value;
            AVL.deleteNode_recursive(AVL.getRoot(), value);
            cout << "Node Deleted Successfully From AVL Binary Tree";
            break;

        case 11:
            AVL.deleteAllNode(AVL.getRoot());
            AVL.setRoot(NULL);
            cout << "Successfully Delete All Nodes of a Binary Tree!";
            break;

        case 12:
            cout << "\nPreOrder Traversal: ";
            AVL.printPreorder(AVL.getRoot());
            cout << "\n";
            break;

        case 13:
            cout << "\nPostOrder Traversal: ";
            AVL.printPostorder(AVL.getRoot());
            cout << "\n";
            break;

        case 14:
            cout << "\nInOrder Traversal: ";
            AVL.printInorder(AVL.getRoot());
            cout << "\n";
            break;

        case 15:
            cout << "Enter the Level That You Want To Print All Node On a AVL Binary Tree: ";
            cin >> value;
            AVL.printGivenLevel(AVL.getRoot(), value);
            break;

        case 16:
            cout << "\nlevelOrder Traversal: ";
            AVL.printLevelOrder_iterative();
            cout << "\n";
            break;

        case 17:
            cout << "\nlevelOrder Traversal: ";
            AVL.printLevelOrder_recursive(AVL.getRoot());
            cout << "\n";
            break;

        case 18:
            AVL.printTwoDimentionalOrder(AVL.getRoot(), 5);
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
