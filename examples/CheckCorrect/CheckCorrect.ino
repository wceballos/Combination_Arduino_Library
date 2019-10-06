/**
 * CheckCorrect
 * 
 * This sketch demonstrates how to check if a user-entered combination is correct.
 * 
 * Note that Arduino boards have different EEPROM sizes. E.g:
 * Duemilanove: 512  bytes (ATmega168)
 * Uno:         1024 bytes (ATmega328)
 * Mega:        4096 bytes (ATmega1280 and ATmega2560)
*/

#include <EEPROM.h>
#include "Combination.h"

const int SIZE = 5;
int userInput[SIZE] = {1, 2, 5, 9, 11}; // The combination the user has entered

// Create a combination of length = SIZE
// By default, the combination begins at EEPROM address 0.
// A different address can be specified as the second parameter if needed.
Combination<int> savedCombination(SIZE);

void setup() {
  Serial.begin(9600);

  Serial.print("Current solution: ");
  for(int i = 0; i < SIZE; i++) {
    Serial.print(savedCombination.get(i));
    Serial.print(" ");
  }
  Serial.println();
  
  Serial.print("User input: ");
  for(int i = 0; i < SIZE; i++) {
    Serial.print(userInput[i]);
    Serial.print(" ");
  }
  Serial.println();

  Serial.print("Input matches solution: ");
  if(savedCombination.equals(userInput))
    Serial.print("YES");
  else
    Serial.print("NO");
}

void loop() {

}
