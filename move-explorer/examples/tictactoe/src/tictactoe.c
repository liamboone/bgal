#include <stdlib.h>
#include <stdio.h>

#include "tictactoe.h"



board new_board()
{
    board b = (board)calloc(3, sizeof(int*));
    for (int i = 0; i < 3; i++) {
        b[i] = (int*)calloc(3, sizeof(int));
    }
    return b;
}

board clone(board b)
{
    board copy = (board)calloc(3, sizeof(int*));
    for (int r = 0; r < 3; r++) {
        copy[r] = (int*)calloc(3, sizeof(int));
        for (int c = 0; c < 3; c++) {
            copy[r][c] = b[r][c];
        }
    }
    return copy;
}

/**
 * Draw a pretty form of the board to stdout.
 */
void disp_board(board b) 
{
    printf("   a b c\n");
    for (int r = 0; r < 3; r++) {
        printf("%d  ", r + 1);
        for (int c = 0; c < 3; c++) {
            switch (b[r][c]) {
                case B: printf(" "); break;
                case X: printf("X"); break;
                case O: printf("O"); break;
            }
            if (c == 2)
                printf("\n");
            else
                printf("|");
        }

        if (r == 0 || r == 1) {
            printf("   -+-+-\n");
        }
    }
}

void print_encode(board b) 
{
    int r, c;
    FOREACH(r, c) {
        switch (b[r][c]) {
            case X: printf("X"); break;
            case O: printf("O"); break;
            case B: printf("-"); break;
        }
    }
    printf("\n");
}

board read_encode(char *s)
{
    board b = new_board();
    int r, c;
    FOREACH(r, c) {
        switch (*s) {
            case 'X': b[r][c] = X; break;
            case 'O': b[r][c] = O; break;
            case '-': b[r][c] = B; break;
        }
        s++;
    }
    return b;
}

int turn(board b) 
{
    int xcount = 0, ocount = 0;
    int r, c;
    FOREACH(r, c) {
        switch (b[r][c]) {
            case X: xcount++; break;
            case O: ocount++; break;
        }
    }

    if (ocount + xcount == 9)
        return B;
    else if (ocount < xcount)
        return O;
    else 
        return X;
}

board move(board b, int r, int c)
{
    int t = turn(b);
    board copy = clone(b);

    copy[r][c] = t;
    return copy;
}

void disp_moves(board b)
{
    int r, c;

    if (winner(b) != B) {
        return;
    }

    FOREACH(r, c) {
        if (!b[r][c])
            disp_move(r, c);
    }
}

#define check_row(r) \
    if (b[r][0] && b[r][0] == b[r][1] && b[r][0] == b[r][2]) return b[r][0]
#define check_col(c) \
    if (b[0][c] && b[0][c] == b[1][c] && b[0][c] == b[2][c]) return b[0][c]
#define check_diags \
    if (b[0][0] && b[0][0] == b[1][1] && b[0][0] == b[2][2]) return b[0][0];\
    if (b[2][0] && b[2][0] == b[1][1] && b[2][0] == b[0][2]) return b[2][0];

/**
 * If there is a winner (three-in-a-row), return it; otherwise, return B
 */
int winner(board b)
{
    for (int i = 0; i < 3; i++) {
        check_row(i);
        check_col(i);
    }

    check_diags;

    return B;
}

/**
 * Write the move that the computer would make to stdout.
 */
void disp_cpu(board b) 
{
    int m = cpu(b);
    disp_move(m / 3, m % 3);
}

/**
 * Return an optimal move using full minimax.
 *
 * The following information is packed into the return value:
 *     - move score (either 2 for win, 1 for draw, 0 for loss)
 *     - row of move
 *     - column of move
 *
 * Format: score * 9 + row * 3 + column
 */
#define pack(s, r, c) ((s) * 9 + (r) * 3 + (c))
#define score(n) ((n) / 9)
#define WIN 2
#define DRAW 1
#define LOSS 0
int cpu(board b)
{
    int t = turn(b), best = -9;

    int r, c;
    FOREACH(r, c) {
        if (b[r][c] == B) {

            board try = move(b, r, c);

            int w = winner(try);

            if (w == t) {
                return pack(WIN, r, c);

            } else if (turn(try) == B) {
                if (DRAW > score(best)) {
                    best = pack(DRAW, r, c);
                }

            } else {
                int opp = cpu(try);

                int s = 2 - score(opp);
                if (s > score(best)) {
                    best = pack(s, r, c);
                }
            }
        }
    }

	return best;
}
