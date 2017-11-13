#include <iostream>
#include "bitmap.h"
#include <vector>
#include <string>
using namespace std;

vector < vector <Pixel> > bmpComp;
Pixel rgbC, rgbAdd;
int maxImg = 10;
int imgX = 400;
int imgY = 600;
int enteredImgs = 0;

void vectInitilizer();
void average(Pixel &, int,int,int);
void picAdder(vector < vector < Pixel > >);
bool picSizeCheck(vector < vector < Pixel > >);

int main()
{
    vectInitilizer();
    cout<< "Enter up to "<<maxImg<<" photos"<<endl;
    for (int index = 0; index < maxImg; index++)
    {
       string picName;
       Bitmap image;
       cin>> picName;
       image.open(picName);
       bool isImg = image.isImage();
       if (isImg == true)
       {
            vector < vector < Pixel> > bmp;
            bmp = image.toPixelMatrix();
            bool sizeChk = picSizeCheck (bmp);
            if (sizeChk = true) 
            {
                picAdder (bmp);
            }
            else isImg = false;
            enteredImgs++;
       }
       else if (isImg == false)
       {
            cout<< "Invalid photo." <<endl;
            index = index - 1;
       }
       else index = 11;
    }       

}

void vectInitilizer()
{
    bmpComp.resize(imgX);
    for (int index = 0; index < imgX; index++)
    {
        bmpComp[index].resize(imgY);
    }
}

bool picSizeCheck(vector < vector < Pixel > > bmp)
{
    if (bmp.size() == 400 && bmp[0].size() == 600) return true;
    else return false;
}

void picAdder(vector < vector < Pixel > > bmp)
{
    for (int index = 0; index < bmpComp.size(); index++)
    {
        for (int index2 = 0; index2 < bmpComp[index].size(); index2++)
        {
            rgbC = bmpComp[index][index2]; 
            rgbAdd = bmp[index][index2];
            rgbC.red = rgbC.red + rgbAdd.red;
            rgbC.green = rgbC.green + rgbAdd.green;
            rgbC.blue = rgbC.blue + rgbAdd.blue;
        }
    }
}

// ask for an image 10 times or until user stops providing images

// check image is correct and valid (valid bmp & correct size)

// add each image to a 3D vector

// average pixel by "flattening" vector. Use function to find average of 3D stack and apply it to "bottom" vector. Average will be color values added together / number of provide photos.

// give a message after every 10th row with aproxamate percent done. Keep an index that sends a message once 10 lines have past, then reset index.

// save bottom vector as the final bmp
