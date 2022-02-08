#include <stdio.h>
#include <stdlib.h>
// Note that arr[] for fun is just a pointer even if square
// brackets are used
void fun(int arr[])  // SAME AS void fun(int *arr)
{
   unsigned int n = sizeof(arr)/sizeof(arr[0]);
   printf("\nArray size inside fun() is %d", n);

}
 
// Driver program
int main()
{
   int board[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
   unsigned int n = sizeof(board)/sizeof(board[0]);
   printf("Array size inside main() is %d", n);
   fun(board);
   return 0;
}