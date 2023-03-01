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
    int hours = 100;                    //по условию задачи использовать не менее 100 часовой период моделирования
    int counter = 0;                    //счетчик
    //-----------------------------------//
    //эмуляция будет запускать один цикл в минуту
    long cyclelimit = MIN_PER_HR * hours;           // количество циклов
    //-----------------------------------//
    double perhour = 100;                                 // возьмем 100 клиентов так как явно ожидание будет больше чем 1 мин

    double average_time = 0.0;                            // среднее время осблуживания в двух очередях
    //-----------------------------------//
    
    Item temp;          //данные нового клиента

    long turnawaysl1;     //не допущены в полную очередь L1
    long customersl1;     //присоединение к очереди L1
    long servedl1;        //обслужены во время эмуляции L1
    long sum_linel1;      //общая длина очереди L1
    int wait_timel1;      // время до освобождения банкомата L1
    long line_waitl1;     //общее время очереди L1


    long turnawaysl2;     //не допущены в полную очередь L2
    long customersl2;     //присоединение к очереди L2
    long servedl2;        //обслужены во время эмуляции L2
    long sum_linel2;      //общая длина очереди L2
    int wait_timel2;      // время до совобождения банкомата L2
    long line_waitl2;     //общее время очереди L2



    do
    {
        perhour--;								//с каждым циклом декрементируем для нахождения среднего время ожидания равной минуте(или меньше)
        Queue L1(hours * perhour / 2);        	//делаем общую очередь за весь промежуток времени чтобы ни кто не ушел и ДЕЛИМ ее на 2 банкомата 
        Queue L2(hours * perhour / 2);
        double min_per_cust;    //среднее время между появлениями
        min_per_cust = MIN_PER_HR / perhour;

        //без этого код не функционирует//
        //--------------------------------------------------------//
        turnawaysl1 = 0;     
        customersl1 = 0;     
        servedl1 = 0;        
        sum_linel1 = 0;      
        wait_timel1 = 0;      
        line_waitl1 = 0;

        turnawaysl2 = 0;     
        customersl2 = 0;     
        servedl2 = 0;        
        sum_linel2 = 0;      
        wait_timel2 = 0;      
        line_waitl2 = 0;
        //--------------------------------------------------------//

    //запуск моделирования

        for(int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if(newcustomer(min_per_cust))
            {
                if(L1.queuecount() <= L2.queuecount())
                {
                    if(L1.isfull())
                    {
                        turnawaysl1++;
                    }else{
                        customersl1++;
                        temp.set(cycle);          //cycle время прибытия
                        L1.enqueue(temp);         //добавление новичка в очередь
                    }
                }else{
                    if(L2.isfull())
                    {
                        turnawaysl2++;
                    }else{
                        customersl2++;
                        temp.set(cycle);          //cycle время прибытия
                        L2.enqueue(temp);         //добавление новичка в очередь
                    }
                }
            }


            if(wait_timel1 <= 0 && !L1.isempty())
            {
                L1.dequeue(temp);             //обслуживание следующего клиента
                wait_timel1 = temp.ptime();       // в течении wait_time минут
                line_waitl1 += cycle - temp.when();
                servedl1++;
            }
            if(wait_timel2 <= 0 && !L2.isempty())
            {
                L2.dequeue(temp);             //обслуживание следующего клиента
                wait_timel2 = temp.ptime();       // в течении wait_time минут
                line_waitl2 += cycle - temp.when();
                servedl2++;
            }


            if(wait_timel1 > 0)
            {
                wait_timel1--;
            }
            if(wait_timel2 > 0)
            {
                wait_timel2--;
            }

            average_time = (double)(line_waitl1 + line_waitl2) / (servedl1 + servedl2);
            sum_linel1 += L1.queuecount();
            sum_linel2 += L2.queuecount();
        }
        L1.~Queue();
        L2.~Queue();
    }while(average_time > 1.0);
    counter = perhour++;        //с учетом декремента в начале цикла do while


    if(customersl1 + customersl2 > 0)
    {
        cout << "Customers accepted: " << customersl1 + customersl2 << endl;
        cout << " Customers served: " << servedl1 + servedl2 << endl;
        cout << " turnaways: " <<turnawaysl1 + turnawaysl2 << endl;
        cout << "Average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)(sum_linel1 + sum_linel2)/ cyclelimit << endl;
        cout << "Average wait time: "
        << average_time << " minutes\n";
        cout << "Number of customers per hour that makes queue wait more than 1 minute: " << counter << endl;
    }else{
        cout << "No customers!\n";
    }
    cout << "Done!\n";
    return 0;
}


