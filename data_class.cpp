#include "include.h"

Data::Data()
{}
/**
 * @brief Construct a new Data:: Data object
 * 
 * @param _country 
 * @param _epiRank 
 * @param _epi2020 
 * @param _TYchange 
 * @param _us21R 
 * @param _int20R 
 * @param _pop 
 */
Data::Data (std::string _country,int _epiRank,double _epi2020,double _TYchange,int _us21R,int _int20R,double _pop)
{
    country = _country;
    epiRank = _epiRank;
    epi2020 = _epi2020;
    TYchange = _TYchange;
    us21R = _us21R;
    int20R = _int20R;
    pop = _pop;
}
/**
 * @brief gets country from data class
 * 
 * @return std::string 
 */
std::string Data::get_country()
{
    return country;
}
/**
 * @brief gets epiRank from data class
 * 
 * @return int 
 */
int Data::get_epiRank()
{
    return epiRank;
}
/**
 * @brief gets epi2020 from data class
 * 
 * @return double 
 */
double Data::get_epi2020()
{
    return epi2020;
}
/**
 * @brief gets TYchange from data class
 * 
 * @return double 
 */
double Data::get_TYchange()
{
    return TYchange;
}
/**
 * @brief gets us21R from data class
 * 
 * @return int 
 */
int Data::get_us21R()
{
    return us21R;
}
/**
 * @brief gets int20R from data class
 * 
 * @return int 
 */
int Data::get_int20R()
{
    return int20R;
}
/**
 * @brief gets pop from data class
 * 
 * @return int 
 */
double Data::get_pop()
{
    return pop;
}

/**
 * @brief prints out the data, formated  
 * @returns none
 */
void Data::print()
{
    //std::cout << "Saint_Vincent_and_the_Grenadines";
    //Saint_Vincent_and_the_Grenadines  64 49.4000 6.1000 NULL NULL 111.5510
   // std::cout << "\n|-[Country]-----------------------|-[epiRank]-|[Rank2020]|[10YrChange]------------------------------------------\n";

std::cout << "\n---------------------------------------------------------------------------------------------------------------\n";
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "| "; std::cout <<  std::left << std::setw(32) << country << "| ";
      if(epiRank != 0) { std::cout <<  std::left << std::setw(10) << epiRank << "| ";} else std::cout << std::left << std::setw(10) << "NULL" << "| "; 
      if(epi2020 != 0) { std::cout << std::left << std::setw(9)<< epi2020 << "| ";} else std::cout << std::left << std::setw(9) << "NULL" << "| ";
      if(TYchange != 0) {  std::cout << std::left << std::setw(11) << TYchange << "| ";} else std::cout << std::left << std::setw(11) << "NULL" << "| ";
      if(us21R != 0) { std::cout << std::left << std::setw(10)<< us21R << "| ";} else std::cout << std::left << std::setw(10)<< "NULL" << "| ";
      if(int20R != 0) { std::cout << std::left << std::setw(12)<< int20R << "| ";} else std::cout << std::left << std::setw(12) << "NULL" << "| ";
      if(pop != 0) {  std::cout << std::right << std::setw(12)<< pop << "| ";} else std::cout << "NULL *";
    //std::cout << "\n----------------------------------------------------------------------\n";
}
