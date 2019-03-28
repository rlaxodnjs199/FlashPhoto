# Design Justifications for BrushWork
#### Group Name:
<Drosselmeyer>

#### Members:
- Paul Gross
- Thomas Homan
- Zeyuan Xue
- Taewon Kim

#### Instructions 
> Respond to each of the design questions below.  Make your answers factual and compelling.  Where appropriate, reference alternative designs you considered, code snippets, and diagrams within your writing in order to be clear and back up your claims.  As we have discussed in class, when writing with reference to figures make sure to tell the reader what to look for in the diagram or what exactly you want the reader to notice in the code snippet.  Remember that the design of your project is worth 1/3 of the total project grade.  Also remember that when grading the design portion of the project, this design justification document is the only thing we will look at.  This document must stand on its own.  Rather than linking to your actual code, carefully pick the most important code snippets from your project to include here in order to provide convincing detail for your answers to the questions below.


## 1  Design Question One
> This iteration of the project is all about tools. Naturally, a key design decision is how these tools are represented. Each tool has several characteristics, including the shape of the tool, its size, and the way it blends with the canvas when the tool is applied. Some tools share characteristics with other tools, such as how the pen and calligraphy pen tools blend with the canvas in the same manner. 
> First, in the **Design Description** section below, describe the design you developed to address this challenge. We expect that you will include at least one figure showing the relationships of the classes affected by your design. Second, in the **Design Justification** section below present the most compelling argument you can for why this design is justified.  Note that our expectation is that you will need to discuss the pros (and maybe cons) of your final design as compared to alternative designs that you discussed in your group in order to make a strong case for justifying your design.

### 1.1 Design Description

### 1.2 Design Justification


## 2  Design Question Two
> Unlike most of the tools, the Eraser returns the canvas to its original color. One of the challenges in this iteration is giving the eraser the authority or information required to have this effect while having minimal impact on the way the rest of the tools are defined. 
> First, in the **Design Description** section below, describe the design you developed to address this challenge.  Second, in the **Design Justification** section below present the most compelling argument you can for why this design is justified.  Note that our expectation is that you will need to discuss the pros (and maybe cons) of your final design as compared to alternative designs that you discussed in your group in order to make a strong case for justifying your design.

### 2.1 Design Description
 To avoid defining Eraser as a special case, we decided to create 'mask' class, which has mask constructors for all the tools, and 'tool' class, which has virtual 'applyMask' member function that enables all the tool classes to draw pixels. Since 'applyMask' function has PixelBuffer variable, which includes all the information of canvas, we can access 'background_color' variable without any extra concerns.
### 2.2 Design Justification
 In the Eraser class, 'applyMask' function is overwritten. However, this is slightly different from recognizing it as a special case. What we consider in designing 'applyMask' is that like other tools, the Eraser is not removing colors, instead drawing canvas with background color of it. Since we have to include 'PixelBuffer' variable in 'applyMask' to check the size of the canvas, and draw pixels only when the mouse is on the canvas, we already have 'background_color' variable from it. What we have to do for Eraser is just accessing to 'background_color' first and call applyMask(x, y, buffer, background_color), unlike other tools which have no need to reach 'background_color'.
 This implementation is handy comparing to the other designs such as all the tools have their own draw functions. The reason is because we don't need to! All the tools draw pixels in same mechanism, and even for Eraser, we can implement that without using extra parameter as discussed before. Therefore, other tool classes can depend on 'applyMask' function on 'Tool' class without having it, and it possibly makes easier to add other tools later.

## 3  Design Question Three
> A new developer on your team must add a new tool to BrushWork. This tool is called  _Pencil._ This tool is a single, non-transparent pixel that completely replaces the existing colors on the canvas in the same way as the pen or calligraphy pen blend.  
> Describe in the form of a tutorial (including code snippets) exactly what changes would need to be made to your program in order to fully integrate this new tool.

### Programming Tutorial: Adding a New Pencil Tool to BrushWork

1. <Step 1>
2. <Step 2>
<etc>
