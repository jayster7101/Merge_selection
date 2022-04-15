#include "include.h"

/**
 * @brief greets the user and then asks if they want to run file
 * if no then it returns back and ends program 
 * if yes it grabs the file that the user wants to be filtered through 
 * grabs each line and then passses it to parse line()
 * 
 * @param pass_through 
 * @param notNeeded -> is not needed in this function
 * @param go 
 */
void read_line(Data* pass_through, int &notNeeded, bool &go)
{   
    bool start = greet();
    if(!start) 
    {
        go = false;
        return; // return if user doesn't want to use program
    }

    std::string file = get_file(); // gets file
    if(file == "nofile")
    {
        go = false;
        return; // returns if the user cant find a file
    }
    std::ifstream in;
    in.open(file);
    std::string disgard;
    getline(in,disgard); // gets line from "in" and assigns to discard to discard first line
    
    std::string line;
    int count;
    while(getline(in,line)) // parses line as long as their is a line to read
    {
        count ++;
       // std::cout << "line: " << count << "\n";
        parse_line(line,pass_through,notNeeded);
    }


    
}
/**
 * @brief calls for line to be formatted and then opens a string stream to parse and assign each variable its data
 * then creates an object with data and adds it to the next aviliable index of array 
 * calls resize to add an index for next iteration
 * @param _line 
 * @param arr 
 * @param count 
 */
void parse_line(std::string _line,Data* arr, int &count)
{
    std::string correct = format_line(_line); // formats the line for easier parseing
    std::stringstream ss (correct); // creates string stream
    //********DATA********

    std::string quote;
    std::string comma;
    std::string country; // country 
    int epiRank; //epi rank
    double epi2020; // epi 2020
    double TYchange; // ten year change
    int us21R; // us rank 2021
    int int20R; // international rank 2020
    double pop; // population
    ss  >> country  >> epiRank  >> epi2020  >> TYchange  >> us21R  >> int20R  >> pop ; // assigns data to correct variables 
    Data temp_obj(country,epiRank,epi2020,TYchange,us21R,int20R,pop);
    //std::cout << "count " << count; temp_obj.print();
    arr[count] = temp_obj; // assign data to index
    resize_array(arr,count);
}
/**
 * @brief formats line, works with csv files
 * 
 * @param _line 
 * @return std::string formatted
 */
std::string format_line (std::string _line) 
{
    
    std::string formated; // creates var to store formatted line
    for(int i = 0; i < _line.length(); i++)
    {
        if(i == _line.length()-1) // if i length of _line -1 thats passed in, then return because its formatted now
        {
            return formated;
        } 
        else 
        {   
            if(_line[i] ==  '\"' ) // finds first quote
            {   
                 if(_line[i+1] == '\"' ) formated = formated + "0"; // finds second quote in succession, signifies that "" was found -> now = 0
            } 
            else
            {  
            if(_line[i] == ' ') formated = formated + "_"; // if a spaces between words is found ->  make it a _ example united states is now united_states
            else if (_line[i] == ',') //  if line is , then add a space to formatted line -> means its the end of that data 
            {
            formated = formated + " ";
            }
            else formated = formated + _line[i];// else just add the normal letter to formatted
            }
            
        }   
    }
    return formated;
}
    
/**
 * @brief resizes array 
 * creates a new dynamic array with proper array length 
 * increses array length count 
 * assigns back to initial array (arr)
 * deletes temp
 * @param arr 
 * @param count 
 */
void resize_array(Data* arr,int &count) 
{  
    count ++; // add 
    Data* temp = new Data[count]; // create 
    for(int i = 0; i < count; i++)
    {
        temp[i] = arr[i]; // assign 
    }
    arr = temp; // swap

    delete[] temp; // delete
}
/**
 * @brief merge sort algo
 * returns when from parameter is equal to to parameter
 * 
 * @param data 
 * @param from 
 * @param to 
 * @param where 
 */
void merge_sort(Data* data, int from, int to, int where)
{
    if(from == to) { return;} //returns when from parameter is equal to to parameter
    int mid = (from + to) / 2;
    merge_sort(data, from, mid, where);
    merge_sort(data, mid + 1, to, where);
    merge(data, from, mid, to, where); // merges  
}
/**
 * @brief gets full array 
 * filters through and pushes smaller value to dynamic array b
 * and increases count of each smaller "array" 
 * -> is just looking at certain sections of array  but act similar to multiple array
 * 
 * @param a 
 * @param from 
 * @param mid 
 * @param to 
 * @param where 
 */
