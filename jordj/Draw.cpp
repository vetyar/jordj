#include "Engine.h"
void Engine::draw()
{
    // ������� ���������� ����
    m_Window.clear(Color::White);

    // ������������ ���
    //Background();
    m_Window.draw(s_map);
    // � ����
    m_Window.draw(G.getSprite());
    //    m_Window.draw(game.getBobSprite());
    //    m_Window.draw(game.getBackgroundSprite());

    // ���������� ���, ��� ����������
    m_Window.display();
}