/**
 * @file index.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/**
 * \details outline
 * [1]->create class named data
 * [2]-> populate class with data 
 *      [2.1] create a function that just gets the data from array line by line and passes it to next function
 *      [2.2] create a function that handles a line of data and parse through it 
 *      [2.3] create an instacne of an object, assign data, push to array
 * [3] run algo with data 
 */


#include "include.h"
int main()
{    
    bool rerun = true;
    int DYNAMIC = 0;
    Data *data_array = new Data[DYNAMIC];
    read_line(data_array,DYNAMIC,rerun);
    while(rerun)
    {    
        get_algo(data_array,DYNAMIC);
        rerun = print(data_array,DYNAMIC);
        if(!rerun)write(data_array,DYNAMIC);
    }
    thank();
    delete[] data_array;
}

/**
 
 ****** TO DO *****

 * implement time
 * 
 * 
 */