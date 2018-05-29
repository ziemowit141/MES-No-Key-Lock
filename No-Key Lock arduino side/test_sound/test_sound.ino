int speakerPin = 3;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
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
} // Repeat
