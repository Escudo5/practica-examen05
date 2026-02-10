#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


static void printboard(char *board, int width, int height)
{
    for(int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (board[y * width + x])
                putchar('0');
            else
                putchar(' ');
        }
        putchar('\n');
    }
}

static int count_neighbors(char *board, int width, int height, int x, int y)
{
    int count = 0;
    for (int dy = -1; dy <= 1; dy++)
    {
        for(int dx = -1; dx <= 1; dx++)
        {
            if (dy == 0 && dx == 0)
                continue;
            int neighbor_x = x + dx;
            int neighbor_y = y + dy;
            if (neighbor_x >= 0 && neighbor_x < width && neighbor_y >= 0 && neighbor_y < height)
                count += board[neighbor_y * width + neighbor_x];
        }
    }
    return count;
}


static void step(char *board, char *next_board, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int n = count_neighbors(board, width, height, x, y);
            if (board[y * width + x])
            {
                if (n == 2 ||n == 3)
                    next_board[y * width + x] = 1;
                else
                    next_board[y * width + x] = 0;
            }
            else
            {
                if (n == 3)
                    next_board[y * width + x] = 1;
                else
                    next_board[y * width + x] = 0;
            }
        }
    }
}


int main(int argc, char **argv)
{
    if (argc != 4)  
    return 1;

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    int iter = atoi(argv[3]);

    char *board = calloc(width * heigh, 1);
    char *next_board = calloc(width * height, 1);

    if(!board ||!next_board)
        return 1;

    int x = 0, y = 0, pencil = 0;
    char c;

    while (read(0, &c, 1)>0)
    {
        if (c == 'x')
            pencil = !pencil;
        if (c == 'w' && y > 0)
            y--;
        else if (c == 's' && y < height - 1)
            y++;
        else if (c == 'a' && x > 0)
            x--;
        else if (c == 'd' && x < width - 1)
            x++;
        if (pencil)
            board[y * width + x] = 1;
    }


    for (int i = 0; i < iter; i++)
    {
        step(board, next_board, width, height);
        char *temp = board;
        board = next_board;
        next_board = temp;
    }
    printboard(board, width, height);
    free(board);
    free(next_board);
    return 0;

}