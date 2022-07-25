#pragma once

#include "Piece.hpp"

class Knight : public Piece
{
private:
    /* data */
public:
    Knight(bool);
    ~Knight();
    void calculatePossibleMoves(Piece* [8][8]);
    void calculateAttackedSquares(Piece* [8][8]);
    void move(sf::Vector2i);
};