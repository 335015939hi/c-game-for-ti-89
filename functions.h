// Header File
// Created 5/19/2020; 2:36:33 PM
#include "extgraph.h"
#include "advdialogs.h"

#define largest_pickaxe 6





int inventory_add_item (unsigned char item_id) {
	extern volatile unsigned char inventory_spot;
	extern volatile unsigned char inventory_list[20];
	if (inventory_spot > 19)
		return 0;
	inventory_list[inventory_spot] = item_id;
	inventory_spot ++;
	return 1;
};



HANDLE inventory_gen(char str[9]) {
HANDLE popup1 = PopupNew(str,0);
int y = 0;
	for (;y < 20;y ++) {
		if (!inventory_list[y])
			break;
	PopupAddText(popup1,-1,item_name[inventory_list[y]],0);
	};
return popup1;
};




void add_popup_items(HANDLE popup, char items[],int len) {
	int i;
	for(i = 0 ;i < len;i ++){
		if (!items[i])
			break;
		PopupAddText(popup,-1,item_name[items[i]],0);
	};
};


HANDLE home_popup_gen() {
	HANDLE popup1 = PopupNew("Home",0);
	PopupAddText(popup1,0,"Shop",1);
	PopupAddText(popup1,-1,"Craft",2);
	PopupAddText(popup1,-1,"Storage",3);
	
	PopupAddText(popup1,1,"Buy",11);
	PopupAddText(popup1,1,"Sell",12);

	return popup1;
};





void house() {
	HANDLE popup1;
	int x = 0;
	GrayOff();
	clrscr();
	popup1 = home_popup_gen();
	
	while ((x = PopupDo(popup1,0,0,x))) {
		HeapFree(popup1);
		switch (x) {
			case 11:
				house_buy();
				break;
			case 12:
				house_sell();
				break;
			case 3:
				storage_();
				break;
			case 2:
				craft();
		};
		popup1 = home_popup_gen();
	};
	HeapFree(popup1);
};



int place_block(int x,int y,unsigned char block,int xc,int yc) {
	int z = 0;
	
	if ((x < 200) && (x >= 0) && (y < 50) && (y >= 0)) {
	
		if (!map[x][y] && ((xc != 80) || (yc != 52) || block < 11)) {//11 is grass tile, 1st non-passable block
			for (;z < 20;z ++) { 
				if (inventory_list[z] == tile_to_item[block]) {
					inventory_remove_item(z);
					map[x][y] = block;
					sprite(xc,yc,tilespritelist[block]);
					return 1;
					
				};
			};
		};
	};
	
	return 0;
};


int equip(unsigned char item) {

	if (item_to_tile[item]) {
		equip_tile = item_to_tile[item];
		return 1;
	};
	if ((item > 0) && (item <= largest_pickaxe)) {
		
		return 0;
	};
};





ADVDIALOG *storage_popup_gen() {
	int x = 0;
	ADVDIALOG *dlog = AdvDlgNew(160,100,"Storage",TRUE);
	for (;x < 20;x ++) {
		storage1_name[x] = item_name[storage1[x]];
		storage2_name[x] = item_name[storage2[x]];
		storage3_name[x] = item_name[storage3[x]];
		storage4_name[x] = item_name[storage4[x]];
		storage5_name[x] = item_name[storage5[x]];
	};

	
	AdvDlgAddTab(dlog,0,"1");
		AdvDlgAddDropDown(dlog,0,1,"Items:",storage1_name,20,&adv_selected,COLOR_BLACK);
		
	AdvDlgAddTab(dlog,1,"2");
		AdvDlgAddDropDown(dlog,1,1,"Items:",storage3_name,20,&adv_selected2,COLOR_BLACK);
		
	AdvDlgAddTab(dlog,2,"3");
		AdvDlgAddDropDown(dlog,2,1,"Items:",storage3_name,20,&adv_selected3,COLOR_BLACK);
		
	
	AdvDlgAddTab(dlog,3,"4");
		AdvDlgAddDropDown(dlog,3,1,"Items:",storage4_name,20,&adv_selected4,COLOR_BLACK);
	
	AdvDlgAddTab(dlog,4,"5");
		AdvDlgAddDropDown(dlog,4,1,"Items:",storage5_name,20,&adv_selected5,COLOR_BLACK);
	
	return dlog;
};

void storage_ (int n) {
	GrayOn();
	ADVDIALOG *dlog = storage_popup_gen();
	do {
		
	} while (AdvDlgDo(dlog,DUMMY_HANDLER));
	
	
	
	GrayOff();
};



