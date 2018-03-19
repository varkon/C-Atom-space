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

class Human{
public:
    int age = 0, count = 0;
    void Generation () {
    age = 1 + rand() % 80;
    }
};

class Man : public Human {
public:
};

class Woman : public Human {
public:
};

//A *a = new B();
//a -> f();
int main() {

    int i, ALL_man= 0, ALL_woman= 0, WhoBorn = 0, woman_count = 0, man_count = 0;
    int average = 0, average_man = 0, average_woman;

    std::vector <Human> Humanvector(100);
    srand(time(0));

    for (i = 0; i < 100; i++) {

        WhoBorn = 1 + rand() % 2;

        if(WhoBorn == 1 ) {
            Man Humanvector[i];
            Humanvector[i].Generation();
            ALL_man += Humanvector[i].age;
            man_count++;
            std::cout << i << "Man" << std::endl;
        }
        if (WhoBorn == 2 ){
            Woman Humanvector[i];
            Humanvector[i].Generation();
            ALL_woman += Humanvector[i].age;
            woman_count++;
            std::cout << i << "Woman" << std::endl;
        }
    }
    average = (ALL_woman + ALL_man) / 100;
    average_man = ALL_man / man_count;
    average_woman = ALL_woman / woman_count;
    std::cout<< "Средняя продолжительность жизни = " << average << std::endl;
    std::cout<< "Средняя продолжительность жизни мужчины= " << average_man << std::endl;
    std::cout<< "Средняя продолжительность жизни женщины= " << average_woman << std::endl;
    std::cout << "Мужчины =" << man_count << std::endl;
    std::cout << "Женщины =" << woman_count << std::endl;
    std::cout << "Конец " << std::endl;
    return 0;
}

