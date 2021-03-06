//------------------------------------------------------------------------------
// Class: KeithleyDevice
//------------------------------------------------------------------------------
#ifndef __Eaagles_IoDevice_KeithleyDevice_H__
#define __Eaagles_IoDevice_KeithleyDevice_H__

#include "openeaagles/basic/IoDevice.h"

namespace Eaagles {
   namespace Basic { class Number; }

namespace IoDevice {

//------------------------------------------------------------------------------
// Class:  KeithleyDevice
// Description:  Communicates with a standard Keithley I/O device.
//
// Form Name: KeithleyDevice
//
// Slots:
//    deviceIndex <Number>    Unit index
//
//------------------------------------------------------------------------------
class KeithleyDevice : public Basic::IoDevice {
    DECLARE_SUBCLASS(KeithleyDevice,Basic::IoDevice)

public:
   KeithleyDevice();

   virtual unsigned int getDeviceIndex() const;
   virtual bool setDeviceIndex(const int value);

   // IoDevice interface
   virtual unsigned short getNumDiscreteInputChannels() const;
   virtual unsigned short getNumDiscreteInputPorts() const;
   virtual bool getDiscreteInput(bool* const value, const unsigned int channel, const unsigned int port) const;
   virtual unsigned short getNumAnalogInputs() const;
   virtual bool getAnalogInput(LCreal* const value, const unsigned int channel) const;

protected:

   // Slot functions
   virtual bool setSlotDeviceIndex(const Basic::Number* const msg);

   unsigned int deviceIndex; // Device index

   // ---
   // analog 
   // ---
   static const unsigned short MAX_AI = 16;
   unsigned short numAI;   // Number of analog channels
   LCreal inData[MAX_AI];   // Input analog array

   // ---
   // digital bits 
   // ---
   static const unsigned short MAX_DI = 23;
   unsigned short numDI;      // Number of input bits
   bool inBits[MAX_DI];       // Input bit array

private:
   void initData();
};

} // end IoDevice
} // end Eaagles namespace

#endif
