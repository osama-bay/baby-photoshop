// A demo for converting image to gray scale

#include <iostream>
using namespace std;
#include "header/Image_Class.h"

int main() {
    string filename;
    cout << "Pls enter colored image name to turn to gray scale: ";
    cin >> filename;

    Image image(filename);
    Image newImage(image.width, image.height);




    try {
        cout << "Width: " << image.width << endl;
        cout << "Height: " << image.height << endl;

        int kernelSize = 15; // 5x5 kernel
        int edge = kernelSize / 2; // Edge offset for the kernel

        for (int i = 0; i < (image.height - 1); ++i) {
            for (int j = 0; j < (image.width - 1); ++j) {

                int red_sum = 0;
                int green_sum = 0;
                int blue_sum = 0;
                int count = 0;
//                cout << "start \t";

                // Iterate over the kernel
                for (int ki = -edge; ki <= edge; ++ki) {
                    for (int kj = -edge; kj <= edge; ++kj) {
                        int newI = i + ki;
                        int newJ = j + kj;

                        // Check for boundary conditions
                        if (newI >= 0 && newI < image.height && newJ >= 0 && newJ < image.width) {
                            red_sum += image.getPixel(newJ, newI, 0);
                            green_sum += image.getPixel(newJ, newI, 1);
                            blue_sum += image.getPixel(newJ, newI, 2);
                            count++;
                        }
                    }
                }
//                cout << "middle \t";

                // Calculate average
                int red_avg = red_sum / count;
                int green_avg = green_sum / count;
                int blue_avg = blue_sum / count;

                // Set the averaged colors to the new image
                newImage.setPixel(j, i, 0, red_avg);
                newImage.setPixel(j, i, 1, green_avg);
                newImage.setPixel(j, i, 2, blue_avg);

            }
//            cout << "end \t";
        }

        cout << "Pls enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        cin >> filename;
        newImage.saveImage(filename);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
