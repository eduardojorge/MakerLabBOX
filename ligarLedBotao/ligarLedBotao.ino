void setup()
{
  //Define a porta do led como saida
  pinMode(11, OUTPUT);
  pinMode(7, INPUT_PULLUP);
}
  
void loop()
{
  int buttonState = digitalRead(7);
  if (buttonState== LOW){
      //Acende o led
      digitalWrite(11, HIGH);
        
      //Aguarda intervalo de tempo em milissegundos
      delay(1000);
        
      //Apaga o led
      digitalWrite(11, LOW);
        
      //Aguarda intervalo de tempo em milissegundos
      delay(1000);
  }
}
