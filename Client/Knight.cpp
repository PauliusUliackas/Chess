#include "Knight.hpp"

Knight::Knight(bool b) : Piece(b, "Horse", 3)
{
    type = TYPE::Knight;
}

Knight::~Knight()
{
}

void Knight::calculatePossibleMoves(Piece* board[8][8])
{
    int x = position.x;
    int y = position.y;

    addPossibleMove(board, sf::Vector2i(x+1, y+2), false);
    addPossibleMove(board, sf::Vector2i(x+2, y+1), false);
    addPossibleMove(board, sf::Vector2i(x-1, y+2), false);
    addPossibleMove(board, sf::Vector2i(x-2, y+1), false);
    addPossibleMove(board, sf::Vector2i(x+1, y-2), false);
    addPossibleMove(board, sf::Vector2i(x+2, y-1), false);
    addPossibleMove(board, sf::Vector2i(x-1, y-2), false);
    addPossibleMove(board, sf::Vector2i(x-2, y-1), false);
};

void Knight::calculateAttackedSquares(Piece* board[8][8])
{   

    int x = position.x;
    int y = position.y;
    addPossibleMove(board, sf::Vector2i(x+1, y+2), true);
    addPossibleMove(board, sf::Vector2i(x+2, y+1), true);
    addPossibleMove(board, sf::Vector2i(x-1, y+2), true);
    addPossibleMove(board, sf::Vector2i(x-2, y+1), true);
    addPossibleMove(board, sf::Vector2i(x+1, y-2), true);
    addPossibleMove(board, sf::Vector2i(x+2, y-1), true);
    addPossibleMove(board, sf::Vector2i(x-1, y-2), true);
    addPossibleMove(board, sf::Vector2i(x-2, y-1), true);
};

void Knight::move(sf::Vector2i to)
{
    Piece::setPosition(to.x, to.y);
}