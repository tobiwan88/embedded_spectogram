#include <stdint.h>

int main()
{
    volatile auto i = 1;
    while(1)
    {
        i++;
    }
    
    return -1;
}