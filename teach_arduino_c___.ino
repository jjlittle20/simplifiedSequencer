
int pins[9] {12, 11, 10, 9, 8, 7, 6, 5, 4};
//modes - 0 = forward,1 = backward,2 = pulse, 3= random
int mode = 3;
int clk = A0;

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < (sizeof(pins) / sizeof(pins[0])); i++)
  {
    pinMode(pins[i], OUTPUT);
  };
  pinMode(3, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), buttonTwo, FALLING);
  attachInterrupt(digitalPinToInterrupt(2), buttonOne, FALLING);
}

void loop() {

  if (mode == 0) {
    forward();
  }
  if (mode == 1) {
    backward();
  }
  if (mode == 2) {
    pulse();
  }
  if (mode == 3) {
    rnd();
  }
}

void forward() {
  for (int i = 0; i < (sizeof(pins) / sizeof(pins[0])); i++)
  {
    digitalWrite(pins[i], HIGH);
    delay(analogRead(clk)+40);
    digitalWrite(pins[i], LOW);
  };
}

void backward() {

  for (int i = (sizeof(pins) / sizeof(pins[0])); i > -1; --i)
  {
    digitalWrite(pins[i], HIGH);
    delay(analogRead(clk)+40);
    digitalWrite(pins[i], LOW);
  };
}
void pulse() {
  for (int i = 0; i < (sizeof(pins) / sizeof(pins[0])); i++)
  {
    digitalWrite(pins[i], HIGH);
    delay(analogRead(clk)+40);
    digitalWrite(pins[i], LOW);
  };
  for (int i = (sizeof(pins) / sizeof(pins[0]) - 2); i > 0; --i)
  {
    digitalWrite(pins[i], HIGH);
    delay(analogRead(clk)+40);
    digitalWrite(pins[i], LOW);
  };
}
void rnd() {
  int rndPin = random(0, sizeof(pins) / sizeof(pins[0]) );
  digitalWrite(pins[rndPin], HIGH);
  delay(analogRead(clk)+40);
  digitalWrite(pins[rndPin], LOW);
}
void buttonOne() {

  if (mode == 1) {
    mode = 0;
  }
  else {
    mode = 1;
  }
}
void buttonTwo() {

  if (mode == 3) {
    mode = 2;
  }
  else {
    mode = 3;
  }
}
