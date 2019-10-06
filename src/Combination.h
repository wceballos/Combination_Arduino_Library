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

public:
  //! Constructor.
  /*!
   * The constructor will automatically load the data from the EEPROM.
   *
   * \param startAddr Starting address of combination in EEPROM.
   * \param length Length in bytes of the combination.
   */
  Combination(size_t length, int startAddr = 0) {
    _startAddr = startAddr;
    _length = length;
  }

  //! Destructor.
  ~Combination() {
  }

  //! Save a combination to memory.
  /*!
   * Saves the array in the argument on the EEPROM. This will overwrite
   * any previous saves.
   *
   * \param combinationArray The combination that will overwrite the current.
   */
  void save(T *combinationArray);

  //! Loads the combination from memory.
  /*!
   * The combination stored in the EEPROM is loaded into the array passed as an
   * argument. Warning: the array must be able to fit the combination.
   *
   * \param combinationArray The array to load the combination to.
   */
  void load(T *combinationArray);

  //! Check if the combination matches a given array.
  /*!
   *
   * The combination saved in the EEPROM will be compared to the combination
   * in the array passed as an argument.
   *
   * \param combinationArray The array to compare to.
   * \return true if the combination matches the array given.
   */
  bool equals(T *combinationArray);

  //! Get the value of an element at an index.
  /*! 
  * \param index Index of item.
  * \return item.
  */
  T get(int index);
};

template <class T>
void Combination<T>::save(T *combinationArray) {
  int eeAddr = _startAddr;
  int incr = sizeof(T);
  for(int i = 0; i < _length; i++) {
    EEPROM.put(eeAddr, combinationArray[i]);
    eeAddr += incr;
  }
}

template <class T>
void Combination<T>::load(T *combinationArray) {
  int eeAddr = _startAddr;
  int incr = sizeof(T);
  for(int i = 0; i < _length; i++) {
    EEPROM.get(eeAddr, combinationArray[i]);
    eeAddr += incr;
  }
}

template <class T>
bool Combination<T>::equals(T *combinationArray) {
  int eeAddr = _startAddr;
  int incr = sizeof(T);
  T data;
  for(int i = 0; i < _length; i++) {
    EEPROM.get(eeAddr, data);
    eeAddr += incr;
    if(combinationArray[i] != data) return false;
  }
  return true;
}

template <class T>
T Combination<T>::get(int index) {
  int eeAddr =  _startAddr + sizeof(T) * index;
  T data;
  EEPROM.get(eeAddr, data);
  return data;
}

#endif
