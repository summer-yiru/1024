#include "game.h";
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set){
	for (int i = 0; i < rows;i++){
		for (int j = 0; j < cols;j++){
			board[i][j] = set;
			}		
	}	
}
void DisplayBoard(char board[ROWS][COLS], int row, int col){
	printf(" ");
     for (int i = 1; i <= row; i++){
		printf(" %d", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++){
		printf("%d", i);
		for (int j = 1; j <=col; j++){
			printf(" %c", board[i][j]);
			}
		printf("\n");

	}

}
void SetMine(char board[ROWS][COLS], int row, int col){
	int x = 0;
	int y = 0;
	int count = 0;
	srand((unsigned int)time(NULL));
	while (count < EASY_COUNT)
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if (board[x][y] != 1 + '0'){
			board[x][y] = 1 + '0';
			count++;
		}
	} 
	
}
int GetMineCount(char board[ROWS][COLS], int x, int y){
	return (board[x][y - 1] + board[x-1][y-1] + board[x-1][y] + board[x-1][y+1] + board[x][y + 1] + 
		board[x+1][y]+ board[x+1][y - 1] + board[x+1][y+1])-8*'0';
}
char * spread(char board[ROWS][COLS], int x, int y){
	char  arr[4] = { board[x][y - 1], board[x - 1][y - 1], board[x - 1][y], board[x + 1][y - 1] };
	return arr;
}