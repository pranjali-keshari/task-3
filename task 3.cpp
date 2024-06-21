#include <iostream>
using namespace std;

char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

void show_board();
void get_x_player_choice();
void get_o_player_choice();
char check_winner();
void player_vs_player();
int count_total(char s);

int main() {
    player_vs_player();
    return 0;
}

void get_x_player_choice() {
    while (true) {
        cout << "Select your position (1-9): ";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8) {
            cout << "\nPlease select your position from (1-9)." << endl;
        } else if (board[choice] != ' ') {
            cout << "\nPlease select an empty position," << endl;
        } else {
            board[choice] = 'x';
            break;
        }
    }
}

void get_o_player_choice() {
    while (true) {
        cout << "Select your position (1-9): ";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8) {
            cout << "Please select your position from (1-9)." << endl;
        } else if (board[choice] != ' ') {
            cout << "Please select an empty position," << endl;
        } else {
            board[choice] = 'o';
            break;
        }
    }
}

int count_total(char s) {
    int total = 0;
    for (int i = 0; i < 9; i++) {
        if (board[i] == s)
            total += 1;
    }
    return total;
}

void player_vs_player() {
    string x_player_name, o_player_name;
    cout << "\nEnter X player name: ";
    cin >> x_player_name;
    cout << "\nEnter O player name: ";
    cin >> o_player_name;
    while (true) {
        system("cls"); 
        show_board();
        if (count_total('x') == count_total('o')) {
            cout << "\n" << x_player_name << "'s turn";
            get_x_player_choice();
        } else {
            cout << "\n" << o_player_name << "'s turn";
            get_o_player_choice();
        }
        char winner = check_winner();
        if (winner == 'x') {
            system("cls");
            show_board();
            cout << x_player_name << " wins the game!....." << endl;
            break;
        } else if (winner == 'o') {
            system("cls");
            show_board();
            cout << o_player_name << " wins the game!....." << endl;
            break;
        } else if (winner == 'd' && count_total('x') + count_total('o') == 9) {
            system("cls");
            show_board();
            cout << "Game is a draw." << endl;
            break;
        }
    }
}

void show_board() {
	cout << "\n\n\t\t-------TIC TAC TOE-------\n";
	cout << "\t\t-------------------------\n\n\n";
    cout << "\t\t\t " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "\t\t\t---|---|---" << endl;
    cout << "\t\t\t " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "\t\t\t---|---|---" << endl;
    cout << "\t\t\t " << board[6] << " | " << board[7] << " | " << board[8] << endl;
    cout << "\n\n\t\t-------------------------\n\n\n";
}

char check_winner() {
    if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
        return board[0];
    else if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
        return board[3];
    else if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
        return board[6];
    else if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
        return board[0];
    else if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
        return board[1];
    else if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
        return board[2];
    else if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
        return board[0];
    else if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
        return board[2];
    else
        return 'd';
}