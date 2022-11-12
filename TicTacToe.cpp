// was originally created in 20th February 2018

#include <iostream>
#include <windows.h>
using namespace std;

void draw(char tab[3][3], int order);
void check(char tab[3][3], bool& finish);
void win(char winner, bool finish);

int main() {
    char tablo[3][3];
    int que = 0;
    bool finished = false;
    //default tablo
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            tablo[i][j] = ' ';
    }

    while (!finished) {
        if (que % 2 == 0) {
            system("cls");
            draw(tablo, 1);
            int x, y;
            while (true) {
                cin >> x >> y;
                if (x < 3 && x > -1 && y < 3 && y > -1) {
                    if (tablo[x][y] == ' ') {
                        tablo[x][y] = 'X';
                        break;
                    }
                    else if (x == NULL && y == NULL || x == NULL || y == NULL) {
                        cout << "Enter value for both row and column: ";
                    }
                    else
                        cout << "Enter empty place: ";
                }
                else
                    cout << "Values are not acceptable: ";
            }
        }
        else {
            system("cls");
            draw(tablo, 2);
            int x, y, control = 0;
            while (true) {
                cin >> x >> y;
                if (x < 3 && x > -1 && y < 3 && y > -1) {
                    if (tablo[x][y] == ' ') {
                        tablo[x][y] = 'O';
                        break;
                    }
                    else if (x == NULL && y == NULL || x == NULL || y == NULL) {
                        cout << "Enter value for both row and column: ";
                    }
                    else
                        cout << "Enter empty place: ";
                }
                else
                    cout << "Values are not acceptable: ";
            }
        }
        check(tablo, finished);
        que++;
    }

    return 0;
}

// ---------- FUNCTIONS ----------
// ---------- draw func ----------
void draw(char tab[3][3], int order) {
    cout << "  0  1  2\n";
    for (int i = 0; i < 3; i++) {
        cout << i;
        for (int j = 0; j < 3; j++)
            cout << '|' << tab[i][j] << '|';
        cout << endl;
    }

    if (order == 1) {
        cout << endl << "Player 1: X  <--\n";
        cout << "Player 2: O\n";
        cout << "Coordinates (e.g: 0 1 (0 is row, 1 is column)): ";
    }
    else if (order == 2) {
        cout << endl << "Player 1: X\n";
        cout << "Player 2: O  <--\n";
        cout << "Coordinates (e.g: 0 1 (0 is row, 1 is column)):";
    }
}

// --------- check func -----------
void check(char tab[3][3], bool& finish) {
    if (tab[0][0] == 'X' && tab[0][1] == 'X' && tab[0][2] == 'X' || tab[0][0] == 'O' && tab[0][1] == 'O' && tab[0][2] == 'O') win(tab[0][0], finish);

    else if (tab[0][0] == 'X' && tab[1][0] == 'X' && tab[2][0] == 'X' || tab[0][0] == 'O' && tab[1][0] == 'O' && tab[2][0] == 'O') win(tab[0][0], finish);

    else if (tab[1][0] == 'X' && tab[1][1] == 'X' && tab[1][2] == 'X' || tab[1][0] == 'O' && tab[1][1] == 'O' && tab[1][2] == 'O') win(tab[1][0], finish);

    else if (tab[2][0] == 'X' && tab[2][1] == 'X' && tab[2][2] == 'X' || tab[2][0] == 'O' && tab[2][1] == 'O' && tab[2][2] == 'O') win(tab[2][0], finish);

    else if (tab[0][1] == 'X' && tab[1][1] == 'X' && tab[2][1] == 'X' || tab[0][1] == 'O' && tab[1][1] == 'O' && tab[2][1] == 'O') win(tab[0][1], finish);

    else if (tab[0][2] == 'X' && tab[1][2] == 'X' && tab[2][2] == 'X' || tab[0][2] == 'O' && tab[1][2] == 'O' && tab[2][2] == 'O') win(tab[0][2], finish);

    else if (tab[0][0] == 'X' && tab[1][1] == 'X' && tab[2][2] == 'X' || tab[0][0] == 'O' && tab[1][1] == 'O' && tab[2][2] == 'O') win(tab[0][0], finish);
}

// ------------- win func -------------
void win(char winner, bool finish) {
    finish = true;
    system("cls");
    cout << "######################################\n";
    cout << "---------------Winner " << winner << "---------------\n";
    cout << "@@@@@@@@                      @@@@@@@@\n";
    cout << "$$$$$$$$$$$$$            $$$$$$$$$$$$$\n";
    cout << "&&&&&&&&&&&&&&&&&&  &&&&&&&&&&&&&&&&&&\n";
    cout << "                  ~~                    ";
}
