int btnPedra = 7;
int btnPapel = 8;
int btnTesoura = 9;

void setup() {
  Serial.begin(9600);
  pinMode(btnPedra, INPUT);
  pinMode(btnPapel, INPUT);
  pinMode(btnTesoura, INPUT);
}

void loop() {
  if (digitalRead(btnPedra) == HIGH) {
    Serial.println("Pedra");
    delay(500); 
  }

  if (digitalRead(btnPapel) == HIGH) {
    Serial.println("Papel");
    delay(500);
  }

  if (digitalRead(btnTesoura) == HIGH) {
    Serial.println("Tesoura");
    delay(500);
  }
}
