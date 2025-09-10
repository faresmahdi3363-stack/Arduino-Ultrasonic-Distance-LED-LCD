#include <LiquidCrystal.h>

// Pins
const int trigPin = 9;
const int echoPin = 8;
const int redPin = 6;
const int greenPin = 7;
const int photoPin = A0; // Photocell

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Variables
unsigned long duration;
unsigned int distance;
int lightValue;

// For non-blocking LED
unsigned long previousLEDMillis = 0;
unsigned long blinkInterval = 500;
bool redState = LOW;

// For limiting LCD update rate
unsigned long previousLCDMillis = 0;
const unsigned long lcdUpdateInterval = 500; // update every 500ms

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(photoPin, INPUT);

  lcd.begin(16, 2);
  lcd.setCursor(3, 0);
  lcd.print("mahdi3363");
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
}

void loop() {
  unsigned long currentMillis = millis();

  // --- Measure distance ---
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000UL); // timeout
  if(duration == 0) distance = 999; // target not detected
  else distance = duration / 58;

  // --- Control LEDs ---
  if(distance < 60) {
    digitalWrite(greenPin, LOW); // turn off green
    blinkInterval = map(distance, 0, 60, 50, 500); // closer = faster blink
    if(currentMillis - previousLEDMillis >= blinkInterval){
      previousLEDMillis = currentMillis;
      redState = !redState;
      digitalWrite(redPin, redState);
    }
  } else {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
  }

  // --- Read light from photocell ---
  lightValue = analogRead(photoPin);
  String lightLevel;
  if(lightValue < 300) lightLevel = "LOW";         // low light
  else if(lightValue <= 700) lightLevel = "MEDIUM"; // medium light
  else lightLevel = "HIGH";                        // high light

  // --- Update LCD ---
  if(currentMillis - previousLCDMillis >= lcdUpdateInterval){
    previousLCDMillis = currentMillis;

    // Top row: distance + warning + fill percentage
    lcd.setCursor(0,0);
    if(distance < 60){
      lcd.print("WARN ");
      lcd.print(distance);
      lcd.print("cm ");
      int percent = map(distance, 0, 999, 100, 0); // closer = higher percentage
      lcd.print(percent);
      lcd.print("%  "); // clear extra characters
    } else {
      lcd.print("NORM ");
      lcd.print(distance);
      lcd.print("cm ");
      int percent = map(distance, 0, 999, 100, 0);
      lcd.print(percent);
      lcd.print("%  "); 
    }

    // Bottom row: light status
    lcd.setCursor(0,1);
    lcd.print("Light: ");
    lcd.print(lightLevel);
    lcd.print("   "); // clear extra characters
  }
}
