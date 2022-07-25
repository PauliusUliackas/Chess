#include "Pawn.hpp"


Pawn::Pawn(bool isWhite) : Piece(isWhite, "Pawn", 1)
{
    type = TYPE::Pawn;
    moved = false;
    enPesant = false;
}

void Pawn::calculatePossibleMoves(Piece* board[8][8])
{
    int Y;
    if(isWhite()) Y = position.y - 1;
    else Y = position.y + 1;
    
    if(board[Y][position.x] == nullptr)
        addPossibleMove(board, sf::Vector2i(position.x, Y), false);
    
    if(board[Y][position.x -1] != nullptr) addPossibleMove(board, sf::Vector2i(position.x -1, Y), false);
    if(board[Y][position.x +1] != nullptr) addPossibleMove(board, sf::Vector2i(position.x +1, Y), false);

    if(!moved)
    {
        if(isWhite()) Y = Y - 1;
        else Y = Y + 1;
        if(board[Y][position.x] == nullptr)
            addPossibleMove(board, sf::Vector2i(position.x, Y), false);
    }
    
    if(position.y == 3 && isWhite())
    {
        Piece* p = board[position.y][position.x - 1];
        Y = position.y - 1;
        if(p != nullptr && p->isType(TYPE::Pawn) && ((Pawn*) p)->isEnPesant()) addPossibleMove(board, sf::Vector2i(position.x - 1, Y), false);
        p = board[position.y][position.x + 1];
        if(p != nullptr && p->isType(TYPE::Pawn) && ((Pawn*) p)->isEnPesant()) addPossibleMove(board, sf::Vector2i(position.x + 1, Y), false);
    }

    if(position.y == 4 && !isWhite())
    {
        Y = position.y + 1;
        Piece* p = board[position.y][position.x - 1];
        if(p != nullptr && p->isType(TYPE::Pawn) && ((Pawn*) p)->isEnPesant()) addPossibleMove(board, sf::Vector2i(position.x - 1, Y), false);
        p = board[position.y][position.x + 1];
        if(p != nullptr && p->isType(TYPE::Pawn) && ((Pawn*) p)->isEnPesant()) addPossibleMove(board, sf::Vector2i(position.x + 1, Y), false);
    }
    
}

void Pawn::calculateAttackedSquares(Piece* board[8][8])
{
    int Y;
    if(isWhite()) Y = position.y - 1;
    else Y = position.y + 1;

    addPossibleMove(board, sf::Vector2i(position.x -1, Y), true);
    addPossibleMove(board, sf::Vector2i(position.x +1, Y), true);
}

void Pawn::move(sf::Vector2i to)
{

    if(std::abs(to.y - position.y) > 1) enPesant = true;

    setPosition(to.x, to.y);
    moved = true;
}

bool Pawn::isEnPesant()
{
    return enPesant;
}

void Pawn::setEnPesant(bool b)
{
    enPesant = b;
}

Pawn::~Pawn()
{
}