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
};//定义了一个类Nodemember作为图的结点
class Nodehead{
public:
    char b;
    Nodemember* nextone;
    Nodehead(){
        nextone = NULL;
    }
};//定义了图的头结点
class mychart{
public:
    int visit[100];    // 访问数组
    Nodehead* a[100];  // 头节点数组

    mychart()
    {
        memset(visit, 0, sizeof(visit));//memset，将visit的所有数组设置成0
        for(int i=0; i<100; i++)
        {
            a[i] = new Nodehead();//new动态创建一个新的Nodehead
        }
    }//建立一个邻接表并初始化
    bool contains(mychart* s1, int v, int b){  //邻接表的广度优先遍历。
        Nodemember* t;//邻接表
        int w;//存储邻接结点的值
        queue<int> qu;
        qu.push(v);//起始节点

        if(v == b) return true;
        visit[v] = 1;//如果v==目标节点b,返回真，v设置成已经访问过了

        while(!qu.empty()){
            v = qu.front();//取出头结点
            qu.pop();//头结点出栈

            t = s1->a[v]->nextone;//获取结点v的邻接结点的头结点
            while(t != NULL){
                w = t->data;//获取当前邻接结点的值
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

    while(getline(cin, s)){//从标准输入流中读取用户输入的内容，并将其存储在字符串变量 s 中，getline 函数会读取整行输入，直到遇到换行符为止
        if(s == "0 0") break;
        c = s[0] - '0';
        d = s[2] - '0';//转换成整数

        // 直接头插法
        t = new Nodemember(d);
        t->next = s1->a[c]->nextone;
        s1->a[c]->nextone = t;
    }

    getline(cin, s);
    c = s[0] - '0';
    d = s[2] - '0';

    bool x = s1->contains(s1, c, d);//c是起始节点，d是目标节点
    cout << (x == true ? 1 : 0) << endl;

    return 0;
}
