#pragma once

#include "Piece.hpp"

class Bishop : public Piece
{
public:
    Bishop(bool);
    ~Bishop();
    virtual void calculatePossibleMoves(Piece* [8][8]);
    void calculateAttackedSquares(Piece* [8][8]);
    void move(sf::Vector2i);
};