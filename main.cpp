
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include <unistd.h>
#include <filesystem>
using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
int NumberOFimages = 1;


bool loadImage(unsigned char Simage[][SIZE]);
void saveImage();
void doSomethingForImage();
void BlackandWhiteFilter();
void InvertFilter();
bool MergeFilter();
bool FlipImage();
bool RotateImage();
bool Darken_and_Lighten_Image();
void Menu();

//_________________________________________

int main()
{
    cout << "Ahlan ya user ya habibi ^^\n";
    while (loadImage(image)) {
        NumberOFimages--;
    }
    doSomethingForImage();
    saveImage();
    //return 0;
}

//_________________________________________
void Menu() {
    cout << "1 Black & White Filter\n"
        "2 Invert Filter\n"
        "3 Merge Filter \n"
        "4 Flip Image\n"
        "5 Rotate Image\n"
        "6 Darken and Lighten Image\n"
        "7 Shrink Image\n";
}
bool loadImage(unsigned char Simage[][SIZE]) {
    string imageFileName;
    // Get gray scale image file name
    cout << "Please enter file name of the image Number " + to_string(NumberOFimages++) + " to process : \n";
    cin >> imageFileName;
    imageFileName = "\\imgs\\" + imageFileName + ".bmp";
    //strcat (imageFileName, ".bmp");
    // Add to it .bmp extension and load image
    char cwd[PATH_MAX];
    return readGSBMP(strcat(getcwd(cwd, sizeof(cwd)), imageFileName.c_str()), Simage);
}
//_________________________________________
void saveImage() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}
//_________________________________________
void doSomethingForImage() {
    int choose = 1;
    bool flag = true;
    while (choose != 0) {
        cout << "Please select a filter to apply or 0 to exit:\n";
        Menu();
        cin >> choose;
        if (choose == 1) {
            BlackandWhiteFilter();
            flag = true;
        } if (choose == 2) {
            InvertFilter();
            flag = true;
        } if (choose == 3) {
            flag = MergeFilter();

        } if (choose == 4) {
            flag = FlipImage();
        } if (choose == 5) {
            flag = RotateImage();
        }if (choose == 6) {
            flag = Darken_and_Lighten_Image();
        }
        if (flag)
            showGSBMP(image);
    }
}
//_________________________________________
void BlackandWhiteFilter() {
    //code will be here
}
void InvertFilter() {
    //code will be here
}
bool MergeFilter(){
  //code will be here  
}
bool FlipImage(){
    //code will be here
}
bool RotateImage(){
    //code will be here
}
bool Darken_and_Lighten_Image(){
    //code will be here
}
