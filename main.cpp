#include <iostream>
#include "bitmap.h"
#include <vector>
#include <string>
using namespace std;

vector < vector <Pixel> > bmpComp;
Pixel rgb;
int maxImg = 10;

void average(Pixel &, int,int,int);
void picAdder(vector < vector < Pixel > >);
bool picSizeCheck(vector < vector < Pixel > >);

int main()
{

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
       }
       else if (isImg == false)
       {
            cout<< "Invalid photo." <<endl;
            index = index - 1;
       }
       else break;
    }       

}

bool picSizeCheck(vector < vector < Pixel > > bmp)
{
    if (bmp.size() == 399 && bmp[0].size() == 599) return true;
    else return false;
}
void picAdder(vector < vector < Pixel > > bmp)
{
}

// ask for an image 10 times or until user stops providing images

// check image is correct and valid (valid bmp & correct size)

// add each image to a 3D vector

// average pixel by "flattening" vector. Use function to find average of 3D stack and apply it to "bottom" vector. Average will be color values added together / number of provide photos.

// give a message after every 10th row with aproxamate percent done. Keep an index that sends a message once 10 lines have past, then reset index.

// save bottom vector as the final bmp
