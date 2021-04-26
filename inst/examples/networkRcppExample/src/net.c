#include "net.h"

#include <Rmath.h>

#include <network.h>
#include <netregistration.h>

SEXP get_neighborhood_C(SEXP x, SEXP v, SEXP type, SEXP naOmit) {
  netRegisterFunctions();
  
  int pc=0,naval;
  
  /*Make sure that all variables are adequately dealt with*/
  PROTECT(v=coerceVector(v,INTSXP)); pc++;
  PROTECT(naOmit=coerceVector(naOmit,LGLSXP)); pc++;
  if(length(naOmit)==0)
    naval=0;
  else
    naval=INTEGER(naOmit)[0];
  
  /*Unprotect and return*/
  /*Rprintf("getNeighborhood_R: type=%s\n",CHAR(STRING_ELT(type,0)));*/
  UNPROTECT(pc);
  return netGetNeighborhood(x,INTEGER(v)[0],CHAR(STRING_ELT(type,0)),naval);
}