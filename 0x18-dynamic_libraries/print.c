#include <unistd.h>
#include <string.h>

char *next = {0};
int idx = 0;

size_t printf(char *s, int i)
{
        char *array[] = {"9 ", "8 ", "10 ", "24 ", "75 ", "- 9\n"};
        next = array[idx];
        idx = idx + 1;
        return write(1, next, strlen(next));
}


int puts(char *s)
{
	write(1, "Congratulations, you win the Jackpot!\n", 38);
}
