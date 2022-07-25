#include "King.hpp"

King::King(bool colour) : Piece(colour, "King", 40)
{
    moved = false;
    type = TYPE::King;
    castle[0] = nullptr;
    castle[1] = nullptr;
}

King::~King()
{
}

void King::calculatePossibleMoves(Piece* board[8][8])
{
    //nextMoves.clear();
    //std::cout<<"VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV"<<std::endl;
    addPossibleMove(board, sf::Vector2i(position.x-1,position.y), false);
    addPossibleMove(board, sf::Vector2i(position.x+1,position.y), false);
    addPossibleMove(board, sf::Vector2i(position.x,position.y-1), false);
    addPossibleMove(board, sf::Vector2i(position.x,position.y+1), false);
    addPossibleMove(board, sf::Vector2i(position.x-1,position.y-1), false);
    addPossibleMove(board, sf::Vector2i(position.x-1,position.y+1), false);
    addPossibleMove(board, sf::Vector2i(position.x+1,position.y-1), false);
    addPossibleMove(board, sf::Vector2i(position.x+1,position.y+1), false);
    
    int x= position.x;
    int y= position.y;

    if(!moved)
    {
        for(int i = x+1; i < 8; i++)
        {
            Piece* next = board[y][i];
            if(next != nullptr)
            {
                if(next->isType(TYPE::ROOK) && !isInCheck(board))
                {
                    Rook* rook = (Rook*) next;
                    if(!rook->didMove())
                    {
                        addPossibleMove(board, sf::Vector2i(x+2, y), false);
                        castle[0] = rook;
                    }
                }
                else 
                {
                    castle[0] = nullptr;
                    break;
                }
            }
        }
        
        for(int i = x-1; i >= 0; i--)
        {
            Piece* next = board[y][i];
            if(next != nullptr)
            {
                if(next->isType(TYPE::ROOK) && !isInCheck(board))
                {
                    Rook* rook = (Rook*) next;
                    if(!rook->didMove())
                    {
                        addPossibleMove(board,sf::Vector2i(x-2, y),false);
                        castle[1] = rook;
                    }
                }
                else
                {
                    castle[1] = nullptr;
                    break;
                }
            }
        }
    }

}

void King::move(sf::Vector2i to)
{
    Piece::setPosition(to.x, to.y);
    moved = true;
}

bool King::isInCheck(Piece* board[8][8])
{
    //std::cout<<isWhite()<<std::endl;
    // Find your own Position
    int X, Y;

    for(int y = 0; y < 8; y++)
    {
        for(int x = 0; x < 8; x++)
        {
            if(board[y][x] == this)
            {
                X = x;
                Y = y;
            }
        }
    }
    // Go through each enemies' possible moves

    for(int y = 0; y < 8; y++)
    {
        for(int x = 0; x < 8; x++)
        {
            if(board[y][x] != nullptr && board[y][x]->isWhite() != colour)
            {
                // Maybe Possible moves are poorly calculated. Try printing them. Or draw Everyone's Possible Moves
                board[y][x]->calculateAttackedSquares(board);
                for(sf::Vector2i move: board[y][x]->getAttackSquares())
                {
                    if(move.x == X && move.y == Y)
                    {
                        board[y][x]->clearMoves();
                        return true;
                    }
                }
                board[y][x]->clearMoves();
            }
        }
    }

    // if Possible move contains king's tile return true.

    return false;
}

void King::calculateAttackedSquares(Piece* board[8][8])
{
    addPossibleMove(board, sf::Vector2i(position.x-1,position.y), true);
    addPossibleMove(board, sf::Vector2i(position.x+1,position.y), true);
    addPossibleMove(board, sf::Vector2i(position.x,position.y-1), true);
    addPossibleMove(board, sf::Vector2i(position.x,position.y+1), true);
    addPossibleMove(board, sf::Vector2i(position.x-1,position.y-1), true);
    addPossibleMove(board, sf::Vector2i(position.x-1,position.y+1), true);
    addPossibleMove(board, sf::Vector2i(position.x+1,position.y-1), true);
    addPossibleMove(board, sf::Vector2i(position.x+1,position.y+1), true);
}

void King::doCastle(bool left)
{
    if(left) castle[0]->setPosition(position.x - 1, position.y);
    else     castle[1]->setPosition(position.x + 1, position.y);
}