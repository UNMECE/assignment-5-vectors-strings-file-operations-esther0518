#include <iostream>
#include <vector>
#include "pixel.h"
//functions for finding average and flipping the pixels vertically

//will give the integer average of the pixels respectively
void average_colors(std::vector<Pixel> &pixel_list){

    float sum_r = 0, sum_g = 0, sum_b = 0;
    int num_pixels = pixel_list.size();

    //find the sum of each pixel
    for (size_t i = 0; i < pixel_list.size(); i++) {
        sum_r += pixel_list[i].r;
        sum_g += pixel_list[i].g;
        sum_b += pixel_list[i].b;
    }

    //take average of the pixels
    float avg_r = sum_r / num_pixels;
    float avg_g = sum_g / num_pixels;
    float avg_b = sum_b / num_pixels;
    
    //print the averages
    std::cout << "The average of pixel r is: " << avg_r << std::endl;
    std::cout << "The average of pixel g is: " << avg_g << std::endl;
    std::cout << "The average of pixel b is: " << avg_b << std::endl;
}


//store the first y value and move it to the end
void flip_vertically(std::vector<Pixel> &pixel_list){
    //initalize x and y values with given data
    int y_height = 256;
    int x_width = 512;
    //flip only if the pixel list has enough elements
    if (pixel_list.size() < y_height * x_width) {
        std::cerr << "Not enough pixels to flip." << std::endl;
        return;
    }

    //flip
    for (int y = 0; y < y_height / 2; y++) {
        for (int x = 0; x < x_width; x++) {
            int top_index = y * x_width + x;
            int bottom_index = (y_height - y - 1) * x_width + x;

            //check for valid indices
            if (top_index < pixel_list.size() && bottom_index < pixel_list.size()) {
                std::swap(pixel_list[top_index], pixel_list[bottom_index]);
            }
        }
    }
    //not flipping idk y
}

//to print pixels
void print_pixels(const std::vector<Pixel>& pixel_list){
for (size_t i = 0; i < pixel_list.size(); i++) {
    const Pixel& pixel = pixel_list[i];
    std::cout << pixel.x << "," << pixel.y << "," << pixel.r 
            << "," << pixel.g << "," << pixel.b << std::endl;
    }
}