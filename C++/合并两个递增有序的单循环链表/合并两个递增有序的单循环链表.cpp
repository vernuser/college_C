
#include<stdio.h>
#include<stdlib.h>

typedef int DataType;      
struct Node
{
    DataType data;
    struct Node * next;
};
typedef struct Node Node;  
typedef struct Node  *PNode;
typedef struct Node  *LinkList;

PNode createEmptyLinkedList()
{
    PNode current;
    current = (PNode)malloc(sizeof(Node));
    current->next = NULL;
    current->data = -1;
    return current;
}

PNode buildCircularLinkedList(int n, PNode tail)
{
    PNode current=NULL, prev;
    prev = tail; 
    for (int i = 0; i < n; i++)
    {
        current = (PNode)malloc(sizeof(Node));
        current->next = NULL;
        scanf("%d", &current->data);
        prev->next = current;
        prev = current;
    }
    current->next = tail->next;
    tail->next = current;
    return tail;
}

PNode mergeNDeduplicateList(PNode tail1, PNode tail2)
{
	PNode q = tail1->next->next;
	tail1->next->next = tail2->next->next;
	tail2->next->next = q;
	
	PNode current = tail2->next->next;
	PNode p = current->next;
	PNode bp = current;
	do
	{
		do
		{
			if(current->data == p->data)
			{
				bp->next = p->next;
				free(p);
				p = bp->next;
			}
			else
			{
				bp = bp->next;
				p = p->next;
			}

		}while(p!=tail2->next->next);
		current = current->next;
		p = current->next;
		bp = current;
	}while(current!=tail2->next);
	return tail2;
}

void printCircularLinkedList(PNode tail) 
{
    PNode current, last;
    last = tail->next;
    current = last->next;
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != last->next);
}

int main()
{
    PNode list1, list2;
    int list1_number, list2_number;
    list1 = createEmptyLinkedList();
    list2 = createEmptyLinkedList();
    scanf("%d", &list1_number);
    buildCircularLinkedList(list1_number, list1);
    scanf("%d", &list2_number);
    buildCircularLinkedList(list2_number, list2);
    list1 = mergeNDeduplicateList(list1, list2);
    printCircularLinkedList(list1);
    return 0;
}

