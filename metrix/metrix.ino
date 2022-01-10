#include "LedControl.h"

LedControl lc=LedControl(12,11,10,4);

byte data[8][8]=
{
  {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  },
  {
    B00001000,
    B00010100,
    B00101010,
    B00001000,
    B01111111,
    B00111110,
    B00000010,
    B00000010
  },
  {
    B00001000,
    B00010100,
    B00101010,
    B00001000,
    B01111111,
    B00111110,
    B00000010,
    B00000010
  },
  {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  },
  {
    B00111110,
    B00100000,
    B00111110,
    B00001000,
    B01111111,
    B00011100,
    B00100010,
    B00011100
  },
  {
    B00000100,
    B01100100,
    B10010100,
    B10010111,
    B10010100,
    B01100100,
    B00000100,
    B00000000
  },
  {
    B00000100,
    B01110100,
    B00010100,
    B01110100,
    B01000100,
    B01110100,
    B00000100,
    B00000000
  },
  {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  }
};

void setup() {
  for (int num=0; num<4; num++) {
    lc.shutdown(num,false);
    lc.setIntensity(num, 8);
    lc.clearDisplay(num);
  }
}

void loop() {
  byte buffer1[4+1][8];
  for (int i=0; i<4; i++) {
    for (int j=0; j<8; j++) {
      buffer1[i][j]=B00000000;
    }
  }

  for (int i=0; i<8; i++) {
    memcpy(&buffer1[4], &data[i], sizeof(data[i]));
    for (int j=0; j<8; j++) {
      for (int k=0; k<8; k++) {
        buffer1[0][k] = (buffer1[0][k]<<1) | (buffer1[1][k]>>7);
        buffer1[1][k] = (buffer1[1][k]<<1) | (buffer1[2][k]>>7);
        buffer1[2][k] = (buffer1[2][k]<<1) | (buffer1[3][k]>>7);
        buffer1[3][k] = (buffer1[3][k]<<1) | (buffer1[4][k]>>7);
        buffer1[4][k] = (buffer1[4][k]<<1);
      }
      for (int i=0; i<8; i++) {
        lc.setRow(0, i, buffer1[0][i]);
        lc.setRow(1, i, buffer1[1][i]);
        lc.setRow(2, i, buffer1[2][i]);
        lc.setRow(3, i, buffer1[3][i]);
      }
      delay(10);
    }
  }
  delay(1000);
}
