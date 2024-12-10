#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
struct SeqStackNode
{
    int MAX;         
    int top;        
    DataType *elem; 
};
typedef struct SeqStackNode *SeqStack;

SeqStack SetNullStack_Seq(int m) 
{
    SeqStack sstack = (SeqStack)malloc(sizeof(struct SeqStackNode));
    if (sstack != NULL) {
        sstack->elem = (int*)malloc(sizeof(int)*m);
        if (sstack->elem != NULL) {
            sstack->MAX = m;
            sstack->top = -1;
            return(sstack);
        }
        else {
            free(sstack);
            return NULL;
        }
    }
    else {
        printf("out of space");
        return NULL;
    }
}

int IsNullStack_seq(SeqStack sstack) 
{
    return(sstack->top == -1);
}
void Push_seq(SeqStack sstack, int x)
{	
	if(sstack ->top>=(sstack->MAX-1))
        printf("overflow!\n");
    else
    {
        sstack->top ++;
        sstack->elem[sstack->top]=x;
    }
}
void Pop_seq(SeqStack sstack)
{
    if (IsNullStack_seq(sstack)) 
        printf("Underflow!\n");
    else
        sstack->top = sstack->top - 1;
}
DataType Top_seq(SeqStack sstack)
{
    if (IsNullStack_seq(sstack))
    {
        printf("it is empty");
        return 0;
    }
    else
        return sstack->elem[sstack->top];
}

void Hexconversion(SeqStack sstack, int n)
{
    while(n)
    {
        int tmp = n%16;
        switch(tmp)
        {
        case 10:tmp='A';break;
        case 11:tmp='B';break;
        case 12:tmp='C';break;
        case 13:tmp='D';break;
        case 14:tmp='E';break;
        case 15:tmp='F';break;
        }
     Push_seq(sstack,tmp);
        n=n/16;
    }
    while(!IsNullStack_seq(sstack))
    {
        n=Top_seq(sstack);
        if(n<10)
            printf("%d",n);
        else
            printf("%c",n);
        Pop_seq(sstack);
    }
}
int main()
{
    SeqStack mystack = NULL;
    int n;
    mystack = SetNullStack_Seq(4);
    scanf("%d", &n);
    Hexconversion(mystack, n);
    return 0;
}
