# include <iostream>
# include <string>
using namespace std;

// setting a default user
string name = "Shubham";
int balance = 100000;

// creating function for greeting user
int greet(string name){
    cout<<"Hello, "<<name<<".\nWelcome to EN Bank."<<endl;
    return 1;
};

// creating function for checking balance
void check_bal(int balance, string name){
    cout<<"Dear, "<<name<<" your account balance is "<<balance<<endl;    
}

// creating function for deposit
int deposit(int balance, int amt){
    balance+=amt;
    return balance;
}

// creating function for withdrwal
int withdraw(int balance, int amt){
    if (amt>balance){
        return 1;
    } else {
    balance-=amt;
    return balance;};
}

// menu
void menu(){
    cout<<"Choose form the below menu: \n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit"<<endl;
};

// main
int main(){
    int choice;
    int amt;
    bool move = true;
    greet(name);
    while (move==true) {
        menu();
        cout<<"Enter Your Choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            check_bal(balance, name);
            cout<<"\n\n";
            break;
        case 2:
            cout << "Please Enter Your Amount: ";
            cin>>amt;
            cout<<"Your Balance after deposit is: "<<deposit(balance, amt)<<endl;
            balance=deposit(balance, amt);
            cout<<"\n\n";
            break;
        case 3:
            cout << "Please Enter Your Amount: ";
            cin>>amt;
            if (amt>balance){
                cout<<"Invalid amount! Amount should not Exceed balance.";
                cout<<"\n\n";
            } else {
            cout<<"Your Balance after withdraw is: "<<withdraw(balance, amt)<<endl;
            balance=deposit(balance, amt);
            cout<<"\n\n";
            break;};
        case 4: 
            move = false;
            cout<< "Thankyou for using EN Bank services."<<endl;
            break;
        }
    };
}