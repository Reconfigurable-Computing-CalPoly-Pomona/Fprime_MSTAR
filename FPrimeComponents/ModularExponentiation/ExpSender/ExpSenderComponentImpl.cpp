// ======================================================================
// \title  ExpSenderComponentImpl.cpp
// \author macade
// \brief  cpp file for ExpSender component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/ExpSender/ExpSenderComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ExpSenderComponentImpl ::
    ExpSenderComponentImpl(
        const char *const compName
    ) : ExpSenderComponentBase(compName)
  {

  }

  void ExpSenderComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    ExpSenderComponentBase::init(queueDepth, instance);
  }

  ExpSenderComponentImpl ::
    ~ExpSenderComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ExpSenderComponentImpl ::
    ExpIn_handler(
        const NATIVE_INT_TYPE portNum,
        U32 result
    )
  {
    this->tlmWrite_ES_RESULT(result);
    this->log_ACTIVITY_HI_ES_RESULT(result);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void ExpSenderComponentImpl ::
    ES_DO_EXP_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        U32 base,
        U32 exponent,
        U32 modulus
    )
  {
    this->tlmWrite_ES_BASE(base);
    this->tlmWrite_ES_EXPONENT(exponent);
    this->tlmWrite_ES_MODULUS(modulus);
    this->log_ACTIVITY_LO_ES_COMMAND_RECV(base,exponent,modulus);
    this->ExpOut_out(0,base,exponent,modulus);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref
