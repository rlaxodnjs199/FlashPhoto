/**********************************************************************
 * Name             : Eraser.cc
 * Project          : BrushWork
 * Description      : Eraser Class Impelementation
 * Copyright        : 2016 CSCI3081W Drossemlmeyer All rights reserved.
 * Creation Date    : 10/12/16
 * Original Authors : Taewon Kim, Paul Gross
 *
 **********************************************************************/

#include "include/eraser.h"

namespace Tools {
Eraser::Eraser() {
    mask_ = new mask_data::Mask(21, 21, 1.0f);
    mask_->generateCircleMask();
}

Eraser::~Eraser(void) {
    delete mask_;
}
void Eraser::applyMask(int x,
                       int y,
                       image_tools::PixelBuffer* buffer,
                       image_tools::ColorData color) {
    // The color used is just the background color
    image_tools::ColorData background_color = buffer->background_color();
    Tool::applyMask(x, y, buffer, background_color);
}
}  // namespace Tools
