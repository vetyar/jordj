#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
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
public:
	
	
	
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
	int table[6][18] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 ,1,1},
		{ 1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1 ,1,1},
		{ 1,2,2,2,2,1,0,0,0,1,0,0,0,1,2,2 ,2,1},
		{ 1,2,2,2,2,0,0,1,0,0,0,1,0,0,2,2 ,2,1},
		{ 1,2,2,2,2,1,1,1,1,1,1,1,1,1,2,2 ,2,1},
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 ,1,1}
		
	};
	int tabledraw[7][18] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 ,1,1},
		{ 1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1 ,1,1},
		{ 1,2,2,2,2,1,0,0,0,1,0,0,0,1,2,2 ,2,1},
		{ 1,2,2,2,2,0,0,3,0,0,0,3,0,0,2,2 ,2,1},
		{ 1,2,2,2,2,3,3,1,3,3,3,1,3,3,2,2 ,2,1},
		{ 1,3,3,3,3,1,1,1,1,1,1,1,1,1,3,3 ,3,1},
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 ,1,1},


	};
	bool Win =true;
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
};