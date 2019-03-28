/**********************************************************************
 * Name             : tool.h
 * Project          : BrushWork
 * Description      : Tool Class header file
 * Copyright        : 2016 CSCI3081W Drossemlmeyer All rights reserved.
 * Creation Date    : 10/12/16
 * Original Authors : Taewon Kim Paul Gross
 *
 **********************************************************************/

#ifndef SRC_INCLUDE_TOOL_H_
#define SRC_INCLUDE_TOOL_H_

#include <cstddef>
#include "./mask.h"
#include "./color_data.h"
#include "./pixel_buffer.h"

namespace Tools {
class Tool {
 public:
    Tool();
    virtual ~Tool();
    virtual void applyMask(int x, int y,
                           image_tools::PixelBuffer* buffer,
                           image_tools::ColorData color);
    inline int getMaskWidth() const { return mask_->getWidth(); }
    inline int getMaskHeight() const { return mask_->getHeight(); }
 protected:
    mask_data::Mask * mask_ = nullptr;
};
}  // namespace Tools
#endif  // SRC_INCLUDE_TOOL_H_
