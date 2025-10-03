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
            cout << "Invalid input. Please enter 1 or 2.\n\n";
        }
        
    }
        
    // Getting the rating and comment from the user
    while (again == 'y' || again == 'Y') {
        cout << endl;
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


//This function adds a new review at the beginning of the linked list
//It takes a reference to the head pointer, a double for the rating, and a string for the comment as parameters
//It returns nothing
void addBegining(MovieReview*& head, double rating, string comment) {
    bool valid = false;

    // Getting a valid rating from the user
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

    // Getting the comment from the user
    cout << "Enter comment: ";
    getline(cin, comment);

    // Creating a new MovieReview node and adding it to the beginning of the list
    MovieReview* newReview = new MovieReview;
    newReview->rating = rating;
    newReview->comment = comment;
    newReview->next = head;
    head = newReview;

}

//This function adds a new review at the end of the linked list
//It takes a reference to the head pointer, a double for the rating, and a string for the comment as parameters
//It returns nothing
void addEnd(MovieReview*& head, double rating, string comment) {
    bool valid = false;

    // Getting a valid rating from the user
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

    // Getting the comment from the user
    cout << "Enter comment: ";
    getline(cin, comment);

    // Creating a new MovieReview node
    MovieReview* newReview = new MovieReview;
    newReview->rating = rating;
    newReview->comment = comment;
    newReview->next = nullptr;

    // If the list is empty, make the new review the head
    if (head == nullptr) {
        head = newReview;
    } else {
        // Otherwise, traverse to the end of the list and add the new review there
        MovieReview* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newReview;
    }
  }

//This function displays all the reviews in the linked list and calculates the average rating
//It takes the head pointer as a parameter
//It returns nothing
void displayList(MovieReview* head) {
    
    double totalRating = 0;
    int count = 0;

    // If the list is empty, display a message and return    
    if (head == nullptr) {
        cout << "No reviews to display.\n";
        return;
    }
    
    MovieReview* temp = head;

    cout << "\nMovie Reviews:\n";
    while (temp != nullptr) {
        count++;
        cout << "Rating #" << count << ": " << temp->rating << ", Comment: " << temp->comment << "\n";
        
        totalRating += temp->rating;
        temp = temp->next;
    }

    double averageRating = totalRating / count;
    cout << "Average Rating: " << averageRating << "\n";
}

//This function deletes the entire linked list to free memory
//It takes a reference to the head pointer as a parameter
//It returns nothing
void deleteList(MovieReview*& head) {
    MovieReview* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}