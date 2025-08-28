#include <iostream>
using namespace std;

class game {
private:
    char arr[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char xo;
    int x, y;

public:
    void get_char(char a) {
        xo = a;
    }
    
    void get_position(int hori, int vert) {
        if (hori >= 0 && hori < 3 && vert >= 0 && vert < 3 && arr[hori][vert] == ' ') {
            x = hori;
            y = vert;
            arr[x][y] = xo;
        } else {
            cout << "This is not a valid position, try again\n";
        }
    }
    
    void display() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    bool check() {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (arr[i][0] != ' ' && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) {
                if (arr[i][0] == 'x') cout << "Player 1 wins!\n";
                else if (arr[i][0] == 'o') cout << "Player 2 wins!\n";
                return true;
            }
        }
        // Check columns
        for (int j = 0; j < 3; j++) {
            if (arr[0][j] != ' ' && arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j]) {
                if (arr[0][j] == 'x') cout << "Player 1 wins!\n";
                else if (arr[0][j] == 'o') cout << "Player 2 wins!\n";
                return true;
            }
        }
        // Check diagonals
        if (arr[0][0] != ' ' && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
            if (arr[0][0] == 'x') cout << "Player 1 wins!\n";
            else if (arr[0][0] == 'o') cout << "Player 2 wins!\n";
            return true;
        }
        if (arr[0][2] != ' ' && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
            if (arr[0][2] == 'x') cout << "Player 1 wins!\n";
            else if (arr[0][2] == 'o') cout << "Player 2 wins!\n";
            return true;
        }
        return false;
    }
    
    bool end() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (arr[i][j] == ' ') return false; 
            }
        }
        cout << "The game ended (Draw)!\n";
        return true; 
    }
};

int main() {
    game obj;
    int x, y;
    bool swit = true;
    char player = 'x'; 

    while (swit) {
        cout << "Player " << player << ", enter row (0-2) and column (0-2): ";
        cin >> x >> y;
        obj.get_char(player);
        obj.get_position(x, y);
        obj.display();

        if (obj.check()) {
            swit = false;
        } else if (obj.end()) {
            swit = false;
        }

    
        player = (player == 'x') ? 'o' : 'x';
    }

    return 0;
}