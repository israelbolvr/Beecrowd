#include <bits/stdc++.h>
using namespace std;

int main(void){
    string map[100];
    int visitados[100][100];
    int x, y, dirX = 0, i = 0, j = 0;
    int dirY = 1;
    bool tesouro = false;
    while (cin >> y >> x){
        for (int i = 0 ; i < x; i++) {
            cin >> map[i];  
            for(int c = 0; c < y; c++){
                visitados[i][c] = 0;
            }
        }
        while (tesouro == false){
            if (map[i][j] == '*'){
                cout << "*" << endl;
                tesouro = true;
            }
            if (map[i][j] == '>'){
                dirX = 0, dirY = 1;
            }
            if (map[i][j] == '<'){
                dirX = 0, dirY = -1;
            }
            if (map[i][j] == 'v'){
                dirX = 1, dirY = 0;
            }
            if (map[i][j] == '^'){
                dirX = -1, dirY = 0;
            }
            i += dirX, j += dirY;
            if (visitados[i][j] || i >= x || j >= y) 
                break;
            visitados[i][j] = 1;
        }
        if (!tesouro) 
            cout << "!" << endl;
    }
    return 0;
}