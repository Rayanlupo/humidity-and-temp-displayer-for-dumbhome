#include <DHTesp.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(21, 19, 4, 0, 2, 15);

const int humidityPin = 5;
int temperaturePin = 35;

const int buttonPin = 17;  
bool lastButtonState = HIGH;
bool currentButtonState = HIGH;
unsigned long lastDebounceTime = 0;    
unsigned long buttonPressTime = 0;
const unsigned long displayTime = 10000;  
bool buttonState;
bool displayOn = false; 

DHTesp dhtSensor;
void setup() {
  lcd.begin(16,2);
  dhtSensor.setup(humidityPin, DHTesp::DHT22); 
  Serial.begin(115200);
  pinMode(humidityPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
   if (dhtSensor.getStatus() != DHTesp::ERROR_NONE) {
    Serial.println("Failed to read from DHT sensor!");
  }
  if (buttonState != lastButtonState){
    lastDebounceTime = millis();
  }
  if((millis() - lastDebounceTime) > displayTime) {

    if (buttonState != currentButtonState) {
      currentButtonState = buttonState;
    
   if (currentButtonState == LOW) {
    displayOn = !displayOn;
        buttonPressTime = millis();
    Serial.print("pressed");


   }
  }
 }
 if (displayOn && (millis() - buttonPressTime < displayTime)){
  Serial.print("it work");
 }
 delay(500);
 lastButtonState = buttonState;
}

