#include "sudoku.h"

void demo(sudoku*);

void setUpEasy(sudoku*);
void setUpMedium(sudoku*);
void setUpHard(sudoku*);
void setUpVHard(sudoku*);

int main()
{
    
    sudoku* newSudoku = new sudoku();
    
    cout << "Would you like to test the code with a demo sudoku? (1/0)\nIf(0) the you will be asked to type in a sudoku using the space intervals between given values going row by row.\n  i.e: if the first known value, x, is the nth square then the input will be 'skip? n value? x" << endl;
    
    int choice = 0;
    
    cin >> choice;
    
    if (choice)
    {
        demo (newSudoku);
    }
    
    else
    {
        cout << endl << "please enter your sudoku..." << endl;
        newSudoku->input();
    }
    
    newSudoku->print();
    
    if(newSudoku->solver())
    {
        if(newSudoku->testCorrect())
        {
            cout << "The sudoku has been solved correctly!" << endl << endl;
            newSudoku->print();
            
        }
        else
        {
            cout << "The sudoku is invalid or their has been an error with the program.. Please check re-check your input.." << endl;
        }
    }
    
    else
    {
        cout << "The program was unable to complete the sudoku. This is likely due to there being a method required that this program does not have. This is as far as it got..." << endl;
        newSudoku->print();
    }
    
    
    
    cout << "Program ending..." << endl;
    return 0;
}



void demo(sudoku* newSudoku)
{
    int choice = 0;
    cout << "Please enter 1, 2, 3 or 4 for easy, medium, hard or very hard respectively..." << endl;
    cin >> choice;
    
    switch (choice) {
        case 1:
            setUpEasy(newSudoku);
            break;
        
        case 2:
            setUpMedium(newSudoku);
            break;
            
        case 3:
            setUpHard(newSudoku);
            break;
            
        case 4:
            setUpVHard(newSudoku);
            break;
            
        default:
            cout << "you did not enter an appropriate value so you get the easy demo..." << endl << endl;
            setUpEasy(newSudoku);
            break;
    }
}

void setUpEasy(sudoku* newSudoku)
{
/*
0 6 0 2 0 1 0 9 2 3 5 6 0 1 2 8 5 4 1 5 1 6 2 9 1 7 0 8 2 2 0 8 0 6 5 3 0 5 0 1 2 2 0 5 1 9 2 7 1 4 1 6 5 5 2 3 0 7 5 6 2 9 0 4 0 5 0 7 8
*/
    newSudoku->original[0]->setValue(6);
    newSudoku->original[1]->setValue(2);
    newSudoku->original[2]->setValue(1);
    newSudoku->original[3]->setValue(9);
    newSudoku->original[6]->setValue(3);
    newSudoku->original[12]->setValue(6);
    newSudoku->original[13]->setValue(1);
    newSudoku->original[16]->setValue(8);
    newSudoku->original[22]->setValue(4);
    newSudoku->original[24]->setValue(5);
    newSudoku->original[26]->setValue(6);
    newSudoku->original[29]->setValue(9);
    newSudoku->original[31]->setValue(7);
    newSudoku->original[32]->setValue(8);
    newSudoku->original[35]->setValue(2);
    newSudoku->original[36]->setValue(8);
    newSudoku->original[37]->setValue(6);
    newSudoku->original[43]->setValue(3);
    newSudoku->original[44]->setValue(5);
    newSudoku->original[45]->setValue(1);
    newSudoku->original[48]->setValue(2);
    newSudoku->original[49]->setValue(5);
    newSudoku->original[51]->setValue(9);
    newSudoku->original[54]->setValue(7);
    newSudoku->original[56]->setValue(4);
    newSudoku->original[58]->setValue(6);
    newSudoku->original[64]->setValue(5);
    newSudoku->original[67]->setValue(3);
    newSudoku->original[68]->setValue(7);
    newSudoku->original[74]->setValue(6);
    newSudoku->original[77]->setValue(9);
    newSudoku->original[78]->setValue(4);
    newSudoku->original[79]->setValue(5);
    newSudoku->original[80]->setValue(7);
    
}

