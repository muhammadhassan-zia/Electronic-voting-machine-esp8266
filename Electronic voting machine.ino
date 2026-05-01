#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ✅ LCD Setup (I2C address: 0x27)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ✅ Pin Definitions
#define BUTTON1 D1  // GPIO5
#define BUTTON2 D2  // GPIO4
#define BUTTON3 D5  // GPIO14
#define BUTTON4 D6  // GPIO12
#define RESET_BUTTON D0  // GPIO16

#define LED1 D7  // GPIO13
#define LED2 D8  // GPIO15
#define LED3 D3  // GPIO0
#define LED4 D4  // GPIO2
#define RESET_LED D0  // GPIO16 (Same as RESET_BUTTON)
#define BUZZER D7  // GPIO13 (Shared with LED1)

int votes[4] = {0, 0, 0, 0};  // Vote counters

// ✅ Function to make a beep sound
void beepBuzzer() {
  digitalWrite(BUZZER, HIGH);
  delay(100);
  digitalWrite(BUZZER, LOW);
}

// ✅ Function to display votes on LCD
void displayVotes() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("C1:");
  lcd.print(votes[0]);
  lcd.print(" C2:");
  lcd.print(votes[1]);
  lcd.setCursor(0, 1);
  lcd.print("C3:");
  lcd.print(votes[2]);
  lcd.print(" C4:");
  lcd.print(votes[3]);
}

// ✅ Setup function
void setup() {
  Serial.begin(115200);
  
  // ✅ Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Voting Machine");
  delay(2000);
  lcd.clear();

  // ✅ Set button pins as INPUT_PULLUP
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  pinMode(BUTTON4, INPUT_PULLUP);
  pinMode(RESET_BUTTON, INPUT_PULLUP);

  // ✅ Set LED and buzzer pins as OUTPUT
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(RESET_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // ✅ Ensure all LEDs and buzzer are OFF initially
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(RESET_LED, LOW);
  digitalWrite(BUZZER, LOW);
  
  displayVotes();  // Show initial vote counts
}

// ✅ Main Loop - Voting Logic
void loop() {
  // ✅ Button 1 Pressed
  if (digitalRead(BUTTON1) == LOW) {
    votes[0]++;
    digitalWrite(LED1, HIGH);
    beepBuzzer();
    delay(500);
    digitalWrite(LED1, LOW);
    displayVotes();
  }

  // ✅ Button 2 Pressed
  if (digitalRead(BUTTON2) == LOW) {
    votes[1]++;
    digitalWrite(LED2, HIGH);
    beepBuzzer();
    delay(500);
    digitalWrite(LED2, LOW);
    displayVotes();
  }

  // ✅ Button 3 Pressed
  if (digitalRead(BUTTON3) == LOW) {
    votes[2]++;
    digitalWrite(LED3, HIGH);
    beepBuzzer();
    delay(500);
    digitalWrite(LED3, LOW);
    displayVotes();
  }

  // ✅ Button 4 Pressed
  if (digitalRead(BUTTON4) == LOW) {
    votes[3]++;
    digitalWrite(LED4, HIGH);
    beepBuzzer();
    delay(500);
    digitalWrite(LED4, LOW);
    displayVotes();
  }

  // ✅ Reset Button Pressed
  if (digitalRead(RESET_BUTTON) == LOW) {
    for (int i = 0; i < 4; i++) {
      votes[i] = 0;
    }
    digitalWrite(RESET_LED, HIGH);
    beepBuzzer();
    delay(1000);
    digitalWrite(RESET_LED, LOW);
    displayVotes();
  }

  delay(100);  // Small delay for stability
}
