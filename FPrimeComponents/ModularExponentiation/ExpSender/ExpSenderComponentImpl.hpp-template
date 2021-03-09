// ======================================================================
// \title  ExpSenderComponentImpl.hpp
// \author macade
// \brief  hpp file for ExpSender component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef ExpSender_HPP
#define ExpSender_HPP

#include "Ref/ExpSender/ExpSenderComponentAc.hpp"

namespace Ref {

  class ExpSenderComponentImpl :
    public ExpSenderComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object ExpSender
      //!
      ExpSenderComponentImpl(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object ExpSender
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object ExpSender
      //!
      ~ExpSenderComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for ExpIn
      //!
      void ExpIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 result /*!< the result of the operation*/
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for ES_DO_EXP command handler
      //! Do modular exponentiation
      void ES_DO_EXP_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          U32 base, /*!< base value*/
          U32 exponent, /*!< exponent value*/
          U32 modulus /*!< modulus value*/
      );


    };

} // end namespace Ref

#endif
