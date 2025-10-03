//COMSC-210|Lab-18|Ethan Aylard
//IDE used: Visual Studio Code
//This Program uses linked lists to store and display movie reviews and will offer two methods to enter into the list:

#include <iostream>
using namespace std;

struct MovieReview
{
    double rating;
    string comment;
    MovieReview* next;
};

void addBegining(MovieReview*& head, double rating, string comment);
void addEnd(MovieReview*& head, double rating, string comment);
void displayList( MovieReview* head);
void deleteList(MovieReview*& head);


int main()
{
    MovieReview* head = nullptr;
    bool valid = false;
    char again = 'y';
    int choice;
    double rating;
    string comment;

    // Having the user choose how to add a review using a while loop

    while(!valid){
        cout << "Menu:\n";
        cout << "1. Add review at the beginning\n";
        cout << "2. Add review at the end\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) valid = true;
        //if the input is invalid, the loop will repeat 
        else if(cin.fail() || choice < 1 || choice > 2){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter 1 or 2.\n";
        }
        
    }
        
    // Getting the rating and comment from the user
    while (again == 'y' || again == 'Y') {
        
        if (choice == 1) {
            addBegining(head, rating, comment);
        } else if (choice == 2) {
            addEnd(head, rating, comment);
        }

        cout << "Do you want to add another review? (y/n): ";
        cin >> again;
        cin.ignore(); // To ignore the newline character after the char input
    }
   
    // Displaying the list of reviews
    displayList(head);


    //deleting the list to free memory
    deleteList(head);
       

    return 0;
}

void addBegining(MovieReview*& head, double rating, string comment) {
    bool valid = false;

    while (!valid) {
        cout << "Enter rating (1-5): ";
        cin >> rating;
        cin.ignore(1000, '\n');
        if (cin.fail() || rating < 1 || rating > 5) {
            cin.clear();
            cout << "Invalid input. Please enter a rating between 1 and 5.\n";
        } else {
            valid = true;
        }
    }
    
    cout << "Enter comment: ";
    getline(cin, comment);

    MovieReview* newReview = new MovieReview{rating, comment, head};
    head = newReview;
}