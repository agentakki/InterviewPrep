/*Given an n x n array like this:
1 2 3
4 5 6
7 8 9

Write a method to give us this. Do it in place.
1 4 7
2 5 8
3 6 9
*/
// swap i,j elements with j,i
// 1 2  ->  1 3
// 3 4      2 4


void transpose(int **array, unsigned dimension)
{
  for(int i=0; i<dimension; ++i){
      for(int j=i; j<dimension; ++j){
          int tmp = array[i][j];
          array[i][j] = array[j][i];
          array[j][i] = tmp;
      }
  }   
}