void setUpMedium(sudoku* newSudoku)
{
/*
1 1 3 2 0 5 1 3 0 6 2 8 4 2 2 2 1 4 2 8 3 7 4 2 0 4 1 3 0 1 3 6 0 9 1 9 0 6 4 1 3 9 2 1 1 2 2 1 4 5 2 7 0 7 1 5 0 9 3 3 1
*/
    
    newSudoku->original[1]->setValue(1);
    newSudoku->original[5]->setValue(2);
    newSudoku->original[6]->setValue(5);
    newSudoku->original[8]->setValue(3);
    newSudoku->original[9]->setValue(6);
    newSudoku->original[12]->setValue(8);
    newSudoku->original[17]->setValue(2);
    newSudoku->original[20]->setValue(2);
    newSudoku->original[22]->setValue(4);
    newSudoku->original[25]->setValue(8);
    newSudoku->original[29]->setValue(7);
    newSudoku->original[34]->setValue(2);
    newSudoku->original[35]->setValue(4);
    newSudoku->original[37]->setValue(3);
    newSudoku->original[38]->setValue(1);
    newSudoku->original[42]->setValue(6);
    newSudoku->original[43]->setValue(9);
    newSudoku->original[45]->setValue(9);
    newSudoku->original[46]->setValue(6);
    newSudoku->original[51]->setValue(1);
    newSudoku->original[55]->setValue(9);
    newSudoku->original[58]->setValue(1);
    newSudoku->original[60]->setValue(2);
    newSudoku->original[63]->setValue(1);
    newSudoku->original[68]->setValue(5);
    newSudoku->original[71]->setValue(7);
    newSudoku->original[72]->setValue(7);
    newSudoku->original[74]->setValue(5);
    newSudoku->original[75]->setValue(9);
    newSudoku->original[79]->setValue(3);
}

void setUpHard(sudoku* newSudoku)
{
/*
0 2 9 4 4 3 0 6 0 9 1 6 1 8 4 7 2 8 0 5 0 7 3 1 3 2 0 9 0 4 3 5 3 8 0 3 0 4 2 9 4 5 1 3 1 6 0 8 0 3 4 5 9 4 1
*/
    
    newSudoku->original[0]->setValue(2);
    newSudoku->original[10]->setValue(4);
    newSudoku->original[15]->setValue(3);
    newSudoku->original[16]->setValue(6);
    newSudoku->original[17]->setValue(9);
    newSudoku->original[19]->setValue(6);
    newSudoku->original[21]->setValue(8);
    newSudoku->original[26]->setValue(7);
    newSudoku->original[29]->setValue(8);
    newSudoku->original[30]->setValue(5);
    newSudoku->original[31]->setValue(7);
    newSudoku->original[35]->setValue(1);
    newSudoku->original[39]->setValue(2);
    newSudoku->original[40]->setValue(9);
    newSudoku->original[41]->setValue(4);
    newSudoku->original[45]->setValue(5);
    newSudoku->original[49]->setValue(8);
    newSudoku->original[50]->setValue(3);
    newSudoku->original[51]->setValue(4);
    newSudoku->original[54]->setValue(9);
    newSudoku->original[59]->setValue(5);
    newSudoku->original[61]->setValue(3);
    newSudoku->original[63]->setValue(6);
    newSudoku->original[64]->setValue(8);
    newSudoku->original[65]->setValue(3);
    newSudoku->original[70]->setValue(5);
    newSudoku->original[80]->setValue(4);
    
}

void setUpVHard(sudoku* newSudoku)
{
/*
3 8 4 2 5 5 3 1 0 6 0 9 2 2 0 7 3 3 0 2 0 5 4 1 9 8 4 1 0 9 0 2 3 8 0 1 2 3 0 4 0 6 3 4 5 9 4 7 3
*/
    newSudoku->original[3]->setValue(8);
    newSudoku->original[8]->setValue(2);
    newSudoku->original[14]->setValue(5);
    newSudoku->original[18]->setValue(1);
    newSudoku->original[19]->setValue(6);
    newSudoku->original[20]->setValue(9);
    newSudoku->original[23]->setValue(2);
    newSudoku->original[24]->setValue(7);
    newSudoku->original[28]->setValue(3);
    newSudoku->original[29]->setValue(2);
    newSudoku->original[30]->setValue(5);
    newSudoku->original[35]->setValue(1);
    newSudoku->original[45]->setValue(8);
    newSudoku->original[50]->setValue(1);
    newSudoku->original[51]->setValue(9);
    newSudoku->original[52]->setValue(2);
    newSudoku->original[56]->setValue(8);
    newSudoku->original[57]->setValue(1);
    newSudoku->original[60]->setValue(3);
    newSudoku->original[61]->setValue(4);
    newSudoku->original[62]->setValue(6);
    newSudoku->original[66]->setValue(4);
    newSudoku->original[72]->setValue(9);
    newSudoku->original[77]->setValue(7);
}


/*
2 2 0 8 6 4 0 7 1 5 0 2 3 6 0 8 1 7 1 9 3 5 1 4 2 7 1 8 2 6 2 4 2 1 2 2 1 5 2 4 1 9 5 5 1 4 0 2 3 2 0 9 1 6 0 3 6 3 0 1 3
 */


/*
 3 1 1 9 3 9 3 2 3 4 0 5 3 4 3 8 1 5 0 8 1 1 1 9 0 2 2 6 5 8 2 9 0 3 1 7 1 6 0 4 1 6 3 8 3 9 0 2 3 9 3 3 3 5 1 1 3
*/