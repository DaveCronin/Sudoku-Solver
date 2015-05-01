#include "block.h"

block::block()
{
    value = 0;

    known = false;
    
    progress = NULL;
    
    nextRow = nextCol = nextSqr = rowFirst = colFirst = sqrFirst = NULL;

};

block::~block()
{
    //
}

void block::setValue(int newValue)
{
    if (known)
    {
        
    }
    
    else if(newValue>=0 && newValue <= 9)
    {
        value = newValue;
        
        known = true;
        
        int i = 0;
        
        do
        {
            if(possibleAnswers[i] == newValue)
            {
                i++;
                continue;
            }
            else if(possibleAnswers[i])
            {
                this->removePossibility(i+1);
            }
            
            i++;
            
        } while (i<9);
        
    }
    else
    {
        cout << "not in range, try again.. :";
        int again;
        cin >> again;
        this->setValue(again);
    }
}

int block::numPossibilities()
{
    int count=0;
    for (int i = 0; i <9; i++)
    {
        if(possibleAnswers[i] > 0)
        {
            count++;
        }
    }

    return count;
}

void block::removePossibility(int value)
{
    if(numPossibilities()<2 | possibleAnswers[value-1] == 0)
    {
        //cout << "error, too few possibilities"<< endl;
    }
    else
    {
        possibleAnswers[value - 1] = 0;
        progress->made();
    }
    
}

bool block::testKnown()
{
    if(numPossibilities() < 2)
    {
        for (int i = 0; i < 9; i++)
        {
            if(possibleAnswers[i])
            {
                setValue(i+1);
            }
        }
    }
    return known;
}