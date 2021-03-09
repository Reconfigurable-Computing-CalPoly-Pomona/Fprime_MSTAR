// ======================================================================
// \title  ArrReceiverComponentImpl.cpp
// \author xilinx
// \brief  cpp file for ArrReceiver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/ArrReceiver/ArrReceiverComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ArrReceiverComponentImpl ::
    ArrReceiverComponentImpl(
        const char *const compName
    ) : ArrReceiverComponentBase(compName)
  {

  }

  void ArrReceiverComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    ArrReceiverComponentBase::init(queueDepth, instance);
  }

  ArrReceiverComponentImpl ::
    ~ArrReceiverComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ArrReceiverComponentImpl ::
    arrIn_handler(
        const NATIVE_INT_TYPE portNum,
        Ref::OneHundred sentArr
    )
  {
    Ref::ArrCopy copy;
	U32 n, i;
	copy.setval1(sentArr);
	
	this->log_ACTIVITY_HI_COPY_OPERATION_RECEIVED();
	n = (U32)sentArr.SIZE;
	
	Ref::OneHundred copyInputData; 
	
	for(i = 0; i < n; i++){
  		copyInputData[i]=sentArr[i];
	}
	
	copy.setresult(copyInputData);
	this->log_ACTIVITY_HI_AC_OPERATION_PERFORMED();
	this->tlmWrite_AC_OPERATION(copy);
    this->arrOut_out(0,copyInputData);
  }

  void ArrReceiverComponentImpl ::
    SchedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
	  
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void ArrReceiverComponentImpl ::
    AC_CLEAR_EVENT_THROTTLE_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    // TODO
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref
