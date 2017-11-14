#include <iostream>
#include "bitmap.h"
#include <vector>
#include <string>
using namespace std;

vector < vector <Pixel> > bmpComp;
vector < string > photosToAdd;
Pixel rgbC, rgbAdd, rgb;
int maxImg = 10;
int imgX, imgY;
int enteredImgs = 0;

void vectInitilizer();
void picAdder();
bool picSizeCheck(vector < vector < Pixel > >);
void picAverager();

int main()
{
        
        cout<< "Enter up to "<<maxImg<<" photos"<<endl;
        for (int index = 0; index < maxImg; index++)
        {
                string picName;
                Bitmap image;
                cin>> picName;
                if (picName == "Done" || picName == "done" || picName == "DONE" ) goto Done;          

                image.open(picName);
                bool isImg = image.isImage();
                if (isImg == true)
                {
                        vector < vector < Pixel > > bmp;
                        bmp = image.toPixelMatrix();
                        if (imgX == 0 || imgY == 0) //Makes size of first picture the required size
                        {
                                imgX = bmp.size();
                                imgY = bmp[0].size();
                                vectInitilizer();
                        }
                        bool sizeChk = picSizeCheck (bmp); 
                        if (sizeChk == true) //Adds picture to pics to be added list
                        {
                                photosToAdd.push_back (picName);
                                enteredImgs++;//changes number of actual entered pictures
                        }
                        else isImg = false;

                }
                else if (isImg == false)
                {
                        cout<< "Invalid file. Not a bitmap or doesn't exist!" <<endl;
                        index = index - 1;
                }


        }       
        if (enteredImgs = 1)
        {
                cout<< "Too few photos to make composition. Ending program." <<endl;
                goto NoRun;
        }
        Done:
        picAdder();
        picAverager();
        NoRun:
return 0;
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
        if (bmp.size() == imgX && bmp[0].size() == imgY) return true;
        else 
        {
                cout<< "Bmp is the wrong size. Correct size is "<< imgY <<" X "<< imgX <<endl;
                return false;
        }
}

void picAdder()
{
        for (int nameIndex = 0; nameIndex < photosToAdd.size(); nameIndex++)
        {
                Bitmap image;
                image.open(photosToAdd[nameIndex]);
                vector < vector < Pixel > > bmp;
                bmp = image.toPixelMatrix(); 

                for (int index = 0; index < bmpComp.size(); index++)
                {
                        for (int index2 = 0; index2 < bmpComp[index].size(); index2++)
                        {
                                rgbC = bmpComp[index][index2]; 
                                rgbAdd = bmp[index][index2];
                                rgbC.red = rgbC.red + rgbAdd.red;
                                rgbC.green = rgbC.green + rgbAdd.green;
                                rgbC.blue = rgbC.blue + rgbAdd.blue;
                                bmpComp[index][index2] = rgbC;
                        }
                }
                cout<< "Picture " << (nameIndex + 1) << " out of " << photosToAdd.size() << " done" <<endl;
        } 
}

void picAverager()
{
        for (int index = 0; index < bmpComp.size(); index++)
        {
                for (int index2 = 0; index2 < bmpComp[index].size(); index2++)
                {
                        rgb = bmpComp[index][index2];
                        rgb.red = rgb.red/enteredImgs;
                        rgb.green = rgb.green/enteredImgs;
                        rgb.blue = rgb.blue/enteredImgs;
                        bmpComp[index][index2] = rgb;
                }
        }
        Bitmap image;
        image.fromPixelMatrix(bmpComp);
        image.save("composite-dmullaly.bmp");
        cout<< "Done. Image made!" <<endl;
}

// ask for an image 10 times or until user stops providing images

// check image is correct and valid (valid bmp & correct size)

// add each image to a 3D vector

// average pixel by "flattening" vector. Use function to find average of 3D stack and apply it to "bottom" vector. Average will be color values added together / number of provide photos.

// give a message after every 10th row with aproxamate percent done. Keep an index that sends a message once 10 lines have past, then reset index.

// save bottom vector as the final bmp