ADVDIALOG *craft_dlog_gen() {
	ADVDIALOG *dialog = AdvDlgNew(160,100, "Craft", TRUE);
	
	
	AdvDlgAddTab(dialog, 0, "Items to craft"); 
		
	
	AdvDlgAddTab(dialog, 1, "Items add");
	
	return dialog;
};



void craft() {
	//return;
	GrayOn();
	
	ADVDIALOG *dialog =  craft_dlog_gen();
		
	do {	
		
		
	} while (AdvDlgDo(dialog,DUMMY_HANDLER));
		
	AdvDlgFree(dialog);
	GrayOff();
	/*
	
	*/
};


/*int storage_add_item(unsigned char item) {
	
	int x = 0;
	switch (num) {
		case 1:
			for (;x < 100;x ++) {
				if (!storage1[x])
					break;
			};
			if (x == 100)
				return 0;
			storage1[x] = item;
			return 1;
			break;
		case 2:
			for (;x < 100;x ++) {
				if (!storage2[x])
					break;
			};
			if (x == 100)
				return 0;
			storage2[x] = item;
			return 1;
			break;
			break;
		case 3:
			for (;x < 100;x ++) {
				if (!storage3[x])
					break;
			};
			if (x == 100)
				return 0;
			storage3[x] = item;
			return 1;
			break;
			break;
		default:
			return 0;
	};
};*/


void house_buy() {
	HANDLE popup;
	int x;
	int y;
	char str[20];
	sprintf(str,"You have:$%d",money);
	popup = PopupNew(str,0);
	const unsigned char item_buy[] = {
		1,2,3,8,9,12,14,21,22,23,24,25
	};
	for (x = 0;x < 12;x ++) {
		sprintf(str,"%s:$%d",item_name[item_buy[x]],item_values[item_buy[x]]);
		PopupAddText(popup,-1,str,0);
	};
	x = 0;
	while ((x = PopupDo(popup,0,0,x))) {
		
		HeapFree(popup);
		sprintf(str,"You have:$%d",money);
		popup = PopupNew(str,0);
		for (y = 0;y < 12;y ++) {
		sprintf(str,"%s:$%d",item_name[item_buy[y]],item_values[item_buy[y]]);
		PopupAddText(popup,-1,str,0);
		};
		
		y = item_buy[x - 1];
		if (item_values[y] > money) {
			sprintf(str,"need $%d more",item_values[y] - money);
			DlgMessage ("Not Enough Money",str,BT_NONE,BT_OK);
		}
		else
		{
			if (!inventory_add_item(y)) {
				DlgMessage (" ","Inventory full!",BT_NONE,BT_OK);
			}
			else
			{
				money = money - item_values[y];
				DlgMessage (" ","Bought!",BT_NONE,BT_OK);
			};
		};
	};
	HeapFree(popup);
};

void house_sell() {
	HANDLE popup = inventory_gen("Sell");
	int x = 0;
	int item = 1;
	char str[15];
	if (!inventory_list[0]) {
		PopupAddText(popup,-1,"Nothing here...",0);
		item = 0;
	};
	while ((x = PopupDo(popup,0,0,x))) {
		HeapFree(popup);
		if (item) {
			sprintf(str,"Sold for $%d!",item_sell_values[inventory_list[x - 1]]);
			money = money + item_sell_values[inventory_list[x - 1]];
			inventory_remove_item(x - 1);
			DlgMessage(NULL,str,BT_NONE,BT_YES);
		};
		popup = inventory_gen("Sell");
		if (!inventory_list[0]) {
			PopupAddText(popup,-1,"Nothing here...",0);
			item = 0;
		};
	};
	
	HeapFree(popup);
};


int ngetchx2() {
	int key = 0;
	void *kbq = kbd_queue ();
	OSdequeue (&key, kbq);
	while (!key) {
		key = -(_keytest(RR_2ND) + (2 * _keytest(RR_SHIFT)) + (4 * _keytest(RR_DIAMOND)) + (8 * _keytest(RR_ALPHA)));
		OSdequeue (&key, kbq);
	};
	return key;
};






int direction_prompt() {
	DrawStr(0,6,"what direction?",A_REPLACE);
	int key = ngetchx2();
	DrawStr(0,6,"what direction?",A_XOR);
	return key;
};











