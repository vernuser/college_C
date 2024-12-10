#include <stdio.h>
#include <stdlib.h>

typedef char Datatype;
struct Node {
    Datatype data;
    struct Node* next;
};
typedef struct Node *PNode;
typedef struct Node *LinkStack;

LinkStack SetNullStack_link()
{
    LinkStack top = (LinkStack)malloc(sizeof(struct Node));
    if (top != NULL)
        top->next = NULL;
    else
        printf("Alloc failure");
    return top;
}

Datatype IsNullStack_link(LinkStack top)
{
    if (top->next == NULL)
        return 1;
    else
        return 0;
}

void Push_link(LinkStack top, Datatype x)
{
    PNode p;
    p = (PNode)malloc(sizeof(struct Node));
    if (p == NULL)
        printf("Alloc failure");
    else
    {
        p->data = x;
        p->next = top->next;
        top->next = p;
    }
}


void Pop_link(LinkStack top)
{
    PNode p;
    if (top->next == NULL)
        printf("it is empty stack");
    else
    {
        p = top->next;
        top->next = p->next;
        Datatype data = p->data;  // 获取要返回的数据
        free(p);
        printf("%c ", data);     // 打印出栈的数据
    }
}

Datatype Top_link(LinkStack top)
{
    if (top->next == NULL)
    {
        printf("it is empty stack");
        return -1;  // 返回一个错误值表示空栈
    }
    else
        return top->next->data;
}

void BracketMatch(LinkStack top)
{
    int flag = 1;
    char ch, temp;
    ch = getchar();
    while (ch != '#')
    {
        switch (ch)
        {
        case '[':
        case '(':
            Push_link(top, ch);
            break;
        case ')':
            if (Top_link(top) == '(')
                Pop_link(top);
            else
                flag = 0;  // 括号不匹配时，设置flag为0并结束检测
            break;
        case']':
            if(Top_link(top) == '[')
                Pop_link(top);
            else
                flag = 0;  // 括号不匹配时，设置flag为0并结束检测
            break;
        }
        ch = getchar();
        if (!flag)  // 如果括号不匹配，则立即结束检测
            break;
    }
    if (!flag || !IsNullStack_link(top))
        printf("NO");
    else
        printf("YES");
}

int main()
{
    LinkStack mystack = NULL;
    mystack = SetNullStack_link();
    BracketMatch(mystack);
    return 0;
}
