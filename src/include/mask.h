/**********************************************************************
 * Name             : mask.h
 * Project          : BrushWork
 * Description      : Mask class header file
 * Copyright        : 2016 CSCI3081W Drossemlmeyer All rights reserved.
 * Creation Date    : 10/16/16
 * Original Author  : ZEYUAN XUE
 *
 **********************************************************************/

#ifndef SRC_INCLUDE_MASK_H_
#define SRC_INCLUDE_MASK_H_

#include <cstddef>

namespace mask_data {
class Mask {
 public:
    Mask(int height, int width, float opacity);
    void generateRectangleMask();
    virtual ~Mask();
    float ** getMaskArray () {return mask_array_;}
    int getWidth() const {return width_;}
    int getHeight() const {return height_;}
    float getValue(const int & x, const int & y) const;
    void setValue(const int & x, const int & y, const float & v);
    void generateCircleMask();
    void generateSprayCircleMask();
    void generateCrayonCircleMask();

 protected:
    float opacity_ = 0.0f;
    int height_ = 0;
    int width_ = 0;
    float** mask_array_ = nullptr;
};
}  // namespace mask_data
#endif  // SRC_INCLUDE_MASK_H_
