#include <iostream>
#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    cout << "-==STATKI==-" << endl;
    readData();
}

void readData()
{
    FILE *filePointer;
    int bufferLength = 255;
    char buffer[bufferLength];

    filePointer = fopen("ship-1.txt", "r");

    while (fgets(buffer, bufferLength, filePointer))
    {
        printf("%s\n", buffer);
    }

    fclose(filePointer);
}

void readShip(char[] line)
{
}

void displayBoard()
{
}