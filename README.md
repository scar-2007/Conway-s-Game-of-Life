# Conway's Game Of Life

This is a C++ implementation of Conway's Game of Life using raylib for graphics.It is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input.

## Rules:
* Underpopulation : Any live cell with fewer than two live neighbours dies.
* Statis : Any live cell with two or three live neighbours lives on to the next generation.
* Overpopulation : Any live cell with more than three live neighbours dies.
* Reproduction : Any dead cell with exactly three live neighbours becomes a live cell.
  
## Commands:
 To control and interacting with the Game of Life:
 | Command | Action |
| ------- | ------ |
| Start the Simulation | `Enter`|
| Pause/Stop the Simulation | `Spacebar`|
| Create a Random Initial State | `R` |
| Clear the Grid | `C` |
| Adjust Simulation Speed | `F` - making the generations evolve quicker ; `S` - Slow things down |

                             
