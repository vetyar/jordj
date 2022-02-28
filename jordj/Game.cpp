#include "Game.h"
#include <iostream>
using namespace std;
using namespace sf;
Game::Game()
{
	KostylInitCustomMap(table);
	KostylInitCustomMap(tabledraw);
	bob_table_position.x = 1;
	bob_table_position.y = 3;
	m_Texture.loadFromFile("best_bob.png");
	m_Sprite.setTexture(m_Texture);
	square = 64;
	def_pos.x = 0 * square;
	def_pos.y = 6 * square;
	loop = false;
}
Sprite Game::getSprite()
{
	return m_Sprite;
}

// TODO:
void Game::SetLoop(int x_curr, int y_curr, int x_prev = 0, int y_prev = 0)
{
	if (loop == false && table[y_curr][x_curr] == 0)
	{
		loop = true;
		cout << 1;
	}
	if (loop == true && table[y_curr][x_curr] == 2)
	{
		loop = false;
		rem_pos.clear();
		cout << 2;
	}
}

void Game::KostylInitCustomMap(LevelMap& table)
{
	table.fill_rect(1, 1, 4, 4, map_pixel::ENTRY);
	table.fill_rect(5, 3, 2, 1, map_pixel::LOOP);
	table.fill_rect(6, 2, 3, 1, map_pixel::LOOP);
	table.fill_rect(8, 3, 3, 1, map_pixel::LOOP);
	table.fill_rect(10, 2, 3, 1, map_pixel::LOOP);
	table.fill_rect(12, 3, 2, 1, map_pixel::LOOP);
	table.fill_rect(14, 2, 3, 3, map_pixel::ENTRY);
}

void Game::Leftkey()
{
	//table[bob_table_position.x][bob_table_position.y] = 0;
	if (table[bob_table_position.y][bob_table_position.x - 1] == 1)
	{
		Win = false;
	}
	else
	{
		Rem_Pos("Left");
		SetLoop(bob_table_position.x - 1, bob_table_position.y);
		bob_table_position.x -= 1;
	}
	//table[bob_table_position.x][bob_table_position.y] = -1;
}


void Game::Rightkey()
{

	//table[bob_table_position.x][bob_table_position.y] = 0;
	if (table[bob_table_position.y][bob_table_position.x + 1] == 1)
	{
		Win = false;
	}
	else
	{
		Rem_Pos("Right");
		SetLoop(bob_table_position.x + 1, bob_table_position.y);
		bob_table_position.x += 1;

	}
	//table[bob_table_position.x][bob_table_position.y] = -1;
}

void Game::Upkey()
{
	//table[bob_table_position.x][bob_table_position.y] = 0;
	if (table[bob_table_position.y - 1][bob_table_position.x] == 1)
	{
		Win = false;
	}
	else
	{

		Rem_Pos("Up");
		SetLoop(bob_table_position.x, bob_table_position.y - 1);
		bob_table_position.y -= 1;


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
		//bob_table_position.y += 1;
		Rem_Pos("Down");
		SetLoop(bob_table_position.x, bob_table_position.y + 1);
		bob_table_position.y += 1;



	}
	//table[bob_table_position.x][bob_table_position.y] = -1;
}

// ������ �������� ������ �� ����� �������
//m_Sprite.setPosition(m_Position);
void Game::Position()
{
	m_Position.x = def_pos.x + bob_table_position.x * square;
	m_Position.y = def_pos.y + bob_table_position.y * square;
	m_Sprite.setPosition(m_Position);
}
void Game::Rem_Pos(string x)
{
	if (table[bob_table_position.y][bob_table_position.x] == 2)
	{
		rem_pos.push_back(x);
	}
}
void Game::Loop(int l)
{
	if (rem_pos.size() == 0)
	{
		return;
	}
	if (rem_pos.size() != 0)
	{
		if (rem_pos[l] == "Up")
		{
			Upkey();
			return;
		}
		if (rem_pos[l] == "Down")
		{
			Downkey();
			return;
		}
		if (rem_pos[l] == "Right")
		{
			Rightkey();
			return;
		}
		if (rem_pos[l] == "Left")
		{
			Leftkey();
			return;
		}
	}

}
void Game::Looser()
{
	bob_table_position.x = 1;
	bob_table_position.y = 3;
	rem_pos.clear();
	Win = true;
	loop = false;


}
