#include "config/pinout.h"

//  This class is to be used when setting all the pinouts doing it
//  in here means that if we for some reason change any of our input
//  or output pins it can be quickly changed here and reflected across
//  all of our code.

namespace Pinout {
    Pins pins{
        // Commas used here since its technically a list of values to initalise a Pins object
        .examplePin = 25,
        .nextExample = 14,
        .motorPin = 3
    };
}