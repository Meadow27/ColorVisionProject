#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;




bool validcolor(int r, int g, int b){
  if(r>255 || g>255 || b>255 || r<0 || g<0 || b<0){
    return false; 
  } 
  else{return true;}
}

string comment(int redVal, int greenVal, int blueVal, string fcolname){
    string colcomment="";
    if(redVal<30 && blueVal<30 && greenVal<30)
        colcomment="This color is " +fcolname+", so your other colors need to be light";
        else if (redVal>210 && blueVal>210 && greenVal>210)
            colcomment="This color is light "+fcolname+", so your other colors need to be dark";
        else if (((abs(redVal-blueVal))+(abs(redVal-greenVal))+(abs(blueVal-greenVal)))<80 && 50<=redVal && redVal<=190)
            colcomment="Your color is "+fcolname+", so your other colors need to very light or very dark";
        else if (redVal>100 && blueVal<50 && greenVal<50)
            colcomment="Your color is "+fcolname+", ensure the other colors in your pallete are not green or yellow";
        else if (redVal<50 && blueVal<50 && greenVal>100)
            colcomment="Your color is "+fcolname+", ensure your pallete does not include red";
        else if (redVal>200 && blueVal>140 && greenVal>140)
            colcomment="Your color is "+fcolname+", eensure your pallete does not include yellow";
        else if (redVal>200 && blueVal<200 && greenVal>150)
            colcomment="Your color is "+ fcolname+ ", ensure your pallete does not include pink or red!";
        else colcomment="Great choice!";
  return colcomment;

}

void contrasteval(vector <int>comparison, ostream& output){
// comp comparison[0-2]=|col1-col2| r0 g1 b2 
// comparison[3-5]=|col1-col3| r3 g4 b5 
// comparison[6-8]=|col2-col3| r6 g7 b8 
    if(comparison[0]<75 && comparison[2]<75 && (comparison[1])<75 )
        output <<" there is not enough contrast between your colors, try picking one dark and one light color!" << endl;
    else if((comparison[0])>=75 && (comparison[2])>=75 && (comparison[1])>=75 ) 
        output << " the contrast is great, good choices! :)" << endl;
    else if ((comparison[0])>=75 && (comparison[2])>=75)
        output << " the contrast is adequate, but could be improved.\n Try making one of these colors darker or lighter." << endl;
    else if((comparison[0])>=75 && (comparison[1])>=75 ) 
        output << " the contrast is adequate, but could be improved." << endl;
    else if((comparison[1])>=75 && (comparison[2])>=75 ) 
        output <<" the contrast is adequate, but could be improved." << endl;
    else if((comparison[0]<75 && (comparison[1])<75) || (comparison[0]<75 && comparison[2]<75) || (comparison[2]<75 && (comparison[1])<75)){
        output << " the constrast needs to be improved. Try a different palette!" << endl;
    }
    
}


void colorpickeval(vector <int>comparison, ostream& output){
   //Red Green
    //R>60 G>20 B<120
    if((comparison[0])>=60 && (comparison[1])>=20 && (comparison[2])<=120)
         output << "These colors will be difficult for those with red/green colorblindness!\n Try a different palette or replace a color!" << endl; 
    //Red Yellow
    //R<75 G>60 B<120
    else if((comparison[0])<=75 && (comparison[1])<=60 && (comparison[2])<=120)
         output << "These colors will be difficult for those with red/yellow colorblindness!\n Try a different palette or replace a color!" << endl; 
}

