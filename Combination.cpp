#include "Combination.h"

void Combination::_read() {
  for(int i = _startAddr; i < _length; ++i)
    _data[i] = EEPROM.read(i);
}

void Combination::write(char *newCombination) {
  for(int i = _startAddr; i < _length; ++i) {
    _data[i] = newCombination[i];
    EEPROM.write(i, _data[i]);
  }
}

bool Combination::equals(char *operand) {
  for(int i = 0; i < _length; ++i)
    if(operand[i] != _data[i]) return false;
  return true;
}
