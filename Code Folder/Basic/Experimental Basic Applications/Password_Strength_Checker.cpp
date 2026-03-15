# include <iostream>
# include <string>
using namespace std;

// check for password length
bool passLength(string pass){
    return pass.length() >= 8;
}

// check for uppercase
bool hasUppercase(string pass){
    for (char i : pass){
        if (isupper(i)){
            return true;
        }
    }
    return false;
}

// check for lower case
bool hasLowercase(string pass){
    for (char i : pass){
        if (islower(i)){
            return true;
        }
    }
    return false;
}

// check for number
bool hasNumber(string pass){
    for (char i : pass){
        if (isdigit(i)){
            return true;
        }
    }
    return false;
}

// check for sp. char
bool hasSpecialchars(string pass){
    for (char i : pass){
        if (!isalnum(i)){ // if string conatins elements other than alphabets and numbers
            return true;
        }
    }
    return false;
}

// convert to lower case
string toLowerCase(string pass){
    for (int i = 0; i < pass.length(); i++){
        pass[i] = tolower(pass[i]);
    }
    return pass;
}

// check for name
bool hasName(string pass, string name){
    if (toLowerCase(pass).find(toLowerCase(name)) != string :: npos){
        return true;
    }
    return false;
}

int main(){
    string name, password;
    int score = 0;
    cout << "Enter your name: " ;
    cin >> name;
    cout << "Enter Password: ";
    cin >> password;

    bool length = passLength(password);
    bool upper = hasUppercase(password);
    bool lower = hasLowercase(password);
    bool num = hasNumber(password);
    bool sp_char = hasSpecialchars(password);
    bool name_ch = hasName(password, name);

    if (length) score++;
    if (upper) score++;
    if (lower) score++;
    if (sp_char) score++;
    if (num) score++;

    if (name_ch) score--;

    cout << "\n--------------Password Analysis--------------\n";
    
    if (!length) cout << "- Password must contain at least 8 characters long\n";
    if (!upper) cout << "- - Add at least one uppercase letter\n";
    if (!lower) cout << "- Add at least one lowercase letter\n";
    if (!sp_char) cout << "- Add at least one special charcater\n";
    if (!num) cout << "- Add at least one number\n";
    if (name_ch) cout << "- Avoid using your name in the password\n";

    cout << "\n--------------Password Strength--------------\n";

    if(score <= 2)
        cout << "Weak";
    else if(score <= 4)
        cout << "Medium";
    else
        cout << "Strong";
    cout << endl;
    return 0;
} 