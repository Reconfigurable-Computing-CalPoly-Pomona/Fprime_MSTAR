// ======================================================================
// \title  ArrSenderComponentImpl.cpp
// \author xilinx
// \brief  cpp file for ArrSender component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/ArrSender/ArrSenderComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ArrSenderComponentImpl ::
    ArrSenderComponentImpl(
        const char *const compName
    ) : ArrSenderComponentBase(compName)
  {

  }

  void ArrSenderComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    ArrSenderComponentBase::init(queueDepth, instance);
  }

  ArrSenderComponentImpl ::
    ~ArrSenderComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ArrSenderComponentImpl ::
    arrIn_handler(
        const NATIVE_INT_TYPE portNum,
        Ref::OneHundred result
    )
  {
    this->tlmWrite_AC_RES(result);
  	this->log_ACTIVITY_HI_AC_RESULT(result[0]);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void ArrSenderComponentImpl ::
    AC_DO_ARR_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 sentArr
    )
  {
    Ref::OneHundred floatArray = Ref::OneHundred(sentArr);
	this->tlmWrite_AC_RES(floatArray);
	
	for(int i = 0; i < sentArr; i++)
	{
		this->log_ACTIVITY_LO_AC_ARR_RECV();
		this->arrOut_out(0,floatArray);
    		
	}
	
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref
