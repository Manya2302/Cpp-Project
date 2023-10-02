#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

class Login {
protected:
    char email[20], pass[8];

public:
    Login() {}

    void displaylog() {
	cout << "         --------------------------------------------------------------" << endl;
	cout << "           Press any key " << email << " to login to the Movie Ticket Booking System" << endl;
	cout << "         --------------------------------------------------------------" << endl;
    }

    int operator==(Login temp) {
	int n;
	n = strcmp(email, temp.email);
	if (n == 0) {
	    n = strcmp(pass, temp.pass);
	    if (n == 0) {
		cout << endl << endl;
		cout << "        -----------------------------------------------------------" << endl;
		cout << "               Congratulations! You Successfully logged in" << endl;
		cout << "        -----------------------------------------------------------" << endl;
		cout << endl;
		cout << "      -----------------------------------------------------------" << endl;
		cout << "          Press any key " << email << " to the Movie Ticket Booking System" << endl;
		cout << "      -----------------------------------------------------------" << endl;

		return 1;
	    } else {
		cout << endl << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << "                      Enter Valid password" << endl;
		cout << "-----------------------------------------------------------" << endl;
		return 0;
	    }
	} else {
	    cout << endl << endl;
	    cout << "-----------------------------------------------------------" << endl;
	    cout << "                     Enter Valid Email" << endl;
	    cout << "-----------------------------------------------------------" << endl;
	    return 0;
	}
    }

    void reg() {
	cout << "                     Enter Email Id:";
	cin >> email;
	cout << "                     Enter Password:";
	cin >> pass;
    }
};

class Movie {
public:
    char m_Title[50];
    char m_Type[50];
    char m_Duration[50];
    char m_Rating[50];
    char m_Lang[50];

    void setMovieDetails(const char title[], const char type[], const char duration[], const char rating[], const char lang[]) {
	strcpy(m_Title, title);
	strcpy(m_Type, type);
	strcpy(m_Duration, duration);
	strcpy(m_Rating, rating);
	strcpy(m_Lang, lang);
    }

    void displayMovieDetails() {
	cout << "     -----------------------------------------------------------" << endl;
	cout << "                Welcome to the Login Screen                   " << endl;
	cout << "     -----------------------------------------------------------" << endl;
	cout << "Movie Title: " << m_Title << endl;
	cout << "Movie Type: " << m_Type << endl;
	cout << "Movie Duration: " << m_Duration << endl;
	cout << "Movie Rating: " << m_Rating << endl;
	cout << "Movie Language: " << m_Lang << endl;
    }
};

class SeatReservation {
private:
    bool seats[MAX_ROWS][MAX_COLS];

public:
    SeatReservation() {
        // Initialize all seats as available
        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                seats[i][j] = false;
            }
        }
    }

    void displaySeats() {
        // Display seat availability
        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                if (seats[i][j]) {
                    cout << "[ X ] ";
                } else {
                    cout << "[ " << char('A' + i) << j + 1 << " ] ";
                }
            }
            cout << endl;
        }
    }

    void bookSeats() {
        int numSeats;

        cout << "Enter the number of seats you want to book: ";
        cin >> numSeats;

        if (numSeats <= 0) {
            cout << "Invalid number of seats.\n";
            return;
        }

        // Clear input buffer
        cin.ignore(10000, '\n'); // Assuming 10000 is large enough

        cout << "Enter seat selections:\n";
        for (int i = 0; i < numSeats; i++) {
            char rowChar;
            int colNum;

            cout << "Seat " << i + 1 << ":\n";
            cout << "Enter row (A-" << char('A' + MAX_ROWS - 1) << "): ";
            cin >> rowChar;
            rowChar = toupper(rowChar);
            cout << "Enter column (1-" << MAX_COLS << "): ";
            cin >> colNum;

            int row = rowChar - 'A';
            colNum--;

            if (row >= 0 && row < MAX_ROWS && colNum >= 0 && colNum < MAX_COLS) {
                if (!seats[row][colNum]) {
                    seats[row][colNum] = true;
                    cout << "Seat " << rowChar << colNum + 1 << " booked successfully.\n";
                } else {
                    cout << "Seat " << rowChar << colNum + 1 << " is already booked. Please choose another seat.\n";
                    i--; // Decrement i to reattempt booking for the same seat
                }
            } else {
                cout << "Invalid seat selection. Please try again.\n";
                i--; // Decrement i to reattempt seat selection
            }
        }

        displaySeats(); // Display booked seats
    }
};





