#include "Queen.hpp"

Queen::Queen(bool isWhite) : Piece(isWhite, "Queen", 9)
{
    type = TYPE::Queen;
}

void Queen::calculatePossibleMoves(Piece* board[8][8])
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

void Queen::calculateAttackedSquares(Piece* board[8][8])
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

void Queen::move(sf::Vector2i to)
{
    Piece::setPosition(to.x, to.y);
};