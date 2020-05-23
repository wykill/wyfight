#include <iostream>
using namespace std;

struct Node {
    Node() : value(0), left(NULL), right(NULL)
    {
    }
    Node(int val) : value(val), left(NULL), right(NULL)
    {
    }
    ~Node() {
    }

    Node* left;
    Node* right;
    int value;
};

class BSTree {
public:
    enum {
        max_bsize = 32767,
        min_bsize = 0
    };
public:
    BSTree() : m_root(NULL), m_size(0) {}
    virtual ~BSTree() {}

    int size() 
    {
        return m_size;
    }

    void insert(int val) 
    {
        if (m_size == max_bsize) {
            cout << "Error: BSTree size is max size, size is " << m_size << endl;
            return;
        }
        m_root = insert(m_root, val);
    }

    // 前序遍历
    void printByPreOrder()
    {
        printByPreOrder(m_root);
        cout << endl;
    }
    // 中序遍历
    void printByMedOrder()
    {
        printByMedOrder(m_root);
        cout << endl;
    }
    // 后序遍历
    void printByPostOrder()
    {
        printByPostOrder(m_root);
        cout << endl;
    }

    Node* query(int key)
    {
        return query_i(m_root, key);
    }

    void remove_all()
    {
        remove_all(m_root);
        m_size = 0;
    }

    void remove_node(int del_data)
    {
        remove_node(m_root, del_data);
    }

    Node *get_min_node()
    {
        return get_min_node(m_root);
    }

    Node *get_max_node()
    {
        return get_max_node(m_root);
    }

    Node *get_root_node() {
        return m_root;
    }

    Node *get_parent_node(int key) {
        // Node* node = get_parent_node(m_root, key);
        // cout << node->value << endl;
        return get_parent_node(m_root, key);
    }

private:
    Node* insert(Node* root, int val)
    {
        if (root == NULL) {
            root = new Node(val);
            m_size++;
            return root;
        }
        if (val < root->value) {
            root->left = insert(root->left, val);
        } else if (val > root->value){
            root->right = insert(root->right, val);
        }
        // 相等则不插入节点
        return root;
    }

    void printByPreOrder(Node* root)
    {
        if (root != NULL) {
            cout << root->value << ", ";
            printByPreOrder(root->left);
            printByPreOrder(root->right);
        }
    }

    void printByMedOrder(Node* root)
    {
        if (root != NULL) {
            printByMedOrder(root->left);
            cout << root->value << ", ";
            printByMedOrder(root->right);
        }
    }

    void printByPostOrder(Node* root)
    {
        if (root != NULL) {
            printByPostOrder(root->left);
            printByPostOrder(root->right);
            cout << root->value << ", ";
        }
    }

    void remove_all(Node*& root)
    {
        if (root == NULL) {
            return;
        }

        if (root->left) {
            remove_all(root->left);
        }
        if (root->right) {
            remove_all(root->right);
        }
        // cout << "delete Node: " << root->value << endl; 

        delete(root);
        root = NULL;
    }

    void remove_node(Node* root, int val)
    {
        // 1. 找到删除节点
        Node* findNode = query_i(root, val);
        Node* findParentNode = get_parent_node(root, val);
        if (findNode == NULL) {
            ::std::cout << "value[" << val << "] not exist! remove falied!" << ::std::endl;
            return;
        }

        // 2. 如果此节点为叶子节点
        if (findNode->left == NULL && findNode->right == NULL) {
            if (findNode == root) {
                delete(root);
                root = NULL;
            } else {
                if (findParentNode->left == findNode) {
                    // 叶子节点为左子树时，将父节点的左子树置空
                    findParentNode->left = NULL;
                } else {
                    // 叶子节点为右子树时，将父节点的右子树置空
                    findParentNode->right = NULL;
                }
                delete(findNode);
                findNode = NULL;
            }
        } 
        // 3. 如果此节点左子树为空，右子树不为空
        else if (findNode->left == NULL) {
            replaceNode(findNode, findNode->right, findParentNode);
        }
        // 4. 如果此节点左子树不为空，右子树为空
        else if (findNode->right == NULL) {
            replaceNode(findNode, findNode->left, findParentNode);
        } 
        // 5. 此节点左右子树都为非空，需要重新balance
        else {
            // TODO: balance 需要拿到后继节点  （左子树的最大值或者右子树的最小值，这里选择左子树的最大值）
            Node* sonNode = findNode->left;
            Node* successorNode = findNode;
            while(successorNode->right) {
                successorNode = sonNode;
                sonNode = successorNode->right;
            }
            findNode->value = successorNode->value;
            delete(successorNode);
        }

        m_size--;
    }

