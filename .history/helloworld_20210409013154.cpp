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
    cout << "Hello World" << endl;
    readData();
}

void readData()
{
    FILE *filePointer;
    int bufferLength = 255;
    char buffer[bufferLength];

    filePointer = fopen("file.txt", "r");

    cout << "Reading file" << endl;
    
    while (fgets(buffer, bufferLength, filePointer))
    {
        printf("%s\n", buffer);
        cout<<buffer;
    }

    fclose(filePointer);
}