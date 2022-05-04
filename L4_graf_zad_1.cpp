#include <iostream>


using namespace std;



int n;
char ** A;
bool * visited;


void DFS ( int v )
{
  int i;

  visited [ v ] = true;
  cout << v << " ";


  for( i = 0; i < n; i++ )
  {
      if( ( A [ v ][ i ] == 1 ) && !visited [ i ] )
      {
          DFS ( i );
      }
  }

}



int main( )
{
  int i, j;

  n = 6;
  int m = 14;

  A = new char * [ n ];
  visited = new bool [ n ];
  for( i = 0; i < n; i++ )
  {
       A [ i ] = new char [ n ];
  }

  for( i = 0; i < n; i++ )
  {
    visited [ i ] = false;
    for( j = 0; j < n; j++ ) A [ i ][ j ] = 0;
  }

    A [0][0] = 0;
    A [0][1] = 1;
    A [0][2] = 0;
    A [0][3] = 0;
    A [0][4] = 0;
    A [0][5] = 1;
    A [1][0] = 0;
    A [1][1] = 0;
    A [1][2] = 1;
    A [1][3] = 0;
    A [1][4] = 0;
    A [1][5] = 1;
    A [2][0] = 0;
    A [2][1] = 1;
    A [2][2] = 0;
    A [2][3] = 0;
    A [2][4] = 1;
    A [2][5] = 0;
    A [3][0] = 0;
    A [3][1] = 1;
    A [3][2] = 1;
    A [3][3] = 0;
    A [3][4] = 1;
    A [3][5] = 0;
    A [4][0] = 1;
    A [4][1] = 1;
    A [4][2] = 0;
    A [4][3] = 1;
    A [4][4] = 0;
    A [4][5] = 1;
    A [5][0] = 1;
    A [5][1] = 0;
    A [5][2] = 0;
    A [5][3] = 0;
    A [5][4] = 0;
    A [5][5] = 0;


  DFS ( 0 );

  return 0;
}