    void replaceNode(Node*& targetNode, Node* const& sonNode, Node*& parentNode)
    {
        // 清除目标节点
        delete(targetNode);

        // 如果目标节点为根结点，即找不到目标节点的父节点
        if (parentNode == NULL) {
            targetNode = sonNode;
        }
        // 如果目标节点非根结点
        else {
            if (sonNode->value < parentNode->value) {
                parentNode->left = sonNode;
            }
            else {
                parentNode->right = sonNode;
            }
        }
    }

    Node* query_i(Node* root, int val)
    {
        if (root == NULL) {
            return NULL;
        }
        if (root->value == val) {
            return root;
        }
        if (val < root->value) {
            return query_i(root->left, val);
        }
        if (val > root->value) {
            return query_i(root->right, val);
        }
        return NULL;
    }

    Node* get_min_node(Node* proot)
    {
        if (proot == NULL) {
            return NULL;
        }
        if (proot->left == NULL) {
            // cout << "proot is " << proot->value << endl;
            return proot;
        }
        return (get_min_node(proot->left));
    }

    Node* get_max_node(Node* proot)
    {
        if (proot == NULL) {
            return NULL;
        }
        if (proot->right == NULL) {
            return proot;
        }
        return (get_max_node(proot->right));
    }

    Node* get_parent_node(Node* root, int val)
    {
        if (root == NULL) {
            return NULL;
        }
        Node* leftNode = root->left;
        Node* rightNode = root->right;

        // 子树中找到值则返回父节点
        if ((leftNode && leftNode->value == val) || (rightNode && rightNode->value == val)) {
            // cout << root->value << endl;
            return root;
        }

        if (root->value == val) {
            return NULL;
        }
        else if (root->value < val) {
            return get_parent_node(rightNode, val);     // 父节点 小于 val， 说明值只可能在右子树中
        }
        else {
            return get_parent_node(leftNode, val);      // 父节点 大于 val， 说明值只可能在左子树中
        }
    }

private:
    Node* m_root;
    int m_size;
};

int main()
{
    BSTree tree;
    
    tree.insert(9);
    tree.insert(3);
    tree.insert(10);
    tree.insert(99);
    tree.insert(20);
    tree.insert(51);
    tree.insert(0);
    tree.insert(2);
    tree.insert(0);

    cout << "BSTree preOrder print: " << endl;
    tree.printByPreOrder();
    cout << "BSTree medOrder print: " << endl;
    tree.printByMedOrder();
    cout << "BSTree postOrder print: " << endl;
    tree.printByPostOrder();

    cout << "BSTree size is " << tree.size() << endl;

    // tree.remove_all();
    Node* minNode = tree.get_min_node();
    Node* maxNode = tree.get_max_node();
    cout << "BSTree min node is " << minNode->value << endl;
    cout << "BSTree max node is " << maxNode->value << endl;

    Node* parentNode = tree.get_parent_node(2);
    cout << "parentNode 2 is " << parentNode->value << endl;

    tree.remove_node(99);
    tree.remove_node(2);
    tree.remove_node(10);
    tree.remove_node(0);
    tree.remove_node(5);
    tree.remove_node(3);
    cout << "BSTree medOrder print: " << endl;
    tree.printByMedOrder();
    cout << "BSTree size is " << tree.size() << endl;
    return 0;
}