#include "tictactoe.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    if (argc < 1) {
        fprintf(stderr, "usage: moves <E-board>\n");
        return 1;
    }
    board b = read_encode(argv[1]);
    int move = cpu(b);
    disp_move(row(move), col(move));
}
