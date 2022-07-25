#include "Piece.hpp"


Piece::Piece(bool colour, std::string path, int w):
worth{w}
{
    this->colour = colour;
    if(!colour) path+="B";

    texture.loadFromFile("Art/"+path+".png");
    sprite.setTexture(texture);

    sprite.scale(4,4);
}

Piece::~Piece()
{
}

std::vector<sf::Vector2i> Piece::getPossibleMoves()
{
    return nextMoves;
}

void Piece::render(sf::RenderWindow* g, int y, int x)
{
    sprite.setPosition(116+100*x, 116 +100*y);
    g->draw(sprite);
}

bool Piece::isType(TYPE type)
{
    return type == this->type;
};

bool Piece::isWhite()
{
    return colour;
}

int Piece::getWorth()
{
    return worth;
}

bool Piece::isInCheck(Piece* [8][8])
{
    return false;
}

void Piece::addPossibleMove(Piece* board[8][8], sf::Vector2i nextMove, bool attacked)
{
    if(nextMove.x < 0 || nextMove.x > 7 || nextMove.y < 0 || nextMove.y > 7) 
    {
        return;
    }
    
    //Check if is not Occupied by our own piece
    Piece* p = board[nextMove.y][nextMove.x];
    if(p != nullptr && p->isWhite() == colour) return;

    if(attacked) AttackedSquares.push_back(nextMove);
    else nextMoves.push_back(nextMove);
}

void Piece::invalidMove(Piece* cloneBoard[8][8], sf::Vector2i move)
{
    bool isInCheck = false;

    for(int y = 0; y < 8; y++)
    {
        for(int x = 0; x < 8; x++)
        {
            Piece* p = cloneBoard[y][x];
            if(p == nullptr) continue;
            if(p->isType(Piece::TYPE::King) && p->isWhite() == colour)
            {
                if(p->isInCheck(cloneBoard)) isInCheck = true;
            }
        }
    }

    if(!isInCheck) return;

    for(int i = 0; i < nextMoves.size(); i++)
    {
        if(move == nextMoves[i]) nextMoves.erase(nextMoves.begin() + i);
    }
    
}

void Piece::cloneBoard(Piece* board[8][8], sf::Vector2i nextMove, Piece* cloneBoard[8][8])
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            cloneBoard[i][j] = board[i][j];
        }
    }

    cloneBoard[nextMove.y][nextMove.x] = cloneBoard[position.y][position.x];
    cloneBoard[position.y][position.x] = nullptr;
}

void Piece::move(sf::Vector2i postion)
{
    setPosition(position.x, position.y);
};

void Piece::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
}

sf::Vector2i Piece::getPosition()
{
    return position;
}

void Piece::drawBoard(Piece* board[8][8])
{
    std::cout<<"--------------------"<<std::endl;
    for(int i = 0; i< 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            std::string s = "  ";
            if(board[i][j] != nullptr)
            {
                s = "K";
                if(board[i][j]->isWhite()) s += "W";
                else s += "B";
            }
            
            std::cout<<s<<",";
        }
        std::cout<<std::endl;
    }
    std::cout<<"--------------------"<<std::endl;
}

void Piece::clearMoves()
{
    nextMoves.clear();
    AttackedSquares.clear();
}

std::vector<sf::Vector2i> Piece::getAttackSquares()
{
    return AttackedSquares;
}