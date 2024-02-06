#include <shield.h>
#include <cstdlib>
#include <ctime>

void shield::shield_up()
{
    static int mytime=-2000;
    mytime++;
    if(mytime==1000)
    {
        srand(time(NULL));
        point.x = rand() % 32 + 50;
        point.y = rand() % 18 + 50;
        mytime = 0;
    }
}
shield::shield()
{
}