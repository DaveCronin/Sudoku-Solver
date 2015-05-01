#include "list.h"

class set
{
public:
    
    block* blocks[9];
    
    list answers[9];
    
    int type;
    
    int knownRegister = 0;
    
    set(block*, int);
    
    ~set();
    
    void solveForKnowns();
    
    bool testSolved();
    
    void checkKnowns();
    
    bool solveSet();
    
    void solveOnlyPossibilty();
    
    void solveDouble();
    
    void createSet();
    
    void valueExclusivity();
    
    bool testCorrect();
};