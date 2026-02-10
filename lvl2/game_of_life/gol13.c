#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


static void printboard(char *board, int width, int height)
{
    for (int y = 0; y < height, y++)
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



static int count_neighbors(char *board, int width, int heigh, int x, int y)
{
    int count = 0;
    for (int dy = -1; dy <= 1; dy++)
    {
        for (int dx = -1; dx <= 1; dx++)
        {
            if (dy == 0 && dx == 0)
                continue;
            int neighbor_x = x + dx;
            int neighbor_y = y + dy;
            if (neighbor_x >= 0 && neighbor_x < width && neighbor_y >= 0 && neighbor_y < heigh)
                count += board[neighbor_y * width + neighbor_x];

        }
    }
    return count;
}


static void step (char *board, char *next_board, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int n = count_neighbors(board, width, height, x, y);
            if (board[y * width + x])
            {
                if (n == 2 || n == 3)
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
    
}