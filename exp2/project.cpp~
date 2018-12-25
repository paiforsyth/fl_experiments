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
  fl::Variable v(af::array(1), true);
  auto result = v + 10;
  std::cout << "Hello World!" << std::endl;
  af::print("Array value is ", result.array());
  return 0;
}
