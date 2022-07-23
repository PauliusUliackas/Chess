#pragma once

#include "Piece.hpp"
#include "Rook.hpp"

class King : public Piece
{
private:
    bool moved;
    Rook* castle[2];

public:
    King(bool);
    ~King();
    void calculatePossibleMoves(Piece* [8][8]);
    void calculateAttackedSquares(Piece* [8][8]);
    void move(sf::Vector2i);
    bool isInCheck(Piece* [8][8]);
    void doCastle(bool);
};
