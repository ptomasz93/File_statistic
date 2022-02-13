/*
 * lines_counter.cpp
 *
 *  Created on: Feb 13, 2022
 *      Author: tomek93
 */

#include "line_counter.hpp"

std::mutex counter_mutex;


void count_lines(std::string dir_entry,  unsigned *counteralllines, unsigned *counterallnonemptylines)
{
    std::ifstream input2;
    unsigned counterlines = 0;
    unsigned counternonemptylines = 0;
    std::string line;

    input2.open(dir_entry);  //opening file
    if(!input2.fail())       //Checking the correct opening
    {
        while (std::getline(input2 , line))
        {
            ++counterlines;// increamenting counter of lines
            if(line.size()) //If lines non-empty
            ++counternonemptylines; //increamenting counter of non-empty lines
        }

       //std::cout<< std::setw(110)<<std::left << dir_entry<< std::setw(30)<< counterlines << std::setw(30)<< counternonemptylines << std::endl;

        const std::lock_guard<std::mutex> lock(counter_mutex); //
        *counteralllines += counterlines;
        *counterallnonemptylines += counternonemptylines;
     }
    else
        std::cout<<"FILE OPEN ERROR!!!"<<std::endl;
    input2.close();
}



