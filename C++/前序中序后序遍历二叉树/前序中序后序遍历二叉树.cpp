#include<bits/stdc++.h>
using namespace std;
/*定义二叉树的结构*/
typedef struct Node
{
    char data;                    /*数据*/
    struct Node *lchild, *rchild; /*左子树和右子树*/
} * BiTree, BiNode;
/*整棵树和结点名称*/

/*先需创建二叉树*/
void CreateBiTree(BiTree &T)
{
    char ch;
    cin >> ch;
    if (ch == '@')
        T = NULL;
    else
    {
        T = new BiNode; /*创建一个新节点*/
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    /*递归创建*/
}
void InOrderTraverse(BiTree T)
{
    /*中序遍历*/
    if (T)
    {
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}
void PreOrderTraverse(BiTree T)
{
    /*先序遍历*/
    if (T)
    {
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
void PostOrderTraverse(BiTree T)
{
    /*后序遍历*/
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data;
    }
}
/*统计二叉树中结点的个数*/
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