// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				main.cpp
// Last Modification Date:	    10/10/2023
// Author1 and ID and Group:	Gad Amr - 20220095 - N/A
// Author2 and ID and Group:	Bavly Safwat - 20220081 - N/A
// Author3 and ID and Group:	Osama Mohamed - 20220055 - N/A
// Teaching Assistant:		    N/A
// Purpose:                     Assignment 1 Image Processor (First 6 Filters)


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
bool DetectImageEdges();
bool EnlargeImage();
bool ShrinkImage();
bool MirrorImage();
bool ShuffleImage();
bool BlurImage();
bool CropImage();
bool SkewImageRight();
bool SkewImageUp();

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

    return 0;
}

//_________________________________________
void systempause(){
    cout << "\nEnter any Key to continue ";
    system("pause>0");
}
void Menu()
{
    cout << "01 Black & White Filter\n"
            "02 Invert Filter\n"
            "03 Merge Filter \n"
            "04 Flip Image\n"
            "05 Rotate Image\n"
            "06 Darken and Lighten Image\n"
            "07 Detect Image Edges \n"
            "08 Enlarge Image\n"
            "09 Shrink Image\n"
            "10 Mirror 1/2 Image\n"
            "11 Shuffle Image\n"
            "12 Blur Image\n"
            "13 Crop Image\n"
            "14 Skew Image Right  \n"
            "15 Skew Image Up \n"
            "s -Save image \n"
            "0  Exit \n";
}
bool loadImage(unsigned char Simage[][SIZE])
{
    string imageFileName;
    // Get gray scale image file name
    cout << "Please enter file name of the image Number " + to_string(NumberOFimages++) + " to process : without (.exp) \n";
    cin >> imageFileName;

    imageFileName = "\\imgs\\" + imageFileName + ".bmp";
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
    string choose = "1";
    bool flag = true;
    while (choose != "0")
    {
        cout << "Please select a filter to apply or 0 to exit:\n";
        Menu();
        cin >> choose;
        if (choose == "1")
        {
            BlackandWhiteFilter();
            flag = true;
        }
        else if (choose == "2")
        {
            InvertFilter();
            flag = true;
        }
        else if (choose == "3")
        {
            flag = MergeFilter();

        }
        else if (choose == "4")
        {
            flag = FlipImage();
        }
        else if (choose == "5")
        {
            flag = RotateImage();
        }
        else if (choose == "6")
        {
            flag = Darken_and_Lighten_Image();
        }
        else if (choose == "7")
        {
            flag = DetectImageEdges();
        }
       else if (choose == "8")
        {
            EnlargeImage();
            flag = false;
        }
        else if (choose == "9")
        {
            flag = ShrinkImage();
        }
        else if (choose == "10")
        {
            flag = MirrorImage();
        }
        else if (choose == "11")
        {
            ShuffleImage();
            flag = false;
        }
        else if (choose == "12")
        {
            flag = BlurImage();
        }
        else if (choose == "13")
        {
            flag = CropImage();
        }
        else if (choose == "14")
        {
            SkewImageRight();
            flag = false;
        }
        else if (choose == "15")
        {
            flag = SkewImageUp();
        }
        else if (tolower(choose[0]) == 's')
        {
            saveImage();
            flag = false;
        }
        else if (choose == "0")
        {
            cout << "\n Thank You ^^\n";
            flag = false;
        }

        else
        {
            cout << "\tPlease Enter Number in Range or Save Image\n";
            systempause();
            flag = false;
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
            
          // Every white pixel turned to black
            if (image[i][j] == 255)
            {
                image[i][j] = 0;
            }
            // Every black pixel turned to white
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
bool DetectImageEdges()
{
    int Difference = 30;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            // If the neighbors differ in value by (dif), then it is an edge
            if(abs(image[i][j]-image[i][j+1]) > Difference || abs(image[i][j]-image[i+1][j]) > Difference) image[i][j] = 0;
            else image[i][j] = 255;
        }
    }
    return true;
}
bool EnlargeImage()
{
// code will be Here
    cout << "\n\tAccess Denied,This feature will be available soon \n";
    systempause();
}
bool ShrinkImage()
{
    cout << "Shrink to 1/2, 1/3 or 1/4 ? [1,2,3] 0 to cancel\n";
    int c ;cin>>c;
    if (c == 0){
        return false;
    }
    c++;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i/c][j/c] = image[i][j]; // Shrink Image With New Base
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if ((i<(SIZE/c) && j >= (SIZE/c)) || (i>=(SIZE/c) && j < (SIZE/c)) ||(i>=(SIZE/c) && j >= (SIZE/c))  )
            {
                image[i][j] = 255 ;  // Make another Part of Current image White
            }
        }
    }
    return true;

}
bool MirrorImage()
{
    cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side?: ";
    char direction; cin >> direction;
    if(toupper(direction) == 'L'){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE/2; j++) {
                image[i][SIZE-1-j] =image[i][j] ;
            }
        }
    }
    else if(toupper(direction) == 'R'){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE/2; j++) {
                image[i][j] =image[i][SIZE-1-j];
            }
        }
    }
    else if(toupper(direction) == 'U'){
        for (int i = 0; i < SIZE/2; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[SIZE-1-i][j] =image[i][j] ;
            }
        }
    }
    else if(toupper(direction) == 'D'){
        for (int i = 0; i < SIZE/2; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] =image[SIZE-1-i][j];
            }
        }
    }
}
bool ShuffleImage()
{
// code will be Here
    cout << "\n\tAccess Denied,This feature will be available soon \n";
    systempause();
}
bool BlurImage()
{
// Initialize two direction arrayes for x and y to get all neighbors
    int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
    int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
    for (int t = 0; t < 4; ++t)
    {
        for (int i = 0; i < SIZE ; ++i)
        {
            for (int j = 0; j < SIZE ; ++j)
            {
                int Average = 0, cnt = 0;
                for (int k = 0; k < 8; ++k)
                {
                    // Find all its neighbors
                    int nx = i+dx[k], ny = j+dy[k];
                    // Check if it is valid (in range) or not
                    if(nx >= 0 && ny >= 0 && nx < SIZE && ny < SIZE)
                    {
                        cnt++;
                        Average+=image[nx][ny];
                    }
                }
                Average+=image[i][j];
                cnt++;
                // Get the average of each cell with its neighbors
                Average/=cnt;
                // Assign it to the cell
                image[i][j] = Average;
            }
        }
    }
}
bool CropImage()
{
    cout << "Please enter (x-axis, y-axis) Starting position of the Image and length, width of the square: \n";
    int x,y,l,w;   cin>>x>>y>>l>>w;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image2 [i][j] = image[i][j];    // Take a copy from current image to Process
            image[i][j] =255;               // Make our image white to receive the new skewed image
        }
    }
    for (int i = x; i <= x+l; i++)
    {
        for (int j = y; j <= y+w; j++)
        {
            image[i][j] = image2[i][j];     // Take Every Pixels You Want From Inputs Range To Our Image
        }
    }
    return true;
}
bool SkewImageRight()
{
// code will be Here
    cout << "\n\tAccess Denied,This feature will be available soon \n";
    systempause();
}
bool SkewImageUp()
{
    cout << "Please enter degree to skew Up : \n";
    double rad ;cin>>rad;                   // Take Degree
    rad = ( rad * 22 ) / ( 180 * 7 ) ;      // Convert From Degree to Radiant
    int c = 256 / (1 +  tan(rad)) ;      // Make New Base To Shrink
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image2[i][j] =image[i][j];      // Take a copy from current image to Process
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image2[(i*c)/SIZE][j] =image2[i][j]; // shrink Image With New Base
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if ((i >= c && j <= SIZE))
            {
                image2[i][j] = 255;    // Make another Part of copied image White
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
            image[i][j] = 255;         // Make our image white to receive the new skewed image
        }
    }
    double step = SIZE - c;             // The number of steps required to Skew
    double mov = step / SIZE;           // The number of Move required to subtract from steps in each loop to Skew upward
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[j + (int) step][i] = image2[j][i]; //Make Our Image Skewed Up
        }
        step -= mov;
    }

    return true;
}
bool DetectImageEdges()
{
   // code will be Here
   cout << "\n\tAccess Denied,This feature will be available soon \n";
    systempause();
}
bool EnlargeImage()
{
// code will be Here
    cout << "\n\tAccess Denied,This feature will be available soon \n";
systempause();
}
bool ShrinkImage()
{
    cout << "Shrink to 1/2, 1/3 or 1/4 ? [1,2,3] 0 to cancel\n";
    int c ;cin>>c;
    if (c == 0){
        return false;
    }
    c++;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i/c][j/c] = image[i][j]; // Shrink Image With New Base
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if ((i<(SIZE/c) && j >= (SIZE/c)) || (i>=(SIZE/c) && j < (SIZE/c)) ||(i>=(SIZE/c) && j >= (SIZE/c))  )
            {
                image[i][j] = 255 ;  // Make another Part of Current image White
            }
        }
    }
    return true;

}
bool MirrorImage()
{
// code will be Here
    cout << "\n\tAccess Denied,This feature will be available soon \n";
systempause();
}
bool ShuffleImage()
{
// code will be Here
    cout << "\n\tAccess Denied,This feature will be available soon \n";
systempause();
}
bool BlurImage()
{
// Initialize two direction arrayes for x and y to get all neighbors
    int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
    int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
    for (int t = 0; t < 4; ++t)
    {
        for (int i = 0; i < SIZE ; ++i)
        {
            for (int j = 0; j < SIZE ; ++j)
            {
                int Average = 0, cnt = 0;
                for (int k = 0; k < 8; ++k)
                {
                    // Find all its neighbors
                    int nx = i+dx[k], ny = j+dy[k];
                    // Check if it is valid (in range) or not
                    if(nx >= 0 && ny >= 0 && nx < SIZE && ny < SIZE)
                    {
                        cnt++;
                        Average+=image[nx][ny];
                    }
                }
                Average+=image[i][j];
                cnt++;
                // Get the average of each cell with its neighbors
                Average/=cnt;
                // Assign it to the cell
                image[i][j] = Average;
            }
        }
    }
}
bool CropImage()
{
// code will be Here
    cout << "\n\tAccess Denied,This feature will be available soon \n";
systempause();
}
bool SkewImageRight()
{
// code will be Here
    cout << "\n\tAccess Denied,This feature will be available soon \n";
systempause();
}
bool SkewImageUp()
{
    cout << "Please enter degree to skew Up : \n";
    double rad ;cin>>rad;                   // Take Degree
    rad = ( rad * 22 ) / ( 180 * 7 ) ;      // Convert From Degree to Radiant
    int c = 256 / (1 +  tan(rad)) ;      // Make New Base To Shrink
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image2[i][j] =image[i][j];      // Take a copy from current image to Process
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image2[(i*c)/SIZE][j] =image2[i][j]; // shrink Image With New Base
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if ((i >= c && j <= SIZE))
            {
                image2[i][j] = 255;    // Make another Part of copied image White
            }
            image[i][j] = 255;         // Make our image white to receive the new skewed image
        }
    }
    double step = SIZE - c;             // The number of steps required to Skew
    double mov = step / SIZE;           // The number of Move required to subtract from steps in each loop to Skew upward
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[j + (int) step][i] = image2[j][i]; //Make Our Image Skewed Up
        }
        step -= mov;
    }

    return true;
}
