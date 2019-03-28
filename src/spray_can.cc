/**********************************************************************
 * Name             : spray_can.cc
 * Project          : BrushWork
 * Description      : SprayCan Class Impelementation
 * Copyright        : 2016 CSCI3081W Drossemlmeyer All rights reserved.
 * Creation Date    : 10/12/16
 * Original Authors : Taewon Kim Paul Gross
 *
 **********************************************************************/

#include <iostream>
#include <cmath>
#include "include/tool.h"
#include "include/spray_can.h"

namespace Tools {
SprayCan::SprayCan() {
      mask_ = new mask_data::Mask(41, 41, 1.0f);
      mask_->generateSprayCircleMask();
}

SprayCan::~SprayCan(void) {
    delete mask_;
}
}  // namespace Tools
