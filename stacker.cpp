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
#include <sstream>

using namespace std;

stacker::stacker(){
  //initial values
  magic_number = "";
  width = 0;
  height = 0;
  max_color = 0;
}



void stacker::readFile(const std::string& image, int numberImages){
  
  for(int i = 1; i <= numberImages; ++i){
    stringstream ss;
    string fileName;

    //Creating the filename string. I got help from the String Stream Intro video on Canvas.
    string padding;
    if(i < 10){
      padding = "00";
    }else{
      padding = "0";
    }
    
    ss << "../ppms/" << image << "/" << image << "_" << padding << i << ".ppm";
    fileName = ss.str();

    ifstream inputFile(fileName);
    if(!inputFile.is_open()){
      cout << "Please choose a valid file" << endl;
      continue;
    }

    //Read the header values
    inputFile >> magic_number >> width >> height >> max_color;

    //Set the size for the image
    if(i == 1){
      pixels.resize(width * height);
    }

    //This for loop reads in each color value from the file into the pixels vector.
    for(int j = 0; j < width * height; ++j){
      int r, g, b;
      inputFile >> r >> g >> b;
      pixels[j].red += r;
      pixels[j].green += g;
      pixels[j].blue += b;
    }

    cout << "     " << fileName << endl;
    

    inputFile.close();

  }


  //Get the average for each color
  //Changed int k to size_t k to fix warning: comparison of integer expressions of different signedness
  //I got help from cppreference website:https://en.cppreference.com/w/cpp/types/size_t.html 
  for(size_t k = 0; k < pixels.size(); ++k){
    pixels[k].red = pixels[k].red / numberImages;
    pixels[k].green = pixels[k].green / numberImages;
    pixels[k].blue = pixels[k].blue / numberImages;
  }
  
}


void stacker::writeFile(const std::string& image){
  string fileName = image + ".ppm";

  ofstream outputFile(fileName);

  if(!outputFile.is_open()){
    cout << "Error creating output file." << endl;
    return;
  }

  //Create the header
  outputFile << magic_number << endl;
  outputFile << width << " " << height << endl;
  outputFile << max_color << endl;

  //Write the pixel values for the sharper image.
  //Get the average for each color
  //Changed int i to size_t i to fix warning: comparison of integer expressions of different signedness
  //I got help from cppreference website:https://en.cppreference.com/w/cpp/types/size_t.html
  for(size_t i = 0; i < pixels.size(); ++i){
    outputFile << pixels[i].red << " " << pixels[i].green << " " << pixels[i].blue << " ";
  }

  //Close the file.
  outputFile.close();
  
  cout << endl << "Stacking succeeded." << endl;
  cout << "Output witten to: " << fileName << endl;

  outputFile.close();
}

