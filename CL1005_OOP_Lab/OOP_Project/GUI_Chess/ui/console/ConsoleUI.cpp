#include "./ConsoleUI.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

namespace chess {

void clearScreen() {
  system("cls");
}

void help() {
  cout << "\n-----------------------------------------------------\n";
  cout << "                  Available commands\n";
  cout << "-----------------------------------------------------\n\n";
  cout << "   - board: Print the current state of the chessboard.\n";
  cout << "   - move <pos> <pos>: Make a move by specifying the starting and ending positions.\n";
  cout << "   - cls: Clear the screen.\n";
  cout << "   - quit: Quit the game.\n";
  cout << "   - help: Display this help message.\n";
}

void welcome() {
  cout << "\n-----------------------------------------------------\n";
  cout << "           Welcome to Chess::ConsoleUI!\n";
  cout << "-----------------------------------------------------\n";
  cout << "Type 'help' to see the list of available commands.\n\n";
}

void ConsoleUI::printBoard() {
  cout << "\n";

  for (int i = 7; i >= 0; i--) {
    cout << "  ";
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (j == 0) {
        cout << i + 1 << " ";
      }

      if (game.chessBoard.board[i][j].state == CellState::FILLED) {
        const ChessPiece *piece = game.chessBoard.board[i][j].piece;
        string pieceSymbol;

        switch (piece->type) {
        case PieceType::PAWN:
          pieceSymbol = "p";
          break;
        case PieceType::BISHOP:
          pieceSymbol = "b";
          break;
        case PieceType::KING:
          pieceSymbol = "k";
          break;
        case PieceType::QUEEN:
          pieceSymbol = "q";
          break;
        case PieceType::KNIGHT:
          pieceSymbol = "n";
          break;
        case PieceType::ROOK:
          pieceSymbol = "r";
          break;
        default:
          pieceSymbol = "?";
          break;
        }

        if (piece->color == PieceColor::WHITE) {
          pieceSymbol[0] = toupper(pieceSymbol[0]);
        }

        cout << pieceSymbol << " ";
      } else {
        cout << "- ";
      }
    }
    cout << endl;
    if (i == 0) {
      cout << "    a b c d e f g h\n\n";
    }
  }
}

void ConsoleUI::render(const int port) {
  (void)port;

  bool running = true;
  string command;

  clearScreen();
  welcome();

  PieceColor currentPlayer = PieceColor::WHITE;
  while (running) {
    cout << (currentPlayer == PieceColor::WHITE ? "white's" : "black's") << " turn> ";
    getline(cin, command);

    if (command.length() == 0) {
      continue;
    }

    command = trim(command);

    if (command == "quit") {
      running = false;
    } else if (command == "help") {
      clearScreen();
      help();
    } else if (command == "board") {
      clearScreen();
      printBoard();
    } else if (command == "cls") {
      clearScreen();
    } else if (command.substr(0, 4) == "move") {
      vector<string> split = splitString(command, ' ');
      if (split.size() != 3) {
        cout << "Error: Invalid command. Please specify both the starting and ending positions.\n";
        continue;
      }

      string from = split[1];
      string to = split[2];

      try {
        int toY = stoi(to.substr(1));
        int toX = to[0] - 'a' + 1;

        int fromY = stoi(from.substr(1));
        int fromX = from[0] - 'a' + 1;

        if ((toX > BOARD_SIZE || toY > BOARD_SIZE) || (fromX > BOARD_SIZE || fromY > BOARD_SIZE)) {
          cout << "Error: Invalid notation. Positions are out of range.\n";
          continue;
        }

        ChessMove move = {.from = {.x = fromX - 1, .y = fromY - 1},
                          .to = {.x = toX - 1, .y = toY - 1}};

        if (game.validateMove(&move) != MoveValidity::LegalMove) {
          cout << from << " " << to << "\n";
          cout << "Illegal move!\n";
          continue;
        }

        game.makeMove(&move);
        clearScreen();
        printBoard();
        currentPlayer = currentPlayer == PieceColor::WHITE ? PieceColor::BLACK : PieceColor::WHITE;

      } catch (const exception &e) {
        cout << "Error: Invalid command. Please use the standard chess notation.\n"
                "Example: move e3 e4\n";
        continue;
      }
    } else {
      cout << "Error: Invalid command. Type 'help' to see the list of available commands.\n";
    }
  }
}

} 
