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
  const int nEpochs = 100;
  const int nSamples = 10000;
  const int nFeat = 10;
  auto X = af::randu(nFeat,nSamples) +1;
  auto signal = af::sum(af::pow(X,3),0).T();
  auto noise =  af::sin(2*M_PI *af::randu(nSamples));
  //af::print("signal", signal);
  //af::print("noise",noise);
  auto Y = signal + noise;
  const float learningRate = 0.001;
  auto weight = fl::Variable(af::randu(1,nFeat),true );
  auto bias = fl::Variable(af::constant(0.01,1), true);

  std::cout << "Linear Regression Started.."<<std::endl; 
  for (int e =1; e <= nEpochs; ++e){
    af::array error = af::constant(0,1);
    for (int i = 0; i < nSamples; ++i){
        auto input = fl::Variable(X(af::span,i),false);
        auto yPred = fl::matmul(weight, input) + bias;
        auto yTrue = fl::Variable(Y(i),false);
        auto loss = ( (yPred - yTrue) * (yPred - yTrue) ) / nSamples;

        loss.backward();
        weight.array() = weight.array() - learningRate * weight.grad().array();
        bias.array() = bias.array() -learningRate * bias.grad().array();

        weight.zeroGrad();
        bias.zeroGrad();

        error+= loss.array();

    }
    std::cout << "Epoch" << e << "Mean Squared Error: " << error.scalar<float>() <<std::endl;
  
  }
  std::cout << "Linear Regression Done"<<std::endl; 


  return 0;
}
