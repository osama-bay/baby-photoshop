#include "./header/Image_Class.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to apply Sobel operator to detect edges and invert the colors
void apply_sobel_operator(Image& image) {
    int width = image.width;
    int height = image.height;
    vector<vector<int>> gradient_magnitudes(width, vector<int>(height, 0));

    int max_gradient = -1;

    int sobel_x[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int sobel_y[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Apply Sobel operator to each pixel (excluding borders)
    for (int x = 1; x < width - 1; ++x) {
        for (int y = 1; y < height - 1; ++y) {
            int gx = 0;
            int gy = 0;

            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    int pixel_val = image.getPixel(x + i, y + j, 0); // Assuming gray-scale or one channel processing
                    gx += pixel_val * sobel_x[i + 1][j + 1];
                    gy += pixel_val * sobel_y[i + 1][j + 1];
                }
            }

            int gradient_magnitude = static_cast<int>(sqrt(gx * gx + gy * gy));
            max_gradient = max(max_gradient, gradient_magnitude);
            gradient_magnitudes[x][y] = gradient_magnitude;
        }
    }

    // Normalize the gradient magnitudes and invert the colors
    for (int x = 1; x < width - 1; ++x) {
        for (int y = 1; y < height - 1; ++y) {
            int normalized_gradient = (gradient_magnitudes[x][y] * 255) / max_gradient;
            int inverted_color = 255 - normalized_gradient; // Invert colors

            // Set the same inverted value to all channels to maintain the color effect
            image.setPixel(x, y, 0, inverted_color);
            image.setPixel(x, y, 1, inverted_color);
            image.setPixel(x, y, 2, inverted_color);
        }
    }
}

int main() {
    string filename;
    cout << "Please enter the filename of the image: ";
    getline(cin, filename);

    try {
        Image image(filename); // Assuming Image constructor takes a file name

        // Apply the Sobel operator to detect edges
        apply_sobel_operator(image);

        // Save the edge-detected and inverted color image
        string outputFilename = "inverted_sobel_" + filename;
        image.saveImage(outputFilename);

        cout << "Inverted edge-detected image saved successfully as " << outputFilename << endl;
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
        return 1;
    }

    return 0;
}