/**
 * @file stacker.h
 * @author Isaac McKnew and Jose Jaime
 * @date 2026-02-28
 * @brief Stacker class
 * 
 * Header file for the stacker class
 */

#ifndef STACKER_H
#define STACKER_H

#include <string>
#include <vector>

class stacker {
private:

  //magic number is the p3 value
  std::string magic_number;
  //width and height describe the image dimension
  //max_color is the color depth
  int width, height, max_color;

  //struct holding the color values of each color
  struct pixel{
    int red;
    int green;
    int blue;
  };

  //Use the struct name pixel for the vector of pixels and std:: because namespace std is not used.
  std::vector<pixel> pixels;

public:
  

/**
 * constructor
 *
 * @pre  
 * @post 
 * 
 */
  stacker();

  //copy constructor
  //stacker(const stacker& other);

  //destructor
  //~stacker();


/**
 * puts the pixels into the vector. Could probably do that in the constructor?
 *
 * @pre 
 * @return vector<struct> pixels
 * @post the vector of pixels
 * 
 */
  //std::vector<pixel> scan();



/**
 * This function reads each image from the ppms folder.
 *
 * @param const string& image The file name read by the function.
 * @param int numberImages The number of images that are stacked.
 * @pre The images need to be present in the file name path.
 * @return void No return type.
 * @post The pixels vector has the average of the images.
 * 
 */
  void readFile(const std::string& image, int numberImages);



/**
 * This function writes a sharper image to a new file.
 *
 * @param const string& image The file name for the new file.
 * @pre The pixels vector needs the average of the images.
 * @return void No return type.
 * @post A new file is made and has a sharper image.
 * 
 */
  void writeFile(const std::string& image);


};








#endif //STACKER_H
