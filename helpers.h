#ifndef READLINE_H
#define READLINE_H

void read_line(Data*, int&, bool&); // greets user, gets file, opens file and then passes each line to parse line
void parse_line(std::string,Data*, int&);// gets the line, calls format, assigns data the "data" class and then pushes to array
std::string get_file(); // gets the file that the user wants to filter through
std::string format_line(std::string);// takes csv formatting and formats for easier parsing
void resize_array(Data*, int&); // resizes array to add one to the array
void merge_sort(Data*, int, int, int); // merge sort algo
void merge(Data*, int, int, int, int); // merge helper to merge smaller arrays 
void merge_sort_helper(Data*,int,int); //  gets what the user wants to filter though -> country,population...etc
void reorder(Data*, int, int);// takes null values and puts to the back of the array -> helpful when printing as null values act as zeros but are not
void reorder_switch(Data*, Data*, Data*, int, int&, int&, int); // find the null values and returns to reorder for processing
void selection_sort(Data* data, int size, int path); // selection sort algo
int  min_position(Data* data, int from, int to, int path); // finds minimum position 
void swap(Data* data, int x, int y); //  swaps the minimum position with next aviliable spot -> in selection sort
void selection_sort_helper(Data* data, int); //  gets the data that the user wants to sort through and then calls selection sort 
void get_algo(Data*, int); // gets the algo that the user wants to use 
void write(Data* data, int size); //opens ofstream and saves file to a .csv 
std::string get_output_file(); // gets the output file name for step above ^
bool enter(); // takes in and handles user input for yes or no questions
bool print(Data* data, int); // displays different print options and then calls member print function
void show_print_options(); // shows the print options for step above 
bool greet(); //  greets user and tells what program is about   
void thank(); // thanks user for using program 
// void to_array(); not used
#endif