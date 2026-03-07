/**
 * @file stacker.cpp
 * @author Isaac McKnew and Jose Jaime
 * @date 2026-02-28
 * @brief Stacker class
 * 
 * Implementation of the Stacker class
 */


#include "stacker.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>



stacker::stacker(){
  //initial values
  magic_number = "";
  width = 0;
  height = 0;
  max_color = 0;
  
}







void stacker::readFile(const std::string& image, int numberImages){
  ifstream inputFile(image);

  if(!inputFile.is_open()){
    cout << "Please choose a valid file" << endl;
  }

  inputFile >> magic_number >> width >> height >> max_color;
  pixels.reserve(width * height);

  //find way to change the pixel struct so it can be put into the pixels vector

  inputFile.close();

}


void stacker::writeFile(const std::string& image){



}

