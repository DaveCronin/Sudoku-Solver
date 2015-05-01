#include "list.h"

list::list()
{
    amount = 0;
}

void list::add(block* newBlock)
{
    array[amount] = newBlock;
    amount++;
}
