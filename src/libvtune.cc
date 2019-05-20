#include <cstdlib>
#include <iostream>

#include "libvtune.h"


/**
 * place a marker for Region of Interest(ROI)
 */
static void mark(int n) {
	int simics_magic_instr_dummy;
	//__MAGIC_CASSERT((unsigned)(n) < 0x10000);
	__asm__ __volatile__ ("cpuid"
												: "=a" (simics_magic_instr_dummy)
												: "a" (0x4711 | ((unsigned)(n) << 16))
												: "ecx", "edx", "ebx");
}

int invoke(const char* params) {
	int n = strtol(params, (char**)NULL, 10);

  std::cout << "\ninput params: " << params
            << "\n convert to : " << n << std::endl;
  
  mark(n);

  return n;
}
