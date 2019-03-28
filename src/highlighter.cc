/**********************************************************************
 * Name             : Highlighter.cc
 * Project          : BrushWork
 * Description      : Highlighter Class Impelementation
 * Copyright        : 2016 CSCI3081W Drossemlmeyer All rights reserved.
 * Creation Date    : 10/12/16
 * Original Authors : Taewon Kim, Paul Gross
 *
 **********************************************************************/

#include "include/highlighter.h"

namespace Tools {
Highlighter::Highlighter() {
      mask_ = new mask_data::Mask(15, 5, 0.4f);
      mask_->generateRectangleMask();
}

Highlighter::~Highlighter(void) {
    delete mask_;
}
}  // namespace Tools
