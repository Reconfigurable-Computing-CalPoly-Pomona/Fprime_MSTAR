// ======================================================================
// \title  ExpRecieverComponentImpl.cpp
// \author macade
// \brief  cpp file for ExpReciever component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/ExpReciever/ExpRecieverComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ExpRecieverComponentImpl ::
    ExpRecieverComponentImpl(
        const char *const compName
    ) : ExpRecieverComponentBase(compName)
  {

  }

  void ExpRecieverComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    ExpRecieverComponentBase::init(queueDepth, instance);
  }

  ExpRecieverComponentImpl ::
    ~ExpRecieverComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ExpRecieverComponentImpl ::
    ExpIn_handler(
        const NATIVE_INT_TYPE portNum,
        U32 base,
        U32 exponent,
        U32 modulus
    )
  {
    U32 result, i;
    if(modulus == 1)
      {
        result = 0;
      }
    else 
    {
      result = 1;
      for(i = 0; i < exponent; i++)
      {
        result = (result * base) % modulus;
      }
    }

    this->tlmWrite_ER_BASE(base);
    this->tlmWrite_ER_EXPONENT(exponent);
    this->tlmWrite_ER_MODULUS(modulus);
    this->tlmWrite_ER_RESULT(result);
    this->log_ACTIVITY_HI_MR_OPERATION_PERFORMED(result);
    this->expOut_out(0,result);

  }

  void ExpRecieverComponentImpl ::
    SchedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
      QueuedComponentBase::MsgDispatchStatus stat = QueuedComponentBase::MSG_DISPATCH_OK;
      // empty message queue
      while (stat != MSG_DISPATCH_EMPTY) {
          stat = this->doDispatch();
      }
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void ExpRecieverComponentImpl ::
    MR_CLEAR_EVENT_THROTTLE_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    // clear throttle
    // this->log_ACTIVITY_HI_MR_SET_FACTOR1_ThrottleClear();
    // send event that throttle is cleared
    this->log_ACTIVITY_HI_MR_THROTTLE_CLEARED();
    // reply with completion status
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref
