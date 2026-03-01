# include <iostream>
using namespace std;

int main(){
    // what are pointers ?
    // these are the variable that stores the address values for any element.
    int x = 3;
    int *p = &x;
    int **p2 = &p; // see what this ** represent.
    cout << "Pointer p: " << p << " Pointer p2: " << p2 << " Value: " << **p2 << endl;

    // pointer arithmatics
    int arr[3] = {10,20,30}; // here array actually act as a const pointer to first element 
    int* p1 = arr;
    // arr[i] = *(arr+i)
    // int arr >> 10 (location: 100)
    // arr[1] >> *(arr + n*sizeof(dtype)) for int sizeof(int) = 4bits
    // arr[1] >> have location 104

    // p1++; // maybe this ++ (increment operaor) is actually naturally pointing to the index 1 or 
        // 2nd element of the array

    cout <<"First element of array loc: "<< p1 << " element: " << *p1 << endl;
    cout <<"Second element of array loc: "<< p1+1 << " element: " << *(p1+1) << endl;
    cout <<"Third element of array loc: "<< p1+2 << " element: " << *(p1+2) << endl;
    cout <<"Fourth element of array loc: "<< p1+3 << " element: " << *(p1+3) << endl;
    // void x(int arr[]); >> int* arr

    // we can substract the pointers and also compare them 
    // if and only if they both pointers to same array
    int arr1[5] = {10,20,30,40,50};

    int* p3 = &arr[0];
    int* p4 = &arr[4];
    cout << "p3 - p4 : " << p4 - p3 << endl;
}