ADVDIALOG *inv_dlog_gen () {
	int x = 0;
	
	
	for (;x < 20;x ++) {
		inv_list_name[x] = item_name[inventory_list[x]];
		if (!inventory_list[x])
			break;
	};
	
	
	if (!x) {
	 x = 1;
	 inv_list_name[0] = "Nothing here...";
	};
	
	
	ADVDIALOG *dlog1 = AdvDlgNew (160,100,"Inventory",TRUE);
	AdvDlgAddTab(dlog1,0,"Manage");
		AdvDlgAddDropDown(dlog1,0,0,"Items:",inv_list_name,x,&adv_selected,COLOR_BLACK);
		AdvDlgAddDropDown(dlog1,0,1,"Action:",inv_action_list,3,&adv_selected2,COLOR_BLACK);

		
	AdvDlgAddTab(dlog1,1,"Equipped");
		AdvDlgAddText(dlog1,1,0,"Unequip",TXT_ALIGNRIGHT,COLOR_BLACK);
		AdvDlgAddCheckBox(dlog1,1,1,item_name[equip_pickaxe],FALSE,COLOR_BLACK);
		AdvDlgAddCheckBox(dlog1,1,2,tile_name[equip_tile],FALSE,COLOR_BLACK);
	//malloc(123);
	//sprintf(str,"%u",HeapAvail());
	//AdvDlgAddText(dlog1,1,0,str,TXT_CENTERED,COLOR_WHITE);
	
	return dlog1;

};

void inventory () {
//freemem();
	ADVDIALOG *dialog = inv_dlog_gen ();

	do {
		if (AD_CHECKED[1][0]) {//unequip pickaxe
			unequip_pickaxe();
		};
		if (AD_CHECKED[1][1]) {//unequip tile
			equip_tile = 0;
		};
		if (inventory_list[0]) {
			AdvDlgFree(dialog);
			//if (adv_selected2 == 0) {
			//	if (inventory_remove_item(adv_selected))
			//		ad_done();
			//}
			if (adv_selected2 == 2) {
				equip(inventory_list[adv_selected]);
			};
			
			if (adv_selected2 == 1) {
				if (inventory_remove_item(adv_selected))
					ad_done();
			};


		
			dialog = inv_dlog_gen ();
		};
	} while (AdvDlgDo(dialog,DUMMY_HANDLER));
	AdvDlgFree(dialog);
	//freemem();
}; 




int inventory_remove_item (int item_spot) {
	extern volatile unsigned char inventory_spot;
	if (!inventory_list[item_spot])
		return 0;
	inventory_list[item_spot] = 0;
	for (;item_spot < 20;item_spot ++) {
		if (!inventory_list[item_spot + 1])
			break;
		inventory_list[item_spot] = inventory_list[item_spot + 1];
		inventory_list[item_spot + 1] = 0;
	};
	inventory_spot --;
	return 1;
};



inline void sprite(int x,int y,unsigned short sprite[]) {
	Sprite16 (x,y,16,sprite,GrayGetPlane (DARK_PLANE),SPRT_XOR);
	Sprite16 (x,y,16,&sprite[16],GrayGetPlane (LIGHT_PLANE),SPRT_XOR);
};



void ore_vein_gen (int x,int y,int ore) {
	int z;
	int x_;
	int y_;
	int t;
	//extern volatile char (*map)[50];
	for (z = 0;z < (random(4) + 21 - ore);z ++) {
		map[x][y] = ore;
		do {
			x_ = x;
			y_ = y;
			t = random(3);
			if (t == 0)
			{
				x_ = x_ + (2 * random(2)) - 1;
				y_ = y_ + (2 * random(2)) - 1;
			}
			else
			{
				if (t == 1)
				{
					x_ = x_ + (2 * random(2)) - 1;
				}
				else
				{
					y_ = y_ + (2 * random(2)) - 1;
				};
			};
		} while (map[x_][y_] < 13);
		x = x_;
		y = y_;
	};
};




void ad_done() {
	AdvDlgMessageBox("","Done!",COLOR_BLACK,B_OK,DUMMY_HANDLER);
};

void ad_fail() {
	AdvDlgMessageBox("","Failed!",COLOR_BLACK,B_OK,DUMMY_HANDLER);
};












void unequip_pickaxe() {
	if (equip_pickaxe) {
		if (inventory_add_item(equip_pickaxe)) {
			equip_pickaxe = 0;
			ad_done();
		}
		else
			ad_fail();
	}
	else
		ad_fail();
};

//this is for debug
/*
void freemem() {
int x;
	x = HeapAvail();
	sprintf(str,"%d",x);
	DlgMessage(NULL,str,0,0);
};*/