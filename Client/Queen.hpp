#pragma once


#include "Piece.hpp"

class Queen : public Piece
{
public:
    Queen(bool);
    ~Queen();
    virtual void calculatePossibleMoves(Piece* [8][8]);
    void calculateAttackedSquares(Piece* [8][8]);
    void move(sf::Vector2i);
};