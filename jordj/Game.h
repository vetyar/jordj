#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <fstream>

using namespace std;
using namespace sf;
#define HEIGHT_MAP 19//размер карты высота
#define WIDTH_MAP 19//размер карты ширина





//map_pixel* generate_table(unsigned int w, unsigned int h, map_pixel filler)
//{
//	map_pixel* res = new map_pixel[w * h];
//	return res;
//}
//
//// если сделать так, то для обращения вместо table[a][b] мы будем писать table[a*w+b]. 
enum map_pixel
{
	LOOP = 1,
	ENTRY = 2,
	EMPTY = 0,
	STONE = 3,
	WIN = 4
};

enum move_direction
{
	UP = 0,
	DOWN = 1,
	RIGHT = 2,
	LEFT = 3
};
enum levelname
{
	level1 = 1,
	level2 = 2,
	level3 = 3
	
};
class LevelMap
{
public:

	LevelMap()
	{
		table = nullptr;
		width = 0;
		height = 0;
	}
	LevelMap(int w, int h)
	{
		generate_table(w, h, map_pixel::EMPTY);
	}
	~LevelMap()
	{
		destroy_table();
	}

	map_pixel const* const operator[] (unsigned int y)
	{
		if (y >= height)
		{
			return nullptr;
		}

		return table + (y * width);
	}


private:
	map_pixel* table;
	unsigned int width;
	unsigned int height;
	void generate_table(unsigned int w, unsigned int h, map_pixel filler)
	{
		if (table != nullptr)
		{
			destroy_table();
		}

		map_pixel* res = new map_pixel[w * h];
		width = w;
		height = h;
		for (unsigned int i = 0; i < w * h; i++)
		{
			res[i] = filler;
		}
		table = res;
	}

	void destroy_table(void)
	{
		delete[] table;
		width = height = 0;
		table = nullptr;
	}


	friend class Game;
	
	void fill_rect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, map_pixel filler)
	{
		if (x + w >= width || y + h >= height)
		{
			return;
		}
		unsigned int len = width;
		for (unsigned int i = 0; i < h; i++)
		{
			for (unsigned int j = 0; j < w; j++)
			{
				table[(y + i) * len + x + j] = filler;
			}
		}
	}
	

};



class Game
{
private:
	// Позиция Боба
	Vector2f m_Position;
	Vector2i bob_table_position;
	// Объявляем объект Sprite
	Sprite m_Sprite;
	Vector2i def_pos;
	// Добавляем текстуру
	Texture m_Texture;
	int square;
	void SetLoop(int x_prev, int y_prev, int x_curr, int y_curr);
	bool DrStone(int x_curr, int y_curr, int x_prev, int y_prev);
	void KostylInitCustomMap(LevelMap& m);


public:

	friend class LevelMap;

	Game();
	Sprite getSprite();
	void Leftkey();
	void Rightkey();
	void Upkey();
	void Downkey();
	void Position();

	void Rem_Pos(string x);

	void Loop(int l);

	void Loop();
	float time;


	void update(float elapsedTime);

	LevelMap table1 = LevelMap(WIDTH_MAP, HEIGHT_MAP);
	//LevelMap tabledraw = LevelMap(WIDTH_MAP, HEIGHT_MAP);
	
	/*int table[6][18] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 ,1,1},
		{ 1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1 ,1,1},
		{ 1,2,2,2,2,1,0,0,0,1,0,0,0,1,2,2 ,2,1},
		{ 1,2,2,2,2,0,0,1,0,0,0,1,0,0,2,2 ,2,1},
		{ 1,2,2,2,2,1,1,1,1,1,1,1,1,1,2,2 ,2,1},
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 ,1,1}

	};*/
	//int tabledraw[7][18] = {
	//	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 ,1,1},
	//	{ 1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1 ,1,1},
	//	{ 1,2,2,2,2,1,0,0,0,1,0,0,0,1,2,2 ,2,1},
	//	{ 1,2,2,2,2,0,0,3,0,0,0,3,0,0,2,2 ,2,1},
	//	{ 1,2,2,2,2,3,3,1,3,3,3,1,3,3,2,2 ,2,1},
	//	{ 1,3,3,3,3,1,1,1,1,1,1,1,1,1,3,3 ,3,1},
	//	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 ,1,1},
	//};
	
	struct Win     //Создаем структуру!
	{
		bool win;
		bool N_level;
	};
	Win Win;
	//extern vector<vector<int>> table(8, vector<int>(8, 0));
	bool m_LeftPressed;
	bool m_RightPressed;
	bool m_DownPressed;
	bool m_UpPressed;
	vector <string> rem_pos;
	int k = 0;
	bool loop = false;
	Clock clock;
	void Looser();
	void Readfromfile(string array);
	int l = 0;
	
	int table[HEIGHT_MAP][WIDTH_MAP];
	void fastcostyl();

	void unload(string filename);

	void load(string filename);

	void Pobeda(int x_curr, int y_curr);
	
};