void merge(Data* a, int from, int mid, int to, int where)
{

    //***** b=temp    a = a ****
    int n = to - from + 1;
    Data* b = new Data[n];

    int i1 = from;

    int i2 = mid + 1 ;

    int j = 0;
    while( i1 <= mid && i2 <= to)
    {
        switch (where)
        {
        case 1:
        if(a[i1].get_country() < a[i2].get_country())
        {
            b[j] = a[i1];
            i1++;
        }
        else 
        {
            b[j] = a[i2];
            i2++;
        }
            break;
        case 2:
        if(a[i1].get_epiRank() < a[i2].get_epiRank())
        {
            b[j] = a[i1];
            i1++;
        }
        else 
        {
            b[j] = a[i2];
            i2++;
        }
            break;
        case 3:
        if(a[i1].get_epi2020() < a[i2].get_epi2020())
        {
            b[j] = a[i1];
            i1++;
        }
        else 
        {
            b[j] = a[i2];
            i2++;
        }
            break;
        case 4:
        if(a[i1].get_TYchange() < a[i2].get_TYchange())
        {
            b[j] = a[i1];
            i1++;
        }
        else 
        {
            b[j] = a[i2];
            i2++;
        }
            break;
        case 5:
        if(a[i1].get_us21R() < a[i2].get_us21R())
        {
            b[j] = a[i1];
            i1++;
        }
        else 
        {
            b[j] = a[i2];
            i2++;
        }
            break;
        case 6:
        if(a[i1].get_int20R() < a[i2].get_int20R())
        {
            b[j] = a[i1];
            i1++;
        }
        else 
        {
            b[j] = a[i2];
            i2++;
        }
            break;
        case 7:
        if(a[i1].get_pop() < a[i2].get_pop())
        {
            b[j] = a[i1];
            i1++;
        }
        else 
        {
            b[j] = a[i2];
            i2++;
        }
            break;
                               
        default:
            break;
        }
        j++;
    }
    while(i1 <= mid)
    {
        b[j] = a[i1];
        i1++;
        j++;
    }
    while(i2 <= to)
    {
        b[j] = a[i2];
        i2++;
        j++;
    }
    for(int q = 0; q < n; q++)
    {
        a[from+q] = b[q];
    }
    delete[] b;
}
/**
 * @brief displays the possible options for the user to filter through 
 * takes the input and then calls merge_sort with value
 * 
 * @param data 
 * @param from 
 * @param to 
 */
void merge_sort_helper(Data* data, int from, int to)
{
    // gets users decision 
    int decision;
    std::cout << "Which of the values below would you like to sort through?\n";
    std::cout << "[1] Country name alphabetically\n";
    std::cout << "[2] Epi Ranking (Global)\n";
    std::cout << "[3] Epi from 2020 (Global)\n";
    std::cout << "[4] 10 year Epi change (Global)\n";
    std::cout << "[5] US 2021 Ranking\n";
    std::cout << "[6] International 2020 Ranking\n";
    std::cout << "[7] Country by Population\n-> ";
    std::cin >> decision;
    while( std::cin.fail() || (decision <= 0) || (decision > 7) )
    {
        std::cin.clear();
        if(std::cin.fail())
        {
            std::cout << "sorry you didn't enter a number please try again\n-> ";
        }
        else std::cout << "Please enter a number from [0-7] only\n-> ";
        std::cin.ignore(100,'\n');
        std::cin >> decision;
    }
        std::ofstream log; // creates ofstream to save the time it took to run merge sort
        log.open("merge.txt", std::fstream::app); // opens file and uses the append method so it doesnt over write
        // using highresolution clock to take two times and calculate the difference 
        using namespace std::chrono;
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        merge_sort(data,from,to,decision);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double> >(t2 - t1);
        reorder(data,to+1,decision);
        std::cout << "\n\nIt took " << time_span.count() << " seconds. For merge_sort to finish\n\n";

        log << time_span.count() << " merge\n";
}
/**
 * @brief reorders array to handle null values 
 * creates two temp arrays to handle null values and proper working values
 * passes those and the length of each to reorder_switch function
 * @param data 
 * @param length 
 * @param path 
 */
void reorder(Data* data, int length, int path)
{
    int nu_value = 0; // length of array holding null value 
    int temp_v = 0; // length of array holding good values
    Data* temp = new Data[length]; // array or good values
    Data* nu = new Data[length]; // array for null values
    for(int i = 0; i < length; i++) // loops through whole array
    {
        reorder_switch(data,temp,nu,i,temp_v,nu_value,path); // see function definition for more detail
    }
    //****** pushes each null value into the back of the temp array and then puts the order of those values back into the original array *******
    int copy = 0;
    for(int i = temp_v; i < length; i++)
    {
        temp[i] = nu[copy];
        copy++;
    }
    for(int i = 0; i < length; i++)
    {
        data[i] = temp[i];
    }
delete[] nu;
delete[] temp;
}




