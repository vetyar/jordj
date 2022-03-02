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

    // ��������� ������ � �������� ��� ����
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;
    Image map_image;
    Texture map;//�������� �����
    Sprite s_map;//������ ������ ��� �����
    
   

    void input();
    void Background();
    void update(float dtAsSeconds);
    void draw();
    Clock timerkey;
   
public:
    // ����������� ������
    Engine();
    int nowBobSteps;
    // ������� ����� ������� ��� ��������� �������
    void start();
    Game G;
    
    
    
};