#include<stdio.h>
#include<stdlib.h>

typedef int Datatype;

// 定义节点结构体
struct Node{
    Datatype data;
    struct Node *next;
};

typedef struct Node* PNode;
typedef struct Node* Linklist;

// 初始化一个空链表
Linklist SetNullList_link()
{
    Linklist head = (Linklist)malloc(sizeof(struct Node));
    if(head != NULL)
        head->next = NULL;
    else
        printf("分配内存失败");
    return head;
}

// 判断链表是否为空
int IsNullList_link(Linklist llist)
{
    return (llist->next == NULL);
}

// 创建链表
void CreateList(Linklist head)
{
    PNode p = NULL;
    PNode q = head;
    int data;

    scanf("%d", &data);
    while(data != -1)
    {
        p = (Linklist)malloc(sizeof(struct Node));
        p->data = data;
        p->next = NULL;
        q->next = p;
        q = p;
        scanf("%d", &data);
    }
}

// 删除从第i个节点开始的j个节点
void Delete_i_j(Linklist head,int i,int j){
    int count=1;
    PNode p,pre;
    pre=head;
    p=pre->next;
    while(p){
        if(count!=i){
            pre=p;
            p=p->next;
            count++;
        }
        else{
            for(count;count<i+j;count++){
                pre->next=p->next;
                p->next=NULL;
                free(p);
                p=pre->next;
            }
            break;
        }
    }
}

// 打印链表
void print(Linklist head)
{
    PNode p = head->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

// 销毁链表
void DestroyList(Linklist head)
{
    PNode pre = head;
    PNode p = pre->next;
    while(p)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}

int main()
{
    Linklist head = NULL;
    head = SetNullList_link();
    CreateList(head);
    int k;
    int j;
    scanf("%d %d", &j,&k);
    Delete_i_j(head,j,k);
    print(head);
    DestroyList(head);
    return 0;
}