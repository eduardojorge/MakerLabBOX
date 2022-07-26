#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,16,2);

int ldr = A0;//Atribui A0 a variável ldr
int valorldr = 0;//Declara a variável valorldr como inteiro
const int buzzer =11;
const int button = 7;



void setup() {
   pinMode(ldr, INPUT);
   pinMode(buzzer, OUTPUT);
   pinMode(button, INPUT_PULLUP);
   lcd.init();
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(button);
   valorldr=analogRead(ldr);//Lê o valor do sensor ldr e armazena na variável valorldr
   Serial.print("Valor lido pelo LDR = ");//Imprime na serial a mensagem Valor lido pelo LDR
   Serial.println(valorldr);//Imprime na serial os dados de valorldr
    if (  valorldr>0){
       Serial.println("Alerta");
       tone(buzzer, 1000); // Send 1KHz sound signal...
       lcd.setBacklight(HIGH);
       lcd.setCursor(0,0);
       lcd.print("Alerta Fumaca");
       delay(1500); 
       lcd.clear();
       lcd.setBacklight(LOW);
        delay(500);
          lcd.setBacklight(HIGH); 
       lcd.setCursor(0,0);
       lcd.print("Verde[ok]");
       lcd.setCursor(0,1);
       lcd.print("Vermelho[Stop]"); 
       delay(1500);        // ...for 1 sec
       lcd.setBacklight(LOW);
          lcd.clear();
    
   }
   if (buttonState== LOW){
           // ...for 1 sec
     noTone(buzzer);     // Stop sound...
     delay(1000); 
  }
   delay(1000);
  
}
