#pragma once

enum menuButtons
{
	STARTGAME,INFORMATION,FULLSCRREN,SOUND,EXIT,
};
enum gametexture
{
	MENU,JAZZ,LEVELVIEW,BRICK,ENEMY,PRESENT1,PRESENT2,HEART,FIRE,SPIKE,EXITTEXTURE,FINISH,LOSER,WIN,XPIC
};

enum DIRECTION {
	UP, DOWN, RIGHT, LEFT, STOP
};

enum SOUNDS
{
	MENUSOUND,ONESHOOT,MULTISHOOT,HURT,COINSSOUND,CARROTSOUND,CLAP,GAMEOVER
};
const int NUM_OF_BUTTONS = 5;
const int Window_WIDTH = 1000;
const int Window_HEIGHT = 800;
const int DISTANCE = -50;
const int DISTANCE2 = 30;
const int SIZE = 400;
const std::string FILENAME = "resources/Board.txt";
const int ADDTOX = 50;
const int MIDDLE = 330;
const int MIDDLE1 = 292;
const int MIDDLEY = 450;
const int MIDDLEY1 = 0;
const int XPOINT = 50;
const int XPOINT1 = 70;
const int YPOINT = 45;
const int YPOINT1 = 60;
const int X = 14;
const int Y = 109;
const int Y1 = 65;
const int D = 200;
const int SIZEC = 30;
const int SIZEY = 300;
const int YP = 100;
const int LEVEL1 = 1;
const int LEVEL2 = 2;
const int LEVEL3 = 3;
const int XT2 = 0;
const int YT2 = 170;
const int WT2 = 60;
const int HT2 = 85;
const int WT3 = 48;
const int HT3 = 43;
const int XV = 450;
const int YV = 15;
const int WV = 3550;
const int HV = 1000;
const int XT3 = 10;
const int YT3 = 70;
const int W1T3 = 50;
const int H1T3 = 35;


enum WEAPONFIRE
{
	WITH,WITHOUT,
}; 

enum chartoimage {
	JAZZCHAR = 'J', BRICKCHAR = '#',CARROTCHAR = 'C',COINCHAR = '$',
	TURTLECHAR = 'T', BLOCKERCHAR = 'B',AMMOCHAR = 'A',SPIKECHAR = 'S',EXITCHAR = 'E'
};