/**
 * @brief find the index of the array for the null value and then increment the value when found  
 * gets passed back to reorder for full reordering
 * @param data 
 * @param temp 
 * @param nu 
 * @param i 
 * @param temp_v 
 * @param nu_value 
 * @param path 
 */
  void reorder_switch(Data* data, Data* temp, Data* nu, int i, int&temp_v, int& nu_value, int path)
{
    switch (path)
    {
    case 1:
        if (data[i].get_country() == "null")
        {
            nu[nu_value] = data[i];
            nu_value++;
        }
        else 
        {
            temp[temp_v] = data[i];
            temp_v++;
        }
        break;
    case 2:
        if (data[i].get_epiRank() == 0)
        {
            nu[nu_value] = data[i];
            nu_value++;
        }
        else 
        {
            temp[temp_v] = data[i];
            temp_v++;
        }
        break;
    case 3:
        if (data[i].get_epi2020() == 0)
        {
            nu[nu_value] = data[i];
            nu_value++;
        }
        else 
        {
            temp[temp_v] = data[i];
            temp_v++;
        }
        break;
    case 4:
        if (data[i].get_TYchange() == 0)
        {
            nu[nu_value] = data[i];
            nu_value++;
        }
        else 
        {
            temp[temp_v] = data[i];
            temp_v++;
        }
        break;
    case 5:
        if (data[i].get_us21R() == 0)
        {
            nu[nu_value] = data[i];
            nu_value++;
        }
        else 
        {
            temp[temp_v] = data[i];
            temp_v++;
        }
        break;
    case 6:
        if (data[i].get_int20R() == 0)
        {
            nu[nu_value] = data[i];
            nu_value++;
        }
        else 
        {
            temp[temp_v] = data[i];
            temp_v++;
        }
        break;
    case 7:
        if (data[i].get_pop() == 0)
        {
            nu[nu_value] = data[i];
            nu_value++;
        }
        else 
        {
            temp[temp_v] = data[i];
            temp_v++;
        }
        break;
    default:
        break;
    }
}
/**
 * @brief finds the minimum position based on what the user is looking for 
 * this is why a switch statement is used to handle all possible data 
 * 
 * @param data 
 * @param from 
 * @param to 
 * @param path 
 * @return * int 
 */
int  min_position(Data* data, int from, int to, int path)
{
    int min_pos = from;
    for(int i = from + 1; i <= to; i++)
    {
        switch (path)
        {
        case 1:
            if (data[i].get_country() < data[min_pos].get_country()) {min_pos = i;}
            break;
        case 2:
            if (data[i].get_epiRank() < data[min_pos].get_epiRank()) {min_pos = i;}
            break;
        case 3:
            if (data[i].get_epi2020() < data[min_pos].get_epi2020()) {min_pos = i;}
            break;
        case 4:
            if (data[i].get_TYchange() < data[min_pos].get_TYchange()) {min_pos = i;}
            break;
        case 5:
            if (data[i].get_us21R() < data[min_pos].get_us21R()) {min_pos = i;}
            break;
        case 6:
            if (data[i].get_int20R() < data[min_pos].get_int20R()) {min_pos = i;}
            break;
        case 7:
            if (data[i].get_pop() < data[min_pos].get_pop()) {min_pos = i;}
            break;
        default:
            break;
        }
    }
    return min_pos;
}
/**
 * @brief swaps the data at two different position in the array 
 * 
 * @param data 
 * @param x 
 * @param y 
 */
void swap(Data* data, int x, int y)
{   
    Data tempp = data[x]; // creates a temp Data object instance so the y indicies value can also be swapped
    data[x] = data[y];
    data[y] = tempp;
}
/**
 * @brief selection sort algo 
 * find the smallest value in array and then swaps the smallest value to the next aviliable spot 
 * @param data 
 * @param size 
 * @param path 
 */
void selection_sort(Data* data, int size, int path)
{
    int next; // the next aviliable spot
    for(next = 0; next < size-1; next++)
    {
        int min_pos = min_position(data, next, size-1, path); // finds the min position from next to the end of array
        swap(data, next, min_pos); // swaps the next available spot with the positions of min position
    }
}
/**
 * @brief  displays the possible options for the user to filter through 
 * takes the input and then calls selection_sort with the path the user wanted to take
 * also tracks time and opens text file to write the time for later evaluation
 * 
 * @param data 
 * @param size 
 */
