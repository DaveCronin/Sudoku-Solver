#include <iostream>

using namespace std;


class progress
{
private:
    int count;
    
public:
    progress();
    
    void reset();
    
    bool check();
    
    void made();
};