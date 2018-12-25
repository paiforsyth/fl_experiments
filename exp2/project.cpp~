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
    auto r = af::range(af::dim4(2,3));
    auto A = fl::Variable(af::constant(1.0,af::dim4(2,3)  ),false );
    auto B = fl::Variable(af::constant(2.0,af::dim4(2,3)  ),true );
    auto AB = A * B;
    af::print("AB", AB.array());
    af::print("ABGrad", AB.grad().array());
}
