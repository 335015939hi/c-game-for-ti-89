int x = 0;
int y = 0;
int z = 0;
int t = 0;
int x_ = 0;
int y_ = 0;
int key = 0;
int facing = 0;
volatile unsigned int money = 0;
volatile char str[15] = {};
volatile char storage1[20] = {};
volatile char storage2[20] = {};
volatile char storage3[20] = {};
volatile char storage4[20] = {};
volatile char storage5[20] = {};
static *storage1_name[20] = {};
static *storage2_name[20] = {};
static *storage3_name[20] = {};
static *storage4_name[20] = {};
static *storage5_name[20] = {};
//volatile char map[200][50] = {};
volatile unsigned char (*map)[50] = NULL;
volatile unsigned char inventory_list[20] = {};
volatile unsigned char inventory_spot = 0;
volatile int /***/ adv_selected = 0;
volatile int /***/ adv_selected2 = 0;
volatile int /***/ adv_selected3 = 0;
volatile int /***/ adv_selected4 = 0;
volatile int /***/ adv_selected5 = 0;
static char *inv_list_name[20] = {};
static const char *inv_action_list[5] = {"None","Throw","Equip"};
static const char item_name[][15] = {
	"Nothing here",
	"wood pickaxe",
	"iron pickaxe",
	"silver pickaxe",
	"mythril pickaxe",
	"drill",
	" ",
	" ",
	"wood",
	"ladder",
	"chest",
	" ",
	"dirt",
	"stone",
	"coal",
	"iron ore",
	"silver ore",
	"gold ore",
	"ruby ore",
	"diamond ore",
	"mythril ore",
	"iron",
	"silver",
	"gold",
	"ruby",
	"diamond",
	"mythril"
};
static const char tile_name[][13] = {
	"empty",          //0
	"HouseMidLow",    //1
	"HouseMidTop",    //2
	"HouseLeftLow",   //3
	"HouseLeftTop",   //4
	"HouseRightLow",  //5
	"HouseRightTop",  //6
	"tree_top",       //7
	"tree_low",       //8
	"ladder",         //9
	"chest",          //10
	"grass",          //11
	"dirt",           //12
	"stone",          //13
	"coal",           //14
	"iron",           //15
	"silver",         //16
	"gold",           //17
	"ruby",           //18
	"diamond",        //19
	"mythril",        //20
	"wood block"      //21
};
volatile unsigned char storage[100] = {1,2,3};
static const unsigned char tile_to_item[] = {
	0, //0
	0, //1
	0, //2
	0, //3
	0, //4
	0, //5
	0, //6
	8, //7
	8, //8
	9, //9
	10,//10
	12,//11
	12,//12
	13,//13
	14,//14
	15,//15
	16,//16
	17,//17
	18,//18
	19,//19
	20,//20
	8  //21
};
static const unsigned char item_to_tile[] = {
	0, //0
	0, //1
	0, //2
	0, //3
	0, //4
	0, //5
	0, //6
	0, //7
	21,//8
	9, //9
	10,//10
	0, //11
	12,//12
	13,//13
	14,//14
	15,//15
	16,//16
	17,//17
	18,//18
	19,//19
	20,//20
	0, //21
	0, //22
	0, //23
	0, //24
	0, //25
	0  //26
};
static const unsigned short item_values[] = {
	0,5,20,75,200,600,0,0,1,3,
	10,0,1,1,3,7,10,20,27,70,
	120,14,20,50,70,200,400
};
static const unsigned short item_sell_values[] = {
	0,3,13,50,133,400,0,0,0,2,
	7,0,0,0,2,5,7,13,18,47,
	80,9,13,33,47,133,267
};
volatile unsigned char equip_tile = 0;
volatile unsigned char equip_pickaxe = 0;
const unsigned short int * tilespritelist[] = {//list of tile sprites
	empty,&house_mid[32],house_mid,&house_left[32],house_left,&house_right[32],house_right,tree,&tree[32],ladder,
	chest,grass,dirt,stone,coal,iron,silver,gold,ruby,diamond,
	mythril,wood_block
};
const unsigned short * miscspritelist[] = {
	player,&player[32]
};