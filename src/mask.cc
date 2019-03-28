/**********************************************************************
 * Name             : mask.cc
 * Project          : BrushWork
 * Description      : Mask class implementation
 * Copyright        : 2016 CSCI3081W Drossemlmeyer All rights reserved.
 * Creation Date    : 10/16/16
 * Original Author  : ZEYUAN XUE
 *
 **********************************************************************/

#include "include/mask.h"
#include <cmath>
#include <iostream>

namespace mask_data {

Mask::Mask(int height, int width, float opacity) {
    this->height_ = height;
    this->width_ = width;
    this->opacity_ = opacity;
    int i;
    mask_array_ = new float*[height_];
    for (i = 0; i < height_; i++) {
        mask_array_[i] = new float[width_];
    }
}

void Mask::generateRectangleMask() {
    int i;
    int j;
    for (i = 0; i < height_; i++) {
        for (j = 0; j < width_; j++) {
            mask_array_[i][j] = opacity_;
        }
    }
}

Mask::~Mask() {
    for (int i = 0; i < height_; i++) {
        delete[] mask_array_[i];
    }
    delete [] mask_array_;
}

float Mask::getValue(const int & x, const int & y) const {
    if (x < 0 || x > width_ || y < 0 || y > height_) {
        std::cout << x << "," << y << " is not a valid index in Mask\n";
        return -1;
    } else {
      return mask_array_[y][x];
    }
}

void Mask::setValue(const int & x, const int & y, const float & value) {
    if (x < 0 || x > width_ || y < 0 || y > height_) {
        std::cout << x << "," << y << " is not a valid index in Mask\n";
        return;
    } else {
        mask_array_[y][x] = value;
    }
}
void Mask::generateCircleMask() {
    float ri;
    float rj;
    float r;
    float radius = (width_-1)/2.0;
    for (int i=0; i < height_; i++) {
        for (int j=0; j < width_; j++) {
            ri = abs(radius-i);
            rj = abs(radius-j);
            r = sqrt(pow(ri, 2) + pow(rj, 2));
            if (floor(r*10.0)/10.0 <= radius) {
                setValue(i, j, opacity_);
            } else {  // Intialize values outside the circle
                setValue(i, j, 0.0f);
            }
        }
    }
}

void Mask::generateSprayCircleMask() {
    float ri;
    float rj;
    float r;
    int rNum;
    float radius = (width_)/2.0;
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            ri = abs(radius-i);
            rj = abs(radius-j);
            r = sqrt(pow(ri, 2) + pow(rj, 2));
            if (r < radius) {
                setValue(i, j, opacity_ - opacity_*(r/radius));
            } else {  // Intialize values outside the circle
                setValue(i, j, 0.0f);
            }
        }
    }
}

void Mask::generateCrayonCircleMask() {
    float ri;
    float rj;
    float radius = (width_-1)/2.0;
    float r;
    unsigned int seed = 1;  /* Seed for random number */
    int rNum;
    for (int i=0; i < height_; i++) {
        for (int j=0; j < width_; j++) {
            ri = abs(radius-i);
            rj = abs(radius-j);
            r = sqrt(pow(ri, 2) + pow(rj, 2));
            if (r <= radius) {
                rNum = rand_r(&seed)%100+1;
                if (rNum <= 60) {  /* Fill in approximately 60% */
                    setValue(i, j, opacity_);
                } else {  // Intialize values outside the circle
                    setValue(i, j, 0.0f);
                }
            }
        }
    }
}
}  // namespace mask_data
