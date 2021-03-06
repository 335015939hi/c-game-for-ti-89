// Header File
// Created 5/16/2020; 10:17:06 AM
const unsigned short wood_block[32] = {
	0x73C0,0x0702,0xCC65,0xE20F,
    0x0FC0,0xC073,0xF180,0x1E3B,
    0xE380,0x18CC,0x3020,0x8000,
    0x2FC1,0x8158,0x3017,0x8380,
    0x0C18,0xF88D,0x339A,0x1C10,
    0xB039,0x2080,0x0E7F,0xE004,
    0x1C0F,0x0130,0xCFDF,0x7030,
    0x1002,0x7EA7,0xC0E8,0x7C07
};
const unsigned short mythril[32] = {
  0xFFBF,0xFF7F,0xFFFF,0x7EFF,
  0xEEFE,0xD2E5,0xFF5E,0xFCBF,
  0xFEDF,0xFDF7,0xF2F8,0x4E7F,
  0xFFBF,0xFFEF,0xFFF7,0xFFF5,
  0xFFBF,0xFFFF,0xFFFF,0xFEFF,
  0xFEFE,0xD2ED,0xFF5E,0xFEBF,
  0xFEDF,0xFFF7,0xF2FC,0x6EFF,
  0xFFBF,0xFFEF,0xFFFF,0xFFFF
};
const unsigned short diamond[32] = {
  0xFFFF,0xFFFB,0xFEFF,0xFEFF,
  0xF7FF,0xFFEF,0xFFFF,0xFFFF,
  0xFBFF,0xFFFF,0xFFFF,0xFFFE,
  0xFFFF,0xBFEF,0xFBFF,0xFFFF,
  0xFFFF,0xFFFB,0xFEFF,0xFEFF,
  0xF7FF,0xFFEF,0xFFFF,0xFFFF,
  0xFBFF,0xFFFF,0xFFFF,0xFFFE,
  0xFFFF,0xBFEF,0xFBFF,0xFFFF
};
const unsigned short chest[32] = {
  0x0000,0x0FF0,0x1AA8,0x2AAC,
  0x2AAC,0x6AAA,0x6AAA,0x7FFE,
  0x5556,0x55D6,0x55D6,0x55D6,
  0x5556,0x5556,0x5556,0x7FFE,
  0x0000,0x0FF0,0x1558,0x3554,
  0x3554,0x5556,0x5556,0x7FFE,
  0x6AAA,0x6BAA,0x6BAA,0x6BAA,
  0x6AAA,0x6AAA,0x6AAA,0x7FFE
};
const unsigned short ruby[32] = {
  0x7FFF,0xFFFF,0xFFFB,0xFFFF,
  0xFFFF,0xFFFF,0xFF3F,0xFFF7,
  0xFFFF,0xFFFF,0xF3FF,0xFFFF,
  0xFFFF,0xBFFF,0xFFBF,0xFFFF,
  0xFFFF,0xFFFF,0xFFF3,0xE7FF,
  0xFFFF,0xFFFF,0xFF3F,0xFFFF,
  0xFFFF,0xFFFF,0xFFFF,0xFFFF,
  0xFFFF,0xFFFF,0xFFBF,0xFFFF
};
const unsigned short gold[32] = {
  0xEFFF,0xF7FF,0xF7FF,0xF7FF,
  0xFBFF,0xFBFF,0xFCFF,0xFB0F,
  0xFBF0,0x03FF,0xFDFF,0xFDFF,
  0xFBFF,0xFBFF,0xF7FF,0xF7FF,
  0xEFFF,0xFFFF,0xFFFF,0xF7FF,
  0xFBFF,0xFBFF,0xFDFF,0xFF3F,
  0xFBF2,0x73FF,0xFDFF,0xFFFF,
  0xFFFF,0xFFFF,0xF7FF,0xFFFF
};
const unsigned short silver[32] = {
  0xFDFF,0xFE7F,0xFF9B,0x1E65,
  0xE5FE,0xF9FF,0xFE1F,0xFFDF,
  0xFFE7,0xFFDB,0xFFBD,0xFF7E,
  0x7EFF,0x89FF,0xF7FF,0xFBFF,
  0xFDFF,0xFE7F,0xFF9B,0x1E65,
  0xE5FE,0xF9FF,0xFE1F,0xFFDF,
  0xFFE7,0xFFDB,0xFFBD,0xFF7E,
  0x7EFF,0x89FF,0xF7FF,0xFBFF
};
const unsigned short iron[32] = {
  0xFFFF,0xD7E7,0xD7F7,0x7BFF,
  0xF9FF,0xFFFF,0xFE1B,0x77B9,
  0xBFFC,0x7FFB,0xFFFC,0xFFFF,
  0xE7FF,0xF7FF,0xFFFF,0xFFBF,
  0xFFDF,0xEFFF,0xBFFF,0xFFF8,
  0xFFF3,0xFCF7,0xFFE7,0x884F,
  0xDFFF,0x3FFF,0x5FFF,0xCFFF,
  0xFFFF,0xFBFF,0xF8FF,0xFF7F
};
const unsigned short coal[32] = {
  0xFFFF,0xFFFF,0xFFFF,0xFFFF,
  0xFFFF,0xFFFF,0xFFFF,0xFFFF,
  0xFFFF,0xFFFF,0xFFFF,0xFFFF,
  0xFFFF,0xFFFF,0xFFFF,0xFFFF,
  0xBEFF,0x5DFE,0xE111,0xFECF,
  0x7F7F,0x8F30,0xF0CF,0xEF00,
  0x5FFB,0xBF87,0xCC7F,0xF3FF,
  0xFC1F,0x83CF,0x7FB0,0xBF7F
};
const unsigned short stone[32] = {
  0xFFFF,0xFFFF,0xFFFF,0xFFFF,
  0xFFFF,0xFFFF,0xFFFF,0xFFFF,
  0xFFFF,0xFFFF,0xFFFF,0xFFFF,
  0xFFFF,0xFFFF,0xFFFF,0xFFFF,
  0xFFFF,0xFFFF,0xFFFF,0xFFFF,
  0xFFFF,0xFFFF,0xFFFF,0xFFFF,
  0xFFFF,0xFFFF,0xFFFF,0xFFFF,
  0xFFFF,0xFFFF,0xFFFF,0xFFFF
};
const unsigned short dirt[32] = {
  0xFF7F,0xFFFF,0xEFFE,0xEFF7,
  0xFFFF,0xFFFF,0xFFFF,0xFFFF,
  0xBFFE,0xFDFF,0xFFFF,0xFFBB,
  0xBFFB,0xF7FB,0xFFBF,0xFFFF,
  0x0080,0x0000,0x1001,0x1008,
  0x0000,0x0000,0x0000,0x0000,
  0x4001,0x0200,0x0000,0x0044,
  0x4004,0x0804,0x0040,0x0000
};
const unsigned short player[64] = {//player[0] is facing right, [32] is facing left
  0x0000,0x0000,0x0000,0x07E0,
  0x0810,0x0850,0x0810,0x0FF0,
  0x0FF0,0x1FF8,0x2FF4,0x2FF4,
  0x07E0,0x0420,0x0420,0x0420,
  0x0000,0x0000,0x0000,0x07E0,
  0x0FF0,0x0FF0,0x0FF0,0x0FF0,
  0x0810,0x1818,0x2814,0x2814,
  0x27E4,0x0420,0x0420,0x0420,
  0x0000,0x0000,0x0000,0x07E0,
  0x0810,0x0A10,0x0810,0x0FF0,
  0x0FF0,0x1FF8,0x2FF4,0x2FF4,
  0x07E0,0x0420,0x0420,0x0420,
  0x0000,0x0000,0x0000,0x07E0,
  0x0FF0,0x0FF0,0x0FF0,0x0FF0,
  0x0810,0x1818,0x2814,0x2814,
  0x27E4,0x0420,0x0420,0x0420
};
const unsigned short grass[32] = {	//grass tile sprite
  0x0000,0x0000,0xAAAA,0xFFFD,
  0xFF7F,0xFFFF,0xBFFF,0xFFFF,
  0xFDEF,0xFFFF,0xEFFF,0xFDFD,
  0xFFFF,0xDFF7,0xFFFF,0xFF7F,
  0x5555,0xAAAA,0x5555,0x0002,
  0x0080,0x0000,0x4000,0x0000,
  0x0210,0x0000,0x1000,0x0202,
  0x0000,0x2008,0x0000,0x0080
};
const unsigned short tree[64] = {//tree  sprite
  0x0000,0x0000,0x0000,0x0000,
  0x0000,0x0100,0x0100,0x14A4,
  0x0868,0x2928,0x0440,0x05D0,
  0x0320,0x0540,0x03C0,0x02C0,
  0x0000,0x03C0,0x07E0,0x0FF0,
  0x1FF8,0x3EFC,0x7EFE,0xEB5B,
  0xF797,0x56D6,0x3BBC,0x1A28,
  0x0CD0,0x02A0,0x0000,0x0100,

  0x01C0,0x01C0,0x02C0,0x0280,
  0x0380,0x02C0,0x0280,0x0280,
  0x0140,0x0340,0x07E0,0x0540,
  0x0540,0x0B50,0x1B58,0x67A2,
  0x0200,0x0200,0x0100,0x0140,
  0x0040,0x0100,0x0140,0x0140,
  0x0280,0x0080,0x0000,0x02A0,
  0x02A0,0x04A0,0x04A0,0x185C
};
const unsigned short ladder[32] = {
  0x1008,0x1FF8,0x1008,0x1008,
  0x1008,0x1FF8,0x1008,0x1008,
  0x1008,0x1FF8,0x1008,0x1008,
  0x1008,0x1FF8,0x1008,0x1008,
  0x0000,0x0000,0x0000,0x0000,
  0x0000,0x0000,0x0000,0x0000,
  0x0000,0x0000,0x0000,0x0000,
  0x0000,0x0000,0x0000,0x0000
};
const unsigned short empty[32] = {//empty
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
};
const unsigned short house_left[64] = {//house sprite left side
    0x0001,0x0007,0x000F,0x003F,
    0x007F,0x01FF,0x03FF,0x0FFF,
    0x1FFF,0x7FFF,0xFFFF,0x00FF,
    0x00FF,0x00FF,0x00FF,0x00FF,
    
    0x0001,0x0006,0x0008,0x0030,
    0x0040,0x0180,0x0200,0x0C00,
    0x1000,0x6000,0xFFFF,0x0080,
    0x0080,0x0080,0x0080,0x0080,
    
    0x00FF,0x00FF,0x00FF,0x00FF,
    0x00FF,0x00FF,0x00FF,0x00FF,
    0x00FF,0x00FF,0x18FF,0x18FF,
    0x18FF,0x18FF,0x3CFF,0x00FF,
    
    0x0080,0x0080,0x0080,0x0080,
    0x0080,0x0080,0x1880,0x3C80,
    0x7E80,0x7E80,0x2480,0x0080,
    0x0080,0x0080,0x0080,0xFFFF,
};
const unsigned short house_right[64] = {
	  0x8000,0xE000,0xF000,0xFC00,
    0xFE00,0xFF80,0xFFC0,0xFFF0,
    0xFFF8,0xFFFE,0xFFFF,0xFF00,
    0xFF00,0xFF00,0xFF00,0xFF00,
    0x8000,0x6000,0x1000,0x0C00,
    0x0200,0x0180,0x0040,0x0030,
    0x0008,0x0006,0xFFFF,0x0100,
    0x0100,0x0100,0x0100,0x0100,
    
    0xFF00,0xFF00,0xFF00,0xFF00,
    0xFF00,0xFF00,0xFF00,0xFF00,
    0xFF00,0xFF00,0xFF18,0xFF18,
    0xFF18,0xFF18,0xFF3C,0xFF00,
    0x0100,0x0100,0x0100,0x0100,
    0x0100,0x0100,0x0118,0x013C,
    0x017E,0x017E,0x0124,0x0100,
    0x0100,0x0100,0x0100,0xFFFF
};
const unsigned short house_mid[64] = {
	  0xFFFF,0xFFFF,0xFFFF,0xFFFF,
    0xFFFF,0xFFFF,0xFFFF,0xFFFF,
    0xFFFF,0xFFFF,0xFFFF,0xFFFF,
    0xFFFF,0x8001,0x8001,0x8001,
    
    0xFFFF,0x0000,0x0000,0x0000,
    0x0000,0x0000,0x0000,0x0000,
    0x0000,0x0000,0xFFFF,0x0000,
    0xFFFF,0xFFFF,0xFFFF,0xFFFF,
    
    0x8001,0x8001,0x8001,0x8001,
    0x8001,0x8001,0xB001,0xB001,
    0x8001,0x8001,0x8001,0x8001,
    0x8001,0x8001,0x8001,0xFFFF,
    
    0xFFFF,0xFFFF,0xFFFF,0xFFFF,
    0xFFFF,0xFFFF,0xFFFF,0xFFFF,
    0xFFFF,0xFFFF,0xFFFF,0xFFFF,
    0xFFFF,0xFFFF,0xFFFF,0xFFFF
};
