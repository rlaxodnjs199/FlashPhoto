/**********************************************************************
 * Name             : CalligraphyPen.cc
 * Project          : BrushWork
 * Description      : CalligraphyPen Class Impelementation
 * Copyright        : 2016 CSCI3081W Drossemlmeyer All rights reserved.
 * Creation Date    : 10/12/16
 * Original Authors : Taewon Kim Paul, Gross
 *
 **********************************************************************/
#include "include/calligraphy_pen.h"

namespace Tools {
CalligraphyPen::CalligraphyPen() {
        mask_ = new mask_data::Mask(15, 5, 1.0f);
        mask_->generateRectangleMask();
}

CalligraphyPen::~CalligraphyPen(void) {
        delete mask_;
}
}  // namespace Tools
