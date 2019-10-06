/**
 * LoadSave
 * 
 * This sketch demonstrates loading and saving a combination.
 * 
 * Note that Arduino boards have different EEPROM sizes. E.g:
 * Duemilanove: 512  bytes (ATmega168)
 * Uno:         1024 bytes (ATmega328)
 * Mega:        4096 bytes (ATmega1280 and ATmega2560)
*/

#include <EEPROM.h>
#include "Combination.h"

const int SIZE = 5;
int userInput[SIZE] = {0}; // The combination the user has entered
int solution[SIZE]  = {0}; // Where the stored combination will be loaded

// Create a combination of length = SIZE
// By default, the combination begins at EEPROM address 0.
// A different address can be specified as the second parameter if needed.
Combination<int> savedCombination(SIZE);

void setup() {
  Serial.begin(9600);

  // Load the combination saved in the EEPROM into the 'solution' array
  savedCombination.load(solution);

  // Print out the solution that was loaded from memroy
  Serial.println("Current combination: ");
  for(int i = 0; i < SIZE; i++) {
    Serial.print(solution[i]);
    Serial.print(" ");
  }
  Serial.println();

  // Let's say the user enters the following combination
  // Change the values to any integer
  userInput[0] = 1;
  userInput[1] = 2;
  userInput[2] = 5;
  userInput[3] = 9;
  userInput[4] = 10;

  // Save userInput as the new combination
  savedCombination.save(userInput);

  Serial.println("Overwriting saved combination with: ");
  for(int i = 0; i < SIZE; i++) {
    Serial.print(userInput[i]);
    Serial.print(" ");
  }
  Serial.println();

  Serial.println("New combination saved. You can reset the device.");

  // Reset the device and the new combination will be printed
  // upon startup
}

void loop() {

}
