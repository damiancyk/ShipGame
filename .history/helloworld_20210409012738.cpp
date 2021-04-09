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
   FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("/etc/motd", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu:\n", read);
        printf("%s", line);
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);