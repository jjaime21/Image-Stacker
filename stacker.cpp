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


  struct pixel{
    int red = 0;
    int green = 0;
    int blue = 0;
  }

  vector<pixel> pixels;
}







void stacker::readFile(const std::string& image, int numberImages){
  ifstream inputFile(image);

  if(!inputFile.is_open()){
    cout << "Please choose a valid file" << endl;
  }

  inputFile >> magic_number >> width >> height >> max_color;
  pixels.reserve(width * height * numberImages);

  for(pixel& pixel : pixels){
    inputFile >> pixel.red >> pixel.green >> pixel.blue;
  }
  

  inputFile.close();
  //goal here is to make another vector to add multiple images together and then average from there
  //I got lost too late so I can't make it happen

}


void stacker::writeFile(const std::string& image){

  ofstream outputFile(image);
  if(!outputFile.is_open()){
    cout << "Please choose a valid file" << endl;
  }

  outputFile << magic_number << endl << width << " " << height << max_color << endl;

  for(int i=0; i<pixels.size();i++){
    outputFile << pixels[i] << " ";
  }
  

  outputFile.close();
}

