#ifndef PIXEL_H
#define PIXEL_H

#include <vector>

struct _pixel
{
  float r;
  float g;
  float b;
  int x;
  int y;
};
typedef struct _pixel Pixel;

void average_colors(std::vector<Pixel> &pixel_list);
void flip_vertically(std::vector<Pixel> &pixel_list);
void print_pixels(const std::vector<Pixel>& pixel_list);

#endif