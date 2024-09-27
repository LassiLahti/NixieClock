#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include "nixietime.h"

// PIN DEFINES
#define TENHR 32
#define ONEHR 33
#define TENMIN 25
#define ONEMIN 26

#define APIN 27
#define BPIN 14
#define CPIN 16
#define DPIN 13

static int pins[8] = {32, 33, 25, 26, 27, 14, 16, 13};
static int logicpins[4] = {13, 16, 14, 27};
static int pinNum = 8;

int tenHour;
int oneHour;
int tenMin;
int oneMin;

// Replace with your network credentials
#define ssid "DNA-WIFI-2Ghz-F9AD"
#define PASSWORD "75693797586"


const long utcOffsetStandard = 2 * 3600; 
const long utcOffsetDST      = 3 * 3600;
WiFiUDP ntpUDP;

bool isDST() {
  time_t now = time(nullptr);
  struct tm timeinfo;
  localtime_r(&now, &timeinfo);

  int month = timeinfo.tm_mon + 1; 
  int day = timeinfo.tm_mday;
  int weekday = timeinfo.tm_wday; 
 
  bool inDST = (month > 3 && month < 10) || (month == 3 && (day - weekday >= 31 - 7)) || (month == 10 && (day - weekday < 31 - 7));

  return inDST;
}

NTPClient timeClient(ntpUDP, "time.windows.com", isDST() ? utcOffsetStandard : utcOffsetDST);

void setup() {

  // ESTABLISH CONNECTION TO A TIMESERVER AND PERFORM STARTUP TESTS
  delay(3000);
  Serial.begin(9600);
  for (int i = 0; i < pinNum; i++) {
    pinMode(pins[i], OUTPUT);
  } 
  
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(ssid, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println(" Connected!");
  timeClient.begin();
}

void loop() {
  timeClient.update();
  int timeDigit;
  // Split hours into their respctive categories
  timeDigit = timeClient.getHours();
  tenHour = timeDigit / 10;
  oneHour = timeDigit % 10;

  //Serial.println(tenHour);
  //Serial.println(oneHour);

  // Split minutes into their respctive categories
  timeDigit = timeClient.getMinutes();
  tenMin = timeDigit / 10;
  oneMin = timeDigit % 10;

  //Serial.println(tenMin);
  //Serial.println(oneMin);

  Serial.print(" DISPLAYING NUMBER = ");
  Serial.println(oneMin);
  Serial.println("TRUTH =");
  for (int i = 0; i < 4; i++) {
    Serial.print(" ");
    Serial.print(numArr[oneMin][i]);
  }
    delay(1000);
}

