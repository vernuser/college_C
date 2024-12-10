#include<stdio.h>
#include<stdlib.h>

typedef int Datatype;
struct Node{
    Datatype data;
    struct Node *next;
};

typedef struct Node* PNode;
typedef struct Node* Linklist;

Linklist SetNullList_link()
{
    Linklist head = (Linklist)malloc(sizeof(struct Node));
    if(head != NULL)
        head->next = NULL;
    else
        printf("Alloc failure");
    return head;
}

int IsNullList_link(Linklist llist)
{
    return (llist->next == NULL);
}

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

void Delete_element(Linklist head, int target) {
    PNode p, pre;
    pre = head;
    p = pre->next;
    while (p) {
        if (p->data == target) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}

void print(Linklist head)
{
    PNode p = head->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

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

int main() {
    Linklist head = NULL;
    head = SetNullList_link();
    CreateList(head);
    int target;
    printf("Enter the element you want to delete: ");
    scanf("%d", &target);
    Delete_element(head, target);
    print(head);
    DestroyList(head);
    return 0;
}
