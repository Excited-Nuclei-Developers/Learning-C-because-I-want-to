// Topics: constants (const), sizeof operator, type casting

# include <iostream>
using namespace std;

int main(){
    int x;
    const double pi = 3.1418;
    // pi = 3.14;
    cout << "Trying changing the value of pi to anoother: " << pi << endl;
    cout << "size of int dtype or x: " << sizeof(x) << endl;
    cout << "size of double dtype or pi: " << sizeof(pi) << endl;

    double x1;
    x1 = 2.345;
    cout << "value of x1 before type casting: " << x1 << endl;
    cout << "value of x1 after type casting: " << (int)x1 << endl;

    int anotherInt = 5;
    cout << "value of anotherInt before type casting: " << anotherInt/2 << endl;
    double result = static_cast<double>(anotherInt) / 2;
    cout << "value of anotherInt before type casting: " << result << endl;
}