//bank.cpp -- использование интерефейсов queue
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

class Customer
{
private:
    long arrive;                                    //момент появления клиента
    int processtime;                                //время обслуживания клиента
public:
    Customer() {arrive = processtime = 0;}
    void set(long when);
    long when() const {return arrive;}
    int ptime() const { return processtime;}
};

//Метод класса Customer
//При появлении клиента фиксируется момент его прибытия, а время
//обслуживания выбирается случайным образом из диапазона 1-3
void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}

const int MIN_PER_HR = 60;

bool newcustomer(double x);             //появился ли новый клиент?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    
    //подготовка
    
    std::srand(std::time(0));           //случайная инициализация rand()
    cout <<"Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    
    int qs;
    cin >> qs;
    
    std::queue<Customer> line;                     //очередь может содержать до qs клиентов
    cout << "Enter the number of simulation hours: ";           //ввод количество эмулируемых часов
    
    int hours;
    cin >> hours;
    
    // Эмуляция будет запускать один цикл в минуту
    long cyclelimit = MIN_PER_HR  * hours;                      //количество циклов
    cout << "Enter the average number of customers per hour: ";
    
    double perhour;                                             //среднее количество появлений за часж
    cin >> perhour;
    
    double min_per_cust;                                        //среднее время между появлениями
    
    min_per_cust = MIN_PER_HR / perhour;
    
    Customer temp;                                                  //данные нового клиента
    long turnaways = 0;                                         //не допущенны в полную очередь
    long customers = 0;                                         //присоединены к очереди
    long served = 0;                                            //обслуженные
    long sum_line = 0;                                          //общая длина очереди
    int wait_time = 0;                                          //время до совобождения банкомата
    long line_wait = 0;                                         //общее время в очереди
    
    //Запуск моделирования
    
    for(int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if(newcustomer(min_per_cust))                           //есть подошедший клиент
        {
            if(line.size() == qs)
            {
                turnaways++;
            }else{
                customers++;
                temp.set(cycle);                                    //cycle время прибытия
                line.push(temp);                                 //добавление новичка в очередь
            }
        }
        
        if(wait_time <= 0 && !line.empty())
        {
            line.pop();                                 // обслуживание следующего клиента
            wait_time = temp.ptime();                           //в течении wait_time минут
            line_wait += cycle - temp.when();
            served++;
        }
        
        if(wait_time > 0)
        {
            wait_time--;
        }
        sum_line += line.size();
    }
    
    //вывод результатов
    
    if(customers > 0)
    {
        cout << "Customers accepted: " << customers << endl;
        cout << "Customers served: " << served << endl;
        cout << "Turnaways: " << turnaways << endl;
        cout << "Average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << " avarage wait time: "
        << (double) line_wait / served << " minutes.\n";
    }else{
        cout << "No customers!\n";
    }
    cout << "Done!\n";
    return 0;
}

//Х = среднее время между клиентами
// возращение значения true, если в эту минуту появляется клиент
bool newcustomer(double x)
{
    return (std::rand() * x/ RAND_MAX < 1);
}
