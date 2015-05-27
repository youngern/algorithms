#include <stdio.h>
#include <stdint.h>

/*
   given a 2-D array with numbers arranged in such a way that
   it forms an left to right, inward spiral, print the numbers in the
   correct order.
   i.e.
   {{1, 8, 7},
    {2, 9, 6},   =>  1 2 3 4 5 6 7 8 9
    {3, 4, 5}} 

   {{1, 10, 9, 8}
    {2, 11, 12, 7}  => 1 2 3 4 5 6 7 8 9 10 11 12
    {3, 4 ,5 ,6}}


*/
enum direction {DOWN, RIGHT, UP, LEFT};

void printSpiral(int rows, int cols, int spiral[rows][cols], int size){
  int row = 0, col = 0, count = 0;
  int rightEnd = cols - 1;
  int downEnd =  rows - 1;
  int leftEnd = 0, upEnd = 0;
  enum direction currDir = DOWN;
  while(count < size){
    count++;
    switch(currDir){
      case DOWN:
        printf ("%d ",spiral[row][col]);
        if (row == downEnd) {
            downEnd--;
            leftEnd++;
            currDir = RIGHT;
            col++;
        } else { 
            row++;
        }
        break;
      case RIGHT:
        printf ("%d ",spiral[row][col]);       
        if (col == rightEnd) {
            rightEnd--;
            currDir = UP;
            row--;
        } else {
            col++;
        }
        break;
      case UP:
        printf ("%d ", spiral[row][col]); 
        if (row == upEnd) {
            upEnd ++;
            currDir = LEFT;
            col--;
        } else {
            row--;
        }
        break;
      case LEFT:
        printf("%d ",spiral[row][col]);
        if(col == leftEnd){
            leftEnd++;
            currDir = DOWN;
            row++;
        } else {
            col--;
        }
    }
  }
  printf("\n\n");
}

void printArray(int rows, int cols, int array[rows][cols]) {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++){
       printf("%3d ", array[i][j]);
    }
    printf("\n");
  }

}
int main() {   
   int spiral_a[3][4] = {{1,10,9,8},
                         {2,11,12,7},
                         {3,4,5,6}};
   int spiral_b[3][3] = {{1, 8, 7},
                         {2, 9, 6},
                         {3, 4, 5}};
   int col_a = sizeof (spiral_a[0]) / 4;
   int row_a = (sizeof (spiral_a) / 4) / col_a;
   int col_b = sizeof (spiral_b[0]) / 4;
   int row_b = (sizeof (spiral_b) / 4 ) / col_b;
 
   printArray (row_a, col_a, spiral_a);
   printSpiral (row_a, col_a, spiral_a, row_a * col_a);
   printArray (row_b, col_b, spiral_b);
   printSpiral (row_b, col_b, spiral_b, row_b * col_b);

}
