// --------------------------------------------------------------------------------
// Copyright (C) 2011 Dan Malec
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
// of the Software, and to permit persons to whom the Software is furnished to do
// so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// --------------------------------------------------------------------------------
#ifndef ThermalGrapher_h
#define ThermalGrapher_h

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
 #include "WConstants.h"
#endif

#include "Thermal.h"

class ThermalGrapher {

  public:
    ThermalGrapher(Thermal *printer, int min, int max);
    ~ThermalGrapher();
    
    void printValue(int value);

  private:
    Thermal* _printer;
    uint8_t** _buffer;
    int _min;
    int _max;
    int _oldValue;
    boolean _primed;

    void setPixel(int x, int y);
    void drawLine(int x0, int x2, int y0, int y1);
};

#endif
