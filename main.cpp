/**
 * @file main.cpp
 * @author Isaac McKnew and Jose Jaime
 * @date 2026-02-28
 * @brief Image Stacker Project
 * 
 * This program takes the average of 10 noisy images to create a sharper image.
 */


#include "stacker.h"
#include <iostream>

using namespace std;

int main() {
  string image;
  int numberImages;
  stacker imageStacker;

  cout << "Please enter the image you wish to stack: ";
  cin >> image;

  cout << "Please enter the number of images: ";
  cin >> numberImages;

  if(numberImages <= 0 or numberImages > 10){
    cout << "Please enter a number between 1 and 10." << endl;
    return 1;
  }

  cout << "Stacking images:" << endl;

  //Read the images in the folder and get the average.
  imageStacker.readFile(image, numberImages);

  //Make a new file with a sharper image.
  imageStacker.writeFile(image);
  
  return 0;
}
