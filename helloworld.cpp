#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define shipSize 100
#define dashboardX 10
#define dashboardY 10
#define startNumber 0 //min start number for ship position

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
struct ship ships[shipSize];
void displayBoard();
char dashboard[dashboardX][dashboardY];
void initDashboard();
void updateDashboard(int guessX, int guessY);
int nrTury = 1;

int main()
{
    cout << "-==STATKI==-" << endl;
    readData();
    initDashboard();
    cout << "T" << nrTury << endl;
    displayBoard();
    updateDashboard(1, 1);
    nrTury++;

    cout << "T" << nrTury << endl;
    displayBoard();
}

//tutaj i w main musi byc parametr z nazwa pliku
void readData()
{
    FILE *filePointer;
    int bufferLength = 255;
    char buffer[bufferLength];

    filePointer = fopen("ship-1.txt", "r");
    uint8_t shipNumber = 0;

    while (fgets(buffer, bufferLength, filePointer))
    {
        ship ship1 = readShip(buffer);
        ships[shipNumber] = ship1;

        shipNumber++;
    }

    fclose(filePointer);
}

//reading data of one ship
ship readShip(char line[])
{
    ship s;

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

        number = strtok(NULL, ",");

        parameterIndex++;
    }

    return s;
}

void displayBoard()
{
    for (int x = 0; x < dashboardX; x++)
    {
        for (int y = 0; y < dashboardY; y++)
        {
            // printf("%c\t", dashboard[x][y]);
        }
        printf("\n");
    }
}

void initDashboard()
{
    for (int x = 0; x < dashboardX; x++)
    {
        for (int y = 0; y < dashboardY; y++)
        {
            dashboard[x][y] = 'x';
        }
    }
}

//checks all ships and update dashboard
void updateDashboard(int guessX, int guessY)
{
    for (int i = 0; i < shipSize; i++)
    {
        ship s = ships[i];
        if (s.size)
        {
            // cout << s.size;
        }
    }

    //TODO DP zrobic sprawdzanie wspolrzednych wsszystkich statkow i updatowac dashboard, czy trafione, czy nie
}