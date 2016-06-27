//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseRoom_ESP8266 is a sample that demo using multiple sensors
// and actuactor with the FirebaseArduino library.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "arduinogarage-23f34.firebaseio.com"
#define FIREBASE_AUTH "dEmpc0OALGm5Mcpcaeis0pieY5Xv5965UUZKNm0Z"
#define WIFI_SSID "Mestska knihovna"
#define WIFI_PASSWORD ""

//const int grovePowerPin = 15;
//const int vibratorPin = 5;
//const int lightSensorPin = A0;
//const int buttonPin = 14;
//const int fanPin = 13;

const int buzzerPin = 12;
const int rotaryPin = A0;
const int barPin = 14;

void setup() {
  Serial.begin(9600);

  pinMode(buzzerPin, OUTPUT);
  pinMode(rotaryPin, INPUT);
  pinMode(barPin, OUTPUT);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  Firebase.set("buzzer", 0);
  Firebase.set("rotary", 0.0);
}

float rotary = 0.0;

void loop() {
    Serial.println(rotary);

  digitalWrite(buzzerPin, Firebase.getInt("buzzer"));  

//  Serial.println(Firebase.getInt("buzzer"));

  float rotaryValue = analogRead(rotaryPin);
  if (rotaryValue != rotary) {
    rotary = rotaryValue;
    // Firebase.setFloat("rotary", rotaryValue);
  }


//  if (rotaryValue > 200) {
//    Firebase.setInt("buzzer", 1);
//  }

//  digitalWrite(barPin, rotaryValue);

//  float newLight = analogRead(lightSensorPin);
//  if (abs(newLight - light) > 100) {
//    light = newLight;
//    Firebase.setFloat("sunlight", light);
//  }


  delay(200);
}
