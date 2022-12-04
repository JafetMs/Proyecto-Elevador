#include <LiquidCrystal_I2C.h> //DESCARGAR LIBRERÍA:https://github.com/ELECTROALL/Codigos-arduino/blob/master/LiquidCrystal_I2C.zip

LiquidCrystal_I2C lcd(0x27,16,2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 

int IN1 = 2;
int IN2 = 3;
int ENA = 5;

int pinLED = 13;

int pinBoton1 = 11;
int pinBoton2 = 10;
int pinBoton3 = 9;

bool boton1 = LOW;
bool boton2 = LOW;
bool boton3 = LOW;

int posicion = 1;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(pinLED,OUTPUT);

  pinMode(pinBoton1,INPUT); // defino que los pin boton son para input
  pinMode(pinBoton2,INPUT);
  pinMode(pinBoton3,INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Bienvenido"); 
  lcd.setCursor (0,1);
  lcd.print("al elevador :V");

  lcd.display();
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Presiona"); 
  lcd.setCursor (0,1);
  lcd.print("un boton :*");
  delay(1000);
  lcd.noDisplay(); //apaga lcd
}



void subir(){
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(1000);
  digitalWrite(ENA, LOW);
}
void bajar(){
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(1000);
  digitalWrite(ENA, LOW);
}

void buton1(){         // Si el botón está pulsado
    if(posicion == 1){
      //no debe hacer nada
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Imposible bajar"); 
      lcd.setCursor (0,1);
      lcd.print("al sotano :v");
      lcd.display();
      delay(500);
      lcd.noDisplay();//apaga el display cuando termina el delay
      posicion = 1;
    }
    if (posicion == 2){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Bajando a"); 
      lcd.setCursor (0,1);
      lcd.print("piso 1");
      lcd.display();
      delay(500);
      bajar();
      lcd.noDisplay();//apaga el display cuando termina el delay
      //bajar una posicion
      posicion = 1;
    }
    if(posicion == 3){
      //bajar 2 posiciones
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Bajando a"); 
      lcd.setCursor (0,1);
      lcd.print("piso 1");
      lcd.display();
      delay(500);
      bajar();
      bajar();
      lcd.noDisplay();//apaga el display cuando termina el delay
      posicion = 1;
    }//fin boton1
}

void buton2(){
    if(posicion == 1){
      posicion = 2;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Subiendo a"); 
      lcd.setCursor (0,1);
      lcd.print("piso 2");
      lcd.display();
      delay(500);
      subir();
      lcd.noDisplay();//apaga el display cuando termina el delay
      
    }
    if (posicion == 2){
      posicion = 2;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("noda risa"); 
      lcd.setCursor (0,1);
      lcd.print("payaso");
      lcd.display();
      delay(500);
      lcd.noDisplay();//apaga el display cuando termina el delay
    }
    if(posicion == 3){
      //bajar 2 posiciones
      posicion = 2;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Bajando a"); 
      lcd.setCursor (0,1);
      lcd.print("piso 2");
      lcd.display();
      delay(500);
      bajar();
      lcd.noDisplay();//apaga el display cuando termina el delay
    }//fin boton 2
}

void buton3(){

    if(posicion == 1){
      posicion = 3;
      digitalWrite(pinLED,HIGH);  // Enciende el LED
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Subiendo a"); 
      lcd.setCursor (0,1);
      lcd.print("piso 3");
      lcd.display();
      delay(500);
      subir();
      subir();
      lcd.noDisplay();//apaga el display cuando termina el delay
    }
    if (posicion == 2){
      posicion = 3;
      digitalWrite(pinLED,HIGH);  // Enciende el LED
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Subiendo a"); 
      lcd.setCursor (0,1);
      lcd.print("piso 3");
      lcd.display();
      delay(500);
      subir();
      lcd.noDisplay();//apaga el display cuando termina el delay
    }
    if(posicion == 3){
      posicion = 3;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("noda risa"); 
      lcd.setCursor (0,1);
      lcd.print("payaso");
      lcd.display();
      delay(500);
      lcd.noDisplay();//apaga el display cuando termina el delay
    }
}

void loop() {

  // Lee que boton es presionado
  boton1 = digitalRead(pinBoton1);
  boton2 = digitalRead(pinBoton2);
  boton3 = digitalRead(pinBoton3);

  //boton 1 = piso 1
  //boton 2 = piso 2
  //boton 3 = piso 3


  // Valifaciones correspondientes para saber donde nos encontramos
  if(boton1 == HIGH){
    buton1();
  }
  if(boton2 == HIGH){
    buton2();
  }
  if(boton3 == HIGH){
    buton3();
  }

  }




