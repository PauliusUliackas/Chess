#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Piece
{

public:
    enum TYPE
    {
        Pawn,
        Queen,
        King,
        Rook,
        Knight,
        Bishop
    };

protected:
    bool colour;
    const int worth;
    std::vector<sf::Vector2i> nextMoves;
    sf::Vector2i position;
    sf::Texture texture;
    sf::Sprite sprite;
    TYPE type;

public:
    Piece(bool colour, std::string, int worth);
    ~Piece();
    virtual void calculatePossibleMoves(Piece* [8][8]) = 0;
    virtual void move(sf::Vector2i);
    std::vector<sf::Vector2i> getPossibleMoves();
    void render(sf::RenderWindow*, int, int);
    bool isType(TYPE);
    bool isWhite();
    int getWorth();
    virtual bool isInCheck(Piece* [8][8]);
    void setPosition(int x, int y);
    sf::Vector2i getPosition();
    void clearMoves();

protected:
    void addPossibleMove(Piece* [8][8], sf::Vector2i nextMove);
    void drawBoard(Piece* [8][8]);

};