#include "Engine.h"
void Engine::draw()
{
    // Стираем предыдущий кадр
    m_Window.clear(Color::White);

    // Отрисовываем фон
    //Background();
    m_Window.draw(s_map);
    // И Боба
    m_Window.draw(G.getSprite());
    //    m_Window.draw(game.getBobSprite());
    //    m_Window.draw(game.getBackgroundSprite());

    // Отображаем все, что нарисовали
    m_Window.display();
}