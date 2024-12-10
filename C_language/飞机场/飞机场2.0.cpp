#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 定义客户
struct Customer
{
    string name;        // 客户姓名
    string flight_num;   //航班号
    int grade;           //舱位等级
    int ticket_amount;  // 订票数量
    Customer* next;
};
typedef struct Customer customer;

// 定义航班信息
struct Flight
{
    string flight_number;       // 航班号
    string plane_number;        // 飞机号
    string day_of_week;         // 星期几飞
    int available_tickets;      // 余票量
    string destination;         // 目的地
    int people_quota;           //成员定额
    struct Flight* next;
};
typedef struct Flight Flight;

//初始化乘客信息
customer* get_passenger()
{
    fstream f;
    int i = 0;
    customer* c = new customer, * p = new customer, * q = c;
    f.open("passenger.txt", ios::in);
    while (f >> p->name >> p->flight_num >> p->ticket_amount >> p->grade)
    {
        q->next = p;
        p = new customer;
        q = q->next;
    }
    q->next = NULL;
    f.close();
    return c;
}

//初始化航班信息
Flight* Airline()
{
    fstream f;
    int i = 0;
    Flight* c = new Flight, * p = new Flight, * q = c;
    f.open("airline.txt", ios::in);
    while (f >> p->flight_number >> p->plane_number >> p->day_of_week >> p->available_tickets>>p->destination>>p->people_quota)
    {
        q->next = p;
        p = new Flight;
        q = q->next;
    }
    q->next = NULL;
    f.close();
    return c;
}

// 查询航班信息
void query_flight(Flight* Airline)
{
    cout << "请输入目的地：" << endl;
    string destination;
    cin >> destination;
    Flight* a = Airline;
    while(a!=NULL)
    {
        if(a->destination == destination) {
            cout << "航班号: " << a->flight_number << endl;
            cout << "飞机号: " << a->plane_number << endl;
            cout << "起飞日期: " << a->day_of_week << endl;
            cout << "目的地: " << a->destination << endl;
            cout << "余票额: " << a->available_tickets << endl;
            return;
        }
        a = a->next;
    }
    cout << "未找到目的地的航班。" << endl;
}

// 订票
void book_ticket(Flight* Airline, customer* waiting)
{
    cout << "请输入航班号：" << endl;
    string flight_number;
    cin >> flight_number;
    cout << "请输入票数：" << endl;
    int ticket_amount;
    cin >> ticket_amount;
    Flight* a = Airline;
    while (a != NULL)
    {
        if(a->flight_number == flight_number)
        {
            if(a->available_tickets >= ticket_amount)
            {
                cout << "该航班还有足够的机票。" << endl;
                for(int i =1;i <= ticket_amount;i++)
                {
                    cout << "座位号: " << a->available_tickets - ticket_amount + i << endl;
                }
                a->available_tickets -= ticket_amount;
                return;
            }
            else
            {
                cout << "该航班没有足够的机票，是否进行登记排队候补。" << endl;
                cout << "输入1为是，0为否。" << endl;
                int j;
                cin >> j;
                if (j == 1)
                {
                    customer *waite = new customer;
                    cout << "请输入您的姓名：" << endl;
                    cin >> waite->name;
                    waite->flight_num = flight_number;
                    waite->ticket_amount = ticket_amount;
                    cout << "请输入像订购的舱位等级：" << endl;
                    cin >> waite->grade;
                    customer* wpre = waiting;
                    while (wpre != NULL)
                    {
                        if(wpre->next==NULL)
                            wpre->next = waite;
                        wpre = wpre->next;
                    }
                }
                return;
            }
        }
        a = a->next;
    }
    cout << "未找到具有指定航班号的航班。" << endl;
}

// 退票
void cancel_ticket(Flight* Airline,customer* client, customer* waiting)
{
    cout << "请输入航班号：" << endl;
    string flight_number;
    cin >> flight_number;
    cout << "请输入客户姓名：" << endl;
    string name;
    cin >> name;
    Flight* a = Airline;
    while(a!=NULL)
    {
        if(a->flight_number == flight_number)
        {
            customer* cpre = client;
            customer* c = client->next;
            customer* wpre = waiting;
            customer* w = waiting->next;
            customer* u;                    //临时变量用于释放掉被删除节点的空间
            while (cpre != NULL && c != NULL)
            {
                if (c->name == name && c->flight_num == a->flight_number)
                {
                    cpre->next = c->next;
                    c->next = NULL;
                    a->available_tickets += c->ticket_amount;
                    u = c;
                    delete u;
                    cout << "退票成功。" << endl;
                    break;
                }
                cpre = cpre->next;
                c = c->next;
            }
            while (c != NULL)
                c = c->next;
            while(wpre!=NULL && w!=NULL)
            {
                if (w->ticket_amount < a->available_tickets && w->flight_num == a->flight_number)
                {
                    wpre->next = w->next;
                    w->next = NULL;
                    c->next = w;
                    w = wpre->next;
                    return;
                }
                wpre = wpre->next;
                w = w->next;
            }
            cout << "未找到该客户。" << endl;
        }
        cout << "未找到具有指定航班号的航班。" << endl;
    }
}

int main()
{
    customer* client = get_passenger();
    Flight* airline = Airline();
    customer* waiting_list = new customer;
    cout << "=================================欢迎使用航空订票系统===============================" << endl;
    cout << "*                                     1-查询航班                                   *" << endl;
    cout << "*                                     2-订    票                                   *" << endl;
    cout << "*                                     3-退    票                                   *" << endl;
    cout << "*                                     4-退    出                                   *" << endl;
    cout << "====================================================================================" <<"\n"<< endl;
    while (true)
    {
        cout << "请选择操作（1-查询航班 2-订票 3-退票 4-退出）：" << endl;
        int choice;
        cin >> choice;
        if(choice == 1)
            query_flight(airline);
        else if(choice == 2)
            book_ticket(airline,waiting_list);
        else if(choice == 3)
            cancel_ticket(airline,client,waiting_list);
        else if(choice == 4)
            return 0;
        else
            cout << "无效的选择，请重新输入。" << endl;
    }
    return 0;
}
