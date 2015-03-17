#define B 0
#define X 1
#define O 2

#define FOREACH(r,c) for (r = 0; r < 3; r++) for (c = 0; c < 3; c++)

#define disp_move(r, c) printf("%c%d\n", c + 'a', r + 1)

#define row(n) (((n) / 3) % 3)
#define col(n) ((n) % 3)

typedef int** board;

board new_board();
board clone(board b);

void disp_board(board b);

void print_encode(board b);
board read_encode(char *s);

board move(board b, int r, int c);
void disp_moves(board b);

int turn(board b);
int winner(board b);

void disp_cpu(board b);
int cpu(board b);
