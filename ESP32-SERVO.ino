#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

const char* ssid = "ESP32-Servo";
const char* password = "12345678";

WebServer server(80);

Servo myServo;

// المنافذ
const int servoPin = 18;
const int blueLed = 27;
const int redLed = 26;

// الصفحة الرئيسية
void handleRoot() {
  String page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>ESP32 Servo Control</title>
<style>
body{
font-family:Arial;
text-align:center;
margin-top:50px;
background:#f5f5f5;
}
button{
width:170px;
height:60px;
font-size:22px;
margin:15px;
border:none;
border-radius:10px;
cursor:pointer;
}
.open{
background:#4CAF50;
color:white;
}
.close{
background:#F44336;
color:white;
}
</style>
</head>
<body>

<h1>Servo Control</h1>

<button class="open" onclick="location.href='/open'">Open</button>
<button class="close" onclick="location.href='/close'">Close</button>

</body>
</html>
)rawliteral";

  server.send(200, "text/html", page);
}

// فتح
void handleOpen() {

  myServo.write(90);

  digitalWrite(blueLed, HIGH);
  digitalWrite(redLed, LOW);

  server.sendHeader("Location", "/");
  server.send(303);
}

// إغلاق
void handleClose() {

  myServo.write(0);

  digitalWrite(blueLed, LOW);
  digitalWrite(redLed, HIGH);

  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {

  Serial.begin(115200);

  // إعداد الليدات
  pinMode(blueLed, OUTPUT);
  pinMode(redLed, OUTPUT);

  digitalWrite(blueLed, LOW);
  digitalWrite(redLed, HIGH);

  // إعداد السيرفو
  myServo.setPeriodHertz(50);
  myServo.attach(servoPin, 500, 2400);
  myServo.write(0);

  // إنشاء شبكة WiFi
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  Serial.println("Access Point Started!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  // صفحات الويب
  server.on("/", handleRoot);
  server.on("/open", handleOpen);
  server.on("/close", handleClose);

  server.begin();

  Serial.println("Web Server Started!");
}

void loop() {
  server.handleClient();
}