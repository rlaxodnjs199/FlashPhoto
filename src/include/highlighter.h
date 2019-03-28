/**********************************************************************
 * Name             : highlighter.h
 * Project          : BrushWork
 * Description      : Highlighter Class Header File
 * Copyright        : 2016 CSCI3081W Drossemlmeyer All rights reserved.
 * Creation Date    : 10/12/16
 * Original Authors : Taewon Kim Paul Gross
 *
 **********************************************************************/
#ifndef SRC_INCLUDE_HIGHLIGHTER_H_
#define SRC_INCLUDE_HIGHLIGHTER_H_
#include "./tool.h"

namespace  Tools {
class Highlighter:public Tool {
 public:
     Highlighter();
     virtual ~Highlighter();
};
}  // namespace Tools
#endif  // SRC_INCLUDE_HIGHLIGHTER_H_
