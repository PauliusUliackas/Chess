#pragma once

#include "Piece.hpp"

class Pawn : public Piece
{
private:
    bool moved;
    bool enPesant;
public:
    Pawn(bool);
    ~Pawn();
    virtual void calculatePossibleMoves(Piece* [8][8]);
    void calculateAttackedSquares(Piece* [8][8]);
    void move(sf::Vector2i);
    bool isEnPesant();
    void setEnPesant(bool);
};
