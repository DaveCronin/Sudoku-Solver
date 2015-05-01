#include "set.h"

class sudoku
{
public:
    block* rows[9];
    block* cols[9];
    block* sqrs[9];
    
    block* original[81];
    
    sudoku();
    
    void input();
    void print();

    bool solver();
    bool testCorrect();
    
    int knownRegister;
    
    progress* thisProgress;
};