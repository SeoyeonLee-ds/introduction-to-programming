#include <stdio.h>

int main()
{
	char board[3][3];
	int x, y;
	int win = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
	

	for (int k = 1; k < 10; k++)
	{
		printf("좌표입력(x, y):");
	    scanf_s("%d, %d", &x, &y);
		if ((0 <= x && x <= 2) && (0 <= y && y <= 2))
		{
			if (board[x][y] == ' ')
			{
				board[x][y] = (k % 2 == 0) ? 'X' : 'O';

				for (int i = 0; i < 3; i++)
				{
					printf("---|---|---\n");
					printf("%c  |%c  |%c  \n", board[i][0], board[i][1], board[i][2]);
				}
				printf("---|---|---\n");
			}
			else
			{
				printf("이미 말이 놓여 있습니다. 다시 입력하시기 바랍니다.\n");
				k -= 1;
			}
		}
		else
		{
			printf("잘못된 좌표입니다. 다시 입력하시기 바랍니다.\n");
			k -= 1;
		}
		for (int j = 0; j < 3; j++)
		{
			if ((board[j][0] == board[j][1] && board[j][1] == board[j][2] && board[j][0] != ' ') || 
				(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' '))
			{
				win = 1;
			}
		}
		if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') || 
			(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
		{
			win = 1;
		}

		if (win)
		{
			printf("player %c가 승리하였습니다.\n", board[x][y]);
			break;
		}
	}
	printf("게임이 종료되었습니다.");
	return 0;
}


