#include "cube.h"

class Cube3d: public Cube{

    int cube[6][3][3];
    public:
    COLOR getColor(FACE face, int row, int col) override {return cube[getFaceIndex(face)][row][col];}
    
    void l() override{}
};