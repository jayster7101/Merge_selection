#ifndef DATA_CLASS_H
#define DATA_CLASS_H
#include "include.h"
class Data // data class
{
    public: // all public members are returing the date besides the constructor and print
    Data();
    Data(std::string,int,double,double,int,int,double); // constructor
    std::string get_country(); //
    int get_epiRank(); //
    double get_epi2020(); // 
    double get_TYchange(); // 
    int get_us21R(); //
    int get_int20R(); //
    double get_pop(); //
    void print(); // print function
    private:
    std::string country; // country 
    int epiRank; //epi rank
    double epi2020; // epi 2020
    double TYchange; // ten year change
    int us21R; // us rank 2021
    int int20R; // international rank 2020
    double pop; // population
};
#endif