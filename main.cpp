#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//Variables
int RedV1;
int BlueV1;
int GreenV1;

int RedV2;
int BlueV2;
int GreenV2;

char Tryagain;

int main() {
    cout<< "Two Color Palette Evaluator" << endl;
    do{
    cout<< "Input RGB Values of your first color! \n R G B" << endl;
    cin>>RedV1>>GreenV1>>BlueV1;

    if(RedV1<30 && BlueV1<30 && GreenV1<30)
        cout<< "Your first color is black, so your second color needs to be light!" << endl;
        else if (RedV1>210 && BlueV1>210 && GreenV1>210)
            cout<< "Your first color is white or grey, so your second color needs to be dark!" << endl;
        else if (((abs(RedV1-BlueV1))+(abs(RedV1-GreenV1))+(abs(BlueV1-GreenV1)))<80 && 50<=RedV1 && RedV1<=190)
            cout<< "Your first color is grey, so your second color needs to very light or very dark!" << endl;
        else if (RedV1>100 && BlueV1<50 && GreenV1<50)
            cout<< "Your first color is red, ensure your second color is not green or yellow!" << endl;
        else if (RedV1<50 && BlueV1<50 && GreenV1>100)
            cout<< "Your first color is green, ensure your second color is not red!" << endl;
                    //double check on colorblind pickers for other types of easy mistake colors
        else if (RedV1>200 && BlueV1>140 && GreenV1>140)
            cout<< "Your first color is pink, ensure your second color is not yellow!" << endl;
        else if (RedV1>200 && BlueV1<200 && GreenV1>150)
            cout<< "Your first color is yellow, ensure your second color is not pink or red!" << endl;
            else cout<< "Great choice!" <<endl;
    
    cout<< "Input RGB Values of your second color! \n R G B" << endl;
    cin>>RedV2>> GreenV2 >>BlueV2;

    if((abs(RedV1-RedV2))<75 && (abs(BlueV1-BlueV2))<75 && (abs(GreenV1-GreenV2))<75 )
        cout<< "There is not enough contrast between your colors, try picking one dark and one light color!" << endl;
    else if((abs(RedV1-RedV2))>=75 && (abs(BlueV1-BlueV2))>=75 && (abs(GreenV1-GreenV2))>=75 ) 
        cout<< "Great choices! Contrast is great. :)" << endl;
    //Red Green
    else if((abs(RedV1-RedV2))>=100 && (abs(BlueV1-BlueV2))<=100 && (abs(GreenV1-GreenV2))>=100)
         cout<< "These colors will be difficult for those with red/green colorblindness! Try a different pair" << endl; 
    else if((abs(RedV1-RedV2))>=100 && (abs(BlueV1-BlueV2))<=100 && (abs(GreenV1-GreenV2))<=100)
         cout<< "These colors will be difficult for those with red/green colorblindness! Try a different pair" << endl;
    //Red Yellow
    else if(((RedV1>100 && BlueV1<50 && GreenV1<50)||(RedV1>200 && BlueV1<200 && GreenV1>150))&&((RedV2>100 && BlueV2<50 && GreenV2<50)||(RedV2>200 && BlueV2<200 && GreenV2>150)))
        cout<< "These colors will be difficult for those with red/yellow colorblindness! Try a different pair" <<endl;
    else if((abs(GreenV1-GreenV2))<100 && (abs(BlueV1-BlueV2))<150 && (RedV1<80 || RedV2<80))
        cout<< "These colors will be difficult for those with red/yellow colorblindness! Try a different pair" <<endl;
    else if ((abs(RedV1-RedV2))>=75 && (abs(BlueV1-BlueV2))>=75)
        cout<< "Great choices! Contrast is adequate. :)" << endl;
    else if((abs(RedV1-RedV2))>=75 && (abs(GreenV1-GreenV2))>=75 ) 
        cout<< "Great choices! Contrast is adequate. :)" << endl;
    else if((abs(GreenV1-GreenV2))>=75 && (abs(BlueV1-BlueV2))>=75 ) 
        cout<< "Great choices! Contrast is adequate. :)" << endl;
    
    else cout<< "Combination cannot be evaluated, record values and integrate!" ;
    cout<< "Try another pair? (y/n)" << endl;
    cin>>Tryagain;}
    while(Tryagain=='y');

    cout<<"Goodbye!";
    return 0;
    

}