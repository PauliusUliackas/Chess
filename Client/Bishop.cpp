#include "Bishop.hpp"

Bishop::Bishop(bool isWhite) : Piece(isWhite, "Bishop", 3)
{
    type = TYPE::Bishop;
}

void Bishop::calculatePossibleMoves(Piece* board[8][8])
{
    for(int i = 1; i < 8; i++)
    {
        int X = position.x - i;
        int Y = position.y - i;
        if(Y > 7 || Y < 0 || X > 7 || X < 0) break;
        Piece* p = board[Y][X];
        if(p != nullptr && p->isWhite() == colour) break;
        addPossibleMove(board, sf::Vector2i(X, Y), false);
        if(p != nullptr && p->isWhite() != colour) break;
    }
    for(int i = 1; i < 8; i++)
    {
        int X = position.x + i;
        int Y = position.y - i;
        if(Y > 7 || Y < 0 || X > 7 || X < 0) break;
        Piece* p = board[Y][X];
        if(p != nullptr && p->isWhite() == colour) break;
        addPossibleMove(board, sf::Vector2i(X, Y), false);
        if(p != nullptr && p->isWhite() != colour) break;
    }

    for(int i = 1; i < 8; i++)
    {
        int X = position.x - i;
        int Y = position.y + i;
        if(Y > 7 || Y < 0 || X > 7 || X < 0) break;
        Piece* p = board[Y][X];
        if(p != nullptr && p->isWhite() == colour) break;
        addPossibleMove(board, sf::Vector2i(X, Y), false);
        if(p != nullptr && p->isWhite() != colour) break;
    }
    for(int i = 1; i < 8; i++)
    {
        int X = position.x + i;
        int Y = position.y + i;
        if(Y > 7 || Y < 0 || X > 7 || X < 0) break;
        Piece* p = board[Y][X];
        if(p != nullptr && p->isWhite() == colour) break;
        addPossibleMove(board, sf::Vector2i(X, Y), false);
        if(p != nullptr && p->isWhite() != colour) break;
    }
}

void Bishop::calculateAttackedSquares(Piece* board[8][8])
{
    for(int i = 1; i < 8; i++)
    {
        int X = position.x - i;
        int Y = position.y - i;
        if(Y > 7 || Y < 0 || X > 7 || X < 0) break;
        Piece* p = board[Y][X];
        if(p != nullptr && p->isWhite() == colour) break;
        addPossibleMove(board, sf::Vector2i(X, Y), true);
        if(p != nullptr && p->isWhite() != colour) break;
    }
    for(int i = 1; i < 8; i++)
    {
        int X = position.x + i;
        int Y = position.y - i;
        if(Y > 7 || Y < 0 || X > 7 || X < 0) break;
        Piece* p = board[Y][X];
        if(p != nullptr && p->isWhite() == colour) break;
        addPossibleMove(board, sf::Vector2i(X, Y), true);
        if(p != nullptr && p->isWhite() != colour) break;
    }

    for(int i = 1; i < 8; i++)
    {
        int X = position.x - i;
        int Y = position.y + i;
        if(Y > 7 || Y < 0 || X > 7 || X < 0) break;
        Piece* p = board[Y][X];
        if(p != nullptr && p->isWhite() == colour) break;
        addPossibleMove(board, sf::Vector2i(X, Y), true);
        if(p != nullptr && p->isWhite() != colour) break;
    }
    for(int i = 1; i < 8; i++)
    {
        int X = position.x + i;
        int Y = position.y + i;
        if(Y > 7 || Y < 0 || X > 7 || X < 0) break;
        Piece* p = board[Y][X];
        if(p != nullptr && p->isWhite() == colour) break;
        addPossibleMove(board, sf::Vector2i(X, Y), true);
        if(p != nullptr && p->isWhite() != colour) break;
    }
}

void Bishop::move(sf::Vector2i to)
{
    Piece::setPosition(to.x, to.y);
    std::cout<<position.x<<","<<position.y<<std::endl;
};