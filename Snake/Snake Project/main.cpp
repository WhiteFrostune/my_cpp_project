#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

// 定义地图大小
#define H 27
#define W 60

const int dir[4][2] = {
	{-1, 0}, // 上
	{0, 1}, // 右
	{1, 0}, // 下
	{0, -1} // 左
};

enum BlockType { // 枚举类型
	EMPTY = 0,
    FOOD = 1,
};

struct Map {
	BlockType data[H][W];
	bool hasFood;
};

struct Pos {
	int x;
	int y;
};

void drawUnit(Pos p, const char unit[]) {
	COORD coord;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = p.x + 1;
	coord.Y = p.y + 1;
	SetConsoleCursorPosition(hOutput, coord);
	cout << unit;
}


struct Snake {
	Pos snake[H * W];
	int snakeDir;
	int snakeLength;
	int lastMoveTime;
	int moveFrequency;
};

void initSnake(Snake* snk) {
	snk->snakeLength = 3;
	snk->snakeDir = 1;
	snk->snake[0] = { W / 2, H / 2 };
	snk->snake[0] = { W / 2 - 1, H / 2 };
	snk->snake[0] = { W / 2 - 2, H / 2 };
	snk->lastMoveTime = 0;
	snk->moveFrequency = 200;
}

void hideCursor() {  // 隐藏光标
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO curInfo = { 1, FALSE };
	SetConsoleCursorInfo(hOutput, &curInfo);
}

void initMap(Map* map) {
	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {
			map->data[y][x] = BlockType::EMPTY;
		}
	}
	map->hasFood = false;
}

// 绘制地图
void drawMap(Map* map) {
	system("cls"); // 清空控制台
	cout << "<";
	for (int i = 0; i < W; ++i) {
		cout << "-";
	}
	cout << ">" << endl;
	for (int y = 0; y < H; ++y) {
		cout << "|";
		for (int x = 0; x < W; ++x) {
			if(map ->data[y][x] == BlockType::EMPTY)
			cout << " ";
		}
		cout << "|" <<endl;
	}
	cout << "<";
	for (int i = 0; i < W; ++i) {
		cout << "-";
	}
	cout << ">" << endl;
}

void drawSnake(Snake* snk) {
	for (int i = 0; i < snk->snakeLength; ++i) {
		drawUnit(snk->snake[i], "■");
	}
}

bool checkOutOfBound(Pos p) {
	if (p.x <= 0 || p.x >= W + 1 || p.y <= 0 || p.y >= H + 1) {
		return true;
	}
	return false;
}

void checkEatFood(Snake* snk, Pos tail, Map* map) {
	Pos head = snk->snake[0];
	if (map->data[head.y][head.x] == BlockType::FOOD) {
		snk->snake[snk->snakeLength++] = tail;
		map->data[head.y][head.x] = BlockType::EMPTY;
		map->hasFood = false;
		drawUnit(tail, "■");
	}
}

void moveSnake(Snake* snk) {
	for (int i = snk->snakeLength - 1; i >= 1; --i) {
		snk->snake[i] = snk->snake[i - 1];
	}
	snk->snake[0].y += dir[snk->snakeDir][0];
	snk->snake[0].x += dir[snk->snakeDir][1];
}

bool doMove(Snake* snk, Map* map) {
	Pos tail = snk->snake[snk->snakeLength - 1];
	drawUnit(tail, " ");
	moveSnake(snk);
	if (checkOutOfBound(snk->snake[0])) {
		return false;
	}
	checkEatFood(snk, tail, map);
	drawUnit(snk->snake[0], "■");
	return true;
}

bool checkSnakeMove(Snake* snk, Map* map) {
	int curTime = GetTickCount();
	if (curTime - snk->lastMoveTime > snk->moveFrequency) {
		if (false == doMove(snk, map))
			return false;
		snk->lastMoveTime = curTime;
	}
	return true;
}

void checkChangeDir(Snake* snk) {
	if (_kbhit()) {
		switch (_getch()) {
		  case 'w':
			  if(snk->snakeDir != 2)
			  snk->snakeDir = 0;
			break;
		  case 'd':
			  if (snk->snakeDir != 3)
			  snk->snakeDir = 1;
			break; 
		  case 's':
			  if (snk->snakeDir != 0)
			  snk->snakeDir = 2;
			break;
		  case 'a':
			  if (snk->snakeDir != 1)
			  snk->snakeDir = 3;
			break;
		  default:
			break;
		}
	}
}

void checkFoodGenerate(Snake* snk, Map* map) {
	if (false == map->hasFood) {
		while (1) {
			int x = rand() % W;
			int y = rand() % H;
			int i = 0;
			while (i < snk->snakeLength) {
				if (x == snk->snake[i].x && y == snk->snake[i].y) {
					break;
				}
				i++;
			}
			if (i == snk->snakeLength) {
				map->data[y][x] = BlockType::FOOD;
				map->hasFood = true;
				drawUnit({ x,y }, "⚪");
				return;
			}
		}
	}

}

void initGame(Snake* snk, Map* map) {
	hideCursor();
	initMap(map);
	initSnake(snk);
	drawMap(map);
	drawSnake(snk);

}

int main() {
	Map map;
	Snake snk;
	initGame(&snk, &map);

	while (1) {
		checkChangeDir(&snk);
		if (false == checkSnakeMove(&snk, &map)) {
			break;
		}
		checkFoodGenerate(&snk, &map);
	}
	drawUnit({ W / 2 - 4, H / 2 }, "Game Over");
	while(1){}
	return 0;
}