// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				main.cpp
// Last Modification Date:	    10/10/2023
// Author1 and ID and Group:	Gad Amr - 20220095 - N/A
// Author2 and ID and Group:	Bavly Safwat - 20220081 - N/A
// Author3 and ID and Group:	Osama Mohamed - 20220055 - N/A
// Teaching Assistant:		    N/A
// Purpose:                     Assignment 1 Image Processor


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
    while (loadImage(image))
    {
        NumberOFimages--;
    }
    doSomethingForImage();
    saveImage();
    return 0;
}

//_________________________________________
void Menu()
{
    cout << "1 Black & White Filter\n"
            "2 Invert Filter\n"
            "3 Merge Filter \n"
            "4 Flip Image\n"
            "5 Rotate Image\n"
            "6 Darken and Lighten Image\n"
            "7 Shrink Image\n";
}
bool loadImage(unsigned char Simage[][SIZE])
{
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
void saveImage()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}
//_________________________________________
void doSomethingForImage()
{
    int choose = 1;
    bool flag = true;
    while (choose != 0)
    {
        cout << "Please select a filter to apply or 0 to exit:\n";
        Menu();
        cin >> choose;
        if (choose == 1)
        {
            BlackandWhiteFilter();
            flag = true;
        }
        if (choose == 2)
        {
            InvertFilter();
            flag = true;
        }
        if (choose == 3)
        {
            flag = MergeFilter();

        }
        if (choose == 4)
        {
            flag = FlipImage();
        }
        if (choose == 5)
        {
            flag = RotateImage();
        }
        if (choose == 6)
        {
            flag = Darken_and_Lighten_Image();
        }
        if (flag)
            showGSBMP(image);
    }
}
//_________________________________________
void BlackandWhiteFilter()
{
    for (int i = 0 ; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // Check every pixel if it is above the average is turned to white(255) and else it turned to black(0)
            if (image[i][j] > 127)
            {
                image[i][j] = 255;
            }
            else
            {
                image[i][j] = 0;
            }
        }
    }
}
void InvertFilter()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            // Every black pixel turned to white
            if (image[i][j] == 255)
            {
                image[i][j] = 0;
            }
            // Every white pixel turned to black
            else if (image[i][j] == 0)
            {
                image[i][j] = 255;
            }
            // Every gray pixel is turned to opposite level of brightness (255 – pixel value)
            else
            {
                image[i][j] = 255 - image[i][j];
            }
        }
    }
}
bool MergeFilter()
{
    // Make a number of tries to avoid mistakes
    int t = 3;
    while (loadImage(image2))
    {
        NumberOFimages--;
        // Tell you number of tries left
        cout << "You Have "+ to_string(--t)+" Chance to Add Imags\n";
        if (t == 0){
            return false;
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            // Every pixel equal the average gray level of the corresponding pixels in the images to merge
            image[i][j] = (image[i][j] + image2[i][j])/2;
        }
    }
    return true;
}
bool FlipImage()
{
    cout << "Flip (h)orizontally or (v)ertically  ? 0 to cancel\n";
    char c ;
    cin>>c;
    if (c=='0')
    {
        return false;
    }
    if (toupper(c) == 'H')
    {
        for (int i = 0 ; i < SIZE; i++)
        {
            for (int j = 0 ; j< SIZE/2; j++)
            {
                // Swap every pixel corresponding pixel horizontally
                swap(image[i][j] ,image[i][SIZE-1-j]);
            }
        }
    }
    else
    {
        for (int i = 0 ; i < SIZE/2; i++)
        {
            for (int j = 0 ; j< SIZE; j++)
            {
                // Swap every pixel corresponding pixel vertically
                swap(image[i][j] ,image[SIZE-1-i][j]);
            }
        }
    }
    return true;
}
bool RotateImage()
{
    cout << "Rotate (90), (180) or (270) degrees ? 0 to cancel\n";
    int d;cin>>d;
    // To know how many 90s in the actual degree
    d/=90;
    if (d==0)
    {
        return false;
    }
    // Rotate image 90 degrees for (d) times
    while (d--)
    {
        for(int i = 0 ; i < SIZE ; i++)
        {
            for(int j = 0 ; j < SIZE ; j++)
            {
                // Take a copy from current image to flip it 90 degrees
                image2[i][j] = image[i][j];
            }
        }
        for(int i = 0 ; i < SIZE ; i++)
        {
            for(int j = 0 ; j < SIZE ; j++)
            {
                // Make the last column to be the last row and so on
                image[i][j] = image2[SIZE-1-j][i];
            }
        }
    }
    return true;
}
bool Darken_and_Lighten_Image()
{
    cout << "Do you want to (d)arken or (l)ighten? 0 to cancel\n";
    char c ;
    cin>>c;
    if (c =='0')
    {
        return false;
    }
    if (toupper(c)=='D')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                // Merge it with a black image
                image[i][j]/= 2;
            }
        }
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                // Merge it with a white image
                image[i][j] +=(255-image[i][j])/ 2;
            }
        }
    }
    return true;
}
