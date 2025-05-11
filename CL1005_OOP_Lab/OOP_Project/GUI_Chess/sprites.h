 //sprites.h                 
#pragma once
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <string>

class ChessTextures
{
    public:
    // Textures
    sf::Texture blackBishop;
    sf::Texture blackKing;
    sf::Texture blackKnight;
    sf::Texture blackPawn;
    sf::Texture blackQueen;
    sf::Texture blackRook;

    sf::Texture whiteBishop;
    sf::Texture whiteKing;
    sf::Texture whiteKnight;
    sf::Texture whitePawn;
    sf::Texture whiteQueen;
    sf::Texture whiteRook;

    sf::Texture emptyTile;

    ChessTextures()
    {
        if (!blackBishop.loadFromFile("png/bb.png")) throw std::runtime_error("Failed to load black bishop texture");
        if (!blackKing.loadFromFile("png/bk.png")) throw std::runtime_error("Failed to load black king texture");
        if (!blackKnight.loadFromFile("png/bn.png")) throw std::runtime_error("Failed to load black knight texture");
        if (!blackPawn.loadFromFile("png/bp.png")) throw std::runtime_error("Failed to load black pawn texture");
        if (!blackQueen.loadFromFile("png/bq.png")) throw std::runtime_error("Failed to load black queen texture");
        if (!blackRook.loadFromFile("png/br.png")) throw std::runtime_error("Failed to load black rook texture");

        if (!whiteBishop.loadFromFile("png/wb.png")) throw std::runtime_error("Failed to load white bishop texture");
        if (!whiteKing.loadFromFile("png/wk.png")) throw std::runtime_error("Failed to load white king texture");
        if (!whiteKnight.loadFromFile("png/wn.png")) throw std::runtime_error("Failed to load white knight texture");
        if (!whitePawn.loadFromFile("png/wp.png")) throw std::runtime_error("Failed to load white pawn texture");
        if (!whiteQueen.loadFromFile("png/wq.png")) throw std::runtime_error("Failed to load white queen texture");
        if (!whiteRook.loadFromFile("png/wr.png")) throw std::runtime_error("Failed to load white rook texture");

        if (!emptyTile.loadFromFile("png/blank.png")) throw std::runtime_error("Failed to load empty tile texture");
    }

    const sf::Sprite getSprite(const std::string& name)
    {
         const sf::Texture* texture = nullptr;

        if (name == "..") texture = &emptyTile;
        else if (name[0] == 'b') 
            switch (name[1]) 
            {
                case 'B': texture = &blackBishop; break;
                case 'K': texture = &blackKing; break;
                case 'N': texture = &blackKnight; break;
                case 'P': texture = &blackPawn; break;
                case 'Q': texture = &blackQueen; break;
                case 'R': texture = &blackRook; break;
            }
               else switch (name[1]) 
               {
                case 'B': texture = &whiteBishop; break;
                case 'K': texture = &whiteKing; break;
                case 'N': texture = &whiteKnight; break;
                case 'P': texture = &whitePawn; break;
                case 'Q': texture = &whiteQueen; break;
                case 'R': texture = &whiteRook; break;
               }

        if (!texture)
            throw std::runtime_error("Invalid piece name: " + name);

        sf::Sprite sprite(*texture);
        // sf::Vector2f scale( 100.0f / texture->getSize().x , 100.0f / texture->getSize().y );
        // sprite.setScale({100,100});

        return sprite;
    }
};