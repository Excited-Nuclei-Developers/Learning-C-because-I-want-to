#include <iostream>
#include <cmath>
using namespace std;

// Utility function to get positive input
double getPositiveInput(string prompt){
    int choice;
    cout << prompt;
    cin >> choice;
    return choice;
}

// Lens formula: 1/f = 1/v - 1/u
void lensFormula(){
    int lensChoice;
    cout << "\n--- Lens Formula ---\n";
    cout << "1. Calculate Focal Length (f)\n";
    cout << "2. Calculate Object Distance (u)\n";
    cout << "3. Calculate Image Distance (v)\n";
    cout << "Enter your choice: ";
    cin >> lensChoice;
    double u,v,f;
    switch (lensChoice){
        case 1:
            u = getPositiveInput("Enter object distance (u in cm, use negative for virtual objects): ");
            v = getPositiveInput("Enter image distance (v in cm, use negative for virtual objects): ");
            f = 1 / ( (1/v) - (1/u) );
            cout << "Focal Length (f) = " << f << " cm\n";
            break;
        case 2:
            v = getPositiveInput("Enter image distance (v in cm, use negative for virtual objects): ");
            f = getPositiveInput("Enter focal length (f in cm,  use negative for concave lens): ");
            u = 1 / ( (1/v) - (1/f) );
            cout << "Object Distance (u) = " << u << " cm\n";
            break;
        case 3:
            u = getPositiveInput("Enter object distance (u in cm, use negative for virtual objects): ");
            f = getPositiveInput("Enter focal length (f in cm,  use negative for concave lens): ");
            v = 1 / ( (1/f) - (1/u) );
            cout << "Image Distance (v) = " << v << " cm\n";
            break;
        default:
            cout << "Invalid Choice! Retry.";
            break;
    }
}

// Magnification: m = v / u
void magnification(){
    cout << "\n--- Magnification ---\n";
    double u,v,m;
    u = getPositiveInput("Enter object distance (u in cm, use negative for virtual objects): ");
    v = getPositiveInput("Enter image distance (v in cm, use negative for virtual objects): ");
    m = v/u;
    cout << "Linear magnification (m) = " << m << "\n";
}

// Refractive Index: n = sin(i) / sin(r)
void refractiveIndex(){
    cout << "\n--- Refractive Index (Snell's Law) ---\n";
    double angleIncidence, angleRefraction;
    angleIncidence = getPositiveInput("Enter angle of incidence (degrees): ");
    angleRefraction = getPositiveInput("Enter angle of refraction (degrees): ");
    // n radians = n*(pi/180)
    double radIncidence = angleIncidence * M_PI / 180.0;
    double radRefraction = angleRefraction * M_PI / 180.0;

    double n = sin(radIncidence) / sin(radRefraction);
    cout << "Refractive Index (n) = " << n << "\n";
}

int main() {
    int choice;
    do {
        cout << "\n=== Optics Calculator ===\n";
        cout << "1. Lens Formula (f, u, v)\n";
        cout << "2. Magnification (linear)\n";
        cout << "3. Refractive Index (Snell's Law)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:
                lensFormula();
                break;
            case 2:
                magnification();
                break;
            case 3:
                refractiveIndex();
                break;
            case 4:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid Choice! Retry.";
        }
    }
    while(choice != 4);
    return 0;
}