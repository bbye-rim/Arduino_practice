char a=0x0F;
int k,z,m,s;
char b[10][8]={
  {, 
}

unsigned long per;

void setup() {
  for (int i=2; i<32; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  unsigned long cur=micros();
  if (cur-per >1000) {
    per=cur;
    for (int j=0; j<8; j++) {
      digitalWrite(j+2, 1);
      for (int i=0; i<8; i++) {
        if(b[m][j]&(0x80>>i)) digitalWrite(i+10,0);
        else digitalWrite(i+10,1);
      }
      for (int i=0; i<8; i++) {
        digitalWrite(i+10, 1);
      }
      digitalWrite(j+2,0);
    }
    z++;
    if (z%100==0) {
      for (int i=0; i<8; i++) {
        b[m][i]>>=1;
      }
      k++;
      if (k==8) {
        m++;
        if (m==10) {
          m=0;
          for (int i=0; i<10; i++)
            for (int j=0; j<8; j++)
              b[i][j]=b2[i][j];
        }
        k=0;
      }
    }
  }
}
