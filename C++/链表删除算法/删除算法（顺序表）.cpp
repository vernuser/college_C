#include<stdio.h>
#include<stdlib.h>

typedef int Datatype;
struct List{
	int Max;
	int n;
	Datatype *elem;
};
typedef struct List *SeqList;

SeqList SetNullList_Seq(int m){
	SeqList slist = (SeqList)malloc(sizeof(struct List));
	//����ṹ��ռ�
	if(slist!=NULL){
		slist->elem = (Datatype*)malloc(sizeof(Datatype)*m);
		//����˳��ռ䣬��СΪm��Datatype�ռ�
		if(slist->elem){
			slist->Max = m;
			slist->n = 0;
			return(slist);
		}
		else free(slist);
	}
	printf("Alloc failure!\n");
	return NULL;
}

int IsNullList_seq(SeqList slist){//�ж��Ƿ�Ϊ��˳��� 
	return(slist->n==0);
}

int InsertPre_seq(SeqList slist,int p,Datatype x){//������� 
	int q;
	if(slist->n>=slist->Max){//�Ƿ񳬹�˳�����󳤶� 
		printf("overflow");
		return 0;
	}
	if(p<0||p>slist->n){//�������±�Ϊp��Ԫ�� 
		printf("not exit!\n");
		return 0;
	}
	for(q=slist->n-1;q>=p;q--)
		slist->elem[q+1]=slist->elem[q];//�����Ԫ�غ��� 
	slist->elem[p]=x;
	slist->n=slist->n+1;//˳���������1 
		return 0;
}

int print(SeqList slist){//���˳��� 
	int k;
	for(k=0;k<slist->n;k++){
		printf("%d ",slist->elem[k]);
	}
	printf("\n");
}

int DelList(SeqList slist,int p){//ɾ������ 
	int q;
	if(p<0||p>slist->n){//�������±�Ϊp��Ԫ�� 
		printf("not exit\n");
		return 0;
	}
	for(q=p;q<slist->n-1;q++){
		slist->elem[q]=slist->elem[q+1];//Ԫ��ǰ�� 
	}
	slist->n=slist->n-1;//����1 
	return 1;
} 

/*
int DelV_seq(SeqList slist,int x){
	int i;
	for(i=0;i<slist->n;i++){
		if(i==1) break;
		if(slist->elem[i]==x){
			slist->elem[i]=slist->elem[i+1];
			slist->n=slist->n-1;
		}
	}
} 
*/
int main(){
	SeqList alist;
	int max,len,i,x;
	printf("\n please input the max value(<100) of max");
	scanf("%d",&max);
	alist = SetNullList_Seq(max);
	printf("%d\n",IsNullList_seq(alist));
	if(alist!=NULL){
		printf("\n please input the length of the list len= ");
		scanf("%d",&len);
	}
	printf("\n please input the x\n");
	for(i=0;i<len;i++){
		scanf("%d",&x);
		InsertPre_seq(alist,i,x);
	}
	
	print(alist);
	
	InsertPre_seq(alist,2,99);
	print(alist);
	
	DelList(alist,2);
	print(alist);
	//DelV_seq(alist,5);
	//print(alist);
}
