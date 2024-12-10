#include<bits/stdc++.h>
using namespace std;
/*����������Ľṹ*/
typedef struct Node
{
    char data;                    /*����*/
    struct Node *lchild, *rchild; /*��������������*/
} * BiTree, BiNode;
/*�������ͽ������*/

/*���贴��������*/
void CreateBiTree(BiTree &T)
{
    char ch;
    cin >> ch;
    if (ch == '@')
        T = NULL;
    else
    {
        T = new BiNode; /*����һ���½ڵ�*/
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    /*�ݹ鴴��*/
}
void InOrderTraverse(BiTree T)
{
    /*�������*/
    if (T)
    {
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}
void PreOrderTraverse(BiTree T)
{
    /*�������*/
    if (T)
    {
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
void PostOrderTraverse(BiTree T)
{
    /*�������*/
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data;
    }
}
/*ͳ�ƶ������н��ĸ���*/
int NodeCount(BiTree T)
{
    if (T == NULL)
        return 0;
    else
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}
int main()
{
    BiTree T;
    CreateBiTree(T);
    PreOrderTraverse(T);
    cout << endl;
    InOrderTraverse(T);
    cout << endl;
    PostOrderTraverse(T);
    return 0;
}