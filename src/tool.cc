/**********************************************************************
 * Name             : tool.cc
 * Project          : BrushWork
 * Description      : Tool Class Impelementation
 * Copyright        : 2016 CSCI3081W Drossemlmeyer All rights reserved.
 * Creation Date    : 10/12/16
 * Original Authors : Taewon Kim Paul, Gross
 *
 **********************************************************************/
#include "include/tool.h"
#include "include/mask.h"

namespace Tools {
Tool::Tool() {}
Tool::~Tool() {
    delete mask_;
}
void Tool::applyMask(int x,
                     int y,
                     image_tools::PixelBuffer* buffer,
                     image_tools::ColorData color) {
    int i;
    int j;
    int cur_x;
    int cur_y;
    image_tools::ColorData canvas_color;
    double cur_mask_value;
    int PixelBuffer_height = buffer->height();
    int PixelBuffer_width = buffer->width();

    /* Fixes inverted y drawing */
    int y_rel = PixelBuffer_height - y;
    int mask_height = mask_->getHeight();
    int mask_width = mask_->getWidth();
    for (i=0; i < mask_height; i++) {
        for (j=0; j< mask_width; j++) {
            cur_x = x+j;
            cur_y = y_rel+i;

            /* center drawing on mouse */
            cur_x -= mask_width/2;
            cur_y -= mask_height/2;

            cur_mask_value = mask_->getValue(j, i);
            if (cur_x < PixelBuffer_width &&
                cur_x > 0 &&
                cur_y < PixelBuffer_height &&
                cur_y > 0) {
                    canvas_color = buffer->get_pixel(cur_x, cur_y);
                    canvas_color = color*cur_mask_value +
                                   canvas_color *
                                   (1.0 - cur_mask_value);
                    buffer -> set_pixel(cur_x, cur_y, canvas_color);
            }
        }
    }
}
}  // namespace Tools
