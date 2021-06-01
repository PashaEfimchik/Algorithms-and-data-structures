#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

enum Color { RED, BLACK, DOUBLE_BLACK };

template <class T>
class RBTNode {
public:
    int color;
    T data;
    RBTNode<T>* left;
    RBTNode<T>* right;
    RBTNode<T>* parent;

    RBTNode(T data) {
        this->data = data;
        color = RED;
        left = right = parent = nullptr;
    }
};

template<typename T>
class RedBlackTree
{
private:
    RBTNode<T>* root;

    int getColor(RBTNode<T>* p)
    {
        if (p == nullptr)
            return BLACK;

        return p->color;
    }

    void setColor(RBTNode<T>* p, int color)
    {
        if (p == nullptr)
            return;

        p->color = color;
    }

    void rotateLeft(RBTNode<T>* p)
    {
        RBTNode<T>* child = p->right;
        p->right = child->left;

        if (p->right != nullptr)
            p->right->parent = p;

        child->parent = p->parent;

        if (p->parent == nullptr)
            root = child;
        else if (p == p->parent->left)
            p->parent->left = child;
        else
            p->parent->right = child;

        child->left = p;
        p->parent = child;
    }

    void rotateRight(RBTNode<T>* p)
    {
        RBTNode<T>* child = p->left;
        p->left = child->right;

        if (p->left != nullptr)
            p->left->parent = p;

        child->parent = p->parent;

        if (p->parent == nullptr)
            root = child;
        else if (p == p->parent->left)
            p->parent->left = child;
        else
            p->parent->right = child;

        child->right = p;
        p->parent = child;
    }

    void RebalanceInsert(RBTNode<T>* p)
    {
        RBTNode<T>* parent = nullptr;
        RBTNode<T>* grandparent = nullptr;
        while (p != root && getColor(p) == RED && getColor(p->parent) == RED)
        {
            parent = p->parent;
            grandparent = parent->parent;
            if (parent == grandparent->left)
            {
                RBTNode<T>* uncle = grandparent->right;
                if (getColor(uncle) == RED)
                {
                    setColor(uncle, BLACK);
                    setColor(parent, BLACK);
                    setColor(grandparent, RED);
                    p = grandparent;
                }
                else
                {
                    if (p == parent->right)
                    {
                        rotateLeft(parent);
                        p = parent;
                        parent = p->parent;
                    }
                    rotateRight(grandparent);
                    swap(parent->color, grandparent->color);
                    p = parent;
                }
            }
            else
            {
                RBTNode<T>* uncle = grandparent->left;
                if (getColor(uncle) == RED)
                {
                    setColor(uncle, BLACK);
                    setColor(parent, BLACK);
                    setColor(grandparent, RED);
                    p = grandparent;
                }
                else {
                    if (p == parent->left)
                    {
                        rotateRight(parent);
                        p = parent;
                        parent = p->parent;
                    }
                    rotateLeft(grandparent);
                    swap(parent->color, grandparent->color);
                    p = parent;
                }
            }
        }
        setColor(root, BLACK);
    }

    RBTNode<T>* insertValue(RBTNode<T>* root, RBTNode<T>* p)
    {
        if (root == nullptr)
            return p;

        if (root->data >= p->data)
        {
            root->left = insertValue(root->left, p);
            root->left->parent = root;
        }
        else if (root->data < p->data)
        {
            root->right = insertValue(root->right, p);
            root->right->parent = root;
        }

        return root;
    }

    RBTNode<T>* randomInsertValue(RBTNode<T>* p, int k) {
        if (!p) return new RBTNode<T>(k);

    }
    RBTNode<T>* getMinValue(RBTNode<T>* p)
    {
        RBTNode<T>* min = p;

        while (min->left != nullptr)
            min = min->left;

        return min;
    }

    RBTNode<T>* getMaxValue(RBTNode<T>* p)
    {
        RBTNode<T>* max = p;

        while (max->right != nullptr)
            max = max->right;

        return max;
    }

