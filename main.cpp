#include <iostream>
#include <fstream>
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
int RedV3;
int BlueV3;
int GreenV3;
string colorname;
vector<string>colnames;
int color1[3]={0,0,0};
int color2[3]={0,0,0};
int color3[3]={0,0,0};

// struct Colores{
   
// ;
char Tryagain;
char third;
vector<int>comparison1to2;
vector<int>comparison2to3;
vector<int>comparison1to3;

//funct
string comment(int redVal, int greenVal, int blueVal, string fcolname);
void contrasteval(vector <int>comparison, ostream& output);
void colorpickeval(vector <int>comparison, ostream& output);
bool validcolor(int r, int g, int b);
void getcolor(int numcolor);


int main() {
  cout<< "%%%%% Color Palette Evaluator %%%%%" << endl;
  cout << endl;
  ofstream reportWrite;
  reportWrite.open("ColorPaletteReport.txt");
  reportWrite << "Color Palette Evaluation Report\n" << endl;
    do{
      comparison1to2.clear();
      comparison2to3.clear();
      comparison1to3.clear();
      colnames.clear();
      getcolor(1);
      getcolor(2);
      for( int i=0; i<=2; i++){
        comparison1to2.push_back(abs(color1[i]-color2[i]));
      }
      cout<< "Would you like to include a third color? (y/n)" << endl;
      cin>> third;
      if(third=='y' || third=='Y'){   
        getcolor(3);
          for( int i=0; i<=2; i++){
            comparison2to3.push_back(abs(color2[i]-color3[i]));
          }
          for( int i=0; i<=2; i++){
            comparison1to3.push_back(abs(color1[i]-color3[i]));
          }
        }
      cout << "Comparing " << colnames[0] << " and " << colnames[1] <<" for your color palette:";
      contrasteval(comparison1to2, cout);
      colorpickeval(comparison1to2, cout);
      //writeout
        for( int i=0; i<colnames.size(); i++){
          if(i==0){
            reportWrite << colnames[i] << ":"
                        << color1[0] << ", "
                        << color1[1] << ", "
                        << color1[2] << endl;
          }
          else if(i==1){
            reportWrite << colnames[i] << ":"
                        << color2[0] << ", "
                        << color2[1] << ", "
                        << color2[2] << endl;
          }
          else if(i==2){
            reportWrite << colnames[i] << ":"
                        << color3[0] << ", "
                        << color3[1] << ", "
                        << color3[2] << endl;
          }
        }
        reportWrite << colnames[0] << " and " << colnames[1] <<":";
        contrasteval(comparison1to2, reportWrite);
        colorpickeval(comparison1to2, reportWrite);
      if(third=='y' || third=='Y'){
        cout << "For the " << colnames[1] << " and " << colnames[2] <<" in your pallete:";
        contrasteval(comparison2to3, cout);
        colorpickeval(comparison2to3, cout);
        cout << "For a " << colnames[0] << " and " << colnames[2] <<" in your pallete:";
        contrasteval(comparison1to3, cout); 
        colorpickeval(comparison1to3, cout); 

        //writout
        reportWrite << colnames[1] << " and " << colnames[2] <<":";
        contrasteval(comparison2to3, reportWrite);
        colorpickeval(comparison2to3, reportWrite);
        reportWrite << colnames[0] << " and " << colnames[2] <<":";
        contrasteval(comparison1to3, reportWrite);
        colorpickeval(comparison1to3, reportWrite);
        }
      cout<< "Try another set? (y/n)" << endl;
      cin>>Tryagain;
    }
    while(Tryagain=='y'|| Tryagain=='Y');
  reportWrite.close();

  cout<<"Your palette evaluations can be found in the ColorPaletteReport.txt file for download! \n";
  cout<<"Goodbye!";
  return 0;
    

}

void getcolor(int numcolor){
    if(numcolor==1){
      cout << "What is the name of the first color?" << endl;
      getline(cin >> ws, colorname);
      colnames.push_back(colorname);
      cout<< "Input RGB Values of the " << colnames[0] <<" you would like to use! \n R G B" << endl;
      cin>>RedV1>>GreenV1>>BlueV1;
      if(validcolor(RedV1, GreenV1, BlueV1)){
        color1[0]=RedV1;
        color1[1]=GreenV1;
        color1[2]=BlueV1;
        cout << comment(color1[0], color1[1], color1[2], colnames[0]);
        cout << endl;
      }
      else{
        cout << "Invalid color entered. Try again.\n";
        colnames.pop_back();
        getcolor(1);
      }
      
    }
    else if(numcolor==2){
      cout << "What is the name of the second color in your palette? \n";
      getline(cin >> ws, colorname);
      colnames.push_back(colorname);
      cout<< "Input RGB Values of the " << colnames[1] <<" you would like to use! \n R G B" << endl;
      cin>>RedV2>> GreenV2 >>BlueV2;
      if(validcolor(RedV2, GreenV2, BlueV2)){
          color2[0]=RedV2;
          color2[1]=GreenV2;
          color2[2]=BlueV2;
          cout << comment(color2[0], color2[1], color2[2], colnames[1]);
          cout << endl;
        }
        else{
          cout << "Invalid color entered. Try again.\n";
          colnames.pop_back();
          getcolor(2);
        }    
      }
      else if(numcolor==3){
        cout << "What is the name of the third color? \n";
        getline(cin >> ws, colorname);
        colnames.push_back(colorname);
        cout<< "Input RGB Values of the " << colnames[2] <<" you would like to use! \n R G B" << endl;
        cin>>RedV3>>GreenV3>>BlueV3;
        if(validcolor(RedV3, GreenV3, BlueV3)){
          color3[0]=RedV3;
          color3[1]=GreenV3;
          color3[2]=BlueV3;
        }
        else{
          cout << "Invalid color entered. Try again.\n";
          colnames.pop_back();
          getcolor(3);
        }    
        }
}
