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

#include "bitArray.h"


unittest_setup()
{
}

unittest_teardown()
{
}

unittest(test_constructor)
{
  BitArray ba;
  
  ba.begin(1, 1000);

  assertEqual(1, ba.capacity);
  assertEqual(1, ba.memory);
  assertEqual(1, ba.bits);
  assertEqual(1, ba.segments);
}

unittest_main()

// --------
