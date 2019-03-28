/*******************************************************************************
 * Name             : pen.cc
 * Project          : BrushWork
 * Description      : Pen Class Impelementation
 * Copyright        : 2016 CSCI3081W Group Drossemlmeyer All rights reserved.
 * Creation Date    : 10/12/16
 * Original Authors : Taewon Kim, Paul Gross
 *
 ******************************************************************************/

#include <cmath>
#include <iostream>
#include "include/pen.h"
#include "include/tool.h"

namespace Tools {
Pen::Pen() {
    mask_ = new mask_data::Mask(3, 3, 1.0f);
    mask_->generateCircleMask();
}
Pen::~Pen(void) {
    delete mask_;
}
}  // namespace Tools
