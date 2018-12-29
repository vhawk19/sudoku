#include <stdlib.h>
#include<iostream>
#include<conio.h>
using namespace std;
#define UNASSIGNED 0
#define N 9
bool unassignedplaces(int sudoku[N][N], int &row, int &col);
bool istrue(int sudoku[N][N], int row, int col, int num);
bool solve(int sudoku[N][N])
{   int row, col;
    if (!unassignedplaces(sudoku, row, col))
       return true;

  for (int num = 1; num <= 9; num++)
    {if (istrue(sudoku, row, col, num))
        {sudoku[row][col] = num;
            if (solve(sudoku))
                return true;
        sudoku[row][col] = UNASSIGNED;
        }
    }
    return false;
}


bool unassignedplaces(int sudoku[N][N], int &row, int &col)
{for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (sudoku[row][col] == UNASSIGNED)
                return true;
    return false;
}


bool UsedInRow(int sudoku[N][N], int row, int num)
{for (int col = 0; col < N; col++)
        if (sudoku[row][col] == num)
            return true;
    return false;
}

bool UsedInCol(int sudoku[N][N], int col, int num)
{for (int row = 0; row < N; row++)
        if (sudoku[row][col] == num)
            return true;
    return false;
}
bool usedwithinthebox(int sudoku[N][N], int boxStartRow, int boxStartCol, int num)
{for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (sudoku[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}
bool istrue(int sudoku[N][N], int row, int col, int num)
{    return !UsedInRow(sudoku, row, num) &&
           !UsedInCol(sudoku, col, num) &&
           !usedwithinthebox(sudoku, row - row%3 , col - col%3, num);
}
void output(int sudoku[N][N])
{  cout<<"the solution is"<<endl;
    for (int row = 0; row < N; row++)
    {
       for (int col = 0; col < N; col++)
             cout<<sudoku[row][col]<<" ";
        cout<<endl;
    }
}
int main()
{  system("color 37");

    cout<<"please enter the required sudoku to be solved";

    int sudoku[N][N],i,j;
    for(i=0;i<9;i++)

        for(j=0;j<9;j++)

    {
      cin>>sudoku[i][j];
    }
    if (solve(sudoku) == true)
          output(sudoku);
    else
         cout<<"No solution exists";

    return 0;
}
