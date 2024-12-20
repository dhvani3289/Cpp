#include <iostream>
using namespace std;

int main()
{
    int score;
    char grade;

    cout << "Enter your score (out of 100): ";
    cin >> score;

    grade = (score >= 85 && score <= 100) ? 'A'
            : (score >= 70 && score < 85) ? 'B'
            : (score >= 55 && score < 70) ? 'C'
            : (score >= 40 && score < 55) ? 'D'
                                          : 'F';

    cout << "Your grade is: " << grade << endl;

    switch (grade)
    {
    case 'A':
        cout << "Excellent work!" << endl;
        break;
    case 'B':
        cout << "Well done!" << endl;
        break;
    case 'C':
        cout << "Good job." << endl;
        break;
    case 'D':
        cout << "You Passed, but you could do better." << endl;
        break;
    case 'F':
        cout << "Sorry, you failed." << endl;
        break;
    default:
        cout << "Invalid grade." << endl;
    }

    if (grade == 'A' || grade == 'B' || grade == 'C' || grade == 'D')
    {
        cout << "Congratulations! You are eligible for the next level." << endl;
    }
    else
    {
        cout << "Please try again next time" << endl;
    }
    return 0;
}