# Combination Arduino Library

Easily save and load combinations to permanent memory.

This library works with the built-in EEPROM that some Arduino AVR based borads
have. An EEPROM is a type of non-volatile memory. This means that data can be
permanently and can survive even when the power is off, just like a hard drive.

Arduino AVR boards have different EEPROM sizes. E.g.  

```
Duemilanove: 512  bytes (ATmega168)  
Uno:         1024 bytes (ATmega328)  
Mega:        4096 bytes (ATmega1280 and ATmega2560)  
```

## Installing

Option 1. Clone this repository into your libraries directory

```
git clone https://github.com/wceballos/Combination_Arduino_Library.git
```

Option 2. Download as ZIP and extract it into your libraries directory

Option 3. Read this guide

[https://www.arduino.cc/en/guide/libraries](https://www.arduino.cc/en/guide/libraries)

## Usage

### Creating combination instance

A combination is instantiated using the following form:

Combination<type> myCombination(length, eepromAddress = 0)

Parameters:  
**length**: *The number of elements in the combination.*  
**eepromAddress**: *The EEPROM memory address where the combination is stored.*

#### Example code

```cpp
// Create a combination of 10 characters at the default address
Combination<char> combo1(10);

// Create a combination of 5 integers at addresss 20
Combination<int> combo2(5, 20);

// combo1 and combo2 do not overlap in memory, so they can be used simultaneously
```

### Loading a saved combination

The load() function allows loading a combination from memory into an array.

#### Example code

```cpp
const int SIZE = 5;

// Create combination of integers
Combination<int> myCombo(SIZE);

// Load combination into a buffer
int buf[SIZE];
myCombo.load(buf);
```

### Saving a combination to memory

The save() function allows storing an array into memory.

#### Example code

```cpp
const int SIZE = 5;

// Create combination of integers
Combination<int> myCombo(SIZE);

// Load combination into a buffer
int buf[SIZE] = {5, 9, 7, 2, 3};
myCombo.save(buf);
```

### Comparing user input to the stored combination

The equals() function facilitates comparing user input to a stored combination.

#### Example code

```cpp
const int SIZE = 5;
int userInput[SIZE] = {1, 1, 2, 3, 4};

// Create combination of integers
Combination<int> myCombo(SIZE);

// Assuming the combination has been stored prior
// Compares userInput to myCombo element by element. Returns true if they match.
bool isCorrect = myCombo.equals(userInput);
```

see examples directory for example programs.

## License

This library is licensed under the GNU Lesser General Public License v3.0
See the [LICENSE.md](LICENSE.md) file.





