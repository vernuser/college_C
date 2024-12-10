#include<bits/stdc++.h>//C++语言中的预处理指令，<bit/stdc++.h>是非标准的头文件，并不是C++标准库的一部分，是GCC编译器提供的包含了所有常用的C++标准头文件
#define ll long long//宏定义指令，给标识符ll定义为longlong类型
#define pb push_back//宏定义指令，给标识符pb定义为push_back，在C++中,push_back是标准容器的一个成员函数，用于将元素添加到容器末尾
using namespace std;//预处理指令，用于引入标准命名空间std
const int Max=1e6+5;//定义一个名为max的整数常量，并将其初始化为le6+5
const ll INF=1e10;//定义一个名为INF的长整型常量，并将其初始化为1e10
stack<int>s;//定义一个名为s的整数类型栈，后面可以用s.push()将元素压入，s.pop()将元素弹出
queue<int>q;//定义一个名为q的整数型队列，使用和上面的栈一样
int main()
{
    int n,m,k;
    cin>>n>>m>>k;//一个输入语句，用于从标准输入读取三个整数并将其分别存储在变量n，m，k中
    //在这个语句中>>是流提取运算符，用于将输入的数据按照指定的格式存储在变量中，
    //当程序执行到这个语句时，它会等待用户在键盘上输入三个整数值，并按空格或换行符分隔
    //使用cin之前，需要包含头文件<iostream>
    for(int i=0;i<n;i++)
    {
        int t;cin>>t;
        q.push(t);//将读取的n个整数一次压入到栈中
    }
    while(1)
    {
        vector<int>v;//定义了一个名为v的整数型变量
        while(!s.empty())//判断栈s是不是空的
        {
            int num=s.top();//将栈顶元素赋值给num
            if(v.size()==0)//检查v的大小是否为0
                v.pb(num),s.pop();//将栈顶元素bum添加到v的末尾，从栈s中弹出栈顶元素
            else
            {
                if(num<=v[v.size()-1]&&v.size()<k)//判断num是不是小于等于向量v的最后一个元素（即 v[v.size()-1]），判断v的大小是否比给定的值k小
                {
                    v.pb(num),s.pop();
                }
                else break;
            }
        }//先送盒子里面取松针
        if(v.size()==k)
        {
            for(int i=0;i<k;i++)
            {
                if(i==0)
                    cout<<v[i];//输出元素，将向量v中索引为i的元素输出到标准输出流，和cin是一对的
                else
                    cout<<" "<<v[i];//使用 cout 输出一个空格字符和一个空格分隔符 " "，然后输出向量 v 中索引为 i 的元素 v[i]。
            }
            cout<<endl;//输出一个换行符
        }
        else
        {
            while(!q.empty())
            {
                int num=q.front();//将队列q的队头元素赋值给empty
                if(v.size()==0)
                    v.pb(num),q.pop();
                else
                {
                    if(v.size()==k)
                        break;
                    if(num<=v[v.size()-1])
                    {
                        v.pb(num),q.pop();
                    }
                    else
                    {
                        if(s.size()<m)
                        {
                            s.push(num);
                            q.pop();
                        }
                        else break;
                    }
                }
            }
             if(v.size()==0)
                 break;
             for(int i=0;i<v.size();i++)
                {
                    if(i==0)
                     cout<<v[i];
                    else
                    cout<<" "<<v[i];
                }
            cout <<endl;
        }
    }
}


/*用队列放输入样例中的推送器松针
每次从队列的结尾处开始弹出
建立一个栈用来当松枝干
建立一个栈用来当存储小盒子
*/