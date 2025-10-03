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
    int choice;
    double rating;
    string comment;

    while(!valid){
        cout << "Menu:\n";
        cout << "1. Add review at the beginning\n";
        cout << "2. Add review at the end\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) valid = true;
            
        else if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter 1 or 2.\n";
        }
        else cout << "Invalid choice. Please enter 1 or 2.\n";
    }
        
       

    return 0;
}