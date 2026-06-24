
#include "./header/Image_Class.h"
#include <iostream>
#include <string>
using namespace std;

// A function to calculate the gray value of a pixel by averaging the three colors (red, green, blue)
int image_Filter(int red, int green, int blue){
    return (red + green + blue) / 3;
}

// A function to convert a color image to a black and white image
void black_graay(Image& image){
    // Iterate over all pixels in the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Gets the color components of the current pixel
            int red = image(i, j, 0);
            int green = image(i, j, 1);
            int blue = image(i, j, 2);

            // Use the image_Filter function to calculate the gray value
            int gray = image_Filter(red, green, blue);

            // Set a gray value for all color components of the pixel to make it gray
            image(i, j, 0) = gray;
            image(i, j, 1) = gray;
            image(i, j, 2) = gray;
        }
    }
}

int main() {
    string filename, store;
    cout << "Please enter the filename of the image: ";
    getline(cin, filename);

    try {
        // Trying to download the image from the file
        Image image(filename);

        black_graay(image);

        // Asking the user for the desired file format and store it in 'store'
        cout << "Please enter the desired file format (.jpg, .bmp, .tga, .png): ";
        cin >> store;

        // Specify a new file name for the modified image and save it
        string outputFilename = filename + store;
        image.saveImage(outputFilename);

        cout << "Image successfully converted to Grayscale Conversion and saved as " << outputFilename << endl;
    } catch (const exception& e) {
        // Handling errors that may occur while loading or processing the image
        cerr << "An error occurred: " << e.what() << endl;
        return 1; // Exiting the program with an error code
    }

    return 0; // Successful program exit
}

