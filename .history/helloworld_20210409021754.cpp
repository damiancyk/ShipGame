#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 100

using namespace std;

typedef uint32_t coord;

struct position
{
    coord x;
    coord y;
};

struct ship
{
    struct position start; /* punkt statku o najmniejszych współrzędnych */
    unsigned int size;     /* długość statku */
    int direction;         /* orientacja pionowa lub pozioma*/
};
char line[100];
void readData();
ship readShip(char line[]);
struct ship ships[n];

int main()
{
    cout << "-==STATKI==-" << endl;
    readData();
}

//tutaj i w main musi byc parametr z nazwa pliku
void readData()
{
    FILE *filePointer;
    int bufferLength = 255;
    char buffer[bufferLength];

    filePointer = fopen("ship-1.txt", "r");

    while (fgets(buffer, bufferLength, filePointer))
    {
        // printf("%s\n", buffer);
        ship ship1 = readShip(buffer);
    }

    fclose(filePointer);
}

ship readShip(char line[])
{
    ship s;
    // cout << line << endl;

    uint8_t i;

    char *number = strtok(line, ",");
    int parameterIndex = 0;

    while (number != NULL)
    {

        unsigned int param = strtoul(number, NULL, 10);
        if (parameterIndex == 0)
        {
            s.start.x = param;
        }
        else if (parameterIndex == 1)
        {
            s.start.y = param;
        }
        else if (parameterIndex == 2)
        {
            s.size = param;
        }
        else if (parameterIndex == 3)
        {
            s.direction = param;
        }

        printf("%s\n", number);
        number = strtok(NULL, ",");

        parameterIndex++;
    }

    return s;
}

void displayBoard()
{
}