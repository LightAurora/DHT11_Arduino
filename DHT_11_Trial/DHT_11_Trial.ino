#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <DHT.h>
#include <DHT_U.h>
#define Type DHT11
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

int sensePin = 2;
float humidity;
float tempC, tempF, tempK;
int delayT(300);

//Initializing the library
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
DHT HT(sensePin, Type);

void setup() {
//Initializing the DHT11
  HT.begin();

//Initializing the OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();

}

void loop() {
//Getting the data from DHT 11
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = (tempC * (9.0/5.0)) + 32.0;
  tempK = tempC + 273.0;

//Setting the settings for the display
  delay(delayT);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

//Displaying the values received from the DHT 11
  display.setCursor(0,10);
  display.print("tempC: ");
  display.print(tempC);
  display.print("C");

  display.setCursor(0,21);
  display.print("tempF: ");
  display.print(tempF);
  display.print("F");

  display.setCursor(0,32);
  display.print("tempK: ");
  display.print(tempK);
  display.print("K");

  display.setCursor(0,43);
  display.print("humid: ");
  display.print(humidity);
  display.print("%");
  display.display();

}