void selection_sort_helper(Data* data, int size)
{
    int decision;
    std::cout << "Which of the values below would you like to sort through?\n";
    std::cout << "[1] Country name alphabetically\n";
    std::cout << "[2] Epi Ranking (Global)\n";
    std::cout << "[3] Epi from 2020 (Global)\n";
    std::cout << "[4] 10 year Epi change (Global)\n";
    std::cout << "[5] US 2021 Ranking\n";
    std::cout << "[6] International 2020 Ranking\n";
    std::cout << "[7] Country by Population\n-> ";
    std::cin >> decision;
    while( std::cin.fail() || (decision <= 0) || (decision > 7) )
    {
        std::cin.clear();
        if(std::cin.fail())
        {
            std::cout << "sorry you didn't enter a number please try again\n-> ";
        }
        else std::cout << "Please enter a number from [1-7] only\n-> ";
        std::cin.ignore(100,'\n');
        std::cin >> decision;

    }

        std::ofstream log; // creates ofstream to save the time it took to run selection sort
        log.open("sort.txt", std::fstream::app); // opens file and uses the append method so it doesnt over write
        // using highresolution clock to take two times and calculate the difference 
        using namespace std::chrono;
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        selection_sort(data,size,decision);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        reorder(data,size+1,decision);
        duration<double> time_span = duration_cast<duration<double> >(t2 - t1);
        std::cout << "\n\nIt took " << time_span.count() << " seconds. For selection sort to finish\n\n";
        log << time_span.count() << " sort\n";
}
/**
 * @brief Get the algorithm that the user wants to use to filter through data and calls function based on input
 * 
 * @param data 
 * @param size 
 */
void get_algo(Data* data, int size)
{
    std::cout << "Which algorithm would you like to use to sort the data?\n";
    std::cout << "[1] Merge sort\nor\n[2] Selection sort\n-> ";
    int path;
    std::cin >> path;
    while(std::cin.fail() || path < 1 || path > 2)
    {
        std::cin.clear();
        if(std::cin.fail()) std::cout << "Sorry it looks like you entered a letter or word instead of a number\nPlease try again picking either [1] or [2]\n-> ";
        else std::cout << "Please enter [1] or [2] only\n-> ";
        std::cin.ignore();
        std::cin >> path;
    }
    switch (path)
    {
    case 1:
        merge_sort_helper(data,0,size);
        break;
    case 2:
        selection_sort_helper(data,size);
    break;
    
    default:
        break;
    }
}
/**
 * @brief writes sorted data to file
 * 
 * @param data 
 * @param size 
 */
void write(Data* data, int size)
{
    std::string file = get_output_file(); // gets the file name that the user wants to write to 
    if(file == "nofile") return; // returns if they say they dont want to save data
    std::ofstream out; //open ofstream 
    out.open(file += ".csv"); // open file
    // write to file
    out << "\"country\"," << "\"epiRank\"," << "\"epi2020\"," << "\"10yrChange\"," << "\"usn2021Rank\"," << "\"ints2020Rank\"," << "\"pop2022\"" << "\n";
    for(int i = 0; i < size; i++)
    {   std::cout << std::fixed;
        out << "\"" << data[i].get_country() << "\",\""<< data[i].get_epiRank() << "\",\"" << data[i].get_epi2020() << "\",\""<< data[i].get_TYchange() << "\",\"" << data[i].get_us21R() << "\",\"" << data[i].get_int20R() << "\",\"" << std::setprecision(6) << data[i].get_pop() << "\"" << "\n";
    }
}

/**
 * @brief Get the output file name 
 * allows user to not save data but warns first
 * 
 * @return std::string 
 */
std::string get_output_file()
{
       std::cout << "Would you like to save the data to a .csv file?\n-> ";
       bool go = enter();
       if(!go)
       {
           std::cout << "Are you sure you dont want to save this data? All of it will be destroyed!!! Enter yes to destory data\n-> ";
           bool _enter = enter();
           if(_enter)
           {
               std::cout << "All data has been purged!!!\n";
               return "nofile";
           }
           else
           {
               go = true;
           }
       }
       if(go)
       {
            std::string file;
            std::cout << "What would you like to name this file (do not include .csv)?\n-> ";
            std::cin >> file;
            return file;
        }
};
/**
 * @brief simple user input handeling for yes or no questions
 * 
 * @return true 
 * @return false 
 */
