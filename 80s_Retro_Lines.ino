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
  uint16_t identifier = tft.readID();
  if(identifier == 0x9325) {
  } else if(identifier == 0x9328) {
  } else if(identifier == 0x7575) {
  } else if(identifier == 0x9341) {
  } else if(identifier == 0x8357) { 
  } else { return; } 
tft.begin(identifier);
tft.fillScreen(BLACK); 
}
 
void loop() {
  randomSeed(A0); 
  for(uint8_t rotation=0; rotation<4; rotation++) { 
  tft.setRotation(rotation); 
  unsigned long t = 0; 
  int color = random(0xFFFF), color1 = random(0xFFFF), color2 = random(0xFFFF); 
  unsigned long start; 
  int           x,y,n, i, i2,r2 = random() * 2,
                cx = tft.width()  / 2 - 1,
                cy = tft.height() / 2 - 1;
  int           x1, y1, x2, y2,
                w = tft.width(),
                h = tft.height();
  tft.fillScreen(color);
  w     = min(tft.width(), tft.height());
    for(i=0; i<w; i+=6) {
    i2 = i / 2;
    tft.drawRoundRect(cx-i2, cy-i2, i, i, i/8, tft.color565(i, random(0xFFFF), 0));
  }
  for(i=min(tft.width(), tft.height()); i>20; i-=6) {
    i2 = i / 2;
    tft.fillRoundRect(cx-i2, cy-i2, i, i, i/8, tft.color565(random(0xFFFF), i, 0));
  }
   for(i=min(cx,cy); i>10; i-=5) {
    tft.fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      tft.color565(random(0xFFFF), i, i));
    t += micros() - start;
    tft.drawTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      tft.color565(i, i, random(0xFFFF)));
  }
   n     = min(cx, cy);
     for(i=0; i<n; i+=5) {
    tft.drawTriangle(
      cx    , cy - i, // peak
      cx - i, cy + i, // bottom left
      cx + i, cy + i, // bottom right
      tft.color565(random(0xFFFF), 0, i));
  }
  for(x=0; x<w; x+=r2) {
    for(y=0; y<h; y+=r2) {
      tft.drawCircle(x, y, random() * 2, color);
    }
  }
  for(x=random() * 2; x<w; x+=r2) {
    for(y=random() * 2; y<h; y+=r2) {
      tft.fillCircle(x, y, random() * 2, color);
    }
  }
  for(x=0; x<w; x+=r2) {
    for(y=0; y<h; y+=r2) {
      tft.drawCircle(x, y, random(), color);
    }
  }
  for(x=random() * 2; x<w; x+=r2) {
    for(y=random() * 2; y<h; y+=r2) {
      tft.fillCircle(x, y, random(), color);
    }
  }
   for(i=0; i<w; i+=2) {
    i2 = i / 6;
    tft.drawRoundRect(cx-i2, cy-i2, i, i, i/6, tft.color565(i, random(0xFFFF), 0));
  }
  for(i=min(tft.width(), tft.height()); i>20; i-=6) {
    i2 = i / 6;
    tft.fillRoundRect(cx-i2, cy-i2, i, i, i/6, tft.color565(random(0xFFFF), i, 0));
  }
 cx = tft.width() - random(1,40); 
 cy = tft.height() - random(1,40);
   for(i=min(cx,cy); i>20; i-=7) {
    tft.fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      tft.color565(random(0xFFFF), i, i));
    t += micros();
    tft.drawTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      tft.color565(i, i, random(0xFFFF)));
  }
   n     = min(cx, cy);
     for(i=0; i<n; i+=7) {
    tft.drawTriangle(
      cx    , cy - i, // peak
      cx - i, cy + i, // bottom left
      cx + i, cy + i, // bottom right
      tft.color565(random(0xFFFF), 0, i));
  }
   for(x=i * 2; x<w; x+=r2) {
    for(y=i * 2; y<h; y+=r2) {
      tft.fillCircle(x, y, random(), color);
    }
  }
   for(i=0; i<w; i+=9.5) {
    i2 = i / 7;
    tft.drawRoundRect(cx-i2, cy-i2, i, i, i/6, tft.color565(i, random(0xFFFF), 0));
  }
  for(i=min(tft.width(), tft.height()); i>20; i-=6) {
    i2 = i / 7;
    tft.fillRoundRect(cx-i2, cy-i2, i, i, i/6, tft.color565(random(0xFFFF), i, 0));
  } 
 cx = random(1,tft.width()); 
 cy = random(1,tft.height());
   for(i=min(cx,cy); i>20; i-=7) {
    tft.fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      tft.color565(random(0xFFFF), i, i));
    t += micros();
    tft.drawTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      tft.color565(i, i, random(0xFFFF)));
  }
   n = min(cx, cy);
     for(i=0; i<n; i+=7) {
    tft.drawTriangle(
      cx    , cy - i, cx - i, cy + i,       
      cx + i, cy + i, 
      tft.color565(random(0xFFFF), 0, i));
  }
  for(x=random() * 2; x<w; x+=r2) {
    for(y=random() * 2; y<h; y+=r2) {
      tft.fillCircle(x, y, i, color);
    }
  }
   for(i=0; i<w; i+=13) {
    i2 = i / 8;
    tft.drawRoundRect(cx-i2, cy-i2, i, i, i/8, tft.color565(i, random(0xFFFF), 0));
  }
  for(i=min(tft.width(), tft.height()); i>20; i-=6) {
    i2 = i / 8;
    tft.fillRoundRect(cx-i2, cy-i2, i, i, i/8, tft.color565(random(0xFFFF), i, 0));
  }  
 cx = random(0,tft.width()); 
 cy = random(0,tft.height());
   for(i=min(cx,cy); i>20; i-=7) {
    tft.fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      tft.color565(random(0xFFFF), i, i));
    t += micros();
    tft.drawTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      tft.color565(i, i, random(0xFFFF)));
  }
   n     = min(cx, cy);
     for(i=0; i<n; i+=7) {
    tft.drawTriangle(
      cx    , cy - i, 
      cx - i, cy + i, 
      cx + i, cy + i, 
      tft.color565(random(0xFFFF), 0, i));
  }

}  
}

