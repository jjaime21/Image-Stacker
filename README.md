Pathfinding Pioneers
Isaac McKnew and Jose Jaime

We decided to go with two functions. One for reading the files and one for writing the sharper image file.
We shared the work by reviewing each others code as we updated the repository.

How to run the program:
Setup image folder - Please have the ppms folder located one folder above your current directory.
Example: ../ppms/orion/orion_001.ppm

Run the following commands:
Make
./test
Enter the image name: example orion
Enter the number of images example 10
New sharper image file is created in current directory.

Challenges ran into:
Creating the stringstream variable for the folder path
We got help from the String Stream Intro video on Canvas.

Fixing the warning: comparison of integer expressions of different signedness
We got help from the cppreference website:https://en.cppreference.com/w/cpp/types/size_t.html
and changed int to size_t.
