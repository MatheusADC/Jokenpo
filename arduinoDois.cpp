#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

int btnPedra = 7;
int btnPapel = 8;
int btnTesoura = 9;
String escolha1 = "";
String escolha2 = "";

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setBacklight(1);

  pinMode(btnPedra, INPUT);
  pinMode(btnPapel, INPUT);
  pinMode(btnTesoura, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("Aguardando...");
}

void loop() {
  if (Serial.available() > 0) {
    escolha1 = Serial.readStringUntil('\n');
    escolha1.trim();
  }

  if (digitalRead(btnPedra) == HIGH) {
    escolha2 = "Pedra";
    delay(300); 
  } else if (digitalRead(btnPapel) == HIGH) {
    escolha2 = "Papel";
    delay(300);
  } else if (digitalRead(btnTesoura) == HIGH) {
    escolha2 = "Tesoura";
    delay(300);
  }

  if (escolha1 != "" && escolha2 != "") {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("J1: " + escolha1);
    lcd.setCursor(0, 1);
    lcd.print("J2: " + escolha2);

    delay(2000); 

    String resultado = verificaVencedor(escolha1, escolha2);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Resultado:");
    lcd.setCursor(0, 1);
    lcd.print(resultado);

    delay(3000);

    escolha1 = "";
    escolha2 = "";
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Aguardando...");
  }
}

String verificaVencedor(String p1, String p2) {
  if (p1 == p2) return "Empate!";
  if ((p1 == "Pedra" && p2 == "Tesoura") ||
      (p1 == "Papel" && p2 == "Pedra") ||
      (p1 == "Tesoura" && p2 == "Papel")) {
    return "Jog1 venceu!";
  } else {
    return "Jog2 venceu!";
  }
}
