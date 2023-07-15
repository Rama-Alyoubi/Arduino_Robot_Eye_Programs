
const int cols[] = {2, 3, 4, 5, 6, 7}; 
const int rows[] = {8, 9, 10, 11, 12, 13}; 

byte eyeFrames[][6] = {
  { B001100, B010010, B100001, B100001, B010010, B001100 },
  { B000110, B001001, B010000, B010000, B001001, B000110 },
};

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(rows[i], OUTPUT);
    pinMode(cols[i], OUTPUT);
  }
}

void loop() {
  for (int frame = 0; frame < 2; frame++) {
    long startTime = millis();
    while (millis() - startTime < 500) {
      for (int col = 0; col < 6; col++) {
        digitalWrite(cols[col], HIGH);
        for (int row = 0; row < 6; row++) {
          digitalWrite(rows[row], (eyeFrames[frame][row] & (1 << col)) ? LOW : HIGH);
        }
        delay(2);
        digitalWrite(cols[col], LOW);
      }
    }
  }
}