#include "sudoku.h"

sudoku::sudoku()
{
    thisProgress = new progress();
    
    block* start;
    int i, h;
    
    for (i = 0; i < 81; i++)
    {
        original[i] = new block();
    }
    
    block* curr = NULL;
    
    
    for (i = 0; i < 81; i += 9)
    {
        start = original[i];
        curr = start;
        
        rows[i/9] = curr;
        for (h = 1; h <9; h++)
        {
            curr->rowFirst = start;
            curr->progress = thisProgress;
            curr->nextRow = original[i+h];
            curr = curr->nextRow;
            
        }
        curr->nextRow = NULL;
        curr->rowFirst = start;
        curr->progress = thisProgress;
        
    }
    
    curr = NULL;
    
    
    for (i = 0; i <9; i++)
    {
        start = original[i];
        curr = start;
        
        cols[i] = curr;
        for (h = 9; h < 81; h += 9)
        {
            curr->colFirst = start;
            curr->nextCol = original[i+h];
            curr = curr->nextCol;
        }
        curr->nextCol = NULL;
        curr->colFirst = start;
        
    }

    curr = NULL;
    
    
    for(i = 0; i < 81; i+=27)
    {
        for (h = 0; h < 9; h += 3)
        {
            start = original[i+h];
            curr = start;
            
            sqrs[(i/9)+(h/3)] = curr;
            for(int j = 0; j < 27; j += 9)
            {
                for(int l = 0; l < 3; l++)
                {
                    curr->sqrFirst = start;
                    curr->nextSqr = original[(i+h)+(j+l)];
                    curr = curr->nextSqr;
                }
            }
            curr->nextSqr = NULL;
            curr->sqrFirst = start;
        }
    }
    curr = NULL;
    
}

void sudoku::input()
{
    int skip = 0;
    int input = 0;
    int count = 0;
    
    cout << "skip? ";
    cin >> skip;

    count+= skip;
    
    
    while (count < 81)
    {
        cout << "value? ";
        cin >> input;
        original[count]->setValue(input);
        count++;
        
        cout << "skip? ";
        cin >> skip;
        
        count += skip;
    }
    
}

void sudoku::print()
{
    cout << endl;
    
    cout << "-------------------------" << endl;
    for(int i = 0; i < 9; i += 3)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << "| ";
            for(int h = 0; h < 9; h += 3)
            {
                for(int k = 0; k < 3; k++)
                {
                    cout << original[((i+j)*9)+(h+k)]->value << " ";
                }
                cout << "| ";
            }
            
            cout << endl;
        }
        cout << "-------------------------" << endl;
    }
    
    cout << endl;
}

bool sudoku::solver()
{
    int i, n;
    n = 0;
    bool solved = false;
    bool quit = false;
    while(!solved && !quit)
    {
        thisProgress->reset();
        cout << endl << n << " iteration" << endl;
        for (i = 0; i < 9; i++)
        {
            set* newSet = new set(rows[i], 0);
            newSet->solveSet();
        }
        for (i = 0; i < 9; i++)
        {
            set* newSet = new set(cols[i], 1);
            newSet->solveSet();
        }
        for (i = 0; i < 9; i++)
        {
            set* newSet = new set(sqrs[i], 2);
            newSet->solveSet();
            if(newSet->testSolved())
            {
                knownRegister = knownRegister | (1<<i);
            }
        }
        if (knownRegister > 510)
        {
            solved = true;
        }
        n++;
        
        if(!thisProgress->check())
        {
            quit = true;
        }
        
    }
    return solved;
}

bool sudoku::testCorrect()
{
    bool correct = true;
    int i;
    int checkRegister = 0;
    
    for (i = 0; i < 9; i++)
    {
        set* newSet = new set(rows[i], 0);
        if(newSet->testCorrect())
        {
            checkRegister = checkRegister | (1<<i);
        }
    }
    
    if (checkRegister < 511)
    {
        correct = false;
    }
    
    checkRegister = 0;
    
    for (i = 0; i < 9; i++)
    {
        set* newSet = new set(cols[i], 1);
        if(newSet->testCorrect())
        {
            checkRegister = checkRegister | (1<<i);
        }
    }
    
    if (checkRegister < 511)
    {
        correct = false;
    }
    
    checkRegister = 0;
    
    for (i = 0; i < 9; i++)
    {
        set* newSet = new set(sqrs[i], 2);
        if(newSet->testCorrect())
        {
            checkRegister = checkRegister | (1<<i);
        }
    }
    
    if (checkRegister < 511)
    {
        correct = false;
    }
    
    return correct;
}
