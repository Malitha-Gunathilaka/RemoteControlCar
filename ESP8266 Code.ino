#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

// Replace with your network credentials
const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

void setup() {
  Serial.begin(9600);  // Initialize serial communication with Arduino MEGA (Serial3)
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected to Wi-Fi");

  // Print the ESP8266 IP address on the local network
  Serial.print("ESP8266 IP address: ");
  Serial.println(WiFi.localIP());

  // Define routes for the server
  server.on("/", handleRoot);
  server.on("/move", handleMove);
  server.on("/setSpeed", handleSetSpeed);

  server.begin();
  Serial.println("Server started.");
}

void handleRoot() {
  String html = "<html><head><title>Remote Control Car</title></head><body><h1>Remote Control Car</h1>";
  html += "<p>Use the mobile app to control the car.</p>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleMove() {
  String direction = server.arg("dir");
  Serial.print("Sending direction to Mega: ");
  Serial.println(direction); // Debugging log
  Serial.println(direction);  // Ensure newline is sent if Mega code expects it
  server.send(200, "text/plain", "Move command received");
}

void handleSetSpeed() {
  String speed = server.arg("value");
  Serial.print("SPEED:");
  Serial.println(speed);  // Send speed command to Arduino Mega
  server.send(200, "text/plain", "Speed set to: " + speed);
}

void loop() {
  server.handleClient();
}
