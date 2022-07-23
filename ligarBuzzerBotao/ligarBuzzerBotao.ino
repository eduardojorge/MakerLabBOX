
const int buzzer =11;
const int button = 7;
void setup()
{
  //Define a porta do led como saida
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}
  
void loop()
{
  int buttonState = digitalRead(7);
  if (buttonState== LOW){
     tone(buzzer, 1000); // Send 1KHz sound signal...
     delay(1000);        // ...for 1 sec
     noTone(buzzer);     // Stop sound...
     delay(1000); 
  }
}
