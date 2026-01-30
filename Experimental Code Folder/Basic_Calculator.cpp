# include <iostream>
using namespace std;

// Ints -> Floats -> Complex
// if we have number 1
// so 1 can also be written as 1.0
// so 1 can also be written as 1 + 0j (j is imaginary number)

// add func
int add_2nums(int a, int b){
    cout<<"You are using Addition function!"<<endl;
    cout<<"Addition of two numers is : "<<a+b<<endl;
    return a+b;
};

// subs func
int sub_2nums(int a, int b){
    cout<<"You are using Substraction function!"<<endl;
    cout<<"Substraction of two numers is : "<<a-b<<endl;
    return a-b;
};

// Multiply func
int mul_2nums(int a, int b){
    cout<<"You are using Multiplication function!"<<endl;
    cout<<"Multiplication of two numers is : "<<a*b<<endl;
    return a*b;
};

// divide func
float div_2nums(int a, int b){
    float d;
    cout<<"You are using Division function!"<<endl;
    cout<<"Division of two numers is : "<<(float) a/b<<endl;
    if (b==0) { cout<<"The diviser must not be 0"<<endl;}
    else {d = (float) a/b;}
    
    return d;
    // we used (float) because we are trying to diving 2 
    // ints and by default it is going to return int value 
    // thats why we explicitly typecasted it to float
};

// Floor division func
int flor_div_2nums(int a, int b){
    cout<<"You are using Floor division function!"<<endl;
    cout<<"Floor division of two numers is : "<<a/b<<endl;
    return a/b;
};

// Power func
int power_2nums(int a, int b){
    cout<<"You are using Power function!"<<endl;
    int temp=1;
    while (b>0,b--){
        temp*=a;
    }
    cout<<"Power of two numers is : "<<temp<<endl;
    return temp;
};

int main()
{
    int a,b,opt_selcted;

    cout<<"Please enter fist number : "<<endl;
    cin>>a;
    cout<<"Please enter second number : "<<endl;
    cin>>b;

    cout<<"Welcome to Excited Nuclei Channel!"<<endl;
    cout<<"This is a Simple Calculator"<<endl;
    cout<<"Please select your desired operation from below menu :"<<endl;
    cout<<"Press 1 for Addition"<<endl;
    cout<<"Press 2 for Substraction"<<endl;
    cout<<"Press 3 for Multiplication"<<endl;
    cout<<"Press 4 for Division"<<endl;
    cout<<"Press 5 for Floor Division"<<endl;
    cout<<"Press 6 for Power"<<endl;

    // cout<<"This is a Simple Calculator\nPlease select your desired operation from below menu :\nPress 1 for Addition"<<endl;

    cin>>opt_selcted;
    if (opt_selcted==1){
        add_2nums(a,b);}
    else if (opt_selcted==2){
        sub_2nums(a,b);}
    else if (opt_selcted==3){
        mul_2nums(a,b);}
    else if (opt_selcted==4){
        div_2nums(a,b);}
    else if (opt_selcted==5){
        flor_div_2nums(a,b);}
    else if (opt_selcted==6){
        cout<<"second number will be used as the power to raise for first num."<<endl;
        power_2nums(a,b);}

    // Do it yourself create a function for floor division and make your own calculatoe 
    // it is going to be helpful if you also explore things like modulus, power, sqrt
}