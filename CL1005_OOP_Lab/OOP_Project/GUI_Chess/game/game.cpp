#include "./game.hpp"

namespace chess {
void Game::makeMove(ChessMove *move) { chessBoard.makeMove(move); }

MoveValidity Game::validateMove(ChessMove *move) const { return chessBoard.validateMove(move); }

Board *Game::getBoard() { return &(chessBoard); }

}; 
