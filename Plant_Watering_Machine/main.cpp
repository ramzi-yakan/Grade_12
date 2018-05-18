#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class Flower
{
    string type;
    string colour;
    int waterCode;
    int healthCode;
};

class Weather
{
    int weatherCode;
    int temperature;
};

int main()
{
    srand(time(0));
    time_t timer;
    struct tm sinceStartOfProgram = {0};
    double seconds;
    sinceStartOfProgram.tm_sec = 0;
    while(true)
    {
        timer = time(0);
        seconds = difftime(timer,mktime(&sinceStartOfProgram));
        cout << seconds << endl;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
