#include <iostream>
#include <chrono>
#define N 9 
using namespace std; 
using namespace std::chrono;

// Making of the 9 x 9 grid 
int grid[N][N] = { 
    {0, 0, 0, 0, 6, 0, 0, 4, 0},
    {3, 4, 0, 2, 0, 0, 9, 0, 0},
    {0, 9, 1, 7, 0, 0, 2, 3, 6},
    {0, 0, 0, 0, 0, 0, 0, 7, 0},
    {8, 0, 0, 3, 0, 0, 0, 2, 0},
    {0, 0, 0, 0, 7, 0, 0, 0, 9},
    {4, 0, 0, 0, 0, 0, 3, 0, 0},
    {0, 0, 9, 4, 0, 2, 1, 0, 0},
    {0, 0, 0, 0, 3, 0, 0, 0, 0}
};



// checks if the number(num) is present in the column
bool isPresentInCol(int col, int num) {
    for (int row = 0; row < N; row++) 
    {
        if (grid[row][col] == num)
            return true; 
    }
    return false; // if not found then return false
}


// checks if the number is present within the row
bool isPresentInRow(int row, int num) {
    for (int col = 0; col < N; col++)
    {
        if (grid[row][col] == num)
        {
            return true; 
        }
    }
    return false; 
}


// checks in the number is present within the box 
bool isPresentInBox(int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < (N / 3) ; row++)
    {
        for (int col = 0; col < (N / 3); col++)
        {
            if (grid[row + boxStartRow][col + boxStartCol] == num)
            {
                return true; 
            }
        }
    }
    return false; 
}
void sudokuGrid()
{ //print the sudoku grid after solve
   for (int row = 0; row < N; row++){
      for (int col = 0; col < N; col++){
         if(col == 3 || col == 6)
            cout << " | ";
         cout << grid[row][col] <<" ";
      }
      if(row == 2 || row == 5){
         cout << endl;
         for(int i = 0; i<N; i++)
            cout << "---";
      }
      cout << endl;
   }
}

// finds the empty place
bool findEmptyPlace(int &row, int &col)
{
    for (row = 0; row < N; row++)
    {
        for (col =0; col < N; col++)
        {
            if (grid[row][col] == 0) // if this place is 0 then its empty bruh
            {
                return true; 
            }
        }
    }
    return false; 
}

// Checks if the number is in the right place 
bool isValidPlace(int row, int col, int num)
{
       // when the num is not in column, row or the current box that is inspected.

    return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row % 3, col - col % 3, num);    
}

bool solveSudoku()
{
    int row, col; 
    if (!findEmptyPlace(row, col))
    {
        return true; // no empty spaces 
    }
    // numbers from 1-9
    for (int num = 1; num <= 9; num++)
    {
        if (isValidPlace(row, col, num)) { // if it is in the right place, then put the number in it
            grid[row][col] = num; 
            if (solveSudoku()) // recursively goes through the entire grid.
                return true; 
            grid[row][col] = 0; // makes the unassigned space when the shit is not right 
        }
    }
       return false;
}






int main() 
{   
    auto start = high_resolution_clock::now(); 

    if (solveSudoku() == true) {
        
        sudokuGrid();        
    }
    else 
    {
        cout << "This bitch won't solve";
    }

    // Get ending timepoint 
    auto stop = high_resolution_clock::now(); 
  
    // this will yield the time spent solving the puzzle 
    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
}