#define AIN1  5   // Motor A Input 1  
#define AIN2  18  // Motor A Input 2  
#define PWMA  23  // Motor A PWM (Speed Control)  

#define BIN1  19  // Motor B Input 1  
#define BIN2  21  // Motor B Input 2  
#define PWMB  22  // Motor B PWM (Speed Control)  

#define STBY  4   // Standby Pin  

void setup() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  pinMode(STBY, OUTPUT);

  digitalWrite(STBY, HIGH);  // Enable the driver

  Serial.begin(115200);
  Serial.println("TB6612FNG Motor Control Test Started");
}

void loop() {
  moveForward();  // Speed: 200 out of 255
  delay(3000);

  stopMotors();
  delay(2000);

  moveBackward(200);
  delay(3000);

  stopMotors();
  delay(2000);

  /*turnLeft(200);
    delay(2000);

    turnRight(200);
    delay(2000);

  */
}

void moveForward() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 100);  // Set speed

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 90);

  Serial.println("Moving Forward");
}

void moveBackward(int speed) {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, 100);

  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, 90);

  Serial.println("Moving Backward");
}

void turnLeft(int speed) {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, 90);

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 90);

  Serial.println("Turning Left");
}

void turnRight(int speed) {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 90);

  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, 90);

  Serial.println("Turning Right");
}

void stopMotors() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 0);

  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 0);

  Serial.println("Motors Stopped");
}
