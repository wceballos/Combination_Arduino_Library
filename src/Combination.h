//! Combination.h
/*!
 * The Combination class reads and writes a combination to and from EEPROM.
 * A combination must be an array type.
 *
 * \version Verison 3.0.
 */
#ifndef COMBINATION_H
#define COMBINATION_H

#include <EEPROM.h>

template <class T>
class Combination {
private:
  int _startAddr, _length;
  void _read();

public:
  //T *data; /*!< The current combination */

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
  }

  //! Destructor.
  ~Combination() {
  }

  //! Update the combination.
  /*!
   * Copies array passed as a parameter to member data array and then
   * writes it to EEPROM.
   *
   * \param newCombination The combination that will overwrite the current.
   */
  void write(T *newCombination);

  //! Check if the combination matches a given array.
  /*!
   * \param operand The array to compare to.
   * \return true if the combination matches the array given.
   */
  bool equals(T *operand);

 //! Get the value of an item at an index.
 /*! 
 * \param index Index of item.
 * \return item.
 */
  T get(int index);
};

template <class T>
void Combination<T>::write(T *newCombination) {
  int eeAddr = _startAddr;
  int incr = sizeof(T);
  for(int i = 0; i < _length; ++i) {
    EEPROM.put(eeAddr, newCombination[i]);
    eeAddr += incr;
  }
}

/*!
 * \param operand An array to compare to data.
 * \return true if all array elements equal of operand equal the elements of
 *  member variable "data".
 */
template <class T>
bool Combination<T>::equals(T *operand) {
  int eeAddr = _startAddr;
  int incr = sizeof(T);
  T data;
  for(int i = 0; i < _length; ++i) {
    EEPROM.get(eeAddr, data);
    eeAddr += incr;
    if(operand[i] != data) return false;
  }
  return true;
}

 //! Get the value of an item at an index.
 /*! 
 * \param index Index of item.
 * \return item.
 */
template <class T>
T Combination<T>::get(int index) {
  int eeAddr =  _startAddr + sizeof(T) * index;
  T data;
  EEPROM.get(eeAddr, data);
  return data;
}

#endif
