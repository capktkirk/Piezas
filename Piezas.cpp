#include "Piezas.h"
#include <vector>
#include <iostream>
#define fou(i,j) for(int i = 0; i < (int)j.size(); i++)
#define fot(i,j) for(int i = 0, j = 0; j < 3 && i < 4; (i == 3) ? i = 0, j++ : i++)
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
  turn = X;
  board.resize(3); //3 rows
  //If this doesn't work, do two nested for loops.
  for(int i = 0; i < 4; i++){ board[i].resize(4); }
  fot(j,i){
    board[i][j] = Blank;
  }
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
fot(j,i){
    board[i][j] = Blank;
  }

}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
  //returning this to it's original position.
  Piece c_turn = turn;
  turn = turn == X ? O : X;
  //If the column is full return invalid.

  if(column >= BOARD_COLS) { return Invalid; }
  for(int i = 0; i < BOARD_ROWS; i++){
    if(board[i][column] == Blank){
      board[i][column] = turn;
      return c_turn;
    }
  }
  return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
  if(row <= (int)board.size()){
    if(column <= (int)board[0].size()){
      bool row_t = row < 0;
      bool col_t = column < 0;
      if(row_t || col_t){
        return Invalid;
      }
    }
  }
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
  //Initialize max O, max X, current O, current X;
  int m_o = 0, m_x = 0, c_o = 0, c_x = 0;

  //vertical check
  fou(i,board[0]){
    fou(j, board){
      //The game isn't over if this first check finds a blank spot.
      if(board[j][i] == Blank) { return Invalid; }
      if(board[j][i] == O){
        c_x = 0; c_o++; //std::cout << "board[" << j << "][" << i << "] vertical c_o++\n";
        if(c_o > m_o) { m_o = c_o; }
      }
      else if(board[j][i] == X){
        c_o = 0; c_x++; //std::cout << "board[" << j << "][" << i << "]  vertical c_x++\n";
        if(c_x > m_x){ m_x = c_x; }
      }
    }
  }
  //horizontal check (? I think ? starting at 0, then going left to right.)
  int temp_x = m_x;
  int temp_o = m_o;
  m_x = 0;
  m_o = 0;
  fou(i,board){
    fou(j,board[i]){
      if(board[i][j] == O){
        c_x = 0; c_o++; 
        if(c_o > m_o) { m_o = c_o; }
      }
      else if(board[i][j] == X){
        c_o = 0; c_x++; 
        if(c_x > m_x) { m_x = c_x; }
      }
    }
  }
  if(temp_x > m_x){ m_x = temp_x; }
  if(temp_o > m_o){ m_o = temp_o; }
// custom forloop may not work for setting board because of hardcoded values?

  // fot(i,j){
  //   std::cout << "board[" << j << "][" << i << "] == " << board[j][i];
  //   if(i == 3){
  //     std::cout << std::endl;
  //   }
  //   else{
  //     std::cout << " ";
  //   }
  // }
  // std::cout << "m_x == " << m_x << std::endl;
  // std::cout << "m_o == " << m_o << std::endl;
  if(m_x > m_o) { return X; }
  else if(m_x < m_o) { return O; }
  //Base case if m_x is not less than or greater than m_o then it has to be equal to.
  return Blank; //I think I need a return at base level for full coverage or to remove warnings.
}
