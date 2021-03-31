#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 5
#define STEPS 4
#define GRIDSIZE 5.0
int randomInteger(int r,int l) {
	int sonuc;
    sonuc = (rand() % (r - l + 1)) + l;
	return sonuc;
}
int cells[N][N];  
int cellsonceki[N][N];
int main(void) {
	srand(time(NULL));
	int i, j, k, ii, jj,top=0;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++){
			cells[i][j] = 0;
		}
	for (i = 1; i < N-1; i++)
		for (j = 1; j < N-1; j++){
			cells[i][j] = randomInteger(1,0);
		}
	
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++){
			cellsonceki[i][j] = cells[i][j];
		}
		for(int x=0;x<N;x++){
			printf("%d.",x+1);
			for(int y=0;y<N;y++)
			{
				if(cells[x][y]==1)
				printf("1");
				else printf(" ");
			}
			printf("\n");
		}
		printf("---end of initial---\n");
	for (k = 0; k < STEPS; k++) {
		
		for (i = 1; i < N; i++) {
			for (j = 1; j < N; j++)  {
				top=0;
				if(cellsonceki[i-1][j-1]==1) top++;
				if(cellsonceki[i][j-1]==1) top++;
				if(cellsonceki[i+1][j-1]==1) top++;
				if(cellsonceki[i-1][j]==1) top++;
				if(cellsonceki[i+1][j]==1) top++;
				if(cellsonceki[i-1][j+1]==1) top++;
				if(cellsonceki[i][j+1]==1) top++;
				if(cellsonceki[i+1][j+1]==1) top++;
				
				if ((cellsonceki[i][j]==1&& (top==2 || top==3)) ||
				(cellsonceki[i][j]==0 && top==3) ){
					cells[i][j]=1;
				}
				else cells[i][j]=0;
			}
		}
		for (i = 0; i < N; i++)
		for (j = 0; j < N; j++){
			cellsonceki[i][j] = cells[i][j];
		}
		for(int x=0;x<N;x++){
			printf("%d.",x+1);
			for(int y=0;y<N;y++)
			{
				if(cells[x][y]==1)
				printf("1");
				else printf(" ");
			}
			printf("\n");
		}
		printf("---end of an iteration---\n");
	}
	return 0;
}

