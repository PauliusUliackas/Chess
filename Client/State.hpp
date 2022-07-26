#pragma once

#include "Piece.hpp"
#include "King.hpp"
#include "Bishop.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "Queen.hpp"
#include "Pawn.hpp"

class State
{
private:
    Piece* board[8][8];
public:
    State();
    State(State prev, sf::Vector2i, sf::Vector2i);
    ~State();
    bool isValid(bool didWhiteMove);
    int possibleMoves(bool white);
    void render(sf::RenderWindow*, bool);
    Piece* getTile(int, int);
    int getWorth(bool);
    void calculatePossibleMoves(bool);
    bool isMate(bool);
    
private:
    void render(sf::RenderWindow*, int, int, int, int);
};
