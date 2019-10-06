#ifndef COMBINATION_H
#define COMBINATION_H

#include <EEPROM.h>

class Combination {
private:
  int _startAddr, _length;
  uint8_t *_data; /*!< The current combination */

  void _read();

public:

  //! Constructor.
  /*!
   * The constructor will automatically load the data from the EEPROM.
   *
   * \param startAddr Starting address of combination in EEPROM.
   * \param length Length in bytes of the combination.
   */
  Combination(const int &startAddr, const int &length) {
    _startAddr = startAddr;
    _length = length;
    _data = new uint8_t[_length];
    _read();
  }

  //! Destructor.
  ~Combination() {
    delete[] _data;
  }

  //! Update the combination.
  /*!
   * The combination will be changed both in memory and EEPROM.
   *
   * \param newCombination The combination that will overwrite the current.
   */
  void write(char *newCombination);

  //! Check if the combination matches a given array.
  /*!
   * \param operand The array to compare to.
   * \return true if the combination matches the array given.
   */
  bool equals(char *operand);
};

#endif
