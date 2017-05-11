#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct tree
{
    int data;
    tree *left , *right;
};

class Btree
{
    static int n;
    static int m;
public:
    tree *root;
    Btree()
    {
        root = NULL;
    }

    void create_Btree(int);

    int findleaf(tree*);
    int count(tree*);
    // void PreOrder();

};

int Btree::n = 0;
int Btree::m = 0;

void Btree::create_Btree(int x)  
{  
    tree *newnode = new tree;  
    newnode->data = x;  
    newnode->right = newnode->left = NULL;  
    if(root == NULL)  
        root = newnode;
    else  
    {  
        tree *back;
        tree *current = root;
        while(current != NULL)  
        {  
            back = current;  
            if(current->data > x)  
                current = current->left;  
            else  
                current = current->right;  
        }

        if(back->data > x)  
            back->left = newnode;  
        else  
            back->right = newnode;  
    }  
}

int Btree::findleaf(tree* temp)
{
    if(temp == NULL) return 0;

    if(temp->left != NULL && temp->right != NULL)
        return n += 1;
    else{
        findleaf(temp->left);
        findleaf(temp->right);
    }

    return n;
}

int Btree::count(tree *p)  
{  
    if(p == NULL)  
        return 0;  
    else  
        return count(p->left) + count(p->right)+1;      //这是运用了函数嵌套即递归的方法。  
}  

int main(){

    Btree A;
    int array[] = {100,4,2,3,15,35,6,45,55,20,1,14,56,57,58};
    int k;
    k = sizeof(array) / sizeof(array[0]);

    cout << "建立排序二叉树顺序: " << endl;

    for(int i = 0; i < k; i++){

        cout << array[i] << " ";
        A.create_Btree(array[i]);

    }
    
    cout << endl;
    cout << "二叉树节点个数： " << A.count(A.root) << endl;
    cout << "二叉树叶子个数："  << A.findleaf(A.root) << endl;

    printf("hehehei %d \n" ,k);
}