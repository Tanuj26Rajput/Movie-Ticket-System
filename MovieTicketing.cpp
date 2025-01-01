#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Movie{
public:
    string Movie_name;
    string Movie_time;
    string Movie_date;
    int Movie_price;
    vector<vector<int>> seats;
    Movie(string name, string time, string date, int price){
        Movie_name = name;
        Movie_time = time;
        Movie_date = date;
        Movie_price = price;
        seats = vector<vector<int>>{10, vector<int>(10, 0)};
    }
    void bookTicket(int row, int col){
        bool ticket_booked = false;
        if(seats[row][col] == 0){
            seats[row][col] = 1;
            cout << "Ticket booked successfully" << endl;
            cout << "Seat number: "<< row << col << endl;
            ticket_booked = true;
            return;
        }
        if(!ticket_booked){
            cout << "Seat not available" << endl << endl;
        }
    }
    
    void cancelTicket(int row, int col){
        bool ticket_cancelled = false;
        if(seats[row][col] == 1){
            seats[row][col] = 0;
            cout << "Ticket cancelled successfully" << endl;
            cout << "Seat number: "<< row<<col<<endl <<endl;
            ticket_cancelled = true;
            return;
        }
        if(!ticket_cancelled){
            cout << "Ticket not found" <<endl<<endl;
        }
    }
    void seatsAvailable(){
        int available_seats = 0;
        for(int row = 0;row<10;row++){
            for(int col = 0; col<10;col++){
                if(seats[row][col] == 0){
                    available_seats++;
                }
            }
        }
        cout << "Available seats are: "<< available_seats << endl << endl;
    }
};

int main(){
    cout<<"welcome to Movie Ticketing System" << endl;
    vector<Movie> movies = {
        Movie("Thunderbolts", "12:00 PM", "14/02/2025", 200),
        Movie("Captain America: The Brave New World", "3:00 PM", "14/02/2025", 200),
        Movie("Superman", "6:00 PM", "14/02/2025", 200),
        Movie("War 2", "9:00 PM", "14/02/2025", 200)
    };
    while(true){
        cout<<"1. Available Movies" << endl;
        cout<<"2. Book a ticket" << endl;
        cout<<"3. Cancel a ticket" << endl;
        cout<<"4. Seats Available" << endl;
        int choice;
        cout << "Enter you choice: ";
        cin >> choice;
        if(choice == 1){
            cout << endl <<  "Avaialble Movies" << endl << endl;
            for(int i = 0; i<movies.size(); i++){
                cout << "Movie Name: " << movies[i].Movie_name << endl;
                cout << "Movie Time: " << movies[i].Movie_time << endl;
                cout << "Movie Date: " << movies[i].Movie_date << endl;
                cout << "Movie price: "<< movies[i].Movie_price << endl << "-----------------------------------"  << endl;
            }
        }
        else if(choice == 2){
            cin.ignore();
            string name;
            cout << "Enter the name of the movie you want to book: ";
            getline(cin, name);
            for(int i = 0;i<movies.size();i++){
                if(movies[i].Movie_name == name){
                    int row, col;
                    cout << "Enter the row number: ";
                    cin >> row;
                    cout << "Enter the column number: ";
                    cin >> col;
                    movies[i].bookTicket(row, col);
                }
            }
        }
        else if(choice == 3){
            cin.ignore();
            string name;
            cout << "Enter the name of the movie you want to cancel ticket: ";
            getline(cin, name);
            for(int i = 0;i<movies.size();i++){
                if(movies[i].Movie_name == name){
                    int row, col;
                    cout << "Enter the row number: ";
                    cin >> row;
                    cout << "Enter the column number: ";
                    cin >> col;
                    movies[i].cancelTicket(row, col);
                }
            }
        }
        else if(choice == 4){
            cin.ignore();
            string name;
            cout << "Enter the name of the movie you want to check available seats: ";
            getline(cin, name);
            for(int i = 0;i<movies.size();i++){
                if(movies[i].Movie_name == name){
                    movies[i].seatsAvailable();
                }
            }
        }
    }
}
