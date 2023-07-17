int SPEED_BTN = 7;
int EMERGENCY_BTN = 8;
int EMERGENCY_LED = 9; // D9 (PWM)
int PWM_PIN = 10; // D10 (PWM)
int IN1_PIN = 11; // D11
int IN2_PIN = 12; // D12
int SPEED = 0;
int EMERGENCY_STOP = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(PWM_PIN, OUTPUT);
  pinMode(EMERGENCY_LED, OUTPUT);
  pinMode(SPEED_BTN, INPUT_PULLUP);
  pinMode(EMERGENCY_BTN, INPUT_PULLUP);
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);
}

void loop()
{
  delay(1000);
  // put your main code here, to run repeatedly:
  int SPEED_BTN_VALUE = digitalRead(SPEED_BTN);
  int EMERGENCY_BTN_VALUE = digitalRead(EMERGENCY_BTN);
  if (SPEED_BTN_VALUE == LOW && EMERGENCY_STOP == 0) {
    SPEED += 1;
    if (SPEED == 1) {
      analogWrite(PWM_PIN, 64);
    } else if (SPEED == 2) {
      analogWrite(PWM_PIN, 128);
    } else if (SPEED == 3) {
      analogWrite(PWM_PIN, 192);
    } else if (SPEED == 4) {
      analogWrite(PWM_PIN, 255);
    } else if (SPEED == 5) {
      analogWrite(PWM_PIN, 0);
      SPEED = 0;
    }
  }

  if (EMERGENCY_BTN_VALUE == LOW) {
    if (EMERGENCY_STOP == 0) {
    EMERGENCY_STOP = 1;
    SPEED = 0;
    analogWrite(EMERGENCY_LED, 127);
    analogWrite(PWM_PIN, 0);
    } else if (EMERGENCY_STOP == 1) {
      EMERGENCY_STOP = 0;
      analogWrite(EMERGENCY_LED, 0);
    }
  }
}