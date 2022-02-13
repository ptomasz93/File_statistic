/*
 * Creat_test_catalog.hpp
 *
 *  Created on: Feb 13, 2022
 *      Author: tomek93
 */

#ifndef CREAT_TEST_CATALOG_HPP_
#define CREAT_TEST_CATALOG_HPP_

#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <thread>
#include <atomic>
#include <chrono>

namespace fs = std::filesystem;
/**
 * @brief Function create folders and files, for test aplication
 *
 * @param startpath - path to the location where the files will be created
 * @param catalognumber -number of catalog first level
 * @param how many folders be created in folders
 * @param linesnumber - text file will have this many lines non-empty and empty
 */
void create_catalog(std::string startpath,int catalognumber, int depthnumber, int linesnubmer);

#endif /* CREAT_TEST_CATALOG_HPP_ */
