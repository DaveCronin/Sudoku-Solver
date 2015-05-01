#include "progress.h"

progress::progress()
{
    count  = 0;
}

void progress::reset()
{
    count = 0;
}

bool progress::check()
{
    cout << count << endl;
    if(count)
    {
        return true;
    }
    else return false;
}

void progress::made()
{
    count++;
}