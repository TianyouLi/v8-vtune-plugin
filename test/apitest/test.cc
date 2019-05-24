#include <iostream>
#include "invokedynamic.h"

#define dynamiclibrarypath "/home/hre/v8/v8-vtune-plugin/out/libv8-vtune-plugin.so"    //fill the dynamic library path here

int main() {
  DynamicFunction dynamic_function_;

  for(int i = 0; i < 1000000; i++) {
    std::cout << ".";
  }

  if(dynamic_function_.initialize(dynamiclibrarypath)) {
    std::cout << "\nDynamic initialization failed!" << std::endl; 
  }

  if(dynamic_function_.invoke("init:MyTest")) {
    std::cout << "\nInvoke start successfully!" << std::endl;
  }

  if(dynamic_function_.invoke("start:MyBenchmarkTest")) {
    std::cout << "\nInvoke start successfully!" << std::endl;
  }

  for(int i = 0; i < 4; i++) {
    dynamic_function_.invoke("start:MyCreateThread");
    for(int i = 0; i < 100000; i++) {
      std::cout << ".";
    }
    dynamic_function_.invoke("end");
  }

  if(dynamic_function_.invoke("end")) {
    std::cout << "\nInvoke end successfully!" << std::endl;
  }

  return 0;
}