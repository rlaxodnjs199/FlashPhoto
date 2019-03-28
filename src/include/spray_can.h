/**********************************************************************
 * Name             : spray_can.h
 * Project          : BrushWork
 * Description      : SprayCan Class Header File
 * Copyright        : 2016 CSCI3081W Drossemlmeyer All rights reserved.
 * Creation Date    : 10/12/16
 * Original Authors : Taewon Kim Paul Gross
 *
 **********************************************************************/
#ifndef SRC_INCLUDE_SPRAY_CAN_H_
#define SRC_INCLUDE_SPRAY_CAN_H_
#include "./tool.h"
namespace  Tools {
class SprayCan:public Tool {
 public:
    SprayCan();
    virtual ~SprayCan();
};
}  // namespace Tools
#endif  // SRC_INCLUDE_SPRAY_CAN_H_
