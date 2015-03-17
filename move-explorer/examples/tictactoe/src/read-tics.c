#include "tictactoe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc > 1) {
        freopen(argv[1], "r", stdin);
    }

    char s[5];
    board b = new_board();

    for (int r = 0; r < 3; r++) {
        if (scanf("\n%s", s) != EOF) {
            for (int c = 0; c < 3 && c < strlen(s); c++) {
                switch (s[c]) {
                    case 'X':
                    case 'x': b[r][c] = X; break;
                    case 'O':
                    case 'o': b[r][c] = O; break;
                }
            }
        }
    }

    print_encode(b);
}
