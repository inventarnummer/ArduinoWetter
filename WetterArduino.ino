#include "U8glib.h"
#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

U8GLIB_SSD1306_128X64 u8g(13, 11, 10, 9, 8);

float hum;
float tem;
char charHum[5];
char temp;    
char charTemp[5];  
DHT dht(DHTPIN, DHTTYPE);

void draw(void) {
                u8g.setPrintPos(2, 10); 
                u8g.print("Temperatur");
                u8g.setPrintPos(2, 25); 
                u8g.print(charTemp);
                u8g.setPrintPos(2, 40); 
                u8g.print("Luftfeuchtigkeit");
                u8g.setPrintPos(2, 55); 
                u8g.print(charHum);
}

void setup(void) {
                pinMode(13, OUTPUT);           
                digitalWrite(13, HIGH);
                // flip screen, if required
                u8g.setRot180();
                u8g.setFont(u8g_font_unifont);
                temp=0;
                dht.begin();
}

void readTemp(void){   
                tem = dht.readTemperature();
                delay(200);
                hum = dht.readHumidity();
                dtostrf(tem, 5, 1, charTemp);
                dtostrf(hum, 5, 1, charHum);
}
