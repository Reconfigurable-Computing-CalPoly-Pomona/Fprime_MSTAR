// ======================================================================
// \title  ExpReceiverComponentImpl.hpp
// \author macade
// \brief  hpp file for ExpReceiver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef ExpReceiver_HPP
#define ExpReceiver_HPP

#include "Ref/ExpReceiver/ExpReceiverComponentAc.hpp"

namespace Ref {

  class ExpReceiverComponentImpl :
    public ExpReceiverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object ExpReceiver
      //!
      ExpReceiverComponentImpl(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object ExpReceiver
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object ExpReceiver
      //!
      ~ExpReceiverComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for ExpIn
      //!
      void ExpIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 base, 
          U32 exponent, 
          U32 modulus 
      );

      //! Handler implementation for SchedIn
      //!
      void SchedIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for MR_CLEAR_EVENT_THROTTLE command handler
      //! Clear the event throttle
      void MR_CLEAR_EVENT_THROTTLE_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );


    };

} // end namespace Ref

#endif
