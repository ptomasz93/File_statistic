/*
 * line_counter.hpp
 *
 *  Created on: Feb 13, 2022
 *      Author: tomek93
 */

#ifndef LINE_COUNTER_HPP_
#define LINE_COUNTER_HPP_


#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <thread>
#include <atomic>
#include <chrono>
#include <mutex>





namespace fs = std::filesystem;


/**
 * @brief Function calculates the number of lines in the indicated file and displays the data in the terminal.
 *        Result of the calculation is added to the gloabal row cunter.
 *
 *
 * @param std::string dir_entry               - Path to file
 * @param unsigned *counteralllines           - Global cunter of all lines in files
 * @param unsigned *counterallnonemptylines   - Global counter of all non-empty lines
 *
 */
void count_lines(std::string dir_entry,  unsigned *counteralllines, unsigned *counterallnonemptylines);


#endif /* LINE_COUNTER_HPP_ */
