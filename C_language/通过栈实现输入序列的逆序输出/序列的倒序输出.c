#include<stdio.h>
#include<stdlib.h>

typedef int Datatype;
struct Node{
    Datatype data;
    struct Node* next; // Ìí¼Ó·ÖºÅ
};
typedef struct Node* PNode;
typedef struct Node* Linkstack;

Linkstack SetNullStack_link() {
    Linkstack top = (Linkstack)malloc(sizeof(struct Node));
    if(top != NULL) 
        top->next = NULL;
    else 
        printf("Alloc failure");
    return top;
}

int IsNullStack_link(Linkstack top) {
    if(top->next == NULL)
        return 1;
    else 
        return 0;
}

void Push_link(Linkstack top, Datatype x) {
    PNode p;
    p = (PNode)malloc(sizeof(struct Node));
    if(p == NULL)
        printf("Alloc failure");
    else {
        p->data = x;
        p->next = top->next;
        top->next = p;
    }
}

void Pop_link(Linkstack top) {
    PNode p;
    if(top->next == NULL) {
        printf("it is empty stack");
    } else {
        p = top->next;
        top->next = p->next;
        free(p);
    }
}

Datatype Top_link(Linkstack top) {
    if(top->next == NULL) {
        printf("it is empty stack");
        return 0;
    } else {
        return top->next->data; 
    }
}

int main() {
    Linkstack stackA = SetNullStack_link();
    Datatype data;
    scanf("%d", &data);
    while(data != -1) {
        Push_link(stackA, data);
        scanf("%d", &data);
    }
    while(!IsNullStack_link(stackA)) {
        printf("%d", Top_link(stackA));
        Pop_link(stackA);
    }
    return 0;
}
