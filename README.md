# RGB Contrast Evaluator

## Description

**version 2.0**

This program asks for the RGB values of 2-3 colors in a color palette. 
From these input values, it determines whether the contrast between the colors is enough for them to 
be “colorblind safe” based on the difference in the RGB values themselves. It will also comment
if your colors are not red/green or red/yellow colorblind safe. 
It will commit your inputs and the feedback to a .txt file

## Developer

Meadow Palomba

## Example

Here is an example of the program running:

```
%%%%% Color Palette Evaluator %%%%%

What is the name of the first color?
Blue
Input RGB Values of the Blue you would like to use! 
 R G B
0 20 200
Great choice!
What is the name of the second color in your palette? 
Red
Input RGB Values of the Red you would like to use! 
 R G B
400 0 0 
Invalid color entered. Try again.
What is the name of the second color in your palette? 
Red
Input RGB Values of the Red you would like to use! 
 R G B
200 0 0
Your color is Red, ensure the other colors in your pallete are not green or yellow
Would you like to include a third color? (y/n)
n
Comparing Blue and Red for your color palette: the contrast is adequate, but could be improved.
 Try making one of these colors darker or lighter.
Try another set? (y/n)
n
Your palette evaluations can be found in the ColorPaletteReport.txt file for download! 
Goodbye!

```
