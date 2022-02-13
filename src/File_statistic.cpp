//============================================================================
// Name        : File_statistic.cpp
// Author      : Tomasz Piotrowski
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <thread>
#include <atomic>
#include <chrono>


#include "line_counter.hpp"
#include "thread_pool.hpp" // ready library from GitHub
#include "Create_test_catalog.hpp"

namespace fs = std::filesystem;




int main(int argc, char *argv[])
{

    unsigned counterfiles =0;//global counter number of files
    unsigned counteralllines = 0; //global counter number of lines
    unsigned counterallnonemptylines = 0; //global counter number of non-empty lines
    std::string filepath , defaultpath; // path to file
    thread_pool pool;

    //If file path was not given on startup
    if(argc<2)
    {
        std::cout << "File Path:";
        std::cin >> defaultpath;
    }
    else
    	defaultpath=argv[1];

    if(!fs::exists(defaultpath))
    {
    	std::cout<<"!!!!!!!!!WRONG FILE PATH!!!!!!!!!"<<std::endl;
    	return 0;
    }

    fs::current_path(defaultpath);
    std::cout << "The searched folder is:" << fs::current_path() << '\n'; // (1)

   //create_catalog(defaultpath, 20, 20 , 2000); //Function create testing folders.


   std::cout<<std::endl<<"*********** Thread pool************"<<std::endl;

   auto start = std::chrono::high_resolution_clock::now();//take actual time (ms) for speed test
    //std::cout<< std::setw(110)<<"PATH"<< std::setw(30)<<"number of lines:" << std::setw(30)<< "nomber of no empty lines:"<<std::endl;//index for statistics for each file
   for (const fs::directory_entry& dir_entry : fs::recursive_directory_iterator(defaultpath)) // Recursive searching files
    {
       if(!dir_entry.is_directory()) // if is not catalog
       {
    	   counterfiles++;  //increment counters of files
    	   filepath=dir_entry.path().string();// conversion from path to string
    	   pool.push_task(count_lines, filepath, &counteralllines, &counterallnonemptylines); //push function to queue task for threats
        }
    }
    pool.wait_for_tasks();// waiting for end of queue task
    auto finish = std::chrono::high_resolution_clock::now();//take time of end for seed test
    //print of statistic
    std::cout <<"nomber of files:  "<< counterfiles << std::endl;
    std::cout <<"nomber lines in all files:  "<< counteralllines << std::endl;
    std::cout <<"nomber non-empty lines in all files:  "<< counterallnonemptylines << std::endl;

    std::chrono::duration<double> elapsed = finish - start;// calculation work time
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";

    // clearing counters for test with one thread
    counterfiles=0;
    counteralllines=0;
    counterallnonemptylines=0;

    std::cout<<std::endl<<"*********** Only one thread************"<<std::endl;
    //std::cout<< std::setw(110)<<"PATH"<< std::setw(30)<<"number of lines:" << std::setw(30)<< "nomber of no empty lines:"<<std::endl;

    start = std::chrono::high_resolution_clock::now();//take actual time (ms) for speed test
     //std::cout<< std::setw(110)<<"PATH"<< std::setw(30)<<"number of lines:" << std::setw(30)<< "nomber of no empty lines:"<<std::endl;//index for statistics for each file
    for (const fs::directory_entry& dir_entry : fs::recursive_directory_iterator(defaultpath)) // Recursive searching files
     {
        if(!dir_entry.is_directory()) // if is not catalog
        {
     	   counterfiles++;  //increment counters of files
     	   filepath=dir_entry.path().string();// conversion from path to string
     	   count_lines( filepath, &counteralllines, &counterallnonemptylines); //push function to queue task for threats
         }
     }
     pool.wait_for_tasks();// waiting for end of queue task
     finish = std::chrono::high_resolution_clock::now();//take time of end for seed test
     //print of statistic
     std::cout <<"nomber of files:  "<< counterfiles << std::endl;
     std::cout <<"nomber lines in all files:  "<< counteralllines << std::endl;
     std::cout <<"nomber non-empty lines in all files:  "<< counterallnonemptylines << std::endl;

     elapsed = finish - start;// calculation work time
     std::cout << "Elapsed time: " << elapsed.count() << " s\n";

}


