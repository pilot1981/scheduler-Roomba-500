/*
  Set a schedule on an iRobot Roomba 500 series, using just an Arduino.
  Mads Chr. Olesen, 2015.
*/

const byte currentDay = 3;
// 0: Sunday, 1: Monday, 2: Tuesday, 3: Wednesday, 4: Thursday, 5: Friday, 6: Saturday
const byte currentHour = 2;
const byte currentMinute = 58;

// Wanted Scheduler TODO CHANGE FIRST!!!!
const byte SUNDAY = 0x01, MONDAY = 0x02, TUESDAY = 0x04, WEDNESDAY = 0x08, THURSDAY = 0x10, FRIDAY = 0x20, SATURDAY = 0x40;

const byte daystorun = SUNDAY | MONDAY | WEDNESDAY | FRIDAY;
const byte times[14] = {
  3, 0, // Sunday time
  3, 0, // Monday time
  3, 0, // Tuesday time
  3, 0, // Wednesday time
  3, 0, // Thursday time
  3, 0, // Friday time
  3, 0, // Saturday time
};

const int ledPin = 13;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, 0);
  
  Serial.write(128); //Start
  delay(1000);
  Serial.write(131); //Safe mode, turns off Roomba light
  delay(1000);
  Serial.write(128); //Start, back to passive mode
  delay(500);
  
  //Set day time TODO CHANGE FIRST!!!!
  Serial.write(168);
  Serial.write(currentDay);
  Serial.write(currentHour);
  Serial.write(currentMinute);
  delay(500);
  
  //Set schedule
  Serial.write(167);
  Serial.write(daystorun);
  for (int i = 0; i < 14; i++) {
    Serial.write(times[i]);
  }  
}

void loop() {
  digitalWrite(ledPin, 1);
  delay(1000);
  digitalWrite(ledPin, 0);
  delay(1000);
}
