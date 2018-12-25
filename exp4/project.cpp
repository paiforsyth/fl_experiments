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
  auto signal = af::sum(af::pow(X,3),0).T();
  auto noise =  af::sin(2*M_PI *af::randu(nSamples));
  //af::print("signal", signal);
  //af::print("noise",noise);
  auto Y = signal + noise;
  std::cout <<"X Dimensions: "<< X.dims() <<std::endl;
  std::cout <<"Y Dimensions: "<< Y.dims() <<std::endl;

  fl::TensorDataset data({X,Y});
  
  return 0;
}
