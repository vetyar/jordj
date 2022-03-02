#pragma once

#include <SFML/Graphics.hpp>


#include <vector>
#include "Game.h"


using namespace sf;

class Engine
{
private:

    RenderWindow m_Window;
    View view;
    Vector2u lastSize;

    // Объявляем спрайт и текстуру для фона
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;
    Image map_image;
    Texture map;//текстура карты
    Sprite s_map;//создаём спрайт для карты
    
   

    void input();
    void Background();
    void update(float dtAsSeconds);
    void draw();
    Clock timerkey;
   
public:
    // Конструктор движка
    Engine();
    int nowBobSteps;
    // Функция старт вызовет все приватные функции
    void start();
    Game G;
    
    
    
};