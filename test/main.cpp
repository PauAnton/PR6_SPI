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
  myFile=SD.open("/archivo.txt",FILE_WRITE); // FILE_WIRTE: si no existe el archivo, lo crea. 
  // SD.remove("/archivo.txt");
  // myFile=SD.open("/archivo.txt");
  myFile.println("Me estoy comunicando con SD");
  myFile.println("Doble entrada");
  myFile.close();

  myFile=SD.open("/archivo.txt"); //Abrimos, mostramos y leemos
  if (myFile) {
    Serial.println("archivo.txt:");
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

