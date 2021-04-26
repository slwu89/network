#include <Rcpp.h>

#ifdef __cplusplus
extern "C" {
#endif
  
#include "net.h"
  
#ifdef __cplusplus
}
#endif

//' @title Get neighborhood of a node (unsafe)
//' @description This \code{Rcpp} function is intended as an example of how to
//' use the \code{network} C API from \code{Rcpp}. Please do not use it for
//' actual projects as no type checking or other input checking is implemented.
//' @param x a \code{\link[network]{network}} class object (type is not checked)
//' @param v a vertex ID
//' @param type the neighborhood to be computed
//' @param na logical; should missing edges be ignored when obtaining vertex neighborhoods?
//' @examples
//' 
//' #Create a network with three edges
//' library(network)
//' library(networkRcppExample)
//' m<-matrix(0,3,3)
//' m[1,2]<-1; m[2,3]<-1; m[3,1]<-1
//' g<-network(m)
//' 
//' #Examine the neighborhood of vertex 1
//' get_neighborhood_Rcpp(g,1,"out",TRUE) # compare to get.neighborhood(g,1,"out")
//' get_neighborhood_Rcpp(g,1,"in",TRUE) # compare to get.neighborhood(g,1,"in")
//' get_neighborhood_Rcpp(g,1,"combined",TRUE) # compare to get.neighborhood(g,1,"combined")
//' 
//' @export
// [[Rcpp::export]]
Rcpp::IntegerVector get_neighborhood_Rcpp(SEXP x, const Rcpp::IntegerVector& v, const Rcpp::CharacterVector& type, SEXP na) {

  // Compute the result in _C_ from _C++_.
  SEXP out_sexp = get_neighborhood_C(x, v, type, na);
  
  Rcpp::IntegerVector out(out_sexp);

  return out;
}