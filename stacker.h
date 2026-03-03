/**
 * @file stacker.h
 * @author Jose Jaime
 * @date 2026-02-28
 * @brief Stacker class
 * 
 * Header file for the stacker class
 */

#ifndef STACKER_H
#define STACKER_H

#include <vector>

class stacker {
Private:

  //magic number is the p3 value
  string magic_number;
  //width and height describe the image dimension
  //max_color is the color depth
  int width, height, max_color;

  //struct holding the color values of each color
  struct pixel{
    int red;
    int green;
    int blue;
  }

  //vector of pixel structs
  vector<struct> pixels;

Public:
  

/**
 * constructor
 *
 * @pre  
 * @post 
 * 
 */
  stacker();

  //copy constructor
  stacker(const stacker& other);

  //destructor
  ~stacker();


/**
 * puts the pixels into the vector. Could probably do that in the constructor?
 *
 * @pre 
 * @return vector<struct> pixels
 * @post the vector of pixels
 * 
 */
  vector<struct> scan();
  


};








#endif //STACKER_H
