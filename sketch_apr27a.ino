//MADE BY FARREL

int ledR = 2;
int ledY = 3;
int ledG = 4;
int xPin = A0;
int swPin = 7;
int x;
int posisi = 0;
bool online = false;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, INPUT_PULLUP);
}

void loop() {
  x = analogRead(xPin);

  if (digitalRead(swPin) == LOW) {
  online = !online;
  digitalWrite(ledR, HIGH);
  digitalWrite(ledY, HIGH);
  digitalWrite(ledG, HIGH);
  delay(500);
  offLed();
  }

  if (online) {
    trafficLight();
  } else if (!online) return;

  if (x > 700) {
    posisi--;
    delay(300);
    if (posisi < 0) posisi = 0;
  } else if (x < 300) {
    posisi++;
    delay(300);
    if (posisi > 2) posisi = 2;
    } 
    if (x > 400 && x < 600) {
    }
    trafficLight();
  }


void trafficLight() {
  if (posisi == 0) {
    digitalWrite(ledR, HIGH);
    digitalWrite(ledY, LOW);
    digitalWrite(ledG, LOW);

  } else if (posisi == 1) {
    digitalWrite(ledR, LOW);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledG, LOW);

  } else if (posisi == 2) {
    digitalWrite(ledR, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledG, HIGH);
  }
}

void offLed() {
  digitalWrite(ledR, LOW);
  digitalWrite(ledY, LOW);
  digitalWrite(ledG, LOW);
}