// $Id: ESMC_State.h,v 1.12 2007/12/23 20:57:10 rosalind Exp $
//
// Earth System Modeling Framework
// Copyright 2002-2007, University Corporation for Atmospheric Research, 
// Massachusetts Institute of Technology, Geophysical Fluid Dynamics 
// Laboratory, University of Michigan, National Centers for Environmental 
// Prediction, Los Alamos National Laboratory, Argonne National Laboratory, 
// NASA Goddard Space Flight Center.
// Licensed under the University of Illinois-NCSA License.

// ESMF State C++ declaration include file
//
// (all lines below between the !BOP and !EOP markers will be included in 
//  the automated document processing.)
//-----------------------------------------------------------------------------
//
 // these lines prevent this file from being read more than once if it
 // ends up being included multiple times

 #ifndef ESMC_State_H
 #define ESMC_State_H

//-----------------------------------------------------------------------------
//BOP
// !CLASS:  ESMC_State - C interface to the F90 State object
//
// !DESCRIPTION:
//
// The code in this file defines the C State members and declares method 
// signatures (prototypes).  The companion file ESMC\_State.C contains
// the definitions (full code bodies) for the State methods.
//
// 
//
//-----------------------------------------------------------------------------
// 
// !USES:
#include "ESMCI_Util.h"
#include "ESMC_F90Interface.h"
#include "ESMC_Base.h"  // all classes inherit from the ESMC Base class.
#include "ESMC_Array.h"
#include "ESMC_Field.h"
#include "ESMC_Bundle.h"


extern "C" {

// class declaration type
typedef struct {

    // pointer to fortran derived type
    ESMC_F90ClassHolder* f90this;


//
//EOP
//-----------------------------------------------------------------------------

} ESMC_State ; // end class ESMC_State


 // accessor methods for class members
    //int ESMC_StateGet<Value>(<value type> *value) const;
    //int ESMC_StateSet<Value>(<value type>  value);
    
 // required methods inherited and overridden from the ESMC_Base class
 //   int ESMC_StatePrint(const char *options) const;

 // initialize and free secondary resources
 //   int ESMC_StateConstruct(void);
 //   int ESMC_StateDestruct(void);

  
//
//EOP
//-----------------------------------------------------------------------------



 ESMC_State* ESMC_StateCreate(char *name, int *rc);

 int ESMC_StateDestroy(ESMC_State *state);

 }; // end extern "C"

// !PRIVATE TYPES:

typedef enum ESMC_StateType {
      ESMC_StateImport=1, ESMC_StateExport,
      ESMC_StateImpExp, ESMC_StateUnknown } ESMC_StateType;

typedef enum ESMC_Objtype { Bundle=1, Field=2, Array=3 } ESMC_Objtype;
typedef enum ESMC_Needed { Needed=1, NotNeeded=2 } ESMC_Needed;
typedef enum ESMC_Ready { ReadyToRead=1, ReadyToWrite=2 } ESMC_Ready;


 #endif  // ESMC_State_H
