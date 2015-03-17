#include "tictactoe.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    if (argc < 1) {
        fprintf(stderr, "usage: show-board <E-board>\n");
        return 1;
    }

    board b = read_encode(argv[1]);
    disp_board(b);
}
