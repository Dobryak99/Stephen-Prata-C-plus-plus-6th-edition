#include <iostream>
#include <cstdlib>               //для rand() и srand()
#include <ctime>                 //time()
#include "bank.h"
//#include "bank.cpp"

const int MIN_PER_HR = 60;

//x - среднее время в минутах между клиентами
// возвращает значение true если появился новый клиент
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    //подготовка
    std::srand(time(0));        //случайная генерация rand()
    cout << "Case Study: Bank of Heather Automatic Teller\n";
    
    //-----------------------------------//
    int hours = 100;
    int counter = 0;                    //счетчик
    //-----------------------------------//
    //эмуляция будет запускать один цикл в минуту
    long cyclelimit = MIN_PER_HR * hours;           // количество циклов
    //-----------------------------------//
    double perhour;         
    int i = 100;                                    // возьмем 100 так как явно ожидание будет больше чем 1 мин
    //-----------------------------------//
    
    Item temp;          //данные нового клиента
    long turnaways;     //не допущены в полную очередь
    long customers;     //присоединение к очереди
    long served;        //обслужены во время эмуляции
    long sum_line;      //общая длина очереди
    int wait_time;      // время до совобождения банкомата
    long line_wait;     //общее время очереди



    do
    {
        perhour = i--;
        Queue line(hours * perhour);        //делаем общую очередь за весь промежуток времени чтобы ни кто не ушел 
        double min_per_cust;    //среднее время между появлениями
        min_per_cust = MIN_PER_HR / perhour;

        //без этого код не функционирует//
        //--------------------------------------------------------//
        turnaways = 0;     //не допущены в полную очередь
        customers = 0;     //присоединение к очереди
        served = 0;        //обслужены во время эмуляции
        sum_line = 0;      //общая длина очереди
        wait_time = 0;      // время до совобождения банкомата
        line_wait = 0;
        //--------------------------------------------------------//

    //запуск моделирования

        for(int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if(newcustomer(min_per_cust))
            {
                if(line.isfull())
                {
                    turnaways++;
                }else{
                    customers++;
                    temp.set(cycle);            //cycle время прибытия
                    line.enqueue(temp);         //добавление новичка в очередь
                }
            }
            if(wait_time <= 0 && !line.isempty())
            {
                line.dequeue(temp);             //обслуживание следующего клиента
                wait_time = temp.ptime();       // в течении wait_time минут
                line_wait += cycle - temp.when();
                served++;
            }
            if(wait_time > 0)
            {
                wait_time--;
            }
            sum_line += line.queuecount();
        }
        line.~Queue();
    }while((double)line_wait / served > 1.0);
    counter = i++;        //с учетом декремента в начале цикла do while


    if(customers > 0)
    {
        cout << "Customers accepted: " << customers << endl;
        cout << " Customers served: " << served << endl;
        cout << " turnaways: " <<turnaways << endl;
        cout << "Average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << "Average wait time: "
        << (double)line_wait / served << " minutes\n";
        cout << "Number of customers per hour that makes queue wait more than 1 minute: " << counter << endl;
    }else{
        cout << "No customers!\n";
    }
    cout << "Done!\n";
    return 0;
}


