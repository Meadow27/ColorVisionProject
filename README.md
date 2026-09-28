# RGB Contrast Evaluator

## Description

**version 1.0**

This program asks for the RGB of two colors. 
From these input values, it determines whether the contrast between the colors is enough for them to 
be “colorblind safe” based on the difference in the RGB values themselves.

## Developer

Meadow Palomba

## Example

To run the program, give the following commands:

```
g++ --std=c++11 *.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
Two Color Palette Evaluator
Input RGB Values of your first color! 
 R G B
30 80 100
Great choice!
Input RGB Values of your second color! 
 R G B
20 200 20
Great choices! Contrast is adequate. :)
Try another pair? (y/n)

```
