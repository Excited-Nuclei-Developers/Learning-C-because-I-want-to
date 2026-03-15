# include <iostream>
# include <cmath>
# include <string>
# include <ctime>
# include <cstdlib>
using namespace std;

// Random Number Generator 
int rng(int range){
    srand(time(0));
    int num = rand() % range +1;
    return num;
}

// User Input
int ui(){
    int guess;
    cout << "Enter Your Guess: ";
    cin >> guess;
    return guess;
}

/* Hints
act num is = 30 and ui >> 5 >> too low
act num is = 30 and ui >> 60 >> too high
act num is = 30 and ui >> in range (28 to 32) >> close */

string hint(int ui, int act_num){
    if (abs(ui - act_num) <= 2){
        return "Close";
    }else if (ui > act_num){
        return "Too High";
    } else {
        return "Too Low";
    }
}

// Levels and numbers seed
int lev_num_range(int level){
    switch (level){
    case 0:
        return 100;
    case 1:
        return 500;
    case 2:
        return 1000;
    default : 
        return 100;
    }
}

// Menu system
string menu(){
    string m = "Welcome to Number Guessing Game\
    \nChoose the level you want to play: \
    \nEasy (1 to 100)   >> 0\
    \nMedium (1 to 500) >> 1\
    \nHell (1 to 1000)  >> 2\
    \nExit              >> -1";
    return m;
}

int main(){
    // Code
    int level;
    cout << menu() << endl;
    cout << "You only got 5 chances!" << endl;
    cout << "Enter your choice: " ;
    cin >> level;
    switch (level){
        case 0:
            cout << "I know you are scared!"<<endl;
            break;
        case 1:
            cout << "Now you are talking"<<endl;
            break;
        case 3:
            cout << "OHHHHHHHHH.......! Now you are Worthy of my respect"<<endl;
            break;
    }
    if (level != -1){
        int range = lev_num_range(level);
        const int act_num = rng(range);
        // cout << "Print Actual Number is: " << act_num << endl;
        for (int i=0; i<5; i++){
            cout << "Attempt " << i+1 << " of 5\n";
            int guess = ui();
            // cout << "User Input and Actual Number: " << guess << ", " << act_num << endl;
            if (act_num == guess) {
                cout << "Congratuations you got the right number !" << endl;
                break;
            } else {
            cout << hint(guess, act_num) << endl;
            }
        }
        cout << "Actual Number was: " << act_num;
    } else {
        cout << "Thank you for playing with us !";
    }
}