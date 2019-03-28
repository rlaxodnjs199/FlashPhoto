/**********************************************************************
 * Name             : brushwork_app.cc
 * Project          : BrushWork
 * Module           : App
 * Description      : Implementation of BrushWrok
 * Copyright        : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date    : 2/15/15
 * Original Author  : Seth Johnson
 * Revising Authors : Taewon Kim, Paul Gross, Zeyuan Xue, Thomas Homan
 *
 **********************************************************************/

/**********************************************************************
 * Includes
 **********************************************************************/
#include "include/brushwork_app.h"
#include <cmath>
#include <iostream>
#include "include/color_data.h"
#include "include/pixel_buffer.h"


/**********************************************************************
 * Namespaces
 **********************************************************************/
namespace image_tools {

/**********************************************************************
 * Constructors/Destructors
 **********************************************************************/
BrushWorkApp::BrushWorkApp(int width,
                           int height)
    : BaseGfxApp(width,
                 height),
      display_buffer_(nullptr),
      cur_tool_(0.0),
      cur_color_red_(0.0),
      cur_color_green_(0.0),
      cur_color_blue_(0.0),
      pre_x_(0.0),
      pre_y_(0.0),
      spinner_r_(nullptr),
      spinner_g_(nullptr),
      spinner_b_(nullptr) {}

BrushWorkApp::~BrushWorkApp(void) {
    if (display_buffer_) {
        delete display_buffer_;
    }
    if (tool_array_) {
        delete tool_array_;
    }
    if (cur_color_) {
      delete cur_color_;
    }
}

/**********************************************************************
 * Member Functions
 **********************************************************************/
void BrushWorkApp::Init(
    int argc,
    char* argv[],
    int x,
    int y,
    ColorData background_color) {

    BaseGfxApp::Init(argc, argv,
                     x, y,
                     GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH,
                     true,
                     width()+51,
                     50);

    // Set the name of the window
    set_caption("BrushWork");

    // Initialize Interface
    InitializeBuffers(background_color, width(), height());

    InitGlui();
    InitGraphics();
    InitTools();
    cur_color_ = new ColorData(cur_color_red_,
                               cur_color_green_,
                               cur_color_blue_);
}

void BrushWorkApp::Display(void) {
    DrawPixels(0, 0, width(), height(), display_buffer_->data());
}

void BrushWorkApp::MouseDragged(int x, int y) {
    cur_color_->red(cur_color_red_);
    cur_color_->green(cur_color_green_);
    cur_color_->blue(cur_color_blue_);
    int x_diff = x - pre_x_;
    int y_diff = y - pre_y_;
    double magnitude = sqrt(pow(x_diff, 2) + pow(y_diff, 2));
    if (magnitude / tool_array_[cur_tool_].getMaskWidth() >= 1) {
        FillInTheEmptySpot(x, y);
    }
    tool_array_[cur_tool_].applyMask(x, y, display_buffer_, *cur_color_);
    pre_x_ = x;
    pre_y_ = y;
}
void BrushWorkApp::FillInTheEmptySpot(int x, int y) {
    int x_diff = x - pre_x_;
    int y_diff = y - pre_y_;
    double temp_x;
    double temp_y;
    double slope;
    int i;
    double magnitude = sqrt(pow(x_diff, 2) + pow(y_diff, 2));
    double iterations = 2*magnitude / tool_array_[cur_tool_].getMaskWidth();
    double b;
    if (pre_x_ != x) {
        slope = static_cast<double>(y_diff) / static_cast<double>(x_diff);
        b = y - slope * x;
        for (i = 1; i <= iterations; i++) {
            temp_x = pre_x_ + i * (x_diff / iterations);
            temp_y = slope * temp_x + b;
            tool_array_[cur_tool_].applyMask(temp_x,
                                             temp_y,
                                             display_buffer_,
                                             *cur_color_);
        }

    // Special Case for when Slope is Undefined
    } else {
        for (i = 1; i <= iterations; i++) {
            temp_y = pre_y_ + i * (y_diff / iterations);
            tool_array_[cur_tool_].applyMask(x,
                                             temp_y,
                                             display_buffer_,
                                             *cur_color_);
        }
    }
}
void BrushWorkApp::MouseMoved(int x, int y) {
}
void BrushWorkApp::LeftMouseDown(int x, int y) {
    std::cout << "mousePressed " << x << " " << y << std::endl;
    cur_color_->red(cur_color_red_);
    cur_color_->green(cur_color_green_);
    cur_color_->blue(cur_color_blue_);
    pre_x_ = x;
    pre_y_ = y;
    tool_array_[cur_tool_].applyMask(x, y, display_buffer_, *cur_color_);
}

void BrushWorkApp::LeftMouseUp(int x, int y) {
    std::cout << "mouseReleased " << x << " " << y << std::endl;
}

void BrushWorkApp::InitializeBuffers(
    ColorData background_color,
    int width,
    int height) {
    display_buffer_ = new PixelBuffer(width, height, background_color);
}

void BrushWorkApp::InitGlui(void) {
    // Select first tool (this activates the first radio button in glui)
    cur_tool_ = 0;

    GLUI_Panel *tool_panel = new GLUI_Panel(glui(), "Tool Type");
    GLUI_RadioGroup *radio = new GLUI_RadioGroup(tool_panel,
                                                 &cur_tool_,
                                                 UI_TOOLTYPE,
                                                 s_gluicallback);

    // Create interface buttons for different tools:
    new GLUI_RadioButton(radio, "Pen");
    new GLUI_RadioButton(radio, "Eraser");
    new GLUI_RadioButton(radio, "Spray Can");
    new GLUI_RadioButton(radio, "Caligraphy Pen");
    new GLUI_RadioButton(radio, "Highlighter");
  new GLUI_RadioButton(radio, "Crayon");

    GLUI_Panel *color_panel = new GLUI_Panel(glui(), "Tool Color");

    cur_color_red_ = 0;
    spinner_r_  = new GLUI_Spinner(color_panel, "Red:", &cur_color_red_,
                                   UI_COLOR_R, s_gluicallback);
    spinner_r_->set_float_limits(0, 1.0);

    cur_color_green_ = 0;
    spinner_g_ = new GLUI_Spinner(color_panel, "Green:", &cur_color_green_,
                                   UI_COLOR_G, s_gluicallback);
    spinner_g_->set_float_limits(0, 1.0);

    cur_color_blue_ = 0;
    spinner_b_  = new GLUI_Spinner(color_panel, "Blue:", &cur_color_blue_,
                                   UI_COLOR_B, s_gluicallback);
    spinner_b_->set_float_limits(0, 1.0);
    new GLUI_Button(color_panel, "Red", UI_PRESET_RED, s_gluicallback);
    new GLUI_Button(color_panel, "Orange", UI_PRESET_ORANGE, s_gluicallback);
    new GLUI_Button(color_panel, "Yellow", UI_PRESET_YELLOW, s_gluicallback);
    new GLUI_Button(color_panel, "Green", UI_PRESET_GREEN, s_gluicallback);
    new GLUI_Button(color_panel, "Blue", UI_PRESET_BLUE, s_gluicallback);
    new GLUI_Button(color_panel, "Purple", UI_PRESET_PURPLE, s_gluicallback);
    new GLUI_Button(color_panel, "White", UI_PRESET_WHITE, s_gluicallback);
    new GLUI_Button(color_panel, "Black", UI_PRESET_BLACK, s_gluicallback);


    new GLUI_Button(glui(), "Quit", UI_QUIT, static_cast<GLUI_Update_CB>(exit));
}


void BrushWorkApp::InitGraphics(void) {
    // Initialize OpenGL for 2D graphics as used in the BrushWork app
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0, width(), 0, height());
    glViewport(0, 0, width(), height());
}

