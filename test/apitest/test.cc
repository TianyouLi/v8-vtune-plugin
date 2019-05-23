#include <iostream>
#include "invokedynamic.h"

#define dynamiclibrarypath "/home/hre/v8/v8-vtune-plugin/out/libv8-vtune-plugin.so"    //fill the dynamic library path here

int main() {
  DynamicFunction dynamic_function_;

  if(dynamic_function_.initialize(dynamiclibrarypath)) {
    std::cout << "\nDynamic initialization failed!" << std::endl; 
  }

  if(dynamic_function_.invoke("init:")) {
    std::cout << "\nInvoke start successfully!" << std::endl;
  }

  if(dynamic_function_.invoke("start:Benchmark")) {
    std::cout << "\nInvoke start successfully!" << std::endl;
  }

  if(dynamic_function_.invoke("end")) {
    std::cout << "\nInvoke end successfully!" << std::endl;
  }

  return 0;
}