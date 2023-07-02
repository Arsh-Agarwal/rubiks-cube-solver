#ifndef CUBE_H
#define CUBE_H

class Cube{
    public:
    enum COLOR{
        WHITE, BLUE, RED, YELLOW, GREEN, ORANGE
    };

    enum FACE{
        UP, DOWN, FRONT, BACK, LEFT, RIGHT
    };

    virtual int getColorIndex(COLOR color);
    virtual char getColorLetter(COLOR color);

    virtual int getFaceIndex(FACE face);

    //rotations
    virtual void l() = 0;
    virtual void lp() = 0;
    virtual void l2() = 0;

    virtual void r() = 0;
    virtual void rp() = 0;
    virtual void r2() = 0;

    virtual void f() = 0;
    virtual void fp() = 0;
    virtual void f2() = 0;

    virtual void b() = 0;
    virtual void bp() = 0;
    virtual void b2() = 0;

    virtual void u() = 0;
    virtual void up() = 0;
    virtual void u2() = 0;

    virtual void d() = 0;
    virtual void dp() = 0;
    virtual void d2() = 0;

    //basics
    virtual COLOR getColor(FACE face, int row, int col) = 0;
    virtual void printCube();
};

#endif