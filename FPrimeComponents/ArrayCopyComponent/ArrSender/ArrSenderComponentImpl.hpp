// ======================================================================
// \title  ArrSenderComponentImpl.hpp
// \author xilinx
// \brief  hpp file for ArrSender component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef ArrSender_HPP
#define ArrSender_HPP

#include "Ref/ArrSender/ArrSenderComponentAc.hpp"

namespace Ref {

  class ArrSenderComponentImpl :
    public ArrSenderComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object ArrSender
      //!
      ArrSenderComponentImpl(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object ArrSender
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object ArrSender
      //!
      ~ArrSenderComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for arrIn
      //!
      void arrIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Ref::OneHundred result /*!< the result of the array copy*/
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for AC_DO_ARR command handler
      //! Do an array copy
      void AC_DO_ARR_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F32 sentArr /*!< The array*/
      );


    };

} // end namespace Ref

#endif
