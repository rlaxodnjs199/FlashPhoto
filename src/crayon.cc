/*******************************************************************************
 * Name            : Crayon.cc
 * Project         : BrushWork
 * Description     : Crayon Class Impelementation
 * Copyright       : 2016 CSCI3081W Group Drossemlmeyer All rights reserved.
 * Creation Date   : 10/12/16
 * Original Author : Taewon Kim, Paul Gros
 *
 ******************************************************************************/

#include "include/crayon.h"

namespace Tools {
Crayon::Crayon() {
      mask_ = new mask_data::Mask(4, 4, 1.0f);
      mask_->generateCrayonCircleMask();
}

Crayon::~Crayon(void) {
    delete mask_;
}
}  // namespace Tools
