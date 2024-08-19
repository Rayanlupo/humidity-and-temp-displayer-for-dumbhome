#include <DHTesp.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(21, 19, 4, 0, 2, 15);

const int humidityPin = 13;
int temperaturePin = 35;

const int buttonPin = 34;  
bool lastButtonState = HIGH;
bool currentButtonState = HIGH;
unsigned long lastDebounceTime = 0;  
const unsigned long debounceDelay = 50;  
unsigned long buttonPressTime = 0;
const unsigned long displayDuration = 10000;  
bool displayOn = false; 

DHTesp dhtSensor;
void setup() {
  lcd.begin(16,2);
  dhtSensor.setup(humidityPin, DHTesp::DHT22); 
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
}

void loop() {
  TempAndHumidity  data = dhtSensor.getTempAndHumidity();
  Serial.println(String(data.temperature, 2) + "°C");
  
}
