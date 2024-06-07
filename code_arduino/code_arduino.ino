
//oled
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <SoftwareSerial.h>
#define nombreDePixelsEnLargeur 128         // Taille de l'écran OLED, en pixel, au niveau de sa largeur
#define nombreDePixelsEnHauteur 64          // Taille de l'écran OLED, en pixel, au niveau de sa hauteur
#define brocheResetOLED         -1          // Reset de l'OLED partagé avec l'Arduino (d'où la valeur à -1, et non un numéro de pin)
#define adresseI2CecranOLED     0x3C        // Adresse de "mon" écran OLED sur le bus i2c (généralement égal à 0x3C ou 0x3D)
#define DEBUG
#define MCP_NOP 0b00000000
#define MCP_WRITE 0b00010001
#define MCP_SHTDWN 0b00100001
//#include <SoftwareSerial.h>
#define baudrate 9600
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

#define Switch 5 // Switch connection if available

const int ssMCPin = 10; // Define the slave select for the digital pot

#define WAIT_DELAY 5000

//Flex sensor
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
const int flexPin = A1;      // Pin connected to voltage divider output
const int analogInPin = A0;
const int analogOutPin = 9;
float Rflex=0;
float Resistance=0;
int VCC=5;
int R_DIV=24000;
int flatResistance=25000;
int bendResistance=100000;
float sensorValue;
float outputValue;
float valresflex;
char buffer[10];
char resflex[15];
char resgraph[15];

// Constantes
int lastStateCLK;
int lastStateDT;
int stateCLK;
int stateDT;

//bouton 


#include <SPI.h>

int res = 128;  // Valeur de résistance par défaut
const byte csPin = 10;  // Broche de sélection du MCP42100
const int maxPositions = 256;  // Nombre de positions possibles pour le curseur (de 0 à 255 = 256 positions)
const long rAB = 50000;  // Résistance entre les bornes A et B du potentiomètre 100k (92500 ohms pour ajustement au multimètre)
const byte rWiper = 125;  // Résistance du curseur du potentiomètre (125 ohms)
const byte pot0 = 0x11;  // Adresse du potentiomètre 0
const byte pot0Shutdown = 0x21;  // Adresse pour éteindre le potentiomètre 0

// Définition des broches pour l'encodeur rotatif
const int CLK = 6;  // Broche CLK de l'encodeur rotatif
const int DT = 4;   // Broche DT de l'encodeur rotatif

// Variables pour suivre l'état de l'encodeur rotatif
int oldCLKState = HIGH;  // Ancien état de la broche CLK
int counter = 128;  // Compteur de position du curseur

// Fonction pour ajuster la position du curseur du potentiomètre
void setPotWiper(int addr, int pos) {
  pos = constrain(pos, 0, 255);  // Limiter la position du curseur entre 0 et 255
  digitalWrite(csPin, LOW);  // Sélectionner le MCP42100
  SPI.transfer(addr);  // Configurer le potentiomètre cible avec la position du curseur
  SPI.transfer(pos);
  digitalWrite(csPin, HIGH);  // Désélectionner le MCP42100

  // Calcul de la résistance entre le curseur et la borne B
  long resistanceWB = ((rAB * pos) / maxPositions) + rWiper;
  Serial.print("Position du curseur : ");
  Serial.println(pos);
  Serial.print("Résistance du potentiomètre digital est égale à: ");
  Serial.print(resistanceWB);
  Serial.println(" ohms");
}


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  pinMode(csPin, OUTPUT);  // Configurer la broche de sélection comme sortie
  SPI.begin();
  digitalWrite(csPin, HIGH);  // Désélectionner par défaut le MCP42100

  // Configurer les broches de l'encodeur rotatif en entrée avec pull-up
  pinMode(CLK, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP);
  attachInterrupt(0, doEncoder, RISING);
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS))
    while (1);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
 
}
// the loop routine runs over and over again forever:
void loop() { 
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("ValRes:    ");
  display.println(res);
  display.display();
  setPotWiper(pot0,res);                    // Arrêt du programme (boucle infinie) si échec d'initialisation
  int ADCflex = analogRead(flexPin);
  float Vflex = ADCflex * VCC / 1023.0;
  float Rflex = (R_DIV * (VCC / Vflex - 1.0));
  float angle = map(Rflex, flatResistance, bendResistance, 0, 90.0);
  float angle2= map(valresflex, 64000000,2500000, 0, 90.0);

  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = sensorValue*5/1023;
  valresflex=((101*100)*5/outputValue);

  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the Serial Monitor:
  Serial.println("Résitance du capteur Graphène=" + String(abs(valresflex)) + "kohms");
  Serial.println("Resistance du Flex Sensor : " + String(Rflex/1000) + " kohms");
  Serial.println("Angle du capteur graphite:" + String(angle2) + " degrés");
  Serial.println("Angle du flexsensor:" + String(angle) + " degrés");
  Serial.println();
  
 


  delay(1000);
}
 

void doEncoder(){
  

  if (digitalRead(DT)==LOW) {
    res++;
    
    }
    else if (digitalRead(DT)==HIGH){
      res--;
    }

}





