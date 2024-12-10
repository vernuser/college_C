#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
//�ַ�����������
typedef char **HuffmanCode;
 
typedef struct
{
    int weight;
    char name;
    int parent, lchild, rchild;
}HTNode, *HuffmanTree;
 
//�����������
void Select(HuffmanTree HT, int len, int *s1, int *s2)
{
    int i, min1 = 0x3f3f3f3f, min2 = min1;
    for(i = 1; i <= len; i++)
    {
        //��parentֵΪ0ʱ˵����δ�ϲ����Ľ��
        if(HT[i].parent == 0)
        {
            //����СֵС��ʱ��
            if(HT[i].weight < min1)
            {
                //����Сֵ��������Сֵ
                min2 = min1;
                //����Сֵ�±�������Сֵ���±�
                *s2 = *s1;
                //���µ���Сֵ������Сֵmin
                min1 = HT[i].weight;
                //���µ���Сֵ�±긳��s1
                *s1 = i;
            }
            //û����СֵС��ʱ�򣬱Ƚ����ʹ���Сֵ
            else if(HT[i].weight < min2)
            {
                min2 = HT[i].weight;
                *s2 = i;
            }
        }
    }
}
 
//nΪҶ������
void CreateHuffmanTree(HuffmanTree *HT, int n)
{
    if(n<=1) return;
    int i;
    //����Ҫ���ٵĽ����
    int m = 2*n-1;
    *HT = (HTNode*)malloc(sizeof(HTNode)*(m+1));
    //�����н���˫�ס�������������ȫ��ʼ��Ϊ0
    for(i = 1; i <= m; i++)
    {
        (*HT)[i].parent = 0;
        (*HT)[i].lchild = 0;
        (*HT)[i].rchild = 0;
    }
    //�����������Ȩֵ������
    for(i = 1; i <= n; i++)
    {
        scanf("%c", &((*HT)[i].name));
        getchar();
        scanf("%d", &((*HT)[i].weight));
        getchar();
 
    }
    //��ʼ������������
    for(i = n+1; i <= m; i++)
    {-
        int s1,s2;
        //�ҳ���ǰ����Сֵ�ʹ���Сֵ
        Select(*HT, i-1, &s1, &s2);
        //��Ȩֵ�ϲ���ֵ��n+1��λ�ÿ�ʼ��ֵ
        (*HT)[s1].parent = i;
        (*HT)[s2].parent = i;
 
        (*HT)[i].lchild = s1;
        (*HT)[i].rchild = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }
}
 
void CreateHuffmanCode(HuffmanTree HT, HuffmanCode *HC, int n)
{
    //����n���ַ�������Ŀռ�
    *HC = (HuffmanCode)malloc(sizeof(char*)*(n+1));
    //����һ������Ϊn���ַ�����������ʱ��ű���
    char* cd = (char*)malloc(sizeof(char)*n);
    cd[n-1] = '\0';  //�ַ���������
    int i;
    for(i = 1; i <= n; i++)
    {
        int start = n-1; //���ַ������ĩβ��ʼ��ֵ
        int c = i;       //
        int f = HT[i].parent; //�ҳ����ڵ�
        //�������Ϊ0ʱ��˵��������ڵ㣬�������
        while(f != 0)
        {
            start--;
            //���c��f�����ӣ������ɴ���0
            if(HT[f].lchild == c)
                cd[start] = '0';
            else
                cd[start] = '1';
            //��ԭ����㿴���µ�����
            c = f;
            f = HT[f].parent;
        }
        //Ϊ��i���ַ�����������С���ʵĿռ�,����ʱ��ŵĸ��ƽ�ȥ
        (*HC)[i] = (char*)malloc(sizeof(char)*(n-start));
        //��start��λ�ÿ�ʼ����
        strcpy((*HC)[i], &cd[start]);
    }
    free(cd);
}
 
 
int main()
{
    int i;
	int n=8;
	HuffmanTree HT;   //��������ָ�����
	HuffmanCode HC;   //����������ָ�루����ָ�룩
	CreateHuffmanTree(&HT,n);    //������������
	CreateHuffmanCode(HT,&HC,n);  //���������������
	for(i=1;i<=n;i++)   //λ��һ���ģ����Ա�������
	{
		printf("%c:",HT[i].name);
		printf("%s\n",HC[i]);  //HC[i]�Ǳ��봮�׵�ֵַ��%s��ʽʱ�׵�ַ�Ϳ���
	}
	return 0;
 
}