#include "./header/Image_Class.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to reduce a pixel's brightness by 50%
void divide(int& red, int& green, int& blue){
    red = red / 2;
    green = green / 2;
    blue = blue / 2;
}

// Function to apply the dimmer filter to the entire image
void Lighten_Image(Image& image){
    // Iterate over all pixels in the image
    for (int i = 0; i < image.width; ++i) {
        for (int x = 0; x < image.height; ++x) {
            // Get the color components of the current pixel
            int red = image(i, x, 0);
            int green = image(i, x, 1);
            int blue = image(i, x, 2);

            // Make the pixel dimmer
            divide(red, green, blue);

            // Set the new color values back to the image
            image.setPixel(i, x, 0, red);
            image.setPixel(i, x, 1, green);
            image.setPixel(i, x, 2, blue);
        }
    }
}

int main() {
    string inputFilename;
    string outputFilename;
    string fileExtension;

    cout << "Please enter the filename of the image: ";
    getline(cin, inputFilename);

    cout << "Please enter the new image name to store\n";
    cout << "and specify extension (.jpg, .bmp, .png, .tga): ";
    getline(cin, outputFilename);

    // Extract the file extension if provided
    size_t dotPos = outputFilename.rfind('.');
    if(dotPos != string::npos){
        fileExtension = outputFilename.substr(dotPos);
    } else {
        cerr << "Invalid file format specified." << endl;
        return 1; // Exit the program with an error code
    }

    try {
        // Load the image from the file
        Image image(inputFilename);

        // Apply the dimmer filter to the image
        Lighten_Image(image);

        // Save the modified image with the new name and format
        image.saveImage(outputFilename);

        cout << "Image successfully made and saved as " << outputFilename << endl;
    } catch (const exception& e) {
        // Handle any errors that occur while loading or processing the image
        cerr << "An error occurred: " << e.what() << endl;
        return 1; // Exit the program with an error code
    }

    return 0; // Successful program exit
}
