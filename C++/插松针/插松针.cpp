#include<bits/stdc++.h>//C++�����е�Ԥ����ָ�<bit/stdc++.h>�ǷǱ�׼��ͷ�ļ���������C++��׼���һ���֣���GCC�������ṩ�İ��������г��õ�C++��׼ͷ�ļ�
#define ll long long//�궨��ָ�����ʶ��ll����Ϊlonglong����
#define pb push_back//�궨��ָ�����ʶ��pb����Ϊpush_back����C++��,push_back�Ǳ�׼������һ����Ա���������ڽ�Ԫ����ӵ�����ĩβ
using namespace std;//Ԥ����ָ����������׼�����ռ�std
const int Max=1e6+5;//����һ����Ϊmax�������������������ʼ��Ϊle6+5
const ll INF=1e10;//����һ����ΪINF�ĳ����ͳ������������ʼ��Ϊ1e10
stack<int>s;//����һ����Ϊs����������ջ�����������s.push()��Ԫ��ѹ�룬s.pop()��Ԫ�ص���
queue<int>q;//����һ����Ϊq�������Ͷ��У�ʹ�ú������ջһ��
int main()
{
    int n,m,k;
    cin>>n>>m>>k;//һ��������䣬���ڴӱ�׼�����ȡ��������������ֱ�洢�ڱ���n��m��k��
    //����������>>������ȡ����������ڽ���������ݰ���ָ���ĸ�ʽ�洢�ڱ����У�
    //������ִ�е�������ʱ������ȴ��û��ڼ�����������������ֵ�������ո���з��ָ�
    //ʹ��cin֮ǰ����Ҫ����ͷ�ļ�<iostream>
    for(int i=0;i<n;i++)
    {
        int t;cin>>t;
        q.push(t);//����ȡ��n������һ��ѹ�뵽ջ��
    }
    while(1)
    {
        vector<int>v;//������һ����Ϊv�������ͱ���
        while(!s.empty())//�ж�ջs�ǲ��ǿյ�
        {
            int num=s.top();//��ջ��Ԫ�ظ�ֵ��num
            if(v.size()==0)//���v�Ĵ�С�Ƿ�Ϊ0
                v.pb(num),s.pop();//��ջ��Ԫ��bum��ӵ�v��ĩβ����ջs�е���ջ��Ԫ��
            else
            {
                if(num<=v[v.size()-1]&&v.size()<k)//�ж�num�ǲ���С�ڵ�������v�����һ��Ԫ�أ��� v[v.size()-1]�����ж�v�Ĵ�С�Ƿ�ȸ�����ֵkС
                {
                    v.pb(num),s.pop();
                }
                else break;
            }
        }//���ͺ�������ȡ����
        if(v.size()==k)
        {
            for(int i=0;i<k;i++)
            {
                if(i==0)
                    cout<<v[i];//���Ԫ�أ�������v������Ϊi��Ԫ���������׼���������cin��һ�Ե�
                else
                    cout<<" "<<v[i];//ʹ�� cout ���һ���ո��ַ���һ���ո�ָ��� " "��Ȼ��������� v ������Ϊ i ��Ԫ�� v[i]��
            }
            cout<<endl;//���һ�����з�
        }
        else
        {
            while(!q.empty())
            {
                int num=q.front();//������q�Ķ�ͷԪ�ظ�ֵ��empty
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


/*�ö��з����������е�����������
ÿ�δӶ��еĽ�β����ʼ����
����һ��ջ��������֦��
����һ��ջ�������洢С����
*/