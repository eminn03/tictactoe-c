#include <stdio.h>
#include <stdbool.h>

char board[3][3] = {"   ","   ","   "};
char winner = 0;
char freeSpace = 0;
bool AIwin = 0;

int spaceCheck()
{
    int spc;
    for(int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if(board[i][j])
                spc++;
        }       
    }
    return spc;
}

void winCheck()
{
    int spc = 0;
    for(int i = 0; i <= 2; i++)
    {
        for(int j = 0; j <= 2; j++)
        {
            if(board[i][j] == 'X' || board[i][j] == 'O')
                spc++;
        }
        
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
            winner = board[i][0];
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
            winner = board[0][i];
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
            winner = board[0][0];
        if(board[2][0] == board[1][1] && board[2][0] == board[0][2])
            winner = board[2][0];
    }
    if(spc >= 9 && winner != 'X' && winner != 'O')
        winner = 'D';
}

void AImove()
{
    bool moveDone = 0;
    for(int i = 0; i <= 2; i++)
    {
        for(int j = 0; j <= 2; j++)
        {
            if(board[i][j] == 'X' && moveDone == 0)
            {
                if(board[(i+1)%3][(j+1)%3] == 'X' && board[(i+2)%3][(j+2)%3] == ' ')
                {
                    board[(i+2)%3][(j+2)%3] = 'O';
                    moveDone = 1;
                }
                else if(board[(i+1)%3][(j-1)%3] == 'X' && board[(i+2)%3][(j-2)%3] == ' ')
                {
                    board[(i+2)%3][(j-2)%3] = 'O';
                    moveDone = 1;
                }
                else if(board[(i+1)%3][j] == 'X' && board[(i+2)%3][j] == ' ')
                {
                    board[(i+2)%3][j] = 'O';
                    moveDone = 1;
                }
                else if(board[i][(j+1)%3] == 'X' && board[i][(j+2)%3] == ' ')
                {
                    board[i][(j+2)%3] = 'O';
                    moveDone = 1;
                }
                else if(board[1][1] == ' ')
                {
                    board[1][1] = 'O';
                    moveDone = 1;
                }
                else if(board[(i+1)%3][j] == ' ')
                {
                    board[(i+1)%3][j] = 'O';
                    moveDone = 1;
                }
                else if(board[i][(j+1)%3] == ' ')
                {
                    board[i][(j+1)%3] = 'O';
                    moveDone = 1;
                }
                else if(board[(i-1)%3][j] == ' ')
                {
                    board[(i-1)%3][j] = 'O';
                    moveDone = 1;
                }
                else if(board[i][(j-1)%3] == ' ')
                {
                    board[i][(j-1)%3] = 'O';
                    moveDone = 1;
                }
                else if(board[(i+1)%3][(j+1)%3] == ' ')
                {
                    board[(i+1)%3][(j+1)%3] = 'O';
                    moveDone = 1;
                }
                else if(board[(i+1)%3][(j-1)%3] == ' ')
                {
                    board[(i+1)%3][(j-1)%3] = 'O';
                    moveDone = 1;
                }
            }
        }
    }
}

int main()
{
    
    int row,column;

    while(1)
    {
        for(int i = 0; i <= 2; i++)
        {
            printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
            if(i != 2)
            {
                printf("---|---|---\n");
            }
        }

        winCheck();
        if(winner == 'O')
        {
            printf("Computer Win!!!\n");
            break;
        }
        else if(winner == 'D')
        {
            printf("It's Draw!!!\n");
            break;
        }
        while(1)
        {
            printf("Type Row: ");
            scanf("%d", &row);
            printf("Type Column: ");
            scanf("%d", &column);
            
            if(board[row - 1][column - 1] == ' ')
            {
                board[row - 1][column - 1] = 'X';
                break;
            }
            else
                printf("Please select an empty place!\n");
        }
        winCheck();
        if(winner == 'X')
        {
            for(int i = 0; i <= 2; i++)
            {
                printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
                if(i != 2)
                {
                    printf("---|---|---\n");
                }
            }
            printf("You Win!!!\n");
            break;
        }
        else if(winner == 'D')
        {
            for(int i = 0; i <= 2; i++)
            {
                printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
                if(i != 2)
                {
                    printf("---|---|---\n");
                }
            }
            printf("It's Draw!!!\n");
            break;
        }
        
        AImove();
    }

    return 0;
}
