// ======================================================================
// \title  ArrReceiverComponentImpl.hpp
// \author xilinx
// \brief  hpp file for ArrReceiver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef ArrReceiver_HPP
#define ArrReceiver_HPP

#include "Ref/ArrReceiver/ArrReceiverComponentAc.hpp"

namespace Ref {

  class ArrReceiverComponentImpl :
    public ArrReceiverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object ArrReceiver
      //!
      ArrReceiverComponentImpl(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object ArrReceiver
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object ArrReceiver
      //!
      ~ArrReceiverComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for arrIn
      //!
      void arrIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Ref::OneHundred sentArr 
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

      //! Implementation for AC_CLEAR_EVENT_THROTTLE command handler
      //! Clear the event throttle
      void AC_CLEAR_EVENT_THROTTLE_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );


    };

} // end namespace Ref

#endif
