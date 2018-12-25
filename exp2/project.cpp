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
    auto r = af::range(af::dim4(2,3), 1.0);
    auto A = f1:Variable(r,true);
    af::print("A",A.array());
    return 0;
}