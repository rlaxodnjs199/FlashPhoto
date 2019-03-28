/**********************************************************************
 * Name             : crayon.h
 * Project          : BrushWork
 * Description      : Crayon Class Header File
 * Copyright        : 2016 CSCI3081W Drossemlmeyer All rights reserved.
 * Creation Date    : 10/12/16
 * Original Authors : Taewon Kim Paul Gross
 *
 **********************************************************************/

#ifndef SRC_INCLUDE_CRAYON_H_
#define SRC_INCLUDE_CRAYON_H_

#include "./tool.h"
namespace  Tools {
class Crayon:public Tool {
 public:
    Crayon();
    virtual ~Crayon();
};
}  // namespace Tools
#endif  // SRC_INCLUDE_CRAYON_H_
