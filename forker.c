#include "libs.h"

const int NO_PROCESSES  = 10000;
const int LEAK_SIZE     = 1000000;
const int DELAY         = 120;


long getNumber(char *numString);

int main(int argc, char *argv[])
{
    int NOProcesses = argc > 1 ? getNumber(argv[1]) : NO_PROCESSES;
    int NOLeak      = argc > 2 ? getNumber(argv[2]) : LEAK_SIZE;
    int delay       = argc > 3 ? getNumber(argv[3]) : DELAY;

    double memoryLeak[NOLeak];//[NOLeak];

    //fprintf(stderr, "NOProcesses = %d\n", NOProcesses);
    //fprintf(stderr, "NOLeak = %d\n", NOLeak);
    //fprintf(stderr, "sleepTime = %d\n", sleepTime);

    sleep(delay);

    for (int i = 0; i < NOProcesses; i++)
    {
        pid_t isParent = fork();
        if(isParent == -1)
        {
            //fprintf(stderr, "Error\n");
            break;
        }
        if(!isParent)
        {
            while (1)
            {   
                for(int j = 0; j < NOLeak; j++)
                    memoryLeak[j] = 'x';
            }            
        }
        continue;

    }
}

long getNumber(char *numString)
{
    if (*numString == '\0')
    {
        //fprintf(stderr, "empty number argument\n");
        return DELAY;
    }

    errno = 0;

    long gNumber;
    char* endOfEnter;

    const int baseOfNumber = 10;
    gNumber = strtol(numString, &endOfEnter, baseOfNumber);

    if(*endOfEnter != '\0')
    {
        //fprintf(stderr, "strtol error\n");
        return DELAY;
    }
    if (errno != 0)
    {
        //fprintf(stderr, "strtol error\n");
        // exit(EXIT_FAILURE);
    }
    
    return gNumber;

}