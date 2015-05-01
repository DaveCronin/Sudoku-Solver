#include "block.h"

class list
{
public:
    int amount;
    
    block** array = new block*[9];
    
    list();
    
    
    void add(block*);
};