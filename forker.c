#include "libs.h"

const int NO_PROCESSES  = 1 << 4;
const int LEAK_SIZE     = 1 << 4;
const int SLEEP_TIME    = 1 << 4;

long getNumber(char *numString);

int main(int argc, char *argv[])
{
    int NOProcesses = argc > 1 ? getNumber(argv[1]) : NO_PROCESSES;
    int NOLeak      = argc > 2 ? getNumber(argv[2]) : LEAK_SIZE;
    int sleepTime   = argc > 3 ? getNumber(argv[3]) : SLEEP_TIME;

    double memoryLeak[1000000];//[NOLeak];

    //fprintf(stderr, "NOProcesses = %d\n", NOProcesses);
    //fprintf(stderr, "NOLeak = %d\n", NOLeak);
    //fprintf(stderr, "sleepTime = %d\n", sleepTime);


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
            sleep(sleepTime);
            break;
        }
        
        //fprintf(stderr, "%d: here\n", getpid());
        continue;

    }
}

long getNumber(char *numString)
{
    if (*numString == '\0')
    {
        //fprintf(stderr, "empty number argument\n");
        return SLEEP_TIME;
    }

    errno = 0;

    long gNumber;
    char* endOfEnter;

    const int baseOfNumber = 10;
    gNumber = strtol(numString, &endOfEnter, baseOfNumber);

    if(*endOfEnter != '\0')
    {
        //fprintf(stderr, "strtol error\n");
        // exit(EXIT_FAILURE);
    }
    if (errno != 0)
    {
        //fprintf(stderr, "strtol error\n");
        // exit(EXIT_FAILURE);
    }
    
    return gNumber;

}