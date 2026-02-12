/*
OLED SDA -> Arduino A4 (SDA)
OLED SCL -> Arduino A5 (SCL)
OLED VCC -> 5V or 3.3V (check module)
OLED GND -> GND
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define UP 2
#define DOWN 3
#define RIGHT 4
#define LEFT 5

int x = 8;
int y = 4;
bool up, down, left, right;
void setup() {
  // Initialise buttons
  pinMode(UP, INPUT);
  pinMode(DOWN, INPUT);
  pinMode(LEFT, INPUT);
  pinMode(RIGHT, INPUT);
  Serial.begin(9600);

  // Setup display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
     Serial.println("oled not detected");
    while(true);
   }
  display.clearDisplay();

  // Draw player
  display.fillRect(x*8, y*8, 8, 8, SSD1306_WHITE);
  display.display();
}

void loop() {
  up = digitalRead(UP);
  down = digitalRead(DOWN);
  right = digitalRead(RIGHT);
  left = digitalRead(LEFT);
  if(up){
    y++;
    while(up){
      up = digitalRead(UP);
    }
    }
  if(down){
    y--;
    while(down){
      down = digitalRead(DOWN);  
    }
  }
  if(left){
    x--;
    while(left){
      left = digitalRead(LEFT);
    }
  }
  if(right){
    x++;
    while(right){
      right = digitalRead(RIGHT);
    }
  }

  x = (x+16)%16;
  y = (y+8)%8;
  display.clearDisplay();
  display.fillRect(x*8, y*8, 8, 8, SSD1306_WHITE);
  display.display();  
}
