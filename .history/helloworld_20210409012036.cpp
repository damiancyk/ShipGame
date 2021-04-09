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

void wczytajDane();

int main()
{
    cout << "Hello World" << endl;
    wczytajDane();
}

void wczytajDane()
{
    FILE *in_file  = fopen("name_of_file", "r"); // read only 
    cout<<"Lol"<<endl;
}