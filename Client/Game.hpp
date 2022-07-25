#pragma once

#include "State.hpp"

class Game
{
private:
    std::vector<State> history;
    sf::RenderWindow* g;
    State initial;
    bool isPlayerWhite;
    bool isWhitesTurn;
    Piece* selected;

public:
    Game();
    ~Game();
    void run();

private:
    void handleClicking();
    void drawMoves(Piece*, sf::Color c);
    void drawAttackedSquares(Piece* p);
};