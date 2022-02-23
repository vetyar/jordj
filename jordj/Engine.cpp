#include "Engine.h"
#include "Game.h"
#include <iostream>

using namespace std;
Engine::Engine()
{
   
    // �������� ���������� ������, ������� ���� SFML � View
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

 

    m_Window.create(VideoMode(resolution.x, resolution.y),
        "Simple Game Engine"/*,
        Style::Fullscreen*/);


    lastSize = m_Window.getSize();

    view = sf::View(sf::FloatRect(0, 0, m_Window.getSize().x/1.5, m_Window.getSize().y/1.5));
    view.setViewport(sf::FloatRect(0, 0, 1, 1));

    m_Window.setView(view);


    // ��������� ��� � ��������
    // ����������� ����������� ��� ��� ������ ������ � ���������
    m_BackgroundTexture.loadFromFile("background.png");

    // ��������� ������ � ��������
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
    Clock timerkey;
    nowBobSteps = 0;
    /////////////////////////////////////////////////////////////////
    //������ ����������� ��� �����
    map_image.loadFromFile("map.png");//��������� ���� ��� �����
    
    map.loadFromImage(map_image);//�������� �������� ���������
    
    s_map.setTexture(map);//�������� �������� ��������
    
}

void Engine::start()
{
    // ������ �������
    Clock clock;
    
    while (m_Window.isOpen() && G.Win == true)
    {
        sf::Event event;
        while (m_Window.pollEvent(event))
        {
          // "close requested" event: we close the window
          if (event.type == sf::Event::Closed)
            m_Window.close();
          if (event.type == sf::Event::Resized)
          {
         

            float partX = event.size.width * 1.0 / lastSize.x;
            float partY = event.size.height * 1.0 / lastSize.y;

            view.setSize(event.size.width, event.size.height);

            view.setViewport(sf::FloatRect(0, 0, 1, 1));
            m_Window.setView(view);
          }
        }
        // ������������� ������ � ���������� ���������� ����� � dt
        Time dt = clock.restart();
        
        float dtAsSeconds = dt.asSeconds();

        input();
        G.Position();
        draw();
        
    }
    
    m_Window.clear(Color::Red);
} 
void Engine::input()
{
    
    float dtime = timerkey.getElapsedTime().asSeconds();
    // ������������ ������� Escape
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        m_Window.close();
    }


    //class game {
    //  int table[20][20];
    //public:
    //  void leftKey() {
     //      table[bobPos.x][bobPos.y] = 0;
    //      table[bobPos.x - 1][bobPos.y] = 1;
    //    }
    //  }
    //}


    // game G;
    // 
    // ������������ ������� ������ ��������
    if (G.loop == false)
    {
        if (Keyboard::isKeyPressed(Keyboard::A) && dtime > 0.3)
        {

            timerkey.restart();
            nowBobSteps++;
            G.Leftkey();
        }
        else
        {

        }

        if (Keyboard::isKeyPressed(Keyboard::D) && dtime > 0.3)
        {

            timerkey.restart();
            nowBobSteps++;
            G.Rightkey();
        }
        else
        {

        }
        if (Keyboard::isKeyPressed(Keyboard::W) && dtime > 0.3)
        {

            timerkey.restart();
            nowBobSteps++;
            G.Upkey();
        }
        else
        {

        }
        if (Keyboard::isKeyPressed(Keyboard::S) && dtime > 0.3)
        {
            G.Downkey();
            timerkey.restart();
            nowBobSteps++;
        }
        else
        {

        }
    }
    else
    {

        
        if (G.rem_pos.size()  > l && dtime > 0.5 )
        {
            G.Loop(l);
            l++;
            timerkey.restart();
        }
        if(G.rem_pos.size()  == l )
        {
            l = 0;
      
        }
    }

}
 void Engine::Background()
{
    for (int i = 0; i < HEIGHT_MAP; i++)
        for (int j = 0; j < WIDTH_MAP; j++)
        {
            if (G.table[i][j] == 1)  s_map.setTextureRect(IntRect(0, 0, 64, 64)); //�������
            if (G.table[i][j] == 0)  s_map.setTextureRect(IntRect(64, 0, 64, 64));//����� ������
            if ((G.table[i][j] == 2)) s_map.setTextureRect(IntRect(128, 0, 64, 64));//������� �����


            s_map.setPosition(j * 64, i * 64);
           m_Window.draw(s_map);//������ ���������� �� �����
        }
   
}

