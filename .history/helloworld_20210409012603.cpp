#include <iostream>

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
    FILE *in_file = fopen("ships-1.txt", "r");
    if (in_file == NULL)
    {
        printf("Error! Could not open file\n");
        exit(-1); // must include stdlib.h
    }

    
    while (fgets(line, 100, stdin) != NULL)
    {
        fprintf("The line is: %s\n", line);
    }
}