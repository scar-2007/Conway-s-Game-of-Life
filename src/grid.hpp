#pragma once
# include <vector>

class Grid
{
    public:
        Grid(int width , int height , int cellsize)
        : rows(height/cellsize), columns(width/cellsize), cellsize(cellsize), cells(rows, std::vector<int>(columns,0)) {};
        void Draw();
        void SetValue(int row , int column , int value);
        int GetValue(int row , int column);
        bool IsWithinBounds(int row , int column);

        int GetRows() const { return rows; };
        int GetColumns() const { return columns; };

        void FillRandom();  
    private:
        int rows;
        int columns;
        int cellsize;
        std::vector<std::vector<int>> cells;
};  