#include <Adafruit_GFX.h>
#include <Adafruit_TFTLCD.h>
#define RESET A4
#define CS A3
#define CD A2
#define WR A1
#define RD A0
#define BLACK 0x0000
#define BLUE  0x001F
#define RED   0xF800
#define GREEN 0x07E0
#define CYAN  0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

Adafruit_TFTLCD tft(CS,CD,WR,RD,RESET); 

void setup(void) {
tft.reset(); 
tft.fillScreen(WHITE);
tft.setTextColor(BLUE, WHITE); 
tft.setTextSize(3); 
tft.fillScreen(WHITE); 
  uint16_t identifier = tft.readID();
  tft.begin(identifier);

  if(identifier == 0x9325) {
    tft.setCursor(0, 0); 
    tft.print("Identifier:");
    tft.println(identifier);  
  } else if(identifier == 0x9328) {
    tft.setCursor(0, 0); 
    tft.print("Identifier:");
    tft.println(identifier);  
  } else if(identifier == 0x7575) {
    tft.setCursor(0, 0); 
    tft.println("Identifier:");
    tft.println(identifier);  

  } else if(identifier == 0x9341) {
    tft.setCursor(0, 0); 
    tft.println("Identifier:");
    tft.println(identifier);  

  } else if(identifier == 0x8357) { 
    tft.setCursor(0, 0); 
    tft.println("Identifier:");
    tft.println(identifier);  

  } else { return; } 
delay(1599); 
}
 
void loop() {
  tft.fillScreen(random(0xFFFF)); 
  randomSeed(RD);
  unsigned long t = 0; 
  int color = random(0xFFFF);
  int color1 = random(0xFFFF);
  int color2 = random(0xFFFF); 
  unsigned long start; 
  int x;
  int y;
  int n; 
  int i;
  int i2 = random(0,300); 
  int r2 = random() * 2;
  
  int              cx = tft.width()  / 2 - 1;
  int              cy = tft.height() / 2 - 1;
  int           x1, y1, x2, y2,
                w = tft.width(),
                h = tft.height();
for(uint8_t rotation=0; rotation<4; rotation++) { 
 tft.setRotation(rotation);
 tft.setCursor(1,1);  
 tft.setTextSize(1); 
 cx = random(tft.width()); 
 cy = random(tft.height());
 
 for(i=min(cx,cy); i>7; i-=5) {
    tft.fillTriangle(cx, cy - random(i), cx - random(i), cy + random(i), cx + random(i), cy + random(i),
      tft.color565(random(0xFFFF), i, random(0xFFFF)));
  }

                 
for(int counter = 0; counter<=4; counter++) {
 cx = random(4,tft.width() * i2); 
 cy = random(4,tft.height() * i2);
 tft.setRotation(rotation);
for(int counter = 0; counter<=8; counter++) {
 cx = random(tft.width()); 
 cy = random(tft.height());
   tft.setRotation(rotation);
   for(i=min(cx,cy); i>8; i-=7)  {
      tft.fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      tft.color565(i, random(0xFFFF), random(0xFFFF)));
  }
    for(i=min(cx,cy); i>8; i-=7)  { 
      tft.fillTriangle(cy, cx - i, cy - i, cx + i, cy + i, cx + i,
      tft.color565(i, random(0xFFFF), random(0xFFFF)));
  }
 }

for(int counter = 0; counter<=8; counter++) {
 cx = random(tft.width()); 
 cy = random(tft.height());
   for(uint8_t rotation=0; rotation<4; rotation++) { 
  tft.setRotation(rotation);
   for(i=min(cx,cy); i>11; i-=5) {
    tft.fillTriangle(cx, cy - random(i), cx - random(i), cy + random(i), cx + random(i), cy + random(i),
      tft.color565(random(0xFFFF), i, random(0xFFFF)));
  }
  }
}

   for(uint8_t rotation=0; rotation<4; rotation++) { 
  tft.setRotation(rotation);
   for(i=min(cx,cy); i>7; i-=5) {
    tft.fillTriangle(cx, cy - random(i), cx - random(i), cy + random(i), cx + random(i), cy + random(i),
      tft.color565(random(0xFFFF), i, random(0xFFFF)));
  }
}  int rotation_1 = 4; 
   for(i=min(cy,cx); i>4; i-=7) rotation_1--; {
      tft.setRotation(rotation_1);
      tft.fillTriangle(cy, cx - i, cy - i, cx + i, cy + i, cx + i,
      tft.color565(i, random(0xFFFF), random(0xFFFF)));     
      tft.fillTriangle(cy, cx - i, cy - i, cx + i, cy + i, cx + i,
      tft.color565(i, random(0xFFFF), i));     

  }
    int rotation = 0;
    for(i=min(cx,cy); i>4; i-=7) rotation++; {
      tft.setRotation(rotation);
      tft.fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      tft.color565(i, random(0xFFFF), random(0xFFFF)));
      tft.fillTriangle(cy, cx - i, cy - i, cx + i, cy + i, cx + i,
      tft.color565(random(0xFFFF), i, random(0xFFFF)));     
  }   
}

for(int counter = 0; counter<=4; counter++) {
 rotation++; 
 cx = random(4,tft.width() * i2); 
 cy = random(4,tft.height() * i2);
 tft.setRotation(rotation);
for(int counter = 0; counter<=8; counter++) {
 cx = random(tft.width()); 
 cy = random(tft.height());
   rotation++; 
   tft.setRotation(rotation);
   for(i=min(cx,cy); i>8; i-=7)  {
      tft.fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      tft.color565(i, random(0xFFFF), random(0xFFFF)));
  }
   rotation++; 
   tft.setRotation(rotation); 
    for(i=min(cx,cy); i>8; i-=7)  { 
      tft.fillTriangle(cy, cx - i, cy - i, cx + i, cy + i, cx + i,
      tft.color565(i, random(0xFFFF), random(0xFFFF)));
  }
  // So we are going to do some comparison operators..
  if(rotation != 4){ rotation ++;}
  if(rotation > 4) { rotation = 0; }
  if(rotation <= 4) { rotation = 0; }  
   rotation++; 
   tft.setRotation(rotation);
   for(i=min(cx,cy); i>8; i-=7)  {
      tft.fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      tft.color565(i, random(0xFFFF), random(0xFFFF)));
  }
   rotation++; 
   tft.setRotation(rotation); 
    for(i=min(cx,cy); i>8; i-=7)  { 
      tft.fillTriangle(cy, cx - i, cy - i, cx + i, cy + i, cx + i,
      tft.color565(i, random(0xFFFF), random(0xFFFF)));
  }
 }
}
}
}
