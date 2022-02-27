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
    int l = 0;
public:
    // ����������� ������
    Engine();
    int nowBobSteps;
    // ������� ����� ������� ��� ��������� �������
    void start();
    const int HEIGHT_MAP = 7;//������ ����� ������
    const int WIDTH_MAP = 18;//������ ����� ������ 
    Game G;
    
};