    RBTNode<T>* next(RBTNode<T>* x)
    {
        if (x->right != NULL)
        {
            return getMinValue(x->right);
        }
        RBTNode<T>* y = x->parent;
        while (y != NULL && x == y->right)
        {
            x = y;
            y = y->parent;
        }
        return y;
    }

    RBTNode<T>* prev(RBTNode<T>* x)
    {
        if (x->left != NULL)
        {
            return getMaxValue(x->right);
        }
        RBTNode<T>* y = x->parent;
        while (y != NULL && x == y->left)
        {
            x = y;
            y = y->parent;
        }
        return y;
    }

    void RebalanceDelete(RBTNode<T>* p)
    {
        if (p == nullptr)
            return;

        if (p == root) {
            root = nullptr;
            return;
        }

        if (getColor(p) == RED || getColor(p->left) == RED || getColor(p->right) == RED) {
            RBTNode<T>* child = p->left != nullptr ? p->left : p->right;

            if (p == p->parent->left) {
                p->parent->left = child;
                if (child != nullptr)
                    child->parent = p->parent;
                setColor(child, BLACK);
                delete (p);
            }
            else {
                p->parent->right = child;
                if (child != nullptr)
                    child->parent = p->parent;
                setColor(child, BLACK);
                delete (p);
            }
        }
        else {
            RBTNode<T>* sb = nullptr;
            RBTNode<T>* parent = nullptr;
            RBTNode<T>* temp = p;
            setColor(temp, DOUBLE_BLACK);
            while (temp != root && getColor(temp) == DOUBLE_BLACK) {
                parent = temp->parent;
                if (temp == parent->left) {
                    sb = parent->right;
                    if (getColor(sb) == RED) {
                        setColor(sb, BLACK);
                        setColor(parent, RED);
                        rotateLeft(parent);
                    }
                    else {
                        if (getColor(sb->left) == BLACK && getColor(sb->right) == BLACK) {
                            setColor(sb, RED);
                            if (getColor(parent) == RED)
                                setColor(parent, BLACK);
                            else
                                setColor(parent, DOUBLE_BLACK);
                            temp = parent;
                        }
                        else {
                            if (getColor(sb->right) == BLACK) {
                                setColor(sb->left, BLACK);
                                setColor(sb, RED);
                                rotateRight(sb);
                                sb = parent->right;
                            }
                            setColor(sb, parent->color);
                            setColor(parent, BLACK);
                            setColor(sb->right, BLACK);
                            rotateLeft(parent);
                            break;
                        }
                    }
                }
                else {
                    sb = parent->left;
                    if (getColor(sb) == RED) {
                        setColor(sb, BLACK);
                        setColor(parent, RED);
                        rotateRight(parent);
                    }
                    else {
                        if (getColor(sb->left) == BLACK && getColor(sb->right) == BLACK) {
                            setColor(sb, RED);
                            if (getColor(parent) == RED)
                                setColor(parent, BLACK);
                            else
                                setColor(parent, DOUBLE_BLACK);
                            temp = parent;
                        }
                        else {
                            if (getColor(sb->left) == BLACK) {
                                setColor(sb->right, BLACK);
                                setColor(sb, RED);
                                rotateLeft(sb);
                                sb = parent->left;
                            }
                            setColor(sb, parent->color);
                            setColor(parent, BLACK);
                            setColor(sb->left, BLACK);
                            rotateRight(parent);
                            break;
                        }
                    }
                }
            }
            if (p == p->parent->left)
                p->parent->left = nullptr;
            else
                p->parent->right = nullptr;
            delete(p);
            setColor(root, BLACK);
        }
    }

    RBTNode<T>* deleteValue(RBTNode<T>* p, int val)
    {
        if (p == nullptr)
            return p;

        if (val < p->data)
            return deleteValue(p->left, val);

        if (val > p->data)
            return deleteValue(p->right, val);

        if (p->left == nullptr || p->right == nullptr)
            return p;

        RBTNode<T>* temp = getMaxValue(p->left);
        p->data = temp->data;
        return deleteValue(p->left, temp->data);
    }

