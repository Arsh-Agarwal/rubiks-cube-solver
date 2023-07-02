#include "cube.h"
#include <bits/stdc++.h>
using namespace std;

void Cube::printCube(){

}

int Cube::getFaceIndex(FACE face){
    switch(face){
        case UP: return 0;
        case LEFT: return 1;
        case FRONT: return 2;
        case DOWN: return 3;
        case RIGHT: return 4;
        case BACK: return 5;
    }
}

int Cube::getColorIndex(COLOR color){
    switch(color){
        case WHITE: return 0;
        case BLUE: return 1;
        case RED: return 2;
        case YELLOW: return 3;
        case GREEN: return 4;
        case ORANGE: return 5;
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

void Cube::printCube(){
    string gap; for(int i = 0; i < 6; i++) gap += ' ';
    for(int i = 0; i < 3; i++){
        cout << gap;
        for(int j = 0; j < 3; j++){
            cout << getColorLetter(getColor(FACE::UP, i, j)) << ' ';
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) cout << getColorLetter(getColor(FACE::LEFT, i, j)) << ' ' << getColorLetter(getColor(FACE::FRONT, i, j)) << ' ' << getColorLetter(getColor(FACE::RIGHT, i, j)) << ' ' << getColorLetter(getColor(FACE::BACK, i, j));
        cout << '\n';
    }

    for(int i = 0; i < 3; i++){
        cout << gap;
        for(int j = 0; j < 3; j++){
            cout << getColorLetter(getColor(FACE::DOWN, i, j)) << ' ';
        }
    }
}