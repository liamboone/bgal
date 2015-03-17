#include "tictactoe.h"
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "usage: move <E-board> <Move>\n");
        return 1;
    }

    board b = read_encode(argv[1]);

    board n = move(b, argv[2][1] - '1', argv[2][0] - 'a');

    print_encode(n);
}
