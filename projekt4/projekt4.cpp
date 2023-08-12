#include <iostream>
#include "Winda.h"

int main()
{
    Winda lift;

    
    while (lift.run())
    {
        lift.update();
        lift.Movement();
        lift.render();
    }


    return 0;
}
