#include <stdio.h>
#include <stdlib.h>
#include <string.h> // ����ͷ�ļ�

#define max 65535
int n;
int a[11000][11000];//�洢����Ϣ
int visit[11000];//��Ƿ���
int best[11000];//���·��

int start(int st)//��ʼ��
{
    memset(visit, 0, sizeof(int) * 11000);
    memset(best, 0, sizeof(int) * 11000);
    for (int i = 1; i <= n; i++)
        best[i] = a[st][i];
}

void dijkstr(int st)
{
    start(st);//��ʼ��
    visit[st] = 1;//��Ƿ���
    int mid = st;//�洢��ǰ��
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) // �޸�ѭ������������
        {
            if (visit[j] == 0 && best[j] != max)//û�����ʹ� ͬʱ��best���м�¼������õ������ĵ㱻���ʹ���
            {
                mid = j;//�ҵ����������ĵ㣬���ĵ���Ϊ��ǰ��
                visit[mid] = 1;
                break;
            }
        }
        for (int j = 1; j <= n; j++)//������չ
            if (a[mid][j] + best[mid] < best[j])//ֻ����������ʹ��ĵ������ĵ�Ż������Ѿ���
                best[j] = best[mid] + a[mid][j];
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    int maxmin = max;//�ҵ�ÿ��ҽԺ��������ֵ�м����Сֵ
    int maxminpoint = 1;//maxmin��Ӧ�ĵ㣬��ABCDEF ���Ƶ�
    for (int i = 1; i <= n; i++)//˼·���ҵ�ÿ��ҽԺ��������ֵ�м����Сֵ
    {
        dijkstr(i);
        int maxx = -1;
        for (int j = 1; j <= n; j++)
            if (best[j] > maxx)
                maxx = best[j];
        if (maxx < maxmin)
        {
            maxmin = maxx;
            maxminpoint = i;
        }
    }
    printf("%c", maxminpoint - 1 + 'a');
}
