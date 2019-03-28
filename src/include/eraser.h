/**********************************************************************
 * Name             : eraser.h
 * Project          : BrushWork
 * Description      : Eraser Header File
 * Copyright        : 2016 CSCI3081W Drossemlmeyer All rights reserved.
 * Creation Date    : 10/12/16
 * Original Authors : Taewon Kim Paul Gross
 *
 **********************************************************************/
#ifndef SRC_INCLUDE_ERASER_H_
#define SRC_INCLUDE_ERASER_H_

#include "./tool.h"
#include "./color_data.h"
#include "./pixel_buffer.h"

namespace  Tools {
class Eraser:public Tool {
 public:
     Eraser();
     ~Eraser();
     /* overide applyMask to use backgoung color */
     void applyMask(int x,
                    int y,
                    image_tools::PixelBuffer* buffer,
                    image_tools::ColorData color);
};
}  // namespace Tools
#endif  // SRC_INCLUDE_ERASER_H_
