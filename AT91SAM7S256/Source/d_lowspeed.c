//
// Date init       14.12.2004
//
// Revision date   $Date:: 14-11-07 12:40                                    $
//
// Filename        $Workfile:: d_lowspeed.c                                  $
//
// Version         $Revision:: 1                                             $
//
// Archive         $Archive:: /LMS2006/Sys01/Main_V02/Firmware/Source/d_lows $
//
// Platform        C
//

#include  "stdconst.h"
#include  "m_sched.h"
#include  "d_lowspeed.h"
#include  "d_lowspeed.r"


void      dLowSpeedInit(void)
{
  LOWSpeedTxInit;
  LOWSpeedTimerInit;
  //ENABLEDebugOutput; 
}

void dLowSpeedStartTimer(void)
{
  ENABLEPWMTimerForLowCom;
}

void dLowSpeedStopTimer(void)
{
  DISABLEPWMTimerForLowCom; 
}

void dLowSpeedInitPins(UBYTE ChannelNumber)
{
  ENABLETxPins(ChannelNumber);  
}

UBYTE dLowSpeedSendData(UBYTE ChannelNumber, UBYTE *DataOutBuffer, UBYTE NumberOfTxByte)
{  
  UBYTE Status;
	
  TxData(ChannelNumber, Status, DataOutBuffer, NumberOfTxByte);
  return(Status);
}

void dLowSpeedReceiveData(UBYTE ChannelNumber, UBYTE *DataInBuffer, UBYTE ByteToRx)
{	
  RxData(ChannelNumber, DataInBuffer, ByteToRx); 
}

UBYTE dLowSpeedComTxStatus(UBYTE ChannelNumber)
{
  UBYTE Status; 

  STATUSTxCom(ChannelNumber, Status)

  return(Status);
}

UBYTE dLowSpeedComRxStatus(UBYTE ChannelNumber)
{
  UBYTE Status; 

  STATUSRxCom(ChannelNumber, Status)

  return(Status);
}

void      dLowSpeedExit(void)
{
  LOWSpeedExit;
}
