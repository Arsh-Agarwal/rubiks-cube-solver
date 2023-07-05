#include "cube.h"
#include <bits/stdc++.h>
using namespace std;

int Cube::getFaceIndex(FACE face){
    switch(face){
        case UP: return 0;
        case LEFT: return 1;
        case FRONT: return 2;
        case RIGHT: return 3;
        case BACK: return 4;
        case DOWN: return 5;
    }
}

Cube::FACE Cube::getIndexFace(int index){
    switch(index){
        case 0: return UP;
        case 1: return LEFT;
        case 2: return FRONT;
        case 3: return RIGHT;
        case 4: return BACK;
        case 5: return DOWN;
    }
}

int Cube::getColorIndex(COLOR color){
    switch(color){
        case WHITE: return 0;
        case GREEN: return 1;
        case RED: return 2;
        case BLUE: return 3;
        case ORANGE: return 4;
        case YELLOW: return 5;
    }
}

Cube::COLOR Cube::getIndexColor(int index){
    switch(index){
        case 0: return WHITE;
        case 1: return GREEN;
        case 2: return RED;
        case 3: return BLUE;
        case 4: return ORANGE;
        case 5: return YELLOW;
    }
}

char Cube::getColorLetter(COLOR color){
    switch(color){
        case WHITE: return 'W';
        case YELLOW: return 'Y';
        case BLUE: return 'B';
        case GREEN: return 'G';
        case RED: return 'R';
        case ORANGE: return 'O';
    }
}

void Cube::performMove(int index){
    switch(index){
        case 0: {l(); break;}
        case 1: {l2(); break;}
        case 2: {lp(); break;}

        case 3: {r(); break;}
        case 4: {r2(); break;}
        case 5: {rp(); break;}

        case 6: {u(); break;}
        case 7: {u2(); break;}
        case 8: {up(); break;}

        case 9: {d(); break;}
        case 10: {d2(); break;}
        case 11: {dp(); break;}

        case 12: {b(); break;}
        case 13: {b2(); break;}
        case 14: {bp(); break;}

        case 15: {f(); break;}
        case 16: {f2(); break;}
        case 17: {fp(); break;}
    }
}

void Cube::reverseMove(int index){
    switch(index){
        case 0: {lp(); break;}
        case 1: {l2(); break;}
        case 2: {l(); break;}

        case 3: {rp(); break;}
        case 4: {r2(); break;}
        case 5: {r(); break;}

        case 6: {up(); break;}
        case 7: {u2(); break;}
        case 8: {u(); break;}

        case 9: {dp(); break;}
        case 10: {d2(); break;}
        case 11: {d(); break;}

        case 12: {bp(); break;}
        case 13: {b2(); break;}
        case 14: {b(); break;}

        case 15: {fp(); break;}
        case 16: {f2(); break;}
        case 17: {f(); break;}
    }
}

string Cube::getMoveStr(int index){
    switch(index){
        case 0: return "L";
        case 1: return "L2";
        case 2: return "LP";

        case 3: return "R";
        case 4: return "R2";
        case 5: return "RP";

        case 6: return "U";
        case 7: return "U2";
        case 8: return "UP";

        case 9: return "D";
        case 10: return "D2";
        case 11: return "DP";

        case 12: return "B";
        case 13: return "B2";
        case 14: return "BP";

        case 15: return "F";
        case 16: return "F2";
        case 17: return "FP";

        default: return to_string(index);        
    }
}

void Cube::printCube(){
    string gap; for(int i = 0; i < 6; i++) gap += ' ';
    for(int i = 0; i < 3; i++){
        cout << gap;
        for(int j = 0; j < 3; j++){
            cout << getColorLetter(getColor(FACE::UP, i, j)) << ' ';
        }
        cout << '\n';
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) cout << getColorLetter(getColor(FACE::LEFT, i, j)) << ' ';
        for(int j = 0; j < 3; j++) cout << getColorLetter(getColor(FACE::FRONT, i, j)) << ' ';
        for(int j = 0; j < 3; j++) cout << getColorLetter(getColor(FACE::RIGHT, i, j)) << ' ';
        for(int j = 0; j < 3; j++) cout << getColorLetter(getColor(FACE::BACK, i, j)) << ' ';
        cout << '\n';
    }

    for(int i = 0; i < 3; i++){
        cout << gap;
        for(int j = 0; j < 3; j++){
            cout << getColorLetter(getColor(FACE::DOWN, i, j)) << ' ';
        }
        cout << '\n';
    }
}

vector<int> Cube::shuffle(int moves){
    vector<int> v;
    srand((unsigned int)time(NULL));
    while(moves--){
        int idx = floor(((double) rand()/ (RAND_MAX))*18);
        idx = max(0, idx); idx = (17, idx);
        performMove(idx); v.push_back(idx);
    }
    return v;
}

bool Cube::isSolved(){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++) for(int k = 0; k < 3; k++){
            if(getColorIndex(getColor(getIndexFace(i), j, k)) == i) continue;
            return false;
        }
    }
    return true;
}
