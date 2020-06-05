// C Source File
// Created 5/15/2020; 3:37:30 PM

#include <tigcclib.h>
#define USE_TI89
#define drawtile(x,y,z)	sprite(x,y,tilespritelist[z]);





#define KEY__2ND -1
#define KEY__DIAMOND -4
#define KEY__SHIFT -2
#define KEY__ALPHA -8






#define _empty 0
#define _house_mid_low 1
#define _house_mid_top 2
#define _house_left_low 3
#define _house_left_top 4
#define _house_right_low 5
#define _house_right_top 6
#define _tree_top 7
#define _tree_low 8
#define _ladder 9
#define _chest 10
#define _grass 11
#define _dirt 12
#define _stone 13
#define _coal 14
#define _iron 15
#define _silver 16
#define _gold 17
#define _ruby 18
#define _diamond 19
#define _mythril 20
#define _wood_block 21

#include "sprites.h"
#include "header.h"
#include "functions.h"
#include "extgraph.h"
#include "advdialogs.h"

#define OPTIMIZE_ROM_CALLS
//RXKFJ-67HBV-84TD2-RMDK8-9BDMT
// Main Function
void _main(void)
{	
	map = calloc (200, sizeof (*map));
	
	FontSetSys(0);
	randomize ();//randomize random number generator
	
	
	//SetIntVec(AUTO_INT_7,DUMMY_HANDLER);
	
	
	LCD_BUFFER screen;//save screen
	LCD_save(screen);
	
	
	
	
	
	//generate map
	y = random(5) + 1;//random starting level for grass
	
	//generate above ground and stone
	for(x = 0;x < 200;x ++) {//loop through every x value
		
		map[x][y] = _grass;//change tile to grass
		
		t = random(4) + 1;//randomize dirt depth
		
		for (z = 1;z < t;z ++) {//set tiles to dirt
			map[x][y + z] = _dirt;
		};
		
		for (t = y + z;t < 50;t ++) {//set every other tile in column to stone
			map[x][t] = 13;
		};
		
		if (random(2) && y > 1) {//if theres space and chance make a tree
			map[x][y - 1] = _tree_low;
			map[x][y - 2] = _tree_top;
			
		};
		
		if (random(2)) {//change y value for grass randomly
			switch (y) {
				case 1: 
					y ++;break;
				case 5:
					y --;break;
				default:
					y = y + ((2 * random(2)) - 1);
			};
		};
	};
	
	
	
	
	
	
	//generate ore veins
	for(z = 0;z < (100 + random(50));z ++)
	{
		do {//randomize vein starting point
			x = random(200);
			switch (random (100)){
				case 0 ... 30:
					y = random(5) + 45;
					break;
				case 31 ... 50:
					y = random(5) + 40;
					break;
				case 51 ... 65:
					y = random(5) + 35;
					break;
				case 66 ... 75:
					y = random (5) + 30;
					break;
				case 76 ... 83:
					y = random (5) + 25;
					break;
				case 84 ... 90:
					y = random (5) + 20;
					break;
				case 91 ... 95:
					y = random (5) + 15;
					break;
				case 96 ... 98:
				 y = random (5) + 10;
				default:
					y = random(5) + 5;
			};

		} while(!(map[x][y] >= _stone));
		
		
		
		
		if (y > 40 && !random (999))
			t = _mythril;
		else
			if (y > 40 && !random (30))
				t = _diamond;
			else
				if (y > 40 && !random(23))
					t = _ruby;
				else
					if (y > 35 && !random(12))
						t = _gold;
					else
						if (y > 30 && !random(5) )
							t = _silver;
						else
							if (y > 10 && !random(3))
								t = _iron;
							else
								t = _coal;
		ore_vein_gen(x,y,t);
	};
	
	
	
	do {					//generate the house
		x = random(50) + 75;
	} while (map[x][0] < _grass && map[x][1] < _grass);
	for(y = 1;y < 40;y ++) {
		if (map[x][y + 1] > _grass)
			break;
	};
	map[x][y] = _house_mid_low;
	map[x][y - 1] = _house_mid_top;
	map[x - 1][y] = _house_left_low;
	map[x - 1][y - 1] = _house_left_top;
	map[x + 1][y] = _house_right_low;
	map[x + 1][y - 1] = _house_right_top;
	
	
	
	if (!GrayOn ())
	return;//turn on grayscale
	
	
	clrscr();//clear screen
	
	
	
	for(y_ = 0;y_ < 5;y_ ++) {//draw map
		for(x_ = 0;x_ < 10;x_ ++) {
			if ((y_ + y - 2) >= 0 && (y_ + y - 2) < 50 && (x_ + x - 5) < 200 && (x_ + x - 5) >= 0)
			drawtile(16 * x_,(16 * y_ + 20),map[x_ + x - 5][y_ + y - 2]);
		};
	};
	facing = 0;
	
	sprite(80,52, miscspritelist[facing]);
	
	 do {
	
	sprite(80,52,miscspritelist[facing]);
	
				if ((key == KEY_LEFT && x > 0) && (map[x - 1][y] < _grass)) {
					x --;//lower x value
			
					facing = 1;
					
					GraySetAMSPlane(LIGHT_PLANE);				//scroll screen right
					ScrRectShift(&(SCR_RECT){{0, 0, 159, 99}},&(SCR_RECT){{0, 0, 159, 99}},-16,A_REPLACE);
					ScrRectFill (&(SCR_RECT){{0, 0, 15, 99}},&(SCR_RECT){{0, 0, 15, 99}},A_REVERSE);
					GraySetAMSPlane(DARK_PLANE);
					ScrRectShift(&(SCR_RECT){{0, 0, 159, 99}},&(SCR_RECT){{0, 0, 159, 99}},-16,A_REPLACE);
					ScrRectFill (&(SCR_RECT){{0, 0, 15, 99}},&(SCR_RECT){{0, 0, 15, 99}},A_REVERSE);
					
					if ((x - 5) > -1) {
						for (z = 0;z < 5;z ++) {//draw new tiles
							if ((y + z - 2) < 50 && (y + z - 2) > -1)
								drawtile(0,(16 * z) + 20,map[x - 5][y + z - 2]);
						};
					};
				};

				if ((key == KEY_RIGHT && x < 199) && (map[x + 1][y] < _grass)) {
					x ++;
			
			facing = 0;
			
			GraySetAMSPlane(LIGHT_PLANE);
			ScrRectShift(&(SCR_RECT){{0, 0, 159, 99}},&(SCR_RECT){{0, 0, 159, 99}},16,A_REPLACE);
			ScrRectFill (&(SCR_RECT){{144, 0, 159, 99}},&(SCR_RECT){{144, 0, 159, 99}},A_REVERSE);
			GraySetAMSPlane(DARK_PLANE);
			ScrRectShift(&(SCR_RECT){{0, 0, 159, 99}},&(SCR_RECT){{0, 0, 159, 99}},16,A_REPLACE);
			ScrRectFill (&(SCR_RECT){{144, 0, 159, 99}},&(SCR_RECT){{144, 0, 159, 99}},A_REVERSE);
			if ((x + 4) < 200) {
				for (z = 0;z < 5;z ++) {
					if ((y + z - 2) < 50 && (y + z - 2) > -1)
					drawtile(144,(16 * z) + 20,map[x + 4][y + z - 2]);
				};
			};
				};

			
	
				if (((key == KEY_DOWN) || (!map[x][y + 1] && !map[x][y])) && y < 49 && (map[x][y + 1] < _grass)) {
					y ++;//increase y value
			
			GraySetAMSPlane(LIGHT_PLANE);				//scroll screen up
			ScrRectScroll(&(SCR_RECT){{0, 0, 159, 99}},&(SCR_RECT){{0, 0, 159, 99}},16,A_REPLACE);
			ScrRectFill (&(SCR_RECT){{0, 84, 159,99}},&(SCR_RECT){{0, 84, 159, 99}},A_REVERSE);
			ScrRectFill (&(SCR_RECT){{0, 0, 159, 19}},&(SCR_RECT){{0, 0, 159, 19}},A_REVERSE);
			GraySetAMSPlane(DARK_PLANE);
			ScrRectScroll(&(SCR_RECT){{0, 0, 159, 99}},&(SCR_RECT){{0, 0, 159, 99}},16,A_REPLACE);
			ScrRectFill (&(SCR_RECT){{0, 84, 159,99}},&(SCR_RECT){{0, 84, 159, 99}},A_REVERSE);
			ScrRectFill (&(SCR_RECT){{0, 0, 159, 19}},&(SCR_RECT){{0, 0, 159, 19}},A_REVERSE);
			if ((y + 2) < 50) {
				for (z = 0;z < 15;z ++) {//draw new tiles
					if ((x + z - 5) < 200 && (x + z - 5) > -1)
					drawtile(16 * z,84,map[x + z - 5][y + 2]);
				};
			};
				};

		
	if ((key == KEY_UP && y > 0) && (map[x][y - 1] < _grass)) {
					y --;//increase y value
			
			GraySetAMSPlane(LIGHT_PLANE);				//scroll screen down
			ScrRectScroll(&(SCR_RECT){{0, 0, 159, 99}},&(SCR_RECT){{0, 0, 159, 99}},-16,A_REPLACE);
			ScrRectFill (&(SCR_RECT){{0, 0, 159, 35}},&(SCR_RECT){{0, 0, 159, 35}},A_REVERSE);
			GraySetAMSPlane(DARK_PLANE);
			ScrRectScroll(&(SCR_RECT){{0, 0, 159, 99}},&(SCR_RECT){{0, 0, 159, 99}},-16,A_REPLACE);
			ScrRectFill (&(SCR_RECT){{0, 0, 159, 35}},&(SCR_RECT){{0, 0, 159, 35}},A_REVERSE);
			if ((y - 2) > -1) {
				for (z = 0;z < 15;z ++) {//draw new tiles
					if ((x + z - 5) < 200 && (x + z - 5) > -1) {
						drawtile(16 * z,20,map[x + z - 5][y - 2]);
					};
				};
			};
				};


		
		sprintf(str,"%d %d          ",x,y);
		DrawStr(0,0,str,A_REPLACE);
	
		sprite(80,52,miscspritelist[facing]);
		
		key = ngetchx2();
		
		//sprintf(str,"%d",key);
		// DrawStr(50,0,str,A_REPLACE);
		
		x_ = random(200);
		y_ = random(50);
		switch (map[x_][y_]) {
			case _dirt:
				if (!y_) {
					map[x_][y_] = _grass;
				}
				else
				{
				if (!map[x_][y_ + 1])
						map[x_][y_] = _grass;
						};
				break;
			case _grass:
				if (y_ > 1) {
					if (!map[x_][y_ - 1] && !map[x_][y_ - 2]) {
						map[x_][y_ - 1] = _tree_low;
						map[x_][y_ - 2] = _tree_top;
					};
				};
				break;
		};
	
		
		
		if (key == KEY__SHIFT && map[x][y] == _house_mid_low) {//house
			house();
			FontSetSys(0);
			clrscr();
			GrayOn();
			for(y_ = 0;y_ < 5;y_ ++) {//draw map
				for(x_ = 0;x_ < 10;x_ ++) {
					if ((y_ + y - 2) >= 0 && (y_ + y - 2) < 50 && (x_ + x - 5) < 200 && (x_ + x - 5) >= 0)
						drawtile(16 * x_,(16 * y_) + 20,map[x_ + x - 5][y_ + y - 2]);
				};
			};
			sprite(80,52,miscspritelist[facing]);
		};
		
		if (key == 268) {//inventory
			inventory();
			//FontSetSys(0);
		};
		
		
		
		
		if (key == KEY__DIAMOND) {//place block
			while (_keytest(RR_DIAMOND))
			;
			//DlgMessage(NULL,"asd",0,0)
			
			
			
			
			
			
			;
			key = direction_prompt();
			x_ = 0;
			y_ = 0;
			if (key == 16721)
				y_ = -1;
			if (key == 16728)
				x_ = 1;
			if (key == 16724)
				y_ = 1;
			if (key == 16722)
				x_ = -1;

		//	sprintf(str,"%d %d",x_,y_);
		//	DlgMessage(NULL,str,0,0);
			
			if (x_ || y_ || (key == KEY__DIAMOND)) 
				place_block(x + x_,y + y_,equip_tile,80 + (16 * x_),52 + (16 * y_));
			key = 0;
		};
		
		
		
		
		if (key == KEY__2ND) {//mine a block
			while (_keytest(RR_2ND))
			;
			key = direction_prompt();
			x_ = 0;
			y_ = 0;
			if (key == 4433)
				y_ = -1;
			if (key == 4440)
				x_ = 1;
			if (key == 4436)
				y_ = 1;
			if (key == 4434)
				x_ = -1;
			if (x_ || y_ || (key == RR_2ND)) {

				if ((x + x_ < 200) && (x + x_ >= 0) && (y + y_ < 50) && (y + y_ >= 0)) {
					
					if (tile_to_item[map[x + x_][y + y_]]) {

						if (!inventory_add_item(tile_to_item[map[x + x_][y + y_]])) {
							DrawStr(0,6,"inventory full!",A_REPLACE);
							ngetchx2();
							DrawStr(0,6,"inventory full!",A_XOR);
						}
						else
						{
							drawtile(80 + (16 * x_),52 + (16 * y_),map[x + x_][y + y_]);
							map[x + x_][y + y_] = 0;
						};
					};

				};
			};
		
			key = 0;
		};
		
		
		
	} while (!(key == 264));
	GrayOff();
	LCD_restore(screen);
	free (map);
}