int main() {
    clrscr();
    Login user;
    cout << "           ------------------------------------------------------------" << endl;
    cout << "                     WELCOME To Movie Ticket Booking System            " << endl;
    cout << "           -----------------------------------------------------------" << endl;
    cout << "                     Registration Page" << endl;
    cout << "           -----------------------------------------------------------" << endl;
    user.reg();
    cout << endl << endl;
    cout << "                     Registration Successfully" << endl;
    cout << endl << endl;
    user.displaylog();
    getch();
    clrscr();
    cout << "     -----------------------------------------------------------" << endl;
    cout << "                Welcome to the Login Screen                   " << endl;
    cout << "     -----------------------------------------------------------" << endl;
    cout << "        Enter Email id and Password for login                   " << endl;
    cout << endl;
    Login temp;
    temp.reg();
    if (user == temp) {
	getch();
	clrscr();

	int choice;
	while (1) {
    cout << "     -----------------------------------------------------------" << endl;
    cout << "                Welcome to the Login Screen                   " << endl;
    cout << "     -----------------------------------------------------------" << endl;

	    cout << "            1. Select Movie" << endl;
	    cout << "            2. Get Booking Details" << endl;
	    cout << "            3. Exit" << endl;
	    cout << "            Enter your choice: ";
	    cin >> choice;
	    getch();
	    clrscr();
	    switch (choice) {
		case 1: {
		    int movieChoice;
		    Movie selectedMovie;

		    do {
			cout << "     -----------------------------------------------------------" << endl;
			cout << "                Welcome to the Login Screen                   " << endl;
			cout << "     -----------------------------------------------------------" << endl;
			cout << "\nMenu:\n";
			cout << "1. Select Movie Details\n";
			cout << "2. Display Selected Movie Details\n";
			cout << "3. Return to the Main Menu\n";
			cout  <<"4. Select the seats for movie";
			cout << "5. Exit\n";
			cout << "Enter your choice: ";
			cin >> movieChoice;
			  getch();
			  clrscr();

			switch (movieChoice) {
			    case 1: {
				int movieTitleChoice;
				cout << "     -----------------------------------------------------------" << endl;
				cout << "                Welcome to the Login Screen                   " << endl;
				cout << "     -----------------------------------------------------------" << endl;
				cout << "Select a movie title:\n";
				cout<<endl;
				cout << "1. Avengers: Endgame Action 2:00:00 4.5 English\n";
				cout<<endl;
				cout << "2. Gadar 2 Action 2:06:00 5 Hindi\n";cout<<endl;
				cout << "3. OMG 2 Comedy 2:07:00 4.8 Hindi\n";cout<<endl;
				cout << "4. 3 Aekka Comedy 1:50:00 4.6 Gujrati\n";cout<<endl;
				cout << "5. Ra-One Action 2:07:00 4.7 Hindi\n"; cout<<endl;
				cout << "6. Another Movie ""\n"; cout<<endl;
				cout << "Enter your choice: ";
				cin >> movieTitleChoice;

				switch (movieTitleChoice) {
				    case 1:
					strcpy(selectedMovie.m_Title, "Avengers: Endgame");
					strcpy(selectedMovie.m_Type, "Action");
					strcpy(selectedMovie.m_Duration, "2:00:00");
					strcpy(selectedMovie.m_Rating, "4.5");
					strcpy(selectedMovie.m_Lang, "English");
					break;
				    case 2:
					strcpy(selectedMovie.m_Title, "Gadar 2");
					strcpy(selectedMovie.m_Type, "Action");
					strcpy(selectedMovie.m_Duration, "2:06:00");
					strcpy(selectedMovie.m_Rating, "5");
					strcpy(selectedMovie.m_Lang, "Hindi");
					break;
				    case 3:
					strcpy(selectedMovie.m_Title, "OMG 2");
					strcpy(selectedMovie.m_Type, "Comedy");
					strcpy(selectedMovie.m_Duration, "2:07:00");
					strcpy(selectedMovie.m_Rating, "4.8");
					strcpy(selectedMovie.m_Lang, "Hindi");
					break;
				    case 4:
					strcpy(selectedMovie.m_Title, "3 Aekka");
					strcpy(selectedMovie.m_Type, "Comedy");
					strcpy(selectedMovie.m_Duration, "1:50:00");
					strcpy(selectedMovie.m_Rating, "4.6");
					strcpy(selectedMovie.m_Lang, "Gujrati");
					break;
				    case 5:
					strcpy(selectedMovie.m_Title, "Ra-One");
					strcpy(selectedMovie.m_Type, "Action");
					strcpy(selectedMovie.m_Duration, "2:07:00");
					strcpy(selectedMovie.m_Rating, "4.7");
					strcpy(selectedMovie.m_Lang, "Hindi");
					break;
				    case 6:
					strcpy(selectedMovie.m_Title, "Another Movie");
					strcpy(selectedMovie.m_Type, "");
					strcpy(selectedMovie.m_Duration, "");
					strcpy(selectedMovie.m_Rating, "");
					strcpy(selectedMovie.m_Lang, "");
					break;
				    default:
					cout << "Invalid movie title choice.\n";
					continue;
				}
				break;
			    }
			    case 2: {
				if (selectedMovie.m_Title[0] == '\0') {
				    cout << "No movie selected yet.\n";
				} else {

				    selectedMovie.displayMovieDetails();
				}
				break;
			    }

			    case 3:
				  break;
				case 4:
				getch();
				clrscr();
				SeatReservation reservation;
    char choice;

    do {
        cout << "Seat Reservation System\n";
        cout << "1. Display Available Seats\n";
        cout << "2. Book Seats\n";  // Updated option label
        cout << "3. View Booked Seats\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                reservation.displaySeats();
                break;
            case '2':
                reservation.bookSeats();  // Updated function call
                break;
            case '3':
                cout << "Booked Seats:\n";
                reservation.displaySeats();
                break;
            case '4':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != '4');


			    case 5:
				exit(0);
			}
			cout<<endl;
			cout<<endl;
	cout << "         --------------------------------------------------------------" << endl;
	cout << "           Press any key return to the menu" << endl;
	cout << "         --------------------------------------------------------------" << endl;

			getch();
			clrscr();
		    } while (movieChoice != 3);
		    break;
		}
		case 2:
		    // Code for getting booking details
		    break;
		case 3:
		    exit(0);
		default:
		    cout << "Invalid choice! Please select a valid option." << endl;
	    }
	}
    } else {
        cout << "Login failed! Exiting..." << endl;
    }

    getch();
    return 0;
}
