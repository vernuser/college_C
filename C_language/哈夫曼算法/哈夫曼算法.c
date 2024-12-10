#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
//字符串数组类型
typedef char **HuffmanCode;
 
typedef struct
{
    int weight;
    char name;
    int parent, lchild, rchild;
}HTNode, *HuffmanTree;
 
//构造哈夫曼树
void Select(HuffmanTree HT, int len, int *s1, int *s2)
{
    int i, min1 = 0x3f3f3f3f, min2 = min1;
    for(i = 1; i <= len; i++)
    {
        //当parent值为0时说明是未合并过的结点
        if(HT[i].parent == 0)
        {
            //比最小值小的时候
            if(HT[i].weight < min1)
            {
                //把最小值赋给次最小值
                min2 = min1;
                //把最小值下表赋给次最小值的下标
                *s2 = *s1;
                //把新的最小值赋给最小值min
                min1 = HT[i].weight;
                //把新的最小值下标赋给s1
                *s1 = i;
            }
            //没有最小值小的时候，比较他和次最小值
            else if(HT[i].weight < min2)
            {
                min2 = HT[i].weight;
                *s2 = i;
            }
        }
    }
}
 
//n为叶结点个数
void CreateHuffmanTree(HuffmanTree *HT, int n)
{
    if(n<=1) return;
    int i;
    //计算要开辟的结点数
    int m = 2*n-1;
    *HT = (HTNode*)malloc(sizeof(HTNode)*(m+1));
    //将所有结点的双亲、左子树右子树全初始化为0
    for(i = 1; i <= m; i++)
    {
        (*HT)[i].parent = 0;
        (*HT)[i].lchild = 0;
        (*HT)[i].rchild = 0;
    }
    //输入各个结点的权值和名字
    for(i = 1; i <= n; i++)
    {
        scanf("%c", &((*HT)[i].name));
        getchar();
        scanf("%d", &((*HT)[i].weight));
        getchar();
 
    }
    //开始创建哈夫曼树
    for(i = n+1; i <= m; i++)
    {-
        int s1,s2;
        //找出当前的最小值和次最小值
        Select(*HT, i-1, &s1, &s2);
        //把权值合并的值从n+1的位置开始赋值
        (*HT)[s1].parent = i;
        (*HT)[s2].parent = i;
 
        (*HT)[i].lchild = s1;
        (*HT)[i].rchild = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }
}
 
void CreateHuffmanCode(HuffmanTree HT, HuffmanCode *HC, int n)
{
    //分配n个字符串编码的空间
    *HC = (HuffmanCode)malloc(sizeof(char*)*(n+1));
    //开辟一个长度为n的字符数组用来临时存放编码
    char* cd = (char*)malloc(sizeof(char)*n);
    cd[n-1] = '\0';  //字符串结束符
    int i;
    for(i = 1; i <= n; i++)
    {
        int start = n-1; //从字符数组的末尾开始赋值
        int c = i;       //
        int f = HT[i].parent; //找出父节点
        //当父结点为0时，说明到达根节点，编码结束
        while(f != 0)
        {
            start--;
            //结点c是f的左孩子，则生成代码0
            if(HT[f].lchild == c)
                cd[start] = '0';
            else
                cd[start] = '1';
            //将原父结点看作新的子树
            c = f;
            f = HT[f].parent;
        }
        //为第i个字符串编码分配大小合适的空间,把临时存放的复制进去
        (*HC)[i] = (char*)malloc(sizeof(char)*(n-start));
        //从start的位置开始复制
        strcpy((*HC)[i], &cd[start]);
    }
    free(cd);
}
 
 
int main()
{
    int i;
	int n=8;
	HuffmanTree HT;   //哈夫曼树指针变量
	HuffmanCode HC;   //哈夫曼编码指针（二重指针）
	CreateHuffmanTree(&HT,n);    //创建哈夫曼树
	CreateHuffmanCode(HT,&HC,n);  //创建哈夫曼编码表
	for(i=1;i<=n;i++)   //位置一样的，所以遍历即可
	{
		printf("%c:",HT[i].name);
		printf("%s\n",HC[i]);  //HC[i]是编码串首地址值，%s格式时首地址就可以
	}
	return 0;
 
}