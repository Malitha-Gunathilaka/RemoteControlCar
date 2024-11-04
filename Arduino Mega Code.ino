#include <AFMotor.h>
#include <NewPing.h>

// Motor control constants and objects
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

// Define pins for the ultrasonic sensor
#define TRIGGER_PIN  22
#define ECHO_PIN     23
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int speed = 255;
bool objectDetected = false;

void setup() {
  stopMotors();
  Serial3.begin(9600); // Communication with ESP8266 using Serial3
  setMotorSpeed(speed);
  Serial.begin(9600); // For debugging on the Serial Monitor
  Serial.println("Remote Control Car Initialized");
}

void loop() {
  int distance = sonar.ping_cm();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 0 && distance < 5) {
    objectDetected = true;
    stopMotors();
    Serial3.println('O');
  } else {
    objectDetected = false;
  }

  if (Serial3.available() > 0) {
    String input = Serial3.readStringUntil('\n');
    Serial.print("Received command: ");
    Serial.println(input);
    
    if (input.startsWith("SPEED:")) {
      speed = input.substring(6).toInt();
      setMotorSpeed(speed);
      Serial.print("Speed set to: ");
      Serial.println(speed);
    } else {
      char command = input.charAt(0);
      switch (command) {
        case 'F':
          if (objectDetected) {
            Serial3.println('O');
          } else {
            moveForward();
          }
          break;
        case 'B':
        case 'L':
        case 'R':
          executeCommand(command);
          break;
        case 'S':
          stopMotors();
          break;
        default:
          Serial.println("Unknown command");
          break;
      }
    }
  }

  delay(200);
}

// Motor control functions
void executeCommand(char command) {
  switch (command) {
    case 'B':
      moveBackward();
      break;
    case 'L':
      turnLeft();
      break;
    case 'R':
      turnRight();
      break;
    case 'S':
      stopMotors();
      break;
  }
}

void moveForward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void moveBackward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void turnLeft() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void turnRight() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void stopMotors() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void setMotorSpeed(int speed) {
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);
}
