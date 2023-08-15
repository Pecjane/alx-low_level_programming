#include <unistd.h>

int _putchar(char c) {
    return write(1, &c, 1);
}

void print_alphabet_x10(void) {
    char letter = 'a';

    for (int i = 0; i < 10; i++) {
        while (letter <= 'z') {
            _putchar(letter);
            letter++;
        }
        letter = 'a';  // Reset to 'a' for the next iteration
    }

    _putchar('\n');
}

