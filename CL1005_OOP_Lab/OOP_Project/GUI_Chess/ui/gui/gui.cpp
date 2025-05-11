#include "./GUI.hpp"
#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "../../grid.h"

namespace chess {

string outputMouseInput(RenderWindow& screen) {
    auto coordinates= Mouse::getPosition(screen);
    char x='a'+coordinates.x/100;
    char y='8'-coordinates.y/100;
    std::string a={x,y};
    return a;
}

void GUI::render(const int port) {
    PieceColor currentPlayer = PieceColor::WHITE;

    RenderWindow screen(VideoMode({800, 800}), "Chess Game");
    Grid guiGrid;
    guiGrid.update(1);
    guiGrid.draw(screen);
    string from = "";
    string to = "";
    Board *board = game.getBoard();
    auto fileGrid = guiGrid.getGrid();
    while (screen.isOpen()) {
        // cout << (currentPlayer == PieceColor::WHITE ? "white's" : "black's") << " turn> ";
        while(const std::optional event = screen.pollEvent()) {
            cout << "Test" << std::endl;
            if (event->is<Event::Closed>()){
                screen.close();
                break;
            }
            if (from.empty() && event->is<Event::MouseButtonPressed>()) {
                from = outputMouseInput(screen);
                cout << from << std::endl;
                cout.flush();
            } else if (to.empty() && event->is<Event::MouseButtonPressed>()) {
                to = outputMouseInput(screen);
                cout << to << std::endl;
                continue;
            } else {
                continue;
            }
            // game.makeMove()
        //  if (event->is<Event::KeyPressed>())checkKey();
        }
        try {
            if (from.empty() || to.empty()) continue;
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
            cout << "Illegal move!\n";
            from = "";
            to = "";
            continue;
            }

            game.makeMove(&move);
            auto boardArray = board->board;

            for (int i=7; i>=0; i--) {
                for (int j=0; j<8; j++) {
                    if (boardArray[i][j].state == CellState::FILLED) {
                        const ChessPiece *piece = boardArray[i][j].piece;
                        std::string pieceSymbol;

                        switch (piece->type) {
                            case PieceType::PAWN:
                                if (piece->color == PieceColor::BLACK) 
                                fileGrid[7-i][j] = "bP";
                                else
                                fileGrid[7-i][j] = "wP";
                                break;
                            case PieceType::BISHOP:
                                if (piece->color == PieceColor::BLACK) 
                                fileGrid[7-i][j] = "bB";
                                else
                                fileGrid[7-i][j] = "wB";
                                break;
                            case PieceType::KING:
                                if (piece->color == PieceColor::BLACK) 
                                fileGrid[7-i][j] = "bK";
                                else
                                fileGrid[7-i][j] = "wK";
                                break;
                            case PieceType::QUEEN:
                                if (piece->color == PieceColor::BLACK) 
                                fileGrid[7-i][j] = "bQ";
                                else
                                fileGrid[7-i][j] = "wQ";
                                break;
                            case PieceType::KNIGHT:
                                if (piece->color == PieceColor::BLACK) 
                                fileGrid[7-i][j] = "bN";
                                else
                                fileGrid[7-i][j] = "wN";
                                break;
                            case PieceType::ROOK:
                                if (piece->color == PieceColor::BLACK) 
                                fileGrid[7-i][j] = "bR";
                                else
                                fileGrid[7-i][j] = "wR";
                                break;
                            default:
                                fileGrid[7-i][j] = "..";
                                break;
                        }
                    } else {
                        fileGrid[7-i][j] = "..";
                    }
                    cout << fileGrid[i][j] << " ";
                }
                cout << "\n";
            }

            cout << "before" << "\n";
            guiGrid.update(0);
            cout << "mid" << "\n";
            guiGrid.draw(screen);
            cout << "after" << "\n";

            from = "";
            to   = "";
            currentPlayer = currentPlayer == PieceColor::WHITE ? PieceColor::BLACK : PieceColor::WHITE;

        } catch (const std::exception &e) {
            cout << "Erro: Invalid command. Please follow chess rules.\n"
                    "Example: move e3 e4\n"
                    << from << " " << to << "\n";
            continue;
        }
        
    }
    
    screen.close(); 
}

}