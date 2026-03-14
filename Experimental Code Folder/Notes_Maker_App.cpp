#include <iostream>
using namespace std;

const int MAX_NOTES = 50;

string titles[MAX_NOTES];
string contents[MAX_NOTES];
string topics[MAX_NOTES];
int noteCount = 0;

// create notes
void createNote(){
    if (noteCount >= MAX_NOTES){
        cout << "Note Storage Full!" << endl;
        return;
    }

    cin.ignore(); // basically bypases this line 
    
    cout << "Enter note title: ";
    getline(cin, titles[noteCount]);

    cout << "Enter note topic: ";
    getline(cin, topics[noteCount]);

    cout << "Enter note content: ";
    getline(cin, contents[noteCount]); // this helps us to call cin as well as edit the array

    noteCount++;

    cout << "Note created successfully!" << endl;
}

// view notes
void viewNotes(){
    if (noteCount == 0){
        cout << "No Notes Available!" << endl;
        return;
    }

    cout << "\nList of all notes:\n";

    for(int i = 0; i < noteCount; i++){
        cout << i+1 << ". " << titles[i] << "(Topic: " << topics[i] << ")" << endl;
    }
}

// read notes
void readNote(){
    int index;

    viewNotes();

    cout << "Enter the note number you want to read: " ;
    cin >> index;

    if ( index<1 || index > noteCount){
        cout << "Invalid note number!" << endl;
        return;
    }

    index --;

    cout << "\nTitle: " << titles[index] << endl;
    cout << "\nTopic: " << topics[index] << endl;
    cout << "\nContent: " << contents[index] << endl;
}

// edit notes
void editNote(){
    int index;

    viewNotes();

    cout << "Enter the note number you want to edit: " ;
    cin >> index;
    if ( index<1 || index > noteCount){
        cout << "Invalid note number!" << endl;
        return;
    }
    index --;

    cout << "Enter new content: ";
    cin.ignore(); // basically bypases this line 
    getline(cin, contents[index]); // this helps us to call cin as well as edit the array

    cout << "Note updated successfully!" << endl;
}

// delete notes
// {1,2,3,4,5,6} we want to delete 2 from this array we can do {1,3,4,5,6,_}
void deleteNote(){
    int index;

    viewNotes();

    cout << "Enter note number to delete: ";
    cin >> index;

    if(index < 1 || index > noteCount){
        cout << "Invalid note number!\n";
        return;
    }

    index--;

    for (int i=index; i<noteCount-1; i++){
        titles[i] = titles[i+1];
        topics[i] = topics[i+1];
        contents[i] = contents[i+1];
    }

    noteCount--;

    cout << "Note deleted successfully!\n";
}

// menu system
void menu(){
    int choice;

    do {
        cout << "\n===== NOTES MAKER =====\n";
        cout << "1. Create Note\n";
        cout << "2. View Notes\n";
        cout << "3. Read Note\n";
        cout << "4. Edit Note\n";
        cout << "5. Delete Note\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1: createNote(); break;
            case 2: viewNotes(); break;
            case 3: readNote(); break;
            case 4: editNote(); break;
            case 5: deleteNote(); break;
            case 6: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);
}

// main loop
int main(){
    menu();
    return 0;
}