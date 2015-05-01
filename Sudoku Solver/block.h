#include "progress.h"

class block
{
public:
    int value;
    
    int possibleAnswers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    bool known;
    
    progress* progress;
    
    block* nextRow;
    block* nextCol;
    block* nextSqr;
    
    block* rowFirst;
    block* colFirst;
    block* sqrFirst;
    
    block();
    ~block();
    
    void setValue(int);
    
    void removePossibility(int);
    
    int numPossibilities();
    
    bool testKnown();
};