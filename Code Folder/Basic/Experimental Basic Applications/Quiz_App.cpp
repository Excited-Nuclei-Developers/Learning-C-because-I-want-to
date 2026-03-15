#include <iostream>
using namespace std;

// Function to run the quiz
void startQuiz(){
    const int totalQuestions = 3;
    int score = 0;
    char userAnswer;

    string questions[totalQuestions] = {
        "1. What is the capital of India?",
        "2. Which language is used for system programming?",
        "3. Who is known as the father of computers?"
    };

    string options[totalQuestions][4] = {
        {"A. Mumbai", "B. New Delhi", "C. Kolkata", "D. Chennai"},
        {"A. Python", "B. Java", "C. C++", "D. HTML"},
        {"A. Charles Babbage", "B. Alan Turing", "C. Bill Gates", "D. Steve Jobs"}
    };

    char correctAnswers[totalQuestions] = {'B','C','A'};

    for (int i = 0; i < totalQuestions; i++){
        cout << "\n" << questions[i] << endl;
        for (int j = 0; j < 4; j++){
            cout << options[i][j] << endl;}
        cout << "Enter your answer (A / B / C / D): ";
        cin >> userAnswer;
        if (toupper(userAnswer) == correctAnswers[i]){
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Wrong! Correct Answer: " << correctAnswers[i] << endl;}
    }

    cout << "\n===== QUIZ FINISHED =====\n";
    cout << "Your Score: " << score << "/" << totalQuestions << endl;

    float percentage = (score * 100) / totalQuestions;
    cout << "Percentage: " << percentage << "%" <<  endl;

    if (percentage >= 75){
        cout << "Good Job!" << endl;
    } else {
        cout << "Keep Practicing" << endl;
    }
} 

// main
int main()
{
    cout << "=========================\n";
    cout << "   Welcome to C++ Quiz   \n";
    cout << "=========================\n";

    startQuiz();

    return 0;
}