    RBTNode<T>* searchValue(RBTNode<T>* p, int val)
    {
        if (p == nullptr || p->data == val)
            return p;
        else
            if (val > p->data)
                return searchValue(p->right, val);
            else
                return searchValue(p->left, val);
    }   

    void printTree(string prefix, RBTNode<T>* p, bool isLeft, string outer, string end)
    {
        if (p != nullptr)
        {
            cout << prefix;
            if (!isLeft && p->parent == nullptr)
                cout << "--" << p->data << endl;
            else if (isLeft && !p->parent->right) {
                cout << p->data << (p->color ? "(BLACK)" : "(RED)") << outer << endl;
            }
            else if (isLeft && p->parent->right) {
               
                cout << p->data << (p->color ? "(BLACK)" : "(RED)") << outer << endl;
            }
            else if (!isLeft) {
                cout << p->data << (p->color ? "(BLACK)" : "(RED)") << outer << endl;
            }
            
            printTree(prefix + (isLeft ? end : "    "), p->left, true, "L",end);
            printTree(prefix + (isLeft ? end : "    "), p->right, false, "R",end);
        }
    }

    void destroyTree(RBTNode<T>* p)
    {
        if (p == nullptr)
            return;
        destroyTree(p->left);
        destroyTree(p->right);
        cout << p->data << "(" << (p->color ? "BLACK" : "RED") << ") has been destroyed!" << endl;
        delete p;
        p = nullptr;
    }

public:
    RedBlackTree()
    {
        root = nullptr;
    }

    void insert(int val)
    {
        RBTNode<T>* p;
        p = new RBTNode<T>(val);
        root = insertValue(root, p);
        RebalanceInsert(p);
    }

    void remove(int val)
    {
        if (root == nullptr)
        {
            cout << "\tRed Black Tree is empty!\n";
            return;
        }

        RBTNode<T>* p = deleteValue(root, val);

        if (p != nullptr)
        {
            RebalanceDelete(p);
            cout << "\tValue " << val << " has been removed!\n";
        }
        else
            cout << "\tValue " << val << " does not exist!\n";
    }

    void search(int val)
    {
        if (root == nullptr)
        {
            cout << "\tRed Black Tree is empty!\n";
            return;
        }

        RBTNode<T>* p = searchValue(root, val);

        if (p == nullptr || p->data != val)
            cout << "\tValue " << val << " does not exist!\n";
        else
            cout << "\tValue " << p->data << (p->color ? "(BLACK)" : "(RED)") << " has been found!\n";
    }

    void print()
    {
        if (root == nullptr)
        {
            cout << "\tRed Black Tree is empty!\n";
            return;
        }

        string end1 = "|   ";

        cout << endl;
        printTree("", root, false, "LR", end1);
        cout << endl;
    }
    template<class T>
    class Iterator
    {
    public:
        Iterator(RBTNode<T>* x) {
            ptr = x;
        }
        Iterator() {
            ptr = nullptr;
        }

        Iterator begin()
        {
            RBTNode* v = root;
            while (v && v->left)
                v = v->left;
            return Iterator(v);
        }

        Iterator last()
        {
            RBTNode* v = root;
            while (v && v->right)
                v = v->right;
            return Iterator(v);
        }
        
        Iterator end()
        {
            return Iterator(nullptr);
        }

        Iterator operator++(int)
        {
            Iterator vt = *v->next(ptr);
            return vt;
        }

        Iterator operator--(int)
        {
            Iterator vt = *v->prev(ptr);
            return vt;
        }
    private:
        RBTNode<T> ptr;
        RedBlackTree* v = new RedBlackTree();
    };

    ~RedBlackTree()
    {
        if (root != nullptr)
        {
            destroyTree(root);
            cout << "\nRed Black Tree has been successfully destroyed!\n\n";
        }
        else
            cout << "Red Black Tree is empty!\n\n";

    }
};
