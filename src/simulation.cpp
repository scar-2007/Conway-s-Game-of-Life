#include <vector>
#include <utility>
#include "simulation.hpp"

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value)
{
    grid.SetValue(row , column , value);
}

int Simulation::CountLiveNeighbours(int row, int column)
{
    int liveNeighbours = 0;
    std::vector<std::pair<int,int>> neighbourOffsets = {
        {-1, 0}, //above
        {1, 0},  //below
        {0, -1}, //left
        {0, 1},  //right
        {-1, -1},//D-upper left
        {-1, 1}, //D-upper right
        {1, -1}, //D-lower left
        {1, 1} //D-lower right
    };

    for (const auto& offset : neighbourOffsets)
    {
        //making a toroidal grid
        int neighbourRow = (row + offset.first + grid.GetRows()) % grid.GetRows();
        int neighbourColumn = (column + offset.second + grid.GetColumns()) % grid.GetColumns();
        liveNeighbours += grid.GetValue(neighbourRow, neighbourColumn);
    }
    return liveNeighbours;
}

void Simulation::Update()
{
    if(IsRunning())
    {
        for(int row = 0 ; row < grid.GetRows() ; row ++)
        {
            for(int column = 0 ; column < grid.GetColumns() ; column++)
            {
                int liveNeighbours = CountLiveNeighbours(row , column);
                int cellValue = grid.GetValue(row , column);

                if (cellValue == 1)
                {
                    if(liveNeighbours >3 || liveNeighbours <2)
                    {
                        tempgrid.SetValue(row , column , 0);
                    }
                    else
                    {
                        tempgrid.SetValue(row , column , 1);
                    }

                }
                else
                {
                    if (liveNeighbours ==3)
                    {
                        tempgrid.SetValue(row , column , 1);
                    }
                    else
                    {
                        tempgrid.SetValue(row , column , 0);
                    }
                }
            }
        }
        grid = tempgrid;
    }   
}
