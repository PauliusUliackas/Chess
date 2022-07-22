#pragma once

#include "Piece.hpp"

class Rook : public Piece
{
private:
    bool moved;
public:
    Rook(bool);
    ~Rook();
    virtual void calculatePossibleMoves(Piece* [8][8]);
    void calculateAttackedSquares(Piece* [8][8]);
    virtual void move(sf::Vector2i);
    bool didMove();
};