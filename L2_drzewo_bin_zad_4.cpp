#include <iostream>
using namespace std;

struct BST
{
    BST *left;
    BST *right;
    BST *up;
    int key;
};

BST *root = NULL;

void insertBST(int k)
{
    BST *w = new BST;
    w->left = NULL;
    w->right = NULL;
    w->key = k;

    BST *p;
    p = root;

    if (!p)
    {
        root = w;
    }
    else
        while(true)
        {
            if (k<p->key)
            {
                if (!p->left)
                {
                    p->left = w;
                    break;
                }
                else p = p->left;
            }
            else
            {
                if (!p->right)
                {
                    p->right = w;
                    break;
                }
                else p = p->right;
            }
        }
        w->up=p;
}

void inorderBST(BST *v)
{
    if (v)
    {
        inorderBST(v->left);
        cout << v->key << " ";
        inorderBST(v->right);
    }
}

int findBST(BST *p, int k)
{
    if (p->key==k)
    {
        return p->key;
    }
    if (k<p->key)
    {
        if (p->left!=NULL)
        {
            findBST(p->left,k);
        }
        else
        {
            return -1;
        }
    }
    else
    {
        if (p->right!=NULL)
        {
            findBST(p->right,k);
        }
        else
        {
            return -1;
        }

    }


}

int main()
{
    insertBST(10);
    insertBST(5);
    insertBST(3);
    insertBST(9);
    insertBST(8);
    insertBST(14);
    insertBST(12);
    insertBST(1);
    insertBST(11);
    inorderBST(root);
    cout << endl;
    cout << findBST(root, 10) << endl;
    cout << findBST(root, 1) << endl;
    cout << findBST(root, 12) << endl;
    cout << findBST(root, 3) << endl;
    cout << findBST(root, 14) << endl;
    cout << findBST(root, 9) << endl;
    cout << findBST(root, 7) << endl;
    cout << findBST(root, 16) << endl;
}