void BrushWorkApp::GluiControl(int control_id) {
    switch (control_id) {
    case UI_PRESET_RED:
        cur_color_red_ = 1;
        cur_color_green_ = 0;
        cur_color_blue_ = 0;
        break;
    case UI_PRESET_ORANGE:
        cur_color_red_ = 1;
        cur_color_green_ = 0.5;
        cur_color_blue_ = 0;
        break;
    case UI_PRESET_YELLOW:
        cur_color_red_ = 1;
        cur_color_green_ = 1;
        cur_color_blue_ = 0;
        break;
    case UI_PRESET_GREEN:
        cur_color_red_ = 0;
        cur_color_green_ = 1;
        cur_color_blue_ = 0;
        break;
    case UI_PRESET_BLUE:
        cur_color_red_ = 0;
        cur_color_green_ = 0;
        cur_color_blue_ = 1;
        break;
    case UI_PRESET_PURPLE:
        cur_color_red_ = 0.5;
        cur_color_green_ = 0;
        cur_color_blue_ = 1;
        break;
    case UI_PRESET_WHITE:
        cur_color_red_ = 1;
        cur_color_green_ = 1;
        cur_color_blue_ = 1;
        break;
    case UI_PRESET_BLACK:
        cur_color_red_ = 0;
        cur_color_green_ = 0;
        cur_color_blue_ = 0;
        break;
    default:
        break;
    }

    spinner_b_->set_float_val(cur_color_blue_);
    spinner_g_->set_float_val(cur_color_green_);
    spinner_r_->set_float_val(cur_color_red_);
}
// intialize array of tools
void BrushWorkApp::InitTools(void) {
    tool_array_ = new Tools::Tool[max_tools];
    new (&tool_array_[0]) Tools::Pen();
    new (&tool_array_[1]) Tools::Eraser();
    new (&tool_array_[2]) Tools::SprayCan();
    new (&tool_array_[3]) Tools::CalligraphyPen();
    new (&tool_array_[4]) Tools::Highlighter();
    new (&tool_array_[5]) Tools::Crayon();
}

}  // namespace image_tools
