#include "test_igfiles-driver.h"
#include <iostream>

int
main(int argc, char**argv)
{
  IgCollectionTest app;
  app.run();
  std::cerr << "All tests completed successfully" << std::endl;
}