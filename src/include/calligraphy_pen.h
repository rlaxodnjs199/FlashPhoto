/**********************************************************************
 * Name             : calligraphy_pen.h
 * Project          : BrushWork
 * Description      : CalligraphyPen Header File
 * Copyright        : 2016 CSCI3081W Drossemlmeyer All rights reserved.
 * Creation Date    : 10/12/16
 * Original Authors : Taewon Kim Paul Gross
 *
 **********************************************************************/
#ifndef SRC_INCLUDE_CALLIGRAPHY_PEN_H_
#define SRC_INCLUDE_CALLIGRAPHY_PEN_H_
#include "./tool.h"
namespace  Tools {
class CalligraphyPen:public Tool {
 public:
    CalligraphyPen();
    ~CalligraphyPen();
};
}  // namespace Tools
#endif  // SRC_INCLUDE_CALLIGRAPHY_PEN_H_
