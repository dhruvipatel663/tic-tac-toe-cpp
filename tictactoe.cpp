#include <iostream>
using namespace std;
int main()
{
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};
    char player0 = '0';
    char playerX = 'X';
    char currentPlayer = player0;

    cout << "Let's start the game!" << endl;
    int r = -1;
    int c = -1;
    char winner = ' ';

    cout << "   |   |   " << endl;
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "   |   |   " << endl;

    for (int i = 0; i < 9; i++)
    {
        if (winner != ' ')
        {
            break;
        }
        cout << "Current player is: " << currentPlayer << endl;
        while (true)
        {
            cout << currentPlayer << ", " << "please enter the value for row and column between 0 to 2: ";
            cin >> r >> c;
            if (r < 0 || r > 2 || c < 0 || c > 2)
            {
                cout << "Invalid input, try again." << endl;
            }
            else if (board[r][c] != ' ')
            {
                cout << "Tile is full, try again." << endl;
            }
            else
            {
                break;
            }
            r = -1;
            c = -1;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        board[r][c] = currentPlayer;
        currentPlayer = currentPlayer == player0 ? playerX : player0;

        cout << "   |   |   " << endl;
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout << "   |   |   " << endl;

        for (int r = 0; r < 3; r++)
        {
            if (board[r][0] != ' ' && board[r][0] == board[r][1] && board[r][1] == board[r][2])
            {
                winner = board[r][0];
                break;
            }
        }

        for (int c = 0; c < 3; c++)
        {
            if (board[0][c] != ' ' && board[0][c] == board[1][c] && board[1][c] == board[2][c])
            {
                winner = board[0][c];
                break;
            }
        }

        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            winner = board[0][0];
        }
        else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            winner = board[0][2];
        }
    }
    if (winner != ' ')
    {
        cout << "Player " << winner << " is the winner!" << endl;
    }
    else
    {
        cout << "Tie!" << endl;
    }
    return 0;
}