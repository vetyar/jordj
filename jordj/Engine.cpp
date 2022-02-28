#include "Engine.h"
#include "Game.h"
#include <iostream>

using namespace std;
Engine::Engine()
{

    // Получаем разрешение экрана, создаем окно SFML и View
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;



    m_Window.create(VideoMode(resolution.x, resolution.y),
        "Simple Game Engine"/*,*/
        /*Style::Fullscreen*/);


    lastSize = m_Window.getSize();

    view = sf::View(sf::FloatRect(0, 0, m_Window.getSize().x , m_Window.getSize().y ));
    view.setViewport(sf::FloatRect(0, 0, 1, 1));

    m_Window.setView(view);


    // Загружаем фон в текстуру
    // Подготовьте изображение под ваш размер экрана в редакторе
    m_BackgroundTexture.loadFromFile("background.png");

    // Связываем спрайт и текстуру
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
    Clock timerkey;
    nowBobSteps = 0;
    /////////////////////////////////////////////////////////////////
    //объект изображения для карты
    map_image.loadFromFile("map.png");//загружаем файл для карты

    map.loadFromImage(map_image);//заряжаем текстуру картинкой

    s_map.setTexture(map);//заливаем текстуру спрайтом
    G.Win = true;
    G.loop = false;
}

void Engine::start()
{
    // Расчет времени
    Clock clock;

    while (m_Window.isOpen())
    {
        if (G.Win == true)
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
            // Перезапускаем таймер и записываем отмеренное время в dt
            Time dt = clock.restart();

            float dtAsSeconds = dt.asSeconds();

            input();
            G.Position();
            draw();
        }
        else
        {
            G.Looser();
         
        }

    }


}
void Engine::input()
{

    float dtime = timerkey.getElapsedTime().asSeconds();
    // Обрабатываем нажатие Escape
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        m_Window.close();
    }
    if (Keyboard::isKeyPressed(Keyboard::R) )
    {
        G.Looser();
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
    // Обрабатываем нажатие клавиш движения
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
        if (Keyboard::isKeyPressed(Keyboard::R) && dtime > 0.3)//reboot
        {
            G.Looser();
        }
    }
    else
    {
        if (Keyboard::isKeyPressed(Keyboard::R) && dtime > 0.3)
        {
            G.Looser();
        }

        if (G.rem_pos.size() > G.l && dtime > 0.25)
        {
            if (G.rem_pos.size() != 0)
            {
                G.Loop(G.l);
            }
            G.l++;
            timerkey.restart();
        }
        if (G.rem_pos.size() <= G.l)
        {
            G.l = 0;

        }
        
    }

}
void Engine::Background()
{
    for (int i = 0; i < HEIGHT_MAP; i++)
    {
        for (int j = 0; j < WIDTH_MAP; j++)
        {
            if (G.tabledraw[i][j] == map_pixel::EMPTY)  s_map.setTextureRect(IntRect(0, 0, 64, 64)); //ПУСТОТА
            if (G.tabledraw[i][j] == map_pixel::LOOP)  s_map.setTextureRect(IntRect(64, 0, 64, 64));//можно ходить
            if ((G.tabledraw[i][j] == map_pixel::ENTRY)) s_map.setTextureRect(IntRect(128, 0, 64, 64));//зеленая хрень
            //if ((G.tabledraw[i][j] == map_pixel::THREE_D)) s_map.setTextureRect(IntRect(128 + 64, 0, 64, 64));//3d

            s_map.setPosition(j * 64, i * 64);
            m_Window.draw(s_map);//рисуем квадратики на экран
        }
    }
    

}