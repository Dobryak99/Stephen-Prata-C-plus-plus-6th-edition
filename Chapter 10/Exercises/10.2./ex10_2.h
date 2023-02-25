#ifndef EX10_2_H_
#define EX10_2_H_

#include <string>

class Person
{
    private:
        static const int LIMIT = 25;
        std::string lname;  //   фамилия
        char fname[LIMIT];  //  имя
    public:
        Person() {lname = ""; fname[0] = '\0';};   //   #1
        Person(const std::string & ln, const char * fn = "Heyyou");  //  #2
         ~Person();
         
        //  следующие методы отображают lname и fname
        void show() const;  //  формат: имя фамилия
        void Formalshow() const;    //  формат: фамилия имя
};
#endif
