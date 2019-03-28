/*******************************************************************************
 * Name            : brushwork_app.h
 * Project         : BrushWork
 * Module          : App
 * Description     : Header file for BrushWork application.
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef SRC_INCLUDE_BRUSHWORK_APP_H_
#define SRC_INCLUDE_BRUSHWORK_APP_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "./base_gfx_app.h"
#include "./color_data.h"
#include "./pixel_buffer.h"
#include "./tool.h"
#include "./pen.h"
#include "./spray_can.h"
#include "./highlighter.h"
#include "./eraser.h"
#include "./calligraphy_pen.h"
#include "./crayon.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for BrushWork.
 * It is a graphics app that derives from BaseGfxApp. It creates two graphics
 * windows, one for 2D painting and one for the buttons and other UI widgets to
 * control the brushes.
 **/
class BrushWorkApp : public BaseGfxApp {
 public:
    BrushWorkApp(
        int width,
        int height);

    virtual ~BrushWorkApp(void);

    void MouseDragged(int x, int y);
    void FillInTheEmptySpot(int x, int y);
    void MouseMoved(int x, int y);
    void LeftMouseDown(int x, int y);
    void LeftMouseUp(int x, int y);
    void Display(void);
    void GluiControl(int control_id);

    virtual void Init(
        int argc,
        char* argv[],
        int x,
        int y,
        ColorData background_color);

 private:
    void InitGlui(void);
    void InitGraphics(void);
    void InitTools(void);

    /**
     * @brief Initialize the buffers for the main window
     */
    void InitializeBuffers(ColorData initial_color,
                           int width, int height);

    /**
     * @brief Set of values used to differentiate between what radio buttons is
     * pressed by the user.
     */
    enum UIControlType {
        UI_TOOLTYPE,
        UI_COLOR_R,
        UI_COLOR_G,
        UI_COLOR_B,
        UI_PRESET_RED,
        UI_PRESET_ORANGE,
        UI_PRESET_YELLOW,
        UI_PRESET_GREEN,
        UI_PRESET_BLUE,
        UI_PRESET_PURPLE,
        UI_PRESET_WHITE,
        UI_PRESET_BLACK,
        UI_QUIT
    };

    /** Pointer to pixel data for the screen */
    PixelBuffer *display_buffer_;

    int cur_tool_; /**< Currently selected tool from UI  */
    float cur_color_red_;
    float cur_color_green_;
    float cur_color_blue_;
    int pre_x_; /**< x variable to store previous mouse x position */
    int pre_y_; /**< y variable to store previous mouse y position */
    ColorData *cur_color_;
    
    int max_tools = 6; /**< the maximum number of tools */ 
    Tools::Tool * tool_array_ = NULL; /**< Array for holding tools */

    GLUI_Spinner *spinner_r_; /**< Hook for accessing the UI red amount  */
    GLUI_Spinner *spinner_g_; /**< Hook for accessing the UI green amount  */
    GLUI_Spinner *spinner_b_; /**< Hook for accessing the UI blue amount  */

    /* Copy/move assignment/construction disallowed */
    BrushWorkApp(const BrushWorkApp &rhs) = delete;
    BrushWorkApp& operator=(const BrushWorkApp &rhs) = delete;
};
}  // namespace image_tools

#endif  // SRC_INCLUDE_BRUSHWORK_APP_H_
