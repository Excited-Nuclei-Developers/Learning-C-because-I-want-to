# include <iostream>
# include <ctime>
# include <string>
# include <cstdlib>
using namespace std;

// Choice to String map
string map(int choice){
    switch (choice){
        case 0:
            return "Rock";
        case 1:
            return "Paper";
        case 2:
            return "Scissors";
    }
}

// Random Choice
int random_choice(){
    int num = rand()%3; // 0,1,2
    return num;
}

// Menu
string menu(){
    string m = "Welcome to Rock-Paper-Scissors Game by Excited Nuclei\
    \nControls: \
    \nPress :\
    \nRock     >> 0\
    \nPaper    >> 1\
    \nScissors >> 2\
    \nExit     >> -1";
    return m;
}

// Result
string check_result(int comp_choice, int user){
    if (((comp_choice == 0)&&(user == 1))||(comp_choice == 1)&&(user == 2)||(comp_choice == 2)&&(user == 0)){
        return "u";
    } else if (comp_choice == user){
        return "d";
    }else {
        return "c";
    }
}

int main(){
    int wins, looses, choice;
    wins = 0;
    looses = 0;
    srand(time(0));
    // code
    while (true) {
        cout << menu() << endl;
        cout << "User Wins: " << wins << " | Computer Wins: " << looses << endl;
        cout << "Enter your Choice: ";
        cin >> choice;
        if (choice == -1){
            cout << "Thanks for playing!";
            break;
        }
        int comp_choice = random_choice();
        if (check_result(comp_choice,choice) == "d"){
            wins++;
            looses++;
            cout << "This match is draw" << endl;
        } else if (check_result(comp_choice,choice) == "c"){
            looses++;
            cout << "Computer Won!" << endl;
        } else if (check_result(comp_choice,choice) == "u"){
            wins++;
            cout << "User Won!" << endl;
        } else {
            cout << "Please Select the right option.";
        }
    }   
}