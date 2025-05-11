#ifndef GAME_HPP
#define GAME_HPP

#include "../board/board.hpp"
#include <array>
#include <cassert>
#include <stack>

using std::array, std::stack;

namespace chess {
enum GameState { WhiteCheck, WhiteMate, BlackCheck, BlackMate };

class Game {
public:
  MoveValidity validateMove(ChessMove *move) const;
  void makeMove(ChessMove *move);
  Board chessBoard;
  Board *getBoard();
};
} 
#endif
