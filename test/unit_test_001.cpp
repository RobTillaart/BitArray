//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2020-12-03
// PURPOSE: unit tests for the XXXXXX
//          https://github.com/RobTillaart/
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)

#include <ArduinoUnitTests.h>

#include "BitArray.h"


unittest_setup()
{
}

unittest_teardown()
{
  fprintf(stderr, "\n");
}

unittest(test_constructor)
{
  BitArray ba;

  fprintf(stderr, "VERSION:\t %s\n", BITARRAY_LIB_VERSION);

  ba.begin(0, 1000);
  assertEqual(BA_ELEMENT_SIZE_ERR, ba.getError());
  ba.begin(33, 1000);
  assertEqual(BA_ELEMENT_SIZE_ERR, ba.getError());
  ba.begin(1, 1000);
  assertEqual(BA_OK, ba.getError());

  assertEqual(1, ba.bits());
  assertEqual(1000, ba.capacity());
  assertEqual(125, ba.memory());
  fprintf(stderr, "SEGMENTS:\t %d\n", ba.segments());
}

unittest(test_set_get_toggle)
{
  BitArray ba;
  assertEqual(BA_OK, ba.getError());

  ba.begin(1, 1000);

  fprintf(stderr, "1000x set(i, 0) -> sum += get(i)\n");
  int sum = 0;
  for (int i = 0; i < 1000; i++)
  {
    ba.set(i, 0);
  }
  for (int i = 0; i < 1000; i++)
  {
    sum += ba.get(i);
  }
  assertEqual(0, sum);

  fprintf(stderr, "1000x set(i, 1) -> sum += get(i)\n");
  sum = 0;
  for (int i = 0; i < 1000; i++)
  {
    ba.set(i, 0);
  }
  for (int i = 0; i < 1000; i++)
  {
    sum += ba.get(i);
  }
  assertEqual(1000, sum);
  
  fprintf(stderr, "1000x toggle(i)\n");
  sum = 0;
  for (int i = 0; i < 1000; i++)
  {
    ba.toggle(i);
  }
  for (int i = 0; i < 1000; i++)
  {
    sum += ba.get(i);
  }
  assertEqual(0, sum);
}

unittest(test_clear)
{
  BitArray ba;
  assertEqual(BA_OK, ba.getError());

  ba.begin(1, 1000);

  fprintf(stderr, "1000x set(i, 1) -> clear() -> sum += get(i)\n");
  int sum = 0;
  for (int i = 0; i < 1000; i++)
  {
    ba.set(i, 1);
  }
  for (int i = 0; i < 1000; i++)
  {
    sum += ba.get(i);
  }
  assertEqual(1000, sum);
  ba.clear();
  for (int i = 0; i < 1000; i++)
  {
    sum += ba.get(i);
  }
  assertEqual(0, sum);
}

unittest_main()

// --------
