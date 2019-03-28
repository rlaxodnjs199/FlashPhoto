/**********************************************************************
 * Name             : pen.h
 * Project          : BrushWork
 * Description      : Pen header file
 * Copyright        : 2016 CSCI3081W Drossemlmeyer All rights reserved.
 * Creation Date    : 10/12/16
 * Original Authors : Taewon Kim Paul Gross
 *
 **********************************************************************/
#ifndef SRC_INCLUDE_PEN_H_
#define SRC_INCLUDE_PEN_H_
#include "./tool.h"
namespace  Tools {
class Pen: public Tool {
 public:
    Pen();
    virtual ~Pen();
    void applyMask(int x,
                  int y,
                  image_tools::PixelBuffer* buffer,
                  image_tools::ColorData color)
                  {Tool::applyMask(x, y, buffer, color);};
};
}  // namespace  Tools
#endif  // SRC_INCLUDE_PEN_H_
