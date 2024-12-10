#include<bits/stdc++.h>
using namespace std;

class Nodemember{
public:
    int data;
    Nodemember* next;
    Nodemember(int b)
    {
        this->data = b;
        this->next = NULL;
    }
};//������һ����Nodemember��Ϊͼ�Ľ��
class Nodehead{
public:
    char b;
    Nodemember* nextone;
    Nodehead(){
        nextone = NULL;
    }
};//������ͼ��ͷ���
class mychart{
public:
    int visit[100];    // ��������
    Nodehead* a[100];  // ͷ�ڵ�����

    mychart()
    {
        memset(visit, 0, sizeof(visit));//memset����visit�������������ó�0
        for(int i=0; i<100; i++)
        {
            a[i] = new Nodehead();//new��̬����һ���µ�Nodehead
        }
    }//����һ���ڽӱ���ʼ��
    bool contains(mychart* s1, int v, int b){  //�ڽӱ�Ĺ�����ȱ�����
        Nodemember* t;//�ڽӱ�
        int w;//�洢�ڽӽ���ֵ
        queue<int> qu;
        qu.push(v);//��ʼ�ڵ�

        if(v == b) return true;
        visit[v] = 1;//���v==Ŀ��ڵ�b,�����棬v���ó��Ѿ����ʹ���

        while(!qu.empty()){
            v = qu.front();//ȡ��ͷ���
            qu.pop();//ͷ����ջ

            t = s1->a[v]->nextone;//��ȡ���v���ڽӽ���ͷ���
            while(t != NULL){
                w = t->data;//��ȡ��ǰ�ڽӽ���ֵ
                if(visit[w] == 0){
                    if(w == b) return true;
                    visit[w] = 1;
                    qu.push(w);
                }
                t = t->next;
            }
        }

        return false;
    }
};

int main(){
    string s;
    mychart* s1 = new mychart();
    int c, d;
    Nodemember* t = NULL;

    while(getline(cin, s)){//�ӱ�׼�������ж�ȡ�û���������ݣ�������洢���ַ������� s �У�getline �������ȡ�������룬ֱ���������з�Ϊֹ
        if(s == "0 0") break;
        c = s[0] - '0';
        d = s[2] - '0';//ת��������

        // ֱ��ͷ�巨
        t = new Nodemember(d);
        t->next = s1->a[c]->nextone;
        s1->a[c]->nextone = t;
    }

    getline(cin, s);
    c = s[0] - '0';
    d = s[2] - '0';

    bool x = s1->contains(s1, c, d);//c����ʼ�ڵ㣬d��Ŀ��ڵ�
    cout << (x == true ? 1 : 0) << endl;

    return 0;
}
