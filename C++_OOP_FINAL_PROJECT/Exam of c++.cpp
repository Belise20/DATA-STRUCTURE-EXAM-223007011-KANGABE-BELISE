#include <iostream>
#include <cstring>
using namespace std;

// Structure for a multiple-choice question
struct Question {
    char prompt[100];
    char choices[4][40];
    int correctIdx;
};

// Base abstract class
class QuizParticipant {
public:
    virtual int attempt(Question* questions, int num) = 0;
    virtual ~QuizParticipant() {}
};

// Registered participant: gets score
class RegisteredParticipant : public QuizParticipant {
public:
    int attempt(Question* questions, int num) {
        int score = 0;
        cout << "\n[Registered Participant Attempting Quiz]\n";
        for (int i = 0; i < num; i++) {
            Question* q = questions + i;
            cout << "\nQ" << (i + 1) << ": " << q->prompt << "\n";
            for (int j = 0; j < 4; j++) {
                cout << j << ") " << q->choices[j] << "\n";
            }
            int ans;
            cout << "Your answer (0-3): ";
            cin >> ans;
            if (ans == q->correctIdx)
                score++;
        }
        cout << "Score: " << score << "/" << num << "\n";
        return score;
    }
};

// Guest participant: no score shown
class GuestParticipant : public QuizParticipant {
public:
    int attempt(Question* questions, int num) {
        cout << "\n[Guest Participant Attempting Quiz]\n";
        for (int i = 0; i < num; i++) {
            Question* q = questions + i;
            cout << "\nQ" << (i + 1) << ": " << q->prompt << "\n";
            for (int j = 0; j < 4; j++) {
                cout << j << ") " << q->choices[j] << "\n";
            }
            int ans;
            cout << "Your answer (0-3): ";
            cin >> ans;
        }
        cout << "(Results are available for registered users only)\n";
        return 0;
    }
};

// Add a new question
Question* addQuestion(Question* questions, int& size, Question newQ) {
    Question* newArr = new Question[size + 1];
    for (int i = 0; i < size; i++) {
        newArr[i] = questions[i];
    }
    newArr[size] = newQ;
    delete[] questions;
    size++;
    return newArr;
}

// Remove a question by index
Question* removeQuestion(Question* questions, int& size, int index) {
    if (index < 0 || index >= size) return questions;
    Question* newArr = new Question[size - 1];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (i != index)
            newArr[j++] = questions[i];
    }
    delete[] questions;
    size--;
    return newArr;
}

int main() {
    int numQuestions = 0;
    Question* questions = nullptr;

    // Add sample question 1
    Question q1;
    strcpy(q1.prompt, "What is the capital of France?");
    strcpy(q1.choices[0], "Berlin");
    strcpy(q1.choices[1], "Madrid");
    strcpy(q1.choices[2], "Paris");
    strcpy(q1.choices[3], "Rome");
    q1.correctIdx = 2;
    questions = addQuestion(questions, numQuestions, q1);

    // Add sample question 2
    Question q2;
    strcpy(q2.prompt, "Which planet is known as the Red Planet?");
    strcpy(q2.choices[0], "Earth");
    strcpy(q2.choices[1], "Mars");
    strcpy(q2.choices[2], "Jupiter");
    strcpy(q2.choices[3], "Saturn");
    q2.correctIdx = 1;
    questions = addQuestion(questions, numQuestions, q2);

    // Create participants
    QuizParticipant** participants = new QuizParticipant*[2];
    participants[0] = new GuestParticipant();
    participants[1] = new RegisteredParticipant();

    // Each participant attempts the quiz
    participants[0]->attempt(questions, numQuestions);  // Guest
    participants[1]->attempt(questions, numQuestions);  // Registered

    // Remove question at index 0
    questions = removeQuestion(questions, numQuestions, 0);
    cout << "\nAfter removing the first question, remaining questions:\n";
    for (int i = 0; i < numQuestions; i++) {
        cout << "Q" << i + 1 << ": " << questions[i].prompt << "\n";
    }

    // Cleanup
    for (int i = 0; i < 2; i++)
        delete participants[i];
    delete[] participants;
    delete[] questions;

    return 0;
}

