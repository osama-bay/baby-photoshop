#include "Image_Class.h"
#include <iostream>
using namespace std ;

void black_and_white (string name){
    Image image  ;

    image.loadNewImage(name) ;

    for (int i = 0 ; i < image.width ; i++) {
        for (int j = 0 ;j < image.height ; j++){
            unsigned int ave = 0 ;
            for (int k = 0 ; k < image.channels ; k++){

                ave +=  image (i,j,k)  ;

            }

            ave = ave / 2 ;

            for (int k = 0 ; k < 3 ; k++){
                if (ave <=127){
                    image(i,j,k) = 0 ;
                }
                else if (ave > 127) {
                    image(i,j,k) = 255 ;
                }
            }
        }
    }
    string chioce , new_name ;
    while (true) {
        cout << "do you want save the new image (yes or no ) : ";
        cin >> chioce;
        if (chioce == "yes") {
            image.saveImage(name);
            break;
        } else if (chioce == "no") {
            cout << endl << "please enter the new name : ";
            cin.ignore();
            getline(cin, new_name);
            image.saveImage(new_name);
            break;
        } else {
            cout << "invalid chioce , try again" << endl ;
        }
    }
}
int main(){
    string name ;
    cout << "please enter the name of the image : " ;
    getline(cin, name);

    black_and_white(name) ;

    return 0;
}
