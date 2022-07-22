#include "State.hpp"

State::State()
{
    for(int y = 0; y < 8; y++)
    {
        for(int x = 0; x < 8; x++)
        {
            board[y][x] = nullptr;
        }
    }

    board[0][4] = new King(false);
    board[0][4]->setPosition(4, 0);
    board[7][4] = new King(true);
    board[7][4]->setPosition(4,7);
    
    board[0][0] = new Rook(false);
    board[0][0]->setPosition(0,0);
    board[0][7] = new Rook(false);
    board[0][7]->setPosition(7,0);

    board[7][0] = new Rook(true);
    board[7][0]->setPosition(0,7);
    board[7][7] = new Rook(true);
    board[7][7]->setPosition(7,7);
    

    calculatePossibleMoves(true);
}

State::State(State prev, sf::Vector2i from, sf::Vector2i to)
{
    for(int y = 0; y < 8; y++)
    {
        for(int x = 0; x < 8; x++)
        {
            board[y][x] = prev.getTile(x, y);
            
            if(board[y][x] != nullptr)
                board[y][x]->setPosition(x, y);
        }
    }
    // Possible memory leak
    //delete board[to.y][to.x];
    board[to.y][to.x] = board[from.y][from.x];
    board[from.y][from.x] = nullptr;
    board[to.y][to.x]->move(to);
    //board[to.y][to.x]->setPosition(to.x, to.y);
    bool didWhiteMove = board[to.y][to.x]->isWhite();

    calculatePossibleMoves(!didWhiteMove);
}

Piece* State::getTile(int x, int y)
{
    return board[y][x];
}

bool State::isValid(bool didWhiteMove)
{

    for(int y = 0; y < 8; y++)
    {
        for(int x = 0; x < 8; x++)
        {
            Piece* p = board[y][x];
            if(p == nullptr) continue;
            if(p->isType(Piece::TYPE::King) && p->isWhite() == didWhiteMove)
            {
                return ((King*) p)->isInCheck(board); 
            }
        }
    }
    return true;
}

int State::possibleMoves(bool white)
{
    int amount = 0;
    for(int y = 0; y < 8; y++)
    {
        for(int x = 0; x < 8; x++)
        {
            Piece* p = board[y][x];
            if(p == nullptr) continue;
            if(p->isWhite() == white)
            {
                amount += p->getPossibleMoves().size();
            }
        }
    }
    return amount;
}

int State::getWorth(bool white)
{
    int worth = 0;
    for(int y = 0; y < 8; y++)
    {
        for(int x = 0; x < 8; x++)
        {
            Piece* p = board[y][x];
            if(p == nullptr) continue;
            if(p->isWhite() == white)
            {
                worth += p->getWorth();
            }
            else worth -= p->getWorth();
        }
    }
    return worth;
}

void State::render(sf::RenderWindow* g, bool white)
{

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(white)
            {
                render(g, i, j, i, j);
            }
            else
            {
                render(g, i, j, 7-i, 7-j);
            }
        }
    }
}

void State::render(sf::RenderWindow* g, int i, int j, int x, int y)
{

    sf::RectangleShape tile(sf::Vector2f(100, 100));
    tile.setPosition(100 + 100*i, 100 + 100*j);
                
    if(((j+1/8) % 2 == 0 && (i+1/8) % 2 == 0) || ((j+1/8) % 2 == 1 && (i+1/8) % 2 == 1)) tile.setFillColor(sf::Color::White);
    else tile.setFillColor(sf::Color::Black);
                
    g->draw(tile);

    Piece* p = board[j][i];
    if(p == nullptr) return;

    p->render(g, y, x);
}

void State::calculatePossibleMoves(bool whiteTurn)
{

    std::cout<<"Calculating"<<std::endl;

    std::vector<Piece*> friendly, enemy;


    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            Piece* p = board[i][j];   
            if(p != nullptr)
            {
                //p->calculatePossibleMoves(board);
                p->clearMoves();
                if(p->isWhite() == whiteTurn) friendly.push_back(p); // f.calculate possible moves
                else enemy.push_back(p);
            }
        }
    }

    // Calculate possible moves
    // For each move calculate attacked squares

    // If King in Check remove that possible Move

    //for(Piece* e : enemy) e->calculateAttackedSquares(board);
    for(Piece* f: friendly) f->calculatePossibleMoves(board);

    for(Piece* f: friendly)
    {
        std::vector<sf::Vector2i> pMoves = f->getPossibleMoves();
        for(sf::Vector2i move: pMoves)
        {
            Piece* cb[8][8];
            f->cloneBoard(board, move, cb);
            for(Piece* e: enemy) e->clearMoves();
            for(Piece* e: enemy) e->calculateAttackedSquares(cb);
            for(Piece* f: friendly) f->invalidMove(cb, move);
        }
    }
    //for(Piece* f: enemy) f->invalidMoves(board);
}

State::~State()
{
}