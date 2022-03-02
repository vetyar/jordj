#include "Game.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
using namespace sf;
Game::Game()
{

	unload("level1.txt");
	
	bob_table_position.x = 1;
	bob_table_position.y = 9;
	m_Texture.loadFromFile("driver2.png");
	m_Sprite.setTexture(m_Texture);
	square = 64;
	def_pos.x = bob_table_position.x = 1;
	def_pos.y = bob_table_position.y = 9;
	loop = false;
	Win.N_level = false;
}

Sprite Game::getSprite()
{
	return m_Sprite;
}

// TODO:
void Game::SetLoop(int x_curr, int y_curr, int x_prev = 0, int y_prev = 0)
{
	if (loop == false && table[y_curr][x_curr] == map_pixel::LOOP)
	{
		loop = true;
		cout << 1;
	}
	if (loop == true && table[y_curr][x_curr] == map_pixel::ENTRY)
	{
		loop = false;
		rem_pos.clear();
		cout << 2;
	}
}
 bool Game::DrStone(int x_curr, int y_curr, int x_prev = 0, int y_prev = 0)
{
	if (table[y_curr][x_curr] == map_pixel::STONE)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

void Game::KostylInitCustomMap(LevelMap& table)
{
	table.fill_rect(0, 6, 1, 5, map_pixel::STONE);
	table.fill_rect(17, 6, 1, 9, map_pixel::STONE);
	table.fill_rect(1, 7, 4, 4, map_pixel::ENTRY);
	table.fill_rect(5, 9, 2, 1, map_pixel::LOOP);
	table.fill_rect(6, 8, 3, 1, map_pixel::LOOP);
	table.fill_rect(8, 9, 3, 1, map_pixel::LOOP);
	table.fill_rect(10, 8, 3, 1, map_pixel::LOOP);
	table.fill_rect(12, 9, 2, 1, map_pixel::LOOP);
	table.fill_rect(14, 8, 3, 3, map_pixel::ENTRY);
	
}

void Game::Leftkey()
{
	//table[bob_table_position.x][bob_table_position.y] = 0;
	if (table[bob_table_position.y][bob_table_position.x - 1] == map_pixel::EMPTY)
	{
		Win.win = false;
	}
	else 
	{
		Rem_Pos("Left");
		if (DrStone(bob_table_position.x - 1, bob_table_position.y) == true)
		{
			return;
		}
		
		SetLoop(bob_table_position.x - 1, bob_table_position.y);
		Pobeda(bob_table_position.x - 1, bob_table_position.y);
		bob_table_position.x -= 1;
		cout << -1;
	}
	//table[bob_table_position.x][bob_table_position.y] = -1;
}


void Game::Rightkey()
{

	//table[bob_table_position.x][bob_table_position.y] = 0;
	if (table[bob_table_position.y][bob_table_position.x + 1] == map_pixel::EMPTY)
	{
		Win.win = false;
	}
	else
	{
		Rem_Pos("Right");
		if (DrStone(bob_table_position.x + 1, bob_table_position.y) == true)
		{
			return;
		}
		SetLoop(bob_table_position.x + 1, bob_table_position.y);
		Pobeda(bob_table_position.x + 1, bob_table_position.y );
		bob_table_position.x += 1;

	}
	//table[bob_table_position.x][bob_table_position.y] = -1;
}
		
void Game::Upkey()
{
	//table[bob_table_position.x][bob_table_position.y] = 0;
	if (table[bob_table_position.y - 1][bob_table_position.x] == map_pixel::EMPTY)
	{
		Win.win = false;
	}
	else
	{

		Rem_Pos("Up");
		if (DrStone(bob_table_position.x, bob_table_position.y - 1) == true)
		{
			return;
		}
		SetLoop(bob_table_position.x, bob_table_position.y - 1);
		Pobeda(bob_table_position.x, bob_table_position.y - 1);
		bob_table_position.y -= 1;
		

	}
	//table[bob_table_position.x][bob_table_position.y] = -1;
}

void Game::Downkey()
{
	//table[bob_table_position.x][bob_table_position.y] = 0;
	if (table[bob_table_position.y + 1][bob_table_position.x] == map_pixel::EMPTY)
	{
		Win.win = false;
	}
	else
	{
		//bob_table_position.y += 1;
		Rem_Pos("Down");
		if (DrStone(bob_table_position.x, bob_table_position.y + 1) == true)
		{
			return;
		}
		SetLoop(bob_table_position.x, bob_table_position.y + 1);
		Pobeda(bob_table_position.x, bob_table_position.y + 1);
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
	if (table[bob_table_position.y][bob_table_position.x] == map_pixel::ENTRY)
	{
		rem_pos.push_back(x);
	}
}
void Game::Loop(int l)
{
	
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
	bob_table_position.x = def_pos.x;
	bob_table_position.y = def_pos.y;
	rem_pos.clear();
	Win.win = true;
	loop = false;
	l = 0;

}
void Game::Readfromfile(string array)
{
	const int row = HEIGHT_MAP;
	const int column = WIDTH_MAP;//row stroka column stolbec
	
	ifstream f(array);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			f >> table[i][j];
	//печатаем полученный заполненный массив
	
}
void Game::fastcostyl()
{
	for (int i = 0; i < HEIGHT_MAP; i++)
	{

		for (int j = 0; j < WIDTH_MAP; j++)
		{
			cout << table[i][j] << " ";
		}
		cout << endl;

	}
}
void Game::unload(string filename)
{
	ifstream f(filename);
	for (int i = 0; i < HEIGHT_MAP; i++)
	{

		for (int j = 0; j < WIDTH_MAP; j++)
		{
			f >> table[i][j];
		}

	}
	f.close();

}
void Game::load(string filename)
{
	ofstream f(filename);
	for (int i = 0; i < HEIGHT_MAP; i++)
	{

		for (int j = 0; j < WIDTH_MAP; j++)
		{
			f << table1[i][j]<< " ";
		}
		f << endl;

	}
	f.close();
}
void Game::Pobeda(int x_curr, int y_curr)
{
	if (table[y_curr][x_curr] == map_pixel::WIN)
	{
		Win.N_level = true;
	}
}

			

