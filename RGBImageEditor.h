unsigned char RGBimage[SIZE][SIZE][RGB];
unsigned char RGBimage2[SIZE][SIZE][RGB];
int NumberOFRGBimages = 1;

void RunRGBimageEditor();
bool loadRGBimage(unsigned char SRGBimage[][SIZE][RGB]);
void saveRGBimage();
void doSomethingForRGBimage();
void BlackandWhiteFilterRGB();
void InvertFilterRGB();
bool MergeFilterRGB();
bool FlipRGBimage();
bool RotateRGBimage();
bool Darken_and_Lighten_RGBimage();
bool DetectRGBimageEdges();
bool EnlargeRGBimage();
bool ShrinkRGBimage();
bool MirrorRGBimage();
bool ShuffleRGBimage();
bool BlurRGBimage();
bool CropRGBimage();
bool SkewRGBimageRight();
bool SkewRGBimageUp();

void RGBMenu();

//_________________________________________

void RunRGBimageEditor()
{
    while (loadRGBimage(RGBimage))
    {
        NumberOFRGBimages--;
    }

    doSomethingForRGBimage();
    return;
}

//_________________________________________
void system_pause() {
    cout << "\nEnter any Key to continue ";
    system("pause>0");
}
void RGBMenu()
{
    cout << "01 Black & White Filter\n"
            "02 Invert Filter\n"
            "03 Merge Filter \n"
            "04 Flip image\n"
            "05 Rotate image\n"
            "06 Darken and Lighten image\n"
            "07 Detect image Edges \n"
            "08 Enlarge image\n"
            "09 Shrink image\n"
            "10 Mirror 1/2 image\n"
            "11 Shuffle image\n"
            "12 Blur image\n"
            "13 Crop image\n"
            "14 Skew image Right  \n"
            "15 Skew image Up \n"
            "s- Save image \n"
            "0  Exit from Colored Image Editor \n";
}
bool loadRGBimage(unsigned char SRGBimage[][SIZE][RGB])
{
    string RGBimageFileName;
    // Get gray scale RGBimage file name
    cout << "Please enter file name of the image Number " + to_string(NumberOFRGBimages++) + " to process : without (.exp) \n";
    cin >> RGBimageFileName;

    RGBimageFileName = "\\imgs\\" + RGBimageFileName + ".bmp";
    // Add to it .bmp extension and load RGBimage
    char cwd[PATH_MAX];
    return readRGBBMP(strcat(getcwd(cwd, sizeof(cwd)), RGBimageFileName.c_str()), SRGBimage);
}
//_________________________________________
void saveRGBimage()
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
void doSomethingForRGBimage()
{
    string choose = "1";
    bool flag = true;
    while (choose != "0")
    {
        cout << "Please select a filter to apply or 0 to exit:\n";
        RGBMenu();
        cin >> choose;
        if (choose == "1")
        {
            BlackandWhiteFilterRGB();
            flag = true;
        }
        else if (choose == "2")
        {
            InvertFilterRGB();
            flag = true;
        }
        else if (choose == "3")
        {
            flag = MergeFilterRGB();

        }
        else if (choose == "4")
        {
            flag = FlipRGBimage();
        }
        else if (choose == "5")
        {
            flag = RotateRGBimage();
        }
        else if (choose == "6")
        {
            flag = Darken_and_Lighten_RGBimage();
        }
        else if (choose == "7")
        {
            flag = DetectRGBimageEdges();
        }
        else if (choose == "8")
        {
            flag = EnlargeRGBimage();
        }
        else if (choose == "9")
        {
            flag = ShrinkRGBimage();
        }
        else if (choose == "10")
        {
            flag = MirrorRGBimage();
        }
        else if (choose == "11")
        {
            flag = ShuffleRGBimage();
        }
        else if (choose == "12")
        {
            flag = BlurRGBimage();
        }
        else if (choose == "13")
        {
            flag = CropRGBimage();
        }
        else if (choose == "14")
        {
            flag = SkewRGBimageRight();
        }
        else if (choose == "15")
        {
            flag = SkewRGBimageUp();
        }
        else if (tolower(choose[0]) == 's')
        {
            saveRGBimage();
            flag = false;
        }
        else if (choose == "0")
        {
            flag = false;
        }

        else
        {
            cout << "\tPlease Enter Number in Range or Save RGBimage\n";
            system_pause();
            flag = false;
        }

        if (flag)
            showRGBBMP(RGBimage);
    }
}
//_________________________________________
void BlackandWhiteFilterRGB()
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
        {
            // Check every pixel if it is above the average is turned to white(255) and else it turned to black(0)
            if (RGBimage[i][j][0] +RGBimage[i][j][1] +RGBimage[i][j][2] > 127 * 3) {
                RGBimage[i][j][0] = 255;
                RGBimage[i][j][1] = 255;
                RGBimage[i][j][2] = 255;
            } else {
                RGBimage[i][j][0] = 0;
                RGBimage[i][j][1] = 0;
                RGBimage[i][j][2] = 0;
            }

        }
    }
}
void InvertFilterRGB()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; ++k) {


                // Every gray pixel is turned to opposite level of brightness (255 – pixel value)
                RGBimage[i][j][k] = (255 - RGBimage[i][j][k]);
            }
        }
    }
}
bool MergeFilterRGB()
{
    // Make a number of tries to avoid mistakes
    int t = 3;
    while (loadRGBimage(RGBimage2))
    {
        NumberOFRGBimages--;
        // Tell you number of tries left
        cout << "You Have " + to_string(--t) + " Chance to Add Imags\n";
        if (t == 0) {
            return false;
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; ++k) {


                // Every pixel equal the average gray level of the corresponding pixels in the RGBimages to merge
                RGBimage[i][j][k]= (RGBimage[i][j][k] + RGBimage2[i][j][k]) / 2;
            }
        }
    }
    return true;
}
bool FlipRGBimage()
{
    cout << "Flip (h)orizontally or (v)ertically  ? 0 to cancel\n";
    char c;
    cin >> c;
    if (c == '0')
    {
        return false;
    }
    if (toupper(c) == 'H')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE / 2; j++)
            {
                for (int k = 0; k < RGB; ++k) {
                    // Swap every pixel corresponding pixel horizontally
                    swap(RGBimage[i][j][k], RGBimage[i][SIZE - 1 - j][k]);
                }
            }

        }
    }
    else
    {
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = 0; j < SIZE ; j++)
            {
                for (int k = 0; k < RGB; ++k) {
                    // Swap every pixel corresponding pixel horizontally
                    swap(RGBimage[i][j][k], RGBimage[SIZE - 1 - i][j][k]);
                }
            }

        }
    }
    return true;
}
bool RotateRGBimage()
{
    cout << "Rotate (90), (180) or (270) degrees ? 0 to cancel\n";
    int d; cin >> d;
    // To know how many 90s in the actual degree
    d /= 90;
    if (d == 0)
    {
        return false;
    }
    // Rotate RGBimage 90 degrees for (d) times
    while (d--)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; ++k) {

                    // Take a copy from current RGBimage to flip it 90 degrees
                    RGBimage2[i][j][k] = RGBimage[i][j][k];
                }
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; ++k) {

                    // Make the last column to be the last row and so on
                    RGBimage[i][j][k]= RGBimage2[SIZE - 1 - j][i][k];
                }
            }
        }
    }
    return true;
}
bool Darken_and_Lighten_RGBimage()
{
    cout << "Do you want to (d)arken or (l)ighten? 0 to cancel\n";
    char c;
    cin >> c;
    if (c == '0')
    {
        return false;
    }
    if (toupper(c) == 'D')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; ++k) {

                    // Merge it with a black RGBimage
                    RGBimage[i][j][k] /= 2;
                }

            }
        }
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k <RGB ; ++k) {

                    // Merge it with a white RGBimage
                    RGBimage[i][j][k] += (255 - RGBimage[i][j][k]) / 2;
                }
            }
        }
    }
    return true;
}
bool DetectRGBimageEdges()
{
    int Difference = 23;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k) {

                // If the neighbors differ in value by (dif), then it is an edge
                if (abs(RGBimage[i][j][k] - RGBimage[i][j + 1][k]) > Difference || abs(RGBimage[i][j][k] - RGBimage[i + 1][j][k]) > Difference)
                    RGBimage[i][j][k] = 0;
                else RGBimage[i][j][k] = 255;
            }
        }
    }
    BlackandWhiteFilterRGB();
    return true;
}
bool EnlargeRGBimage()
{
    cout << "Which quarter to enlarge 1, 2, 3 or 4?: ";
    int Quarter; cin >> Quarter;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                // Take a copy from RGBimage
                RGBimage2[i][j][k] = RGBimage[i][j][k];

            }
        }
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k) {

                // Make every pixel englare in 4 pixels according to quarter you choose
                if (Quarter == 1)
                {
                    RGBimage[i][j][k] = RGBimage2[i/2][j/2][k];
                }
                else if (Quarter == 2)
                {
                    RGBimage[i][j][k] = RGBimage2[i/2][j/2+(SIZE/2)][k];
                }
                else if (Quarter == 3)
                {
                    RGBimage[i][j][k] = RGBimage2[i/2 +(SIZE/2)][j/2][k];
                }
                else if (Quarter == 4)
                {
                    RGBimage[i][j][k]= RGBimage2[i/2+(SIZE/2)][j/2+(SIZE/2)][k];
                }
            }
        }
    }
    return true;
}
bool ShrinkRGBimage()
{
    cout << "Shrink to 1/2, 1/3 or 1/4 ? [1,2,3] 0 to cancel\n";
    int c; cin >> c;
    if (c == 0) {
        return false;
    }
    c++;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; ++k) {

                RGBimage[i / c][j / c][k] = RGBimage[i][j][k]; // Shrink RGBimage With New Base
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; ++k) {

                if ((i < (SIZE / c) && j >= (SIZE / c)) || (i >= (SIZE / c) && j < (SIZE / c)) || (i >= (SIZE / c) && j >= (SIZE / c)))
                {
                    RGBimage[i][j][k] = 255;  // Make another Part of Current RGBimage White
                }
            }
        }
    }
    return true;

}
bool MirrorRGBimage()
{
    cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side?: ";
    char direction; cin >> direction;
    if (toupper(direction) == 'L') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++)
            {
                for (int k = 0; k < RGB; ++k) {

                    RGBimage[i][SIZE - 1 - j][k]= RGBimage[i][j][k];
                }
            }
        }
    }
    else if (toupper(direction) == 'R') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < RGB; ++k) {

                    RGBimage[i][j][k] = RGBimage[i][SIZE - 1 - j][k];
                }
            }
        }
    }
    else if (toupper(direction) == 'U') {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; ++k) {

                    RGBimage[SIZE - 1 - i][j][k] = RGBimage[i][j][k];
                }
            }
        }
    }
    else if (toupper(direction) == 'D') {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; ++k) {

                    RGBimage[i][j][k] = RGBimage[SIZE - 1 - i][j][k];
                }
            }
        }
    }
    return true;
}
bool ShuffleRGBimage()
{
    cout << "New order of quarters ?: ";
    int order[4];
    for (int i = 0; i < 4; ++i)
    {
        // Take a new order of quarters
        cin >> order[i];
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE ; ++j)
        {
            for (int k = 0; k < RGB; ++k) {
                //Take copy from RGBimage
                RGBimage2[i][j][k] = RGBimage[i][j][k];
            }
        }
    }
    // Change first quarter according to his new order
    for (int i = 0; i < SIZE/2; ++i)
    {
        for (int j = 0; j < SIZE/2; ++j)
        {
            for (int k = 0; k < RGB; ++k) {
                if(order[0] == 2)
                {
                    RGBimage[i][j][k] = RGBimage2[i][j+(SIZE/2)][k];
                }
                else if(order[0] == 3)
                {
                    RGBimage[i][j][k] = RGBimage2[i+(SIZE/2)][j][k];
                }
                else if(order[0] == 4)
                {
                    RGBimage[i][j][k] = RGBimage2[i+(SIZE/2)][j+(SIZE/2)][k];
                }
            }
        }
    }
    // Change second quarter according to his new order
    for (int i = 0; i < SIZE/2; ++i)
    {
        for (int j = SIZE/2 ; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k) {
                if(order[1] == 1)
                {
                    RGBimage[i][j][k]= RGBimage2[i][j-(SIZE/2)][k];
                }
                else if(order[1] == 3)
                {
                    RGBimage[i][j][k]= RGBimage2[i+(SIZE/2)][j-(SIZE/2)][k];
                }
                else if(order[1] == 4)
                {
                    RGBimage[i][j][k]= RGBimage2[i+(SIZE/2)][j][k];
                }
            }
        }
    }
    // Change third quarter according to his new order
    for (int i = SIZE/2; i < SIZE; ++i)
    {
        for (int j = 0 ; j < SIZE/2; ++j)
        {
            for (int k = 0; k < RGB; ++k) {
                if(order[2] == 1)
                {
                    RGBimage[i][j][k] = RGBimage2[i-(SIZE/2)][j][k];
                }
                else if(order[2] == 2)
                {
                    RGBimage[i][j][k] = RGBimage2[i-(SIZE/2)][j+(SIZE/2)][k];
                }
                else if(order[2] == 4)
                {
                    RGBimage[i][j][k] = RGBimage2[i][j+(SIZE/2)][k];
                }
            }
        }
    }
    // Change fourth quarter according to his new order
    for (int i = SIZE/2; i < SIZE; ++i)
    {
        for (int j = SIZE/2 ; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k) {
                if(order[3] == 1)
                {
                    RGBimage[i][j][k] = RGBimage2[i-(SIZE/2)][j-(SIZE/2)][k];
                }
                else if(order[3] == 2)
                {
                    RGBimage[i][j][k]= RGBimage2[i-(SIZE/2)][j][k];
                }
                else if(order[3] == 3)
                {
                    RGBimage[i][j][k] = RGBimage2[i][j-(SIZE/2)][k];
                }
            }
        }
    }
    return true;
}
bool BlurRGBimage()
{
    // Initialize two direction arrayes for x and y to get all neighbors
    int dx[] = { 1, 0, -1, 0, -1, -1, 1, 1 };
    int dy[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
    for (int t = 0; t < 4; ++t)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                for (int k = 0; k <RGB ; ++k) {

                    int Average = 0, cnt = 0;
                    for (int p = 0; p < 8; ++p)
                    {
                        // Find all its neighbors
                        int nx = i + dx[p], ny = j + dy[p];
                        // Check if it is valid (in range) or not
                        if (nx >= 0 && ny >= 0 && nx < SIZE && ny < SIZE)
                        {
                            cnt++;
                            Average += RGBimage[nx][ny][k];
                        }
                    }
                    Average += RGBimage[i][j][k];
                    cnt++;
                    // Get the average of each cell with its neighbors
                    Average /= cnt;
                    // Assign it to the cell
                    RGBimage[i][j][k] = Average;
                }
            }
        }
    }
    return true;
}
bool CropRGBimage()
{
    cout << "Please enter (x-axis, y-axis) Starting position of the RGBimage and length, width of the square: \n";
    int x, y, l, w;   cin >> x >> y >> l >> w;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; ++k) {

                RGBimage2[i][j][k]= RGBimage[i][j][k];    // Take a copy from current RGBimage to Process
                RGBimage[i][j][k] = 255;               // Make our RGBimage white to receive the new skewed RGBimage
            }
        }
    }
    for (int i = x; i <= x + l; i++)
    {
        for (int j = y; j <= y + w; j++)
        {
            for (int k = 0; k < RGB; ++k) {

                RGBimage[i][j][k] = RGBimage2[i][j][k];     // Take Every Pixels You Want From Inputs Range To Our RGBimage
            }
        }
    }
    return true;
}
bool SkewRGBimageRight()
{
    cout << "Please enter degree to skew Right : \n";
    double rad ;cin>>rad; // Take Degree
    rad = 90 - rad;
    rad = ( rad * 22 ) / ( 180 * 7 ) ; // Convert From Degree to Radiant
    int c = 256 / (1+ ( 1/ tan(rad) ))  ; // Make New Base To Shrink
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; ++k) {
                RGBimage2[i][j][k] =RGBimage[i][j][k];    // Take a copy from current RGBimage to Process

            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; ++k) {

                RGBimage2[i][(j*c)/SIZE][k] =RGBimage2[i][j][k]; // shrink RGBimage With New Base
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; ++k) {

                if ((i<=SIZE && j >= c)  )
                    RGBimage2[i][j][k] = 255 ;     // Make another Part of copied RGBimage White

                RGBimage[i][j][k] = 255;          // Make our RGBimage white to receive the new skewed RGBimage
            }
        }
    }
    double step = SIZE - c;             // The number of steps required to Skew
    double mov = step / SIZE;           // The number of Move required to subtract from steps in each loop to Skew Rightward
    for ( int i = 0 ; i < SIZE ; i++ ){
        for ( int j = 0 ; j < c ; j++ ){
            for (int k = 0; k < RGB; ++k) {

                RGBimage[i][j+(int)step][k] = RGBimage2[i][j][k] ;
            }
        }
        step -= mov ;
    }

    return true;
}
bool SkewRGBimageUp()
{
    cout << "Please enter degree to skew Up : \n";
    double rad; cin >> rad;                   // Take Degree
    rad = (rad * 22) / (180 * 7);      // Convert From Degree to Radiant
    int c = 256 / (1 + tan(rad));      // Make New Base To Shrink
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; ++k) {

                RGBimage2[i][j][k] = RGBimage[i][j][k];      // Take a copy from current RGBimage to Process
            }
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; ++k) {

                RGBimage2[(i * c) / SIZE][j][k] = RGBimage2[i][j][k]; // shrink RGBimage With New Base
            }
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; ++k) {

                if ((i >= c && j <= SIZE))
                {
                    RGBimage2[i][j][k] = 255;    // Make another Part of copied RGBimage White
                }
                RGBimage[i][j][k] = 255;         // Make our RGBimage white to receive the new skewed RGBimage
            }
        }
    }
    double step = SIZE - c;             // The number of steps required to Skew
    double mov = step / SIZE;           // The number of Move required to subtract from steps in each loop to Skew upward
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; ++k) {

                RGBimage[j + (int)step][i][k] = RGBimage2[j][i][k]; //Make Our RGBimage Skewed Up
            }
        }
        step -= mov;
    }

    return true;
}