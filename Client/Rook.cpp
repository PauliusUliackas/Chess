#include "Rook.hpp"


Rook::Rook(bool isWhite) : Piece(isWhite, "Rook", 5)
{
    type = TYPE::ROOK;
    moved = false;
}

void Rook::calculatePossibleMoves(Piece* board[8][8])
{
    for(int i = position.y+1; i < 8; i++)
    {
        Piece* p = board[i][position.x];
        if(p != nullptr && p->isWhite() == colour) break;
        addPossibleMove(board, sf::Vector2i(position.x, i), false);
        if(p != nullptr && p->isWhite() != colour) break;
    }
    for(int i = position.y-1; i >= 0; i--)
    {
        Piece* p = board[i][position.x];
        if(p != nullptr && p->isWhite() == colour) break;
        addPossibleMove(board, sf::Vector2i(position.x, i), false);
        if(p != nullptr && p->isWhite() != colour) break;
    }

    for(int i = position.x+1; i < 8; i++)
    {
        Piece* p = board[position.y][i];
        if(p != nullptr && p->isWhite() == colour) break;
        addPossibleMove(board, sf::Vector2i(i, position.y), false);
        if(p != nullptr && p->isWhite() != colour) break;
    }
    for(int i = position.x-1; i >= 0; i--)
    {
        Piece* p = board[position.y][i];
        if(p != nullptr && p->isWhite() == colour) break;
        addPossibleMove(board, sf::Vector2i(i, position.y), false);
        if(p != nullptr && p->isWhite() != colour) break;
    }
}

void Rook::move(sf::Vector2i to)
{
    Piece::setPosition(to.x, to.y);
    moved = true;
}

bool Rook::didMove()
{
    return moved;
}

Rook::~Rook()
{
}


void Rook::calculateAttackedSquares(Piece* board[8][8])
{
    for(int i = position.y+1; i < 8; i++)
    {
        Piece* p = board[i][position.x];
        if(p != nullptr && p->isWhite() == colour) break;
        addPossibleMove(board, sf::Vector2i(position.x, i), true);
        if(p != nullptr && p->isWhite() != colour) break;
    }
    for(int i = position.y-1; i >= 0; i--)
    {
        Piece* p = board[i][position.x];
        if(p != nullptr && p->isWhite() == colour) break;
        addPossibleMove(board, sf::Vector2i(position.x, i), true);
        if(p != nullptr && p->isWhite() != colour) break;
    }

    for(int i = position.x+1; i < 8; i++)
    {
        Piece* p = board[position.y][i];
        if(p != nullptr && p->isWhite() == colour) break;
        addPossibleMove(board, sf::Vector2i(i, position.y), true);
        if(p != nullptr && p->isWhite() != colour) break;
    }
    for(int i = position.x-1; i >= 0; i--)
    {
        Piece* p = board[position.y][i];
        if(p != nullptr && p->isWhite() == colour) break;
        addPossibleMove(board, sf::Vector2i(i, position.y), true);
        if(p != nullptr && p->isWhite() != colour) break;
    }
}