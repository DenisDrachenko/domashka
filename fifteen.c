#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DIM_MIN 3
#define DIM_MAX 9

int board[DIM_MAX][DIM_MAX];
int d;

void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }
    greet();
    init();
    while (true)
    {
        clear();
        draw();
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);
        if (won())
        {
            printf("ftw!\n");
            break;
        }
        printf("Tile to move: ");
        int tile = GetInt();
        if (tile == 0)
        {
            break;
        }
        fprintf(file, "%i\n", tile);
        fflush(file);
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }
        usleep(500000);
    }
    fclose(file);
    return 0;
}
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}
void init(void)
{
    int row = 0;
    int column = 0;
    // TODO
    for (int i = (d*d)-1 ; i > 0 ; i--)
    {
        board[row][column] = i;
        column++;
        if (column>(d-1))
        {
            column=0;
            row++;
        }
    }
    if (d%2==0)
    {
        board[d-1][d-2] = 2;
        board[d-1][d-3] = 1;
    }
}
void draw(void)
{
    for (int x =0 ; x < d ; x++)
    {
        for (int y = 0 ; y < d ; y++)
        {
            printf("%i ", board[x][y]);
        }
     printf("\n");
    }
}
bool move(int tile)
{
    int x;
    int y;
    for (x =0 ; x < d ; x++)
        {
        for (y = 0 ; y < d ; y++)
            {
            if (tile == board[x][y])
            {
                if ((board[x+1][y]==0)&&((x+1)<d))
                {
                    board[x+1][y]=tile;
                    board[x][y] = 0;
                    return true;
                }
                else if ((board[x-1][y]==0)&&(x-1)>=0)
                {
                    board[x-1][y]=tile;
                    board[x][y]=0;
                    return true;
                }
                else if ((board[x][y+1]==0)&&((y+1)<d))
                {
                    board[x][y+1]=tile;
                    board[x][y]=0;
                    return true;
                }
                else if ((board[x][y-1]==0)&&((y-1)>=0))
                {
                    board[x][y-1]=tile;
                    board[x][y]=0;
                    return true;
                }
            }
        }
    }
    return false;
}
bool won(void)
{
    int counter = 1; 
    for (int x = 0 ; x< d ; x++)
    {
        for (int y = 0 ; y < d ; y++)
        {
            if (board[x][y] == counter)
            {
                counter++;
                if ((counter==(d*d)-1) && (board[d-1][d-1]==0))
                {
                    return true;
                }
            }
            else
            {
                return false;
                break;
            }
        }
    }
    
    return false;
}
