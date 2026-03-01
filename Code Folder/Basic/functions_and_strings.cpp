// Topics: arguments, call by value + strings <string>

# include <iostream>
# include <string>
using namespace std;

int name(string name, int age){
    name.clear();
}

int main(){
    string name = "Shubham";
    string channel = "The owner of Excited Nuclei Channel is ";
    string sentence = channel + name;
    string s = "abcd";
    cout << "Name variable length: " << name.length() << endl;
    cout << "Concatenation: " << sentence << endl;
    s.clear();
    cout << "clearing: " << s << endl;
    cout << "check empty: " << s.empty() << endl;
}
