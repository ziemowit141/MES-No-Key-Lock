#include <LiquidCrystal.h> //Dołączenie bilbioteki
#include <Servo.h>

Servo servo_;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //Informacja o podłączeniu nowego wyświetlacza

int decision = 0;
int servoPin = 10;
int speakerPin = 13;
int passwordCounter = 0;          //Counts times user input wrong password
String password = "dawidKoks";    //String containing the password 
bool passwordFlag = false;        //Bool flag to check if user provided a correct password

void alarm(){
  // Whoop up
  for(int hz = 440; hz < 1000; hz++){
    tone(speakerPin, hz, 50);
    delay(5);
  }
  noTone(speakerPin);

  // Whoop down
  for(int hz = 1000; hz > 440; hz--){
    tone(speakerPin, hz, 50);
    delay(5);
  }
  noTone(speakerPin);   
}

void set_password(){
  Serial.print("\n Enter new password \n");
  while(!Serial.available());
  password = Serial.readString();
    Serial.print("New Passwrod Set! \n");
  Serial.print(password + '\n');
}

void check_password(){

   if (passwordCounter < 3){
      Serial.print("Enter password \n");
      while(!Serial.available());
         String temp = Serial.readString();
         Serial.print(temp + '\n');

      if (temp != password){
         Serial.print("Wrong password entered! \n");
         passwordCounter++;
         check_password();
      }
      else{
         Serial.print("Correct password entered! \n");
         passwordFlag = true;
         return;
      }
   }
   
   for(int i = 0; i < 10; i++)
    alarm();
   check_password(); 
}

void servo_move(){
  servo_.write(114);
  lcd.clear();
  lcd.write("   !UNLOCKED!");
  delay(3000);
  servo_.write(24);
  lcd.clear();
  lcd.write("    !LOCKED!");
}


void setup() {
  lcd.begin(16, 2);                       //Deklaracja typu
  lcd.setCursor(0, 0);                    //Ustawienie kursora
  lcd.print("   Welcome to");   //Wyświetlenie tekstu
  lcd.setCursor(0, 1);
  lcd.print("  No-Key Lock!");
  Serial.begin(9600);
  pinMode(servoPin, OUTPUT);
  servo_.attach(servoPin);
  servo_.write(24);
  check_password();
  lcd.clear();
}

void loop() {
  if(passwordFlag){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.write("   !LOCKED!");

      Serial.print("MENU: \n 1 - Unlock \n 2 - change password \n");
      
      while(!Serial.available());
        decision = Serial.parseInt();

      switch(decision){
        case 1 : 
          servo_move();
          break;
        case 2 :
          set_password();
          break;
        default :
          break;
      }
  }

}

