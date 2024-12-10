#include <stdio.h>
#include <stdlib.h>
typedef char DataType;
typedef struct BTreeNode
{
    DataType data;
    struct BTreeNode *leftchild;
    struct BTreeNode *rightchild;
}BinTreeNode;
typedef BinTreeNode *BinTree;


BinTree CreateBinTree_Recursion()
{
    char ch;
    BinTree bt;
    scanf("%c", &ch);
    if (ch == '@')
        bt = NULL;
    else
    {
        bt = (BinTreeNode *)malloc(sizeof(BinTreeNode));
        bt->data = ch;
        bt->leftchild = CreateBinTree_Recursion();
        bt->rightchild = CreateBinTree_Recursion();
    }
    return bt;
}

int CountRightNode(BinTree bt)
{
    int num=0;
    if(bt==NULL)
        return 0;
    else
    if(bt->rightchild!=NULL)
        num++;
    num+=CountRightNode(bt->leftchild);
    num+=CountRightNode(bt->rightchild);
    return num;
}

void DestroyBinTree(BinTree bt)
{
    if (bt != NULL)
    {
        DestroyBinTree(bt->leftchild);
        DestroyBinTree(bt->rightchild);
        free(bt);
    }
}

int main()
{
    BinTree bt = NULL;
    int rightcount;
    bt = CreateBinTree_Recursion();
    rightcount = CountRightNode(bt);
    printf("%d", rightcount);
    DestroyBinTree(bt);
    return 0;
}
