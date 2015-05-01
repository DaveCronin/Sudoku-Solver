#include "set.h"

set::set(block* start, int _type)
{
    int index = 0;
    type = _type;
    block* curr = start;

    do
    {
        blocks[index] = curr;
        index++;
        
        switch(type)
        {
            case 0:
                curr = curr->nextRow;
                break;
                
            case 1:
                curr = curr->nextCol;
                break;
                
            case 2:
                curr = curr->nextSqr;
                break;
                
            default:
                cout << "error, wrong type" << endl;
        }
        
    } while (curr);
}

void set::createSet()
{
    int i, h;
    for (i = 0; i<9; i++)
    {
        for (h = 0; h <9; h++)
        {
            if(blocks[i]->possibleAnswers[h] > 0 && !blocks[i]->known)
            {
                answers[h].add(blocks[i]);
            }
        }
    }
}

set::~set()
{
    int i;
    for (i = 0; i < 9; i++)
    {
        //delete blocks[i];
    }
    // Need to delete answers list!!!
    
}

void set::solveForKnowns()
{
    int i, h;
    
    for (i = 0; i < 9; i++)
    {
        if(blocks[i]->known)
        {
            for (h = 0; h < 9; h++)
            {
                if(!blocks[h]->known)
                {
                    blocks[h]->removePossibility(blocks[i]->value);
                }
            }
        }
    }
}

void set::checkKnowns()
{
    for(int i = 0; i < 9; i++)
    {
        if(blocks[i]->known)
        {
            knownRegister = knownRegister | (1<<i);
        }
        else
        {
            if(blocks[i]->testKnown())
            {
                knownRegister = knownRegister | (1<<i);
            }
        }
    }
}

bool set::testSolved()
{
    bool solved = false;
    
    checkKnowns();
    
    if(knownRegister > 510)
    {
        solved = true;
    }
    
    return solved;
}

void set::solveOnlyPossibilty()
{
    for (int i = 0; i < 9; i++)
    {
        if(answers[i].amount == 1)
        {
            answers[i].array[0]->setValue(i+1);
            answers[i].array[0] = NULL;
            answers[i].amount = 0;
        }
    }
    
    
}

void set::solveDouble()
{
    for (int i = 0; i < 9; i++)
    {
        if(answers[i].amount == 2)
        {
            for(int h = 0; h < 9; h++)
            {
                if(answers[h].amount == 2 && h!=i)
                {
                    if((answers[i].array[0] == answers[h].array[0] && answers[i].array[1] == answers[h].array[1]) | (answers[i].array[0] == answers[h].array[1] && answers[i].array[1] == answers[h].array[0]))
                    {
                        for (int k = 0; k < 9; k++)
                        {
                            if((k != i) && (k != h))
                            {
                                answers[i].array[0]->removePossibility(k+1);
                                answers[i].array[1]->removePossibility(k+1);
                            }
                            
                        }
                    }
                }
            }
        }
    }
}

void set::valueExclusivity()
{
    for (int i = 0; i < 9; i++)
    {
        if (answers[i].amount == 2)
        {
            if (type != 2)
            {
                for (int h = 0; h < 9; h+= 3)
                {
                    if ((answers[i].array[0] == blocks[h+0] && answers[i].array[1] == blocks[h+1]) | (answers[i].array[0] == blocks[h+0] && answers[i].array[1] == blocks[h+2]) | (answers[i].array[0] == blocks[h+1] && answers[i].array[1] == blocks[h+2]))
                    {
                        set* temp = new set(blocks[h]->sqrFirst, 2);
                        for (int j = 0; j < 9; j++)
                        {
                            if((temp->blocks[j] != answers[i].array[0]) && (temp->blocks[j] != answers[i].array[1]))
                            {
                                temp->blocks[j]->removePossibility(i+1);
                            }
                        }
                    }
                }
            }
            
            else if (type == 2)
            {
                
            }
            
        }
        if (answers[i].amount == 3)
        {
            if (type != 2)
            {
                for (int h = 0; h < 9; h+= 3)
                {
                    if (answers[i].array[0] == blocks[h+0] && answers[i].array[1] == blocks[h+1] && answers[i].array[2] == blocks[h+2])
                    {
                        set* temp = new set(blocks[h]->sqrFirst, 2);
                        for (int j = 0; j < 9; j++)
                        {
                            if((temp->blocks[j] != answers[i].array[0]) && (temp->blocks[j] != answers[i].array[1]) && (temp->blocks[j] != answers[i].array[2]))
                            {
                                temp->blocks[j]->removePossibility(i+1);
                            }
                        }
                    }
                }
            }
            
            else if (type == 2)
            {
                
            }
        }
    }
}

bool set::solveSet()
{
    solveForKnowns();
    
    createSet();
    
    solveOnlyPossibilty();
    
    solveDouble();
    
    valueExclusivity();
    
    return testSolved();
}

bool set::testCorrect()
{
    bool correct = true;
    int checkRegister = 0;
    for(int i = 0; i < 9; i++)
    {
        switch (blocks[i]->value)
        {
            case 1:
                checkRegister = checkRegister | (1<<1);
                break;
            case 2:
                checkRegister = checkRegister | (1<<2);
                break;
            case 3:
                checkRegister = checkRegister | (1<<3);
                break;
            case 4:
                checkRegister = checkRegister | (1<<4);
                break;
            case 5:
                checkRegister = checkRegister | (1<<5);
                break;
            case 6:
                checkRegister = checkRegister | (1<<6);
                break;
            case 7:
                checkRegister = checkRegister | (1<<7);
                break;
            case 8:
                checkRegister = checkRegister | (1<<8);
                break;
            case 9:
                checkRegister = checkRegister | (1<<9);
                break;
                
            default:
                cout << "An invalid number is in the sudoku... Error" << endl;
                break;
        }
    }
    
    if(checkRegister < 511)
    {
        correct = false;
    }
    
    return correct;
}

