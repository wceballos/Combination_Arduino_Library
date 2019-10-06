/**
 * MultiCombo
 * 
 * How to use multiple combinations and combinations of different data types.
 * 
 * Note that Arduino boards have different EEPROM sizes. E.g:
 * Duemilanove: 512  bytes (ATmega168)
 * Uno:         1024 bytes (ATmega328)
 * Mega:        4096 bytes (ATmega1280 and ATmega2560)
*/

#include <EEPROM.h>
#include "Combination.h"

// All combinations will be the same size for simplicity
const int SIZE = 3;

// By default, the combination begins at EEPROM address 0.
// A different address can be specified as the second parameter if needed.
Combination<int> combo1(SIZE, 0);
// combo2 is stored right after combo1
Combination<int> combo2(SIZE, 3*sizeof(int));
// combo3 is of a different type and is stored right after combo2
Combination<char> combo3(SIZE, 6*sizeof(int));

void setup() {
  Serial.begin(9600);

  int  input1[SIZE] = {2, 4, 6};
  int  input2[SIZE] = {100, 200, 300};
  char input3[SIZE] = {'A', 'B', 'C'};

  // Save
  combo1.save(input1);
  combo2.save(input2);
  combo3.save(input3);

  // Show saved content
  Serial.print("Combo 1: ");
  for(int i = 0; i < SIZE; i++) {
    Serial.print(combo1.get(i));
    Serial.print(" ");
  }
  Serial.print("\nCombo 2: ");
  for(int i = 0; i < SIZE; i++) {
    Serial.print(combo2.get(i));
    Serial.print(" ");
  }
  Serial.print("\nCombo 3: ");
  for(int i = 0; i < SIZE; i++) {
    Serial.print(combo3.get(i));
    Serial.print(" ");
  }
  Serial.println();
}

void loop() {

}
