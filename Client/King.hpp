#pragma once

#include "Piece.hpp"

class King : public Piece
{
private:
    bool moved;
public:
    King(bool);
    ~King();
    void calculatePossibleMoves(Piece* [8][8]);
    void move(sf::Vector2i);
    bool isInCheck(Piece* [8][8]);
};