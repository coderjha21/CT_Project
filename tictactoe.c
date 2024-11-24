#include <stdio.h>

char board[3][3];
char currentPlayer = 'X';

void initializeBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }        
}


void printBoard() 
{
    printf("\n");
    for (int i = 0; i < 3; i++) 
    {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
        {
            printf("---|---|---\n");
        }    
    }
    printf("\n");
}


int checkWin() 
{
    for (int i = 0; i < 3; i++)
    {
        if((board[i][0]==currentPlayer&&board[i][1]==currentPlayer&&board[i][2]==currentPlayer)||
           (board[0][i]==currentPlayer&&board[1][i]==currentPlayer&&board[2][i]==currentPlayer))
        {
            return 1;
        }
    }    
    if ((board[0][0]==currentPlayer&&board[1][1]==currentPlayer&&board[2][2]==currentPlayer) ||
        (board[0][2]==currentPlayer&&board[1][1]==currentPlayer&&board[2][0]==currentPlayer))
    {
        return 1;
    }
    return 0;
}


int isBoardFull() 
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}


void play(int x, int y) 
{
    if (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != ' ') 
    {
        printf("Invalid move! Try again.\n");
        return;
    }

    board[x][y] = currentPlayer;
    printBoard();

    if (checkWin()) 
    {
        printf("Player %c wins!\n", currentPlayer);
        return;
    }

    if (isBoardFull()) 
    {
        printf("It's a draw!\n");
        return;
    }
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    printf("Player %c's turn. Enter row and column (0-2): ", currentPlayer);
    int newX, newY;
    scanf("%d %d", &newX, &newY);
    play(newX, newY);
}


int main()
{
    initializeBoard();
    printBoard();
    printf("Player X's turn. Enter row and column (0-2): ");
    int x, y;
    scanf("%d %d", &x, &y);
    play(x, y);
    return 0;
}
