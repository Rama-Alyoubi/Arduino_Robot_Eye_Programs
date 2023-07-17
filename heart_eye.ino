const int cols[] = {2, 3, 4, 5, 6, 7}; 
const int rows[] = {8, 9, 10, 11, 12, 13}; 

byte heart[6] = {
  B010010,
  B101101,
  B100001,
  B010010,
  B001010,
  B000100
};

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(rows[i], OUTPUT);
    pinMode(cols[i], OUTPUT);
  }
}

void loop() {
  for (int col = 0; col < 6; col++) {
    digitalWrite(cols[col], HIGH);
    for (int row = 0; row < 6; row++) {
      digitalWrite(rows[row], (heart[row] & (1 << col)) ? LOW : HIGH);
    }
    delay(2);
    digitalWrite(cols[col], LOW);
  }
}



