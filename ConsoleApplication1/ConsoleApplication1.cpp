/**
 * QUEUE - LILO/FIFO
 *
 * CRUD:
 * - Create
 *  - Insertion: Somewhere in between nodes iin a linkedlist
 *  - Append : Adds at the end of the linkedlist
 * - Read
 *  - Traversal : Read the linkedlist from the start to end
 *  - Searching : Which checks the value based on parameters if they matched
 * - Update
 * - Delete
 *  - Head
 *  - Tail
 *  - Between
 *
 * Markers:
 * - Head : Indicates the first data in the linkedlist
 * - Tail : Indicates the last data in the linkedlist
 * - Curr : Indicates the current data in the linkedlist
 * - PrevCurr : Indicates the previous data of the current data in the
 * linkedlist
 * - Temp : Indicates the temporary data in the linkedlist
 */

#include <array>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct ItemData {
    int id = 0, score = 0;
    string name = "";
};

struct ItemNode {
    // address/pointer member
    ItemNode* next = nullptr;

    // data/information member
    ItemData data;
};

struct Question {
    std::string text;
    char correctAnswer;
};

void InputInstruction(string instruction, string& data);
void InputInstruction(string instruction, int& data);

void MainMenu(const string INSTRUCTIONS[], const int MAX, int& choice);

void CreateNode(ItemNode*& head, ItemNode*& tail, int& counter);

void ReadList(ItemNode* head);

void SearchNode(ItemNode* head);

void TraverseList(ItemNode* head);

int main() {
    const string INSTRUCTIONS[] = { "New Game", "Search"};
    const int MAX = end(INSTRUCTIONS) - begin(INSTRUCTIONS);
    const int numQuestions = 10;
    Question questions[numQuestions] = { {"What is the english of the word Salapi? \n   a) Money\n   b) King\n   c) Egg\n   d) Sandwich", 'a'},
        {"What is the english of the word Bayani? \n   a) Hero\n   b) Villain\n   c) Captain\n   d) Boy", 'a'},
        {"What is the filipino word of the word Table? \n   a) Libro\n   b) Salamin\n   c) Pintuan\n   d) Lamesa", 'd'},
        {"What is the english of the word Pitaka? \n   a) Phone\n   b) CPU\n   c) Wallet\n   d) Neptune", 'c'},
        {"What is the english of the word the word Nagmuni-muni? \n   a) Laptop\n   b) Chair\n   c) Ponder\n   d) Cauldron", 'c'},
        {"What is the english of the word Tampo? \n   a) Sulk\n   b) Charger\n   c) Wire\n   d) Table", 'a'},
        {"What is the english of the word Hagdanan? \n   a) Ladder\n   b) Stairs\n   c) Elevator\n   d) Escalator", 'c'},
        {"What is the filipino word of the word Chair? \n   a) Bolpen\n   b) Bag\n   c) Upuan\n   d) Selpon", 'c'},
        {"What is the filipino word of the word Door? \n   a) Pader\n   b) Pintuan\n   c) Kamay\n   d) Paa", 'b'},
        {"What is the English of the word Ulo? \n   a) Head\n   b) Hair\n   c) Light\n   d) Shirt", 'a'}
    };
    char userAnswers[numQuestions];
    int choice, counter = 0, score = 0;
    ItemNode* head = nullptr, * tail = nullptr;

    do {
        MainMenu(INSTRUCTIONS, MAX, choice);

        switch (choice) {
        case 1:
            CreateNode(head, tail, counter);
            for (int i = 0; i < numQuestions; i++) {
                std::cout << questions[i].text << std::endl;
                std::cout << "Your answer: ";
                std::cin >> userAnswers[i];
            }
            break;
        case 2:
            SearchNode(head);
            break;
        case 0:
            exit(0);

        default:
            break;
        }
    } while (true);

    system("pause");
    return 0;
}

void InputInstruction(string instruction, string& data) {
    cout << instruction << endl;
    getline(cin, data);
}

void InputInstruction(string instruction, int& data) {
    cout << instruction << endl;
    cin >> data;
}

void MainMenu(const string INSTRUCTIONS[], const int MAX, int& choice) {
    cout << "Game Menu: \n\n";
    if (MAX > 0) {
        for (int i = 0; i < MAX; i++) {
            cout << i + 1 << ": " << INSTRUCTIONS[i] << endl;
        }
        cout << "0. Exit\n";
        cout << ":: ";
        cin >> choice;
    }
    else {
        cout << "No Functions yet are available.\n\n\n";
    }
    system("cls");
}

void CreateNode(ItemNode*& head, ItemNode*& tail, int& counter) {
    ItemNode* temp = new ItemNode;

    cout << "Add new player: \n";
    cin.ignore();
    InputInstruction("Enter Name: ", temp->data.name);
    temp->data.id = 1;
    cin.ignore();
    temp->data.id = counter;

    system("cls");

    if (head) {
        tail->next = temp;
        tail = temp;

        cout << "Added New Player\n\n\n";
        cout << "Your ID is: " << temp->data.id << endl;
    }
    else {

        tail = temp;

        cout << "Created New Game and Added New Player\n\n\n";
        cout << "Your ID is: " << temp->data.id << endl;
    }

    counter++;
}

void SearchNode(ItemNode* head) {
    ItemNode* curr = head;
    int WhatToFind;

    TraverseList(head);
    cout << "ID to check full details: ";
    cin >> WhatToFind;

    system("cls");

    while (curr) {
        if (curr->data.id == WhatToFind) {
            cout << curr->data.id << ". " << curr->data.name
                << " | ID: " << curr->data.id
                << " | Score: " << curr->data.score << endl;
            system("pause");
            system("cls");
            return;
        }

        curr = curr->next;
    }

    system("cls");
}

void TraverseList(ItemNode* head) {
    ItemNode* curr = head;
    int counter = 1;

    while (curr) {
        cout << counter << ". " << curr->data.name << " | ID: " << curr->data.id
            << " | Score: " << curr->data.score << endl;

        curr = curr->next;
        counter++;
    }
}

void AnswerChecker(char userAnswers[], Question questions[]) {
    if (tolower(userAnswers[i]) == questions[i].correctAnswer) {
        score++;
    }
}