#include <iostream>
#include "TPtrList.h"


int main()
{
    TPtrList<int>c;
    for (int i = 0; i < 10; ++i) {
        c.InsLast(i);
    }
    TPtrList<int>b = c.multiplesToK(2);
    std::cout << b << std::endl;
    return 0;
}