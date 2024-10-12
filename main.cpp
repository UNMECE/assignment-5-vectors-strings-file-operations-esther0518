#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "pixel.h"

int main(int argc, char* argv[]){
    //checks to see if there are more the=an one arguments
     if (argc < 2) {
        std::cerr << "Please provide the input file as a command-line argument." << std::endl;
        return 1;
    }


    //opent the .dat file from the command line
    std::ifstream file(argv[1]);
    //check to see if the file opens
    if(!file){
        std::cerr <<"Error opening the file "<< argv[1] <<std::endl;
        return 1;
    }

    //make vector named pixel_list
    std::vector<Pixel> pixel_list;
    std::string line;

    //read the file
    while(std::getline(file, line)){
        std::istringstream iss(line);
        Pixel pixel;
        //to read the commas
        char comma;

        //read and parse each pixel to the vector
        iss >> pixel.x >> comma >> pixel.y >> comma >> pixel.r
            >> comma >> pixel.g >> comma >> pixel.b;
    
    //add the pixel to the vector
    pixel_list.push_back(pixel);

    }
    file.close();

    std::cout <<"File read" << std::endl;

    //pixels before being print
    std::cout <<"Pixels before being flipped: " << std::endl;
    print_pixels(pixel_list);

    //print the average
    average_colors(pixel_list);

    //pixels after being flipped
    std::cout <<"Pixels after being flipped: " <<std::endl;
    flip_vertically(pixel_list);
    print_pixels(pixel_list);
    
    //save into new "flipped.dat" file
    std::ofstream outFile("flipped.dat");
    for (size_t i = 0; i < pixel_list.size(); i++) {
        Pixel& pixel = pixel_list[i];
        outFile << pixel.x << "," << pixel.y << "," << pixel.r
                << "," << pixel.g << "," << pixel.b << std::endl;
    }

    return 0;
}