bool enter()
{
   bool return_value;
   std::string yes_no;
   bool reprompt = false;
       while(!reprompt) // this is the first instance of input validation which only accepts yes or Yes or No or no and will keep prompting until valid
       {
           if(std::cin.fail()) std::cin.ignore(100,'\n'); // ignores the flag on the error
           std::cin >> yes_no;
           if(yes_no =="yes" || yes_no =="Yes")// the logic below compares the string to the 4 possible values, and then returns true or false to either enter the if statement or skip to the else statement in the main function
           {
               reprompt = true;
               return_value = true;
           }
           else if (yes_no =="no" || yes_no =="No")
           {
               reprompt = true;
               return_value = false;
           }
           else
           {
               std::cout<<"Please enter yes or no only\n-> ";
           }
       }
   return return_value;
}
// prints options that the user can choose for printing
void show_print_options()
{
    std::cout << "\n";
    std::cout << "Would you like to see any of the options below?\n";
    std::cout << "[0] No extra output\n";
    std::cout << "[1] The top 20 sorted data points\n";
    std::cout << "[2] The bottom 20 sorted data points\n";
    std::cout << "[3] The top 10 sorted data points\n";
    std::cout << "[4] The bottom 10 sorted data points\n-> ";
}
/**
 * @brief prints the array based on what the user wants
 * possible options are listed above
 * 
 * @param data 
 * @param length 
 * @return true 
 * @return false 
 */
bool print(Data* data, int length)
{
    std::cout << "\n| [Country]-----------------------|-[epiRank]-|[Rank2020]|[10YrChange]|[US2021Ran]|[int2020Rank]|-[population]|";
    for(int i = 0; i < length; i++)
    {
        data[i].print();
    }
    int path;
    std::cout << "\n---------------------------------------------------------------------------------------------------------------";
    while(path != 0)
    {
        std::cout << "\n| [Country]-----------------------|-[epiRank]-|[Rank2020]|[10YrChange]|[US2021Ran]|[int2020Rank]|-[population]|\n";
        show_print_options();
        std::cin >> path;
        while(std::cin.fail() || path < 0 || path > 4)
        {
            std::cin.clear();
            if(std::cin.fail()) {std::cout << "Please enter a valid number stated below\n";show_print_options();}
            else {std::cout << "Sorry that not an option, please choose a valid number stated below\n";show_print_options();}
            std::cin.ignore(100,'\n');
            std::cin >> path;
        }
         std::cout << "\n| [Country]-----------------------|-[epiRank]-|[Rank2020]|[10YrChange]|[US2021Ran]|[int2020Rank]|-[population]|";

        switch (path)
        {
            
        case 1:
        for(int i = 0; i < 20; i++)
        {
            data[i].print();
        }
            std::cout << "\n---------------------------------------------------------------------------------------------------------------";
            break;
        case 2:
        for(int i = length-21; i < (length); i++)
        {
            data[i].print();
        }
            std::cout << "\n---------------------------------------------------------------------------------------------------------------";
            break;
        case 3:
        for(int i = 0; i < 10; i++)
        {
            data[i].print();
        }
            std::cout << "\n---------------------------------------------------------------------------------------------------------------";
            break;
        case 4:
        for(int i = length-11; i <(length); i++)
        {
            data[i].print();
        }
            std::cout << "\n---------------------------------------------------------------------------------------------------------------";
            break;
            
        default:
            break;
        }
       
    }
    std::cout << "\nWould you like to sort the data again? Possibly using another algorithm?\n[yes] or [no]\n-> ";
    return enter();
}
//gets the file the user wants to open and checks to see if it is able to be opened
// returns "nofile" if no files are found
   std::string get_file()
   {
       int count = 0;
       std::string _file;
       std::cout << "Please enter the file name.\n-> ";
       std::cin >> _file;
       std::ifstream file;
       file.open(_file);
       while(file.fail())
       {
          count++;
          std::cout<< "It seems that that file does not exist please try again\n-> ";
          std::cin >> _file;
          file.open(_file);
          if(!file.fail())
          {
              file.clear();
          }
          if(count == 4)
           {
               std::cout << "It seems that you are having trouble opening a file, would you like to exit the program?\nPlease enter yes or no\n-> ";
               bool _enter = enter();
               if(_enter)
               {
                   _file = "nofile";
                   return _file;
               }
               count = 0;
           }
       }
       return _file;
   };
// greets user and gets if the user wants the run program again with a different algo
bool greet()
{
    bool decision;
    std::cout << "Hello, this is a program created for sorting through data using either merge sort or selection sort.\nThis program will take in your data, sort it, and then allow you to print it out in a few different ways.\nLastly, you will be able to save and download the newly sorted data into a file!\nWould you like to try it out ?\n-> ";
    decision = enter();
    return decision;

}
// thanks user 
void thank()
{
    std::cout << "Thank you for using my program, I hope it was useful and helped you sort through your data.\n";
}