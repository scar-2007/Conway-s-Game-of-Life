#include<raylib.h>
#include "grid.hpp"


void Grid::Draw()
{
    for(int r = 0; r < rows; r++ )
    {
        for(int c = 0; c < columns; c++)
        {
            Color color = cells[r][c] ? Color{0,255,0,255} : Color{55,55,55,255};
            DrawRectangle(c*cellsize , r*cellsize , cellsize-1 , cellsize-1 , color );

        }
    }
}

void Grid::SetValue(int row, int column, int value)
{
    if(IsWithinBounds(row , column))
    {
        cells[row][column] = value;
    }
}

int Grid::GetValue(int row, int column)
{
    if(IsWithinBounds(row , column))
    {
        return cells[row][column];
    }
    return 0;
}

bool Grid::IsWithinBounds(int row, int column)
{
    if(row >=0 && row <=rows && column >=0 && column <=columns)
    {
        return true;
    }
    return false;
}

void Grid::FillRandom()
{
    for(int row = 0 ; row < rows ; row ++)
    {
        for(int column = 0 ; column < columns ; column++)
        {
            int randomValue = GetRandomValue(0,4);
            cells[row][column] = (randomValue==4) ? 1 : 0 ; //20% chance of cells being 1
        }
    }
}

void Grid::Clear()
{
     for(int row = 0 ; row < rows ; row ++)
     {
         for(int column = 0 ; column < columns ; column++)
         {
            cells[row][column] = 0;
         }
     }
}
