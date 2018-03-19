//#include <QCoreApplication>
//создать базовый класс , который описывает человека есть возраст, пол, нужна программа, которая создает опр кол-во людей случайным образом
//std::vector <std::tuple <class, double>>
/*
*Создать базовый класс Человека(Возраст, Пол)
Программа создает рандомное кол-во людей и определяет, кому нужно жить, а кому — нет

*создать вектор мужчин/женщин, т.е. сделать поселение

*Посчитать средний возраст поселения
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define COUNT_OF_GENERATION 50

class Human{
public:
    virtual ~Human() = default;
    virtual int getGender() = 0;
    virtual int getAge() = 0;
};

class Man : public Human {
    int m_age;
public:
    Man()
        :m_age(0)
        {}
    Man(int age)
        :m_age(age)
        {}
    
    int getAge() override
    {
        return m_age;
    }
    
    int getGender() override
    {
        return 1;
    }
    
};

class Woman : public Human {
    int m_age;
public:
    Woman()
        :m_age(0)
        {}
    Woman(int age)
        :m_age(age)
        {}
     
    int getAge() override
    {
        return m_age;
    }
    
    int getGender() override
    {
        return 0;
    }
};

int main() {

    //It need to be difined where it is needed
    int woman_count = 0, man_count = 0;
    //Use a vector of a pointers - it is good thing))
    std::vector <Human *> humanvector;
    srand(time(0));

    for (int i = 0; i < COUNT_OF_GENERATION; ++i) {
        int WhoBorn = rand();

        if(WhoBorn % 2 ) {
            //Man Humanvector[i]; - What does it mean???
            //Humanvector[i].Generation(); - not bad
            man_count++;
            humanvector.push_back(new Man(1 + rand() % 80));            
        }
        else{
            //The same we do for Women
        }
    }//There are we are filling our vector
    //Define 
    float average = 0.0;
    float average_man = 0.0;
    float average_woman = 0.0;
    for(auto human : humanvector){
        float tmp_average += human->getAge();
        if(human->getGender()){
            average_man += tmp_average;
        }else{
            //
        }
        average += tmp_average;
    }
    average /= COUNT_OF_GENERATION; 
    average_man /= man_count;
    average_woman /= woman_count;
    std::cout<< "Средняя продолжительность жизни = " << average << std::endl;
    std::cout<< "Средняя продолжительность жизни мужчины= " << average_man << std::endl;
    std::cout<< "Средняя продолжительность жизни женщины= " << average_woman << std::endl;
    std::cout << "Мужчины =" << man_count << std::endl;
    std::cout << "Женщины =" << woman_count << std::endl;
    std::cout << "Конец " << std::endl;
    return 0;
}

