#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 10;
const double TICKET_PRICE = 10.0;


vector<vector<bool>> seats(NUM_ROWS, vector<bool>(NUM_COLS, true));

void displaySeating() {
    cout << "Seat Map:\n";
    for (int row = 0; row < NUM_ROWS; ++row) {
        for (int col = 0; col < NUM_COLS; ++col) {
            if (seats[row][col]) {
                cout << "O "; 
            } else {
                cout << "X "; 
            }
        }
        cout << endl;
    }
}


double calculateTotalCost(int numTickets) {
    return numTickets * TICKET_PRICE;
}

int main() {
    int row, col, numTickets;
    
    cout << "Welcome to the Movie Ticket Booking System!\n";
    
    while (true) {
        cout << "\nMovie Listings:\n";
        cout << "1. Movie A\n";
        cout << "2. Movie B\n";
        cout << "3. Exit\n";
        
        int choice;
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        
        if (choice == 1 || choice == 2) {
            cout << "You selected Movie " << (choice == 1 ? "A" : "B") << ".\n";
            displaySeating();
            
            cout << "Enter the number of tickets you want to book: ";
            cin >> numTickets;
            
            if (numTickets <= 0) {
                cout << "Invalid number of tickets. Please try again.\n";
                continue;
            }
            
            cout << "Enter the row and column numbers (e.g., 1 2) for each seat you want to book:\n";
            
            for (int i = 0; i < numTickets; ++i) {
                cout << "Ticket " << i + 1 << ": ";
                cin >> row >> col;
                
                if (row < 1 || row > NUM_ROWS || col < 1 || col > NUM_COLS || !seats[row - 1][col - 1]) {
                    cout << "Invalid seat selection. Please try again.\n";
                    --i; 
                } else {
                    seats[row - 1][col - 1] = false; 
                }
            }
            
            double totalCost = calculateTotalCost(numTickets);
            cout << "Booking successful!\n";
            cout << "Total cost: $" << fixed << setprecision(2) << totalCost << endl;
        } else if (choice == 3) {
            cout << "Thank you for using the Movie Ticket Booking System. Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
