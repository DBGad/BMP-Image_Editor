// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				main.cpp
// Last Modification Date:	    16/10/2023
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
#include "GSImageEditor.h"
#include "RGBImageEditor.h"
using namespace std;


int main (){
    int choose = 123;
    cout << "Ahlan Ya Yuser Ya Habibi ^^\n";
    bool flag = false;
    while (choose != 0)
    {
        if (flag)
            cout << "\nHey Again ^^\n";
        cout << "What type of Image do you want to edit ?\n";
        cout << "1- Gray Scale Image\n";
        cout << "2- Colored Image\n";
        cout << "3- Exit\n";
        cin >> choose;
        if (choose == 1)
        {
            RunGSImageEditor();
            flag = true;
        }
        else if (choose == 2)
        {
            RunRGBimageEditor();
            flag = true;
        }
        else if (choose == 3)
        {
            cout << "\n Thank You For Using Our Application ^^\n";
            break;
        }
        else
        {
            cout << "\tPlease Enter Number in Range\n";
            systempause();
            choose = 123;
        }
    }
    return 0;
}