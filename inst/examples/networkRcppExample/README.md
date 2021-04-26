
<!-- README.md is generated from README.Rmd. Please edit that file -->

# networkRcppExample

<!-- badges: start -->
<!-- badges: end -->

This is a package providing a minimal example of how to write a C
function using the C API from
[network](https://cran.r-project.org/package=network), which is then
used in C++ code which is compiled and linked to R with
[Rcpp](https://cran.r-project.org/package=Rcpp).

The method for calling the C routine from C++ is from
[r-pkg-examples/rcpp-and-c](https://github.com/r-pkg-examples/rcpp-and-c).

To implement this yourself, create a new package using Rcpp. Then, you
must link to network by copying the code in `R/zzz.R`, and adding
network to `LinkingTo` section of the DESCRIPTION. Then, use the
preprocessor commands from `src/netRcpp.cpp` so that your C++ code can
successfully call your C functions.

Functions from network’s C API can be found in
[here](https://github.com/statnet/network/blob/master/inst/include/network.h),
and more information is available in the [package
vignette](https://cran.r-project.org/web/packages/network/vignettes/networkVignette.pdf).
