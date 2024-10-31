#include<iostream>
#include<fstream>
#include<cmath>
#define STB_IMAGE_IMPLEMENTATION
#include"stb_image.h"

using namespace std;

int main(){

    string imagePath = "";
    cin >> imagePath;

    //nacitanie obrazka
    int width, height, channels;
    unsigned char* img = stbi_load(imagePath.c_str(), &width, &height, &channels, 3);

    if(img == NULL){
        cout << "Error in loading the image.";
        return -1;
    }

    else cout << "Image loaded succesfully!";

    //vytvorenie output suboru
    ofstream fout;
    fout.open("output.txt");

    //prechadzanie pixelov
    for(int i = 0; i < height;i++){

        for(int j = 0; j < width;j++){

            int pixelIndex = (i * width + j) * channels;

            float red   = img[pixelIndex + 0];
            float green = img[pixelIndex + 1];
            float blue  = img[pixelIndex + 2];

            float grayscale = 0.3 * red + 0.59 * green + 0.11 * blue;

            grayscale = round(grayscale);

            if(grayscale <= 25 ){
                fout << '@';
            }
            else if(grayscale <= 50){
                fout << '%';
            }
            else if(grayscale <= 75){
                fout << '#';   
            }
            else if(grayscale <= 100){
                fout << '*';
            }
            else if(grayscale <= 125){
                fout << '+';
            }
            else if(grayscale <= 150){
                fout << '=';
            }
            else if(grayscale <= 175){
                fout << '-';
            }
            else if(grayscale <= 200){
                fout << ':';
            }
            else if(grayscale <= 225){
                fout << '.';
            }
            else{
                fout << ' ';
            }
        }
        fout << '\n';
    }
    cout << "\nImage created succesfully!";
    stbi_image_free(img);

    return 0;
}