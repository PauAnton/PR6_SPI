#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

File myFile;

void setup(){

Serial.begin(9600);
Serial.print("Iniciando SD ...");

 SPI.begin(18,19,23,4);

if(! SD.begin(4)){
  Serial.println("No se pudo inicializar");
  while(1);
    }
    
  Serial.println("SD OK");
  
Serial.println("inicializacion exitosa");

  //Escribimos en el fichero
  myFile=SD.open("/config.txt",FILE_WRITE); // FILE_WIRTE: si no existe el archivo, lo crea. 
  // SD.remove("/archivo.txt");
  // myFile=SD.open("/archivo.txt");
  myFile.println("ANCHO");
  myFile.println("128");
  myFile.println("ALTO");
  myFile.println("64");
  myFile.println("TAMAÑO");
  myFile.println("1");
  myFile.println("X");
  myFile.println("0");
  myFile.println("Y");
  myFile.println("16");
  myFile.close();

  myFile=SD.open("/config.txt"); //Abrimos, mostramos y leemos
  if (myFile) {
    Serial.println("config.txt:");
    while (myFile.available()) {
    String line=myFile.readStringUntil('\n');
    Serial.println(line);
    }
    myFile.close(); 
  }
  
  else {
    Serial.println("Error al abrir el archivo");
  }
}

void loop(){}

