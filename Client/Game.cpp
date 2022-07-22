#include "Game.hpp"

Game::Game()
{
    g = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Legit Chess");
    isPlayerWhite = true;
    isWhitesTurn = true;
    initial = State();
    history.push_back(initial);
    selected = nullptr;
}

Game::~Game()
{
}

void Game::run()
{
    while(g->isOpen())
    {
        sf::Event e;
        while(g->pollEvent(e))
        {
            if(e.type == sf::Event::Closed) g->close();

            if(e.type == sf::Event::MouseButtonPressed)
            {
                handleClicking();
            }
        }
        g->clear();
        history[history.size()-1].render(g, isPlayerWhite);

        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8 ; j++)
            {
                drawMoves(history[history.size()-1].getTile(j,i), sf::Color::Red);
            }
        }
        drawMoves(selected, sf::Color::Green);

        g->display();
        
    }
}

void Game::handleClicking()
{
    sf::Vector2i pos = sf::Mouse::getPosition(*g);

    pos.x -= 100;
    pos.y -= 100;

    if(selected == nullptr)
    {
        selected = history[history.size()-1].getTile(pos.x/100, pos.y/100);

        if(selected == nullptr) return;

        if(selected->isWhite() != isWhitesTurn) selected = nullptr;
    }
    else
    {
        pos.x/=100, pos.y/=100;

        bool isInPossibleMoves = false;

        for(sf::Vector2i move: selected->getPossibleMoves())
        {
            if(move == pos) isInPossibleMoves = true;
        }

        if(!isInPossibleMoves) return;

        State newState = State(history[history.size()-1], selected->getPosition(), pos);
        
        history.push_back(newState);
        isWhitesTurn = !isWhitesTurn;
        selected = nullptr;
        //history[history.size()-1].calculatePossibleMoves();
        
    }
}

void Game::drawMoves(Piece* p, sf::Color c)
{
    if(p == nullptr) return;
    if(p->isWhite()) c.r -= 200;
    for(sf::Vector2i pos: p->getPossibleMoves())
    {

        pos.x *= 100;
        pos.y *= 100;

        pos.x += 125;
        pos.y += 125;

        if(p->isWhite()) pos.y -= 20;

        sf::RectangleShape r(sf::Vector2f(50, 50));
        r.setPosition(pos.x, pos.y);
        
        r.setFillColor(c);
        g->draw(r);
    }
}