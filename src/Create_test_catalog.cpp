/*
 * Creat_test_catalog.cpp
 *
 *  Created on: Feb 13, 2022
 *      Author: tomek93
 */

#include "Create_test_catalog.hpp"

/**
 * @brief Function create text file at the indicated location
 *
 * @param numberlines - number of lines in file
 * @param file path - location for new text file.
 */
void create_text_file(int numberlines, std::string filepath)
{
	std::ofstream plik_txt(filepath + "/file.txt"); //open stream to filetext

	for(int lines=0; lines<numberlines; lines++) //add lines to text file
	{
		plik_txt<<lines<<std::endl;
		plik_txt<<std::endl;
	}
	plik_txt.close();

}


void create_catalog(std::string startpath,int catalognumber, int depthnumber, int linesnumber)
{
	std::string foldername = "folder";
	std::string actfolder;
	for(int cat=0; cat<catalognumber; cat++)
	{
		fs::current_path(startpath);
		actfolder= foldername + std::to_string(cat);
	    if(fs::exists(actfolder))
	    	fs::remove_all(actfolder);
		fs::create_directories(actfolder);
		create_text_file(linesnumber, actfolder);

		for(int depth=0;depth < depthnumber; depth++)
		{
			actfolder=actfolder + '/' + "folder"+ std::to_string(depth);

			fs::create_directories(actfolder);
			create_text_file(linesnumber, actfolder);
		}

	}
}
