#include <iostream>

#include <arrayfire.h>
#include <flashlight/flashlight.h>

/**
 * ###### #         ##    ####  #    # #      #  ####  #    # #####
 * #      #        #  #  #      #    # #      # #    # #    #   #
 * #####  #       #    #  ####  ###### #      # #      ######   #
 * #      #       ######      # #    # #      # #  ### #    #   #
 * #      #       #    # #    # #    # #      # #    # #    #   #
 * #      ####### #    #  ####  #    # ###### #  ####  #    #   #
 */
int main() {
  const int nSamples = 10000;
  const int nFeat = 10;
  auto X = af::randu(nFeat,nSamples) +1;
  auto Y = af::sum(aff::pow(X,3),0) + af::sin(2*M_PI *af::randu(nSamples));
  return 0;
}