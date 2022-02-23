#include "Game.h"
#include <iostream>;
using namespace std;
using namespace sf;
Game::Game()
{
		bob_table_position.x = 1;
		bob_table_position.y =3;
		m_Texture.loadFromFile("best_bob.png");
		m_Sprite.setTexture(m_Texture);
		square = 64;
		def_pos.x = (bob_table_position.x - 1) * square ;
		def_pos.y = (bob_table_position.y-1)*square;
		
}
Sprite Game::getSprite()
{
	return m_Sprite;
}
void Game::Leftkey()
{
	//table[bob_table_position.x][bob_table_position.y] = 0;
	if (table[bob_table_position.y][bob_table_position.x-1] == 1)
	{
		Win = false;
	}
	else
	{
		bob_table_position.x -= 1;
		Rem_Pos("Left");
		if (loop == false && table[bob_table_position.y][bob_table_position.x - 1] == 0)
		{
			rem_pos.push_back("Left");
		}
		if (table[bob_table_position.y ][bob_table_position.x-1] == 0)
		{
			loop = true;
		}
		
	}
	//table[bob_table_position.x][bob_table_position.y] = -1;
}

void Game::Rightkey()
{
	//table[bob_table_position.x][bob_table_position.y] = 0;
	if (table[bob_table_position.y][bob_table_position.x+1] == 1)
	{
		Win = false;
	}
	else
	{
		bob_table_position.x += 1;
		//if(table[bob_table_position.y][bob_table_position.x - 1] != 0) //Эту строку можно использовать для того чтобы фиксить баг при входе в другу. зеленую область
		Rem_Pos("Right");
		if (loop == false && table[bob_table_position.y][bob_table_position.x + 1] == 0)
		{
			rem_pos.push_back("Right");
		}
		if (table[bob_table_position.y][bob_table_position.x + 1] == 0)
		{
			loop = true;
		}
		
	}
	//table[bob_table_position.x][bob_table_position.y] = -1;
}

void Game::Upkey()
{
	//table[bob_table_position.x][bob_table_position.y] = 0;
	if (table[bob_table_position.y -1][bob_table_position.x] == 1)
	{
		Win = false;
	}
	else
	{
		bob_table_position.y -= 1;
		Rem_Pos("Up");
		if (loop == false && table[bob_table_position.y - 1][bob_table_position.x] == 0)
		{
			rem_pos.push_back("Up");
		}
		if (table[bob_table_position.y-1][bob_table_position.x] == 0)
		{
			loop = true;
		}
		
	}
	//table[bob_table_position.x][bob_table_position.y] = -1;
}

void Game::Downkey()
{
	//table[bob_table_position.x][bob_table_position.y] = 0;
	if (table[bob_table_position.y + 1][bob_table_position.x] == 1)
	{
		Win = false;
	}
	else
	{
		bob_table_position.y += 1;
		Rem_Pos("Down");
		if (loop == false && table[bob_table_position.y + 1][bob_table_position.x] == 0)
		{
			rem_pos.push_back("Down");//для добавление последнего хода
		}
		if (table[bob_table_position.y + 1][bob_table_position.x] == 0)
		{
			loop = true;
		}
		
		
	}
	//table[bob_table_position.x][bob_table_position.y] = -1;
}

	// Теперь сдвигаем спрайт на новую позицию
	//m_Sprite.setPosition(m_Position);
void Game::Position()
{
	m_Position.x = bob_table_position.x * square;
	m_Position.y = bob_table_position.y * square;
	m_Sprite.setPosition(m_Position);
}
 void Game::Rem_Pos(string x)
{
	 if (table[bob_table_position.y][bob_table_position.x] == 2)
	 {
		 rem_pos.push_back(x);

		 cout << rem_pos[k] << " ";
		 k++;
	 }
}
 void Game::Loop(int l)
 {
	 if (rem_pos[l] == "Up")
	 {
		 Upkey();
		 
	 }
	 if (rem_pos[l] == "Down")
	 {
		 Downkey();
	 }
	 if (rem_pos[l] == "Right")
	 {
		 Rightkey();
	 }
	 if (rem_pos[l] == "Left")
	 {
		 Leftkey();
	 }

 }


