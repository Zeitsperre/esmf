// $Id: ESMCI_State.h,v 1.1 2007/12/23 20:57:09 rosalind Exp $
//
// Earth System Modeling Framework
// Copyright 2002-2007, University Corporation for Atmospheric Research, 
// Massachusetts Institute of Technology, Geophysical Fluid Dynamics 
// Laboratory, University of Michigan, National Centers for Environmental 
// Prediction, Los Alamos National Laboratory, Argonne National Laboratory, 
// NASA Goddard Space Flight Center.
// Licensed under the University of Illinois-NCSA License.

// ESMF State C declaration include file
//
// (all lines below between the !BOP and !EOP markers will be included in 
//  the automated document processing.)
//-----------------------------------------------------------------------------
//
 // these lines prevent this file from being read more than once if it
 // ends up being included multiple times

 #ifndef ESMCI_State_H
 #define ESMCI_State_H

//-----------------------------------------------------------------------------
//BOP
// !CLASS:  ESMC_State - one line general Statement about this class
//
// !DESCRIPTION:
//
// The code in this file defines the ESMC State class prototypes for the
// fortran interface routines. The companion file ESMC\_State_C.F90  contains
// the definitions (full code bodies) for the interface routines.
//
// 
//
//-----------------------------------------------------------------------------
// 
// !USES:
#include "ESMC_State.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//
// prototypes for the fortran interface routines.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
extern "C" {

  void FTN(f_esmf_statecreate)(ESMC_State* state, char* statename, int* rc, int nlen);

  void FTN(f_esmf_statedestroy)(ESMC_State* state, int* rc);

#if 0
      TODO: finish these prototypes
      void FTN(f_esmf_statecreate)(char *statename, statetype, compname,
            bundles, fields, arrays, nestedstates, names, itemcount, int *rc);
      void FTN(f_esmf_statedestroy)(ESMC_State *state, int *rc);
      void FTN(f_esmf_stateaddbundle)(ESMC_State *state, ESMC_Bundle *bundle, int *rc);
      void FTN(f_esmf_stateaddfield)(ESMC_State *state, ESMC_Field *field, int *rc);
      void FTN(f_esmf_stateaddarray)(ESMC_State *state, ESMC_Array *array, int *rc);
      void FTN(f_esmf_stateaddstate)(ESMC_State *state, nestedstate, int *rc);
      void FTN(f_esmf_stateadddataname)(ESMC_State *state, char *name, int *rc);
      void FTN(f_esmf_stategetinfo)(ESMC_State *state, char *statename, 
                          statetype, char *compname,
                          int *itemcount, char *itemnames, objtypes, int *rc);
      void FTN(f_esmf_stategetname)(ESMC_State *state, char *statename, int *rc);
      void FTN(f_esmf_stateisneeded)(ESMC_State *state, char *dataname, int *rc);
      void FTN(f_esmf_stategetneeded)(ESMC_State *state, char *dataname, 
                                 needed, int *rc);
      void FTN(f_esmf_statesetneeded)(ESMC_State *state, char *dataname, needed, int *rc);
      void FTN(f_esmf_stategetbundle)(ESMC_State *state, char *name, ESMC_Bundle *bundle, int *rc);
      void FTN(f_esmf_stategetfield)(ESMC_State *state, char *name, ESMC_Field *field, int *rc);
      void FTN(f_esmf_stategetarray)(ESMC_State *state, char *name, ESMC_Array *array, int *rc);
      void FTN(f_esmf_stategetstate)(ESMC_State *state, char *name, nestedstate, int *rc);
      void FTN(f_esmf_statewriterestart)(ESMC_State *state, iospec, int *rc);
      void FTN(f_esmf_statereadrestart)(char *name, iospec, int *rc);
      void FTN(f_esmf_statevalidate)(ESMC_State *state, char *options, int *rc);
      void FTN(f_esmf_stateprint)(ESMC_State *state, char *options, int *rc);
#endif
 }; // end prototypes for fortran interface

 #endif  // ESMC_State_H
