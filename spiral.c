#include <stdio.h>
#include <stdint.h>

/*given a 2-D array, print values in a out-in spiral*/
enum direction {DOWN, RIGHT, UP, LEFT};

void printSpiral(int rows, int cols, int spiral[rows][cols], int size){
  int row = 0, col = 0, count = 0;
  int rightEnd = cols - 1;
  int downEnd =  rows - 1;
  int leftEnd = 0, upEnd = 0;
  printf("%d\n", spiral[1][0]);
  enum direction currDir = DOWN;
  while(count < size){
    count++;
    switch(currDir){
      case DOWN:
        printf("%d ",spiral[row][col]);
        if(row == downEnd){
            downEnd--;
            leftEnd++;
            currDir = RIGHT;
            col++;
        }
        else 
            row++;
        
        break;
      case RIGHT:
        printf("%d ",spiral[row][col]);       
        if(col == rightEnd){
            rightEnd--;
            currDir = UP;
            row--;
        }
        else
            col++;
        break;
      case UP:
        printf("%d ", spiral[row][col]); 
        if(row == upEnd){
            upEnd ++;
            currDir = LEFT;
            col--;
        }
        else
            row--;
        break;
      case LEFT:
        printf("%d ",spiral[row][col]);
        if(col == leftEnd){
            leftEnd++;
            currDir = DOWN;
            row++;
        }
        else
            col--;
    }
  }

}

int main(){   
   int spirals[3][3] = {1,8,7,2,9,6,3,4,5};
   int row = sizeof(spirals[0]) / 4;
   int col = (sizeof(spirals) / 4) / row;
   

   printSpiral(row,col,spirals, row*col);

}
