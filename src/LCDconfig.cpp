#include <Arduino.h>

#include <SPI.h>
#include <SD.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



void iniciarSD(){

Serial.print("Iniciando SD ...");
SPI.begin(18,19,23,4);

if(! SD.begin(4)){
  Serial.println("No se pudo inicializar");
  while(1);
    }    
  Serial.println("SD OK");
  Serial.println("inicializacion exitosa");

}

void getconfig(int & ancho, int & alto, int & size, int & x, int & y){
    File config;

  config=SD.open("/config.txt");
  
  if(config){
      
      String line, lineaux;
          
      lineaux=config.readStringUntil('\n');
          line=config.readStringUntil('\n');
          ancho=line.toInt();
     
      lineaux=config.readStringUntil('\n');
          line=config.readStringUntil('\n');
          alto=line.toInt();

      lineaux=config.readStringUntil('\n');
          line=config.readStringUntil('\n');
         size=line.toInt();

      lineaux=config.readStringUntil('\n');
          line=config.readStringUntil('\n');
          x=line.toInt();

      lineaux=config.readStringUntil('\n');
          line=config.readStringUntil('\n');
          y=line.toInt();

     config.close();}      

  else {Serial.println("Archivo config.txt no encontrado");}
}

void setup(){

Serial.begin(9600);

iniciarSD();

int ancho, alto, size, x, y;
String color;

getconfig(ancho,alto,size,x,y);

// Objeto de la clase Adafruit_SSD1306
Adafruit_SSD1306 display(ancho, alto, &Wire, -1);

// Iniciar pantalla OLED en la dirección 0x3C
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
#ifdef __DEBUG__
    Serial.println("No se encuentra la pantalla OLED");
#endif
    while (true);
  }

  // Limpiar buffer
  display.clearDisplay();


  display.setTextSize(size);
  // Color del texto
  display.setTextColor(SSD1306_WHITE);
  // Posición del texto
  display.setCursor(x, y);
  display.println("Valores predeterminados establecidos.");
  // Enviar a pantalla
  display.display();
  delay(5000);
  display.clearDisplay();
 
}

void loop(){}