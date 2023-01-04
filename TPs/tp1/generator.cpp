
#include "generator.h"

using namespace std;

void Generator::thread(void) {
	ensitlm::addr_t addr = 0x10000000;
  for (ensitlm::data_t i=0; i < 0x100; i++)
		socket.write(addr+4*i, i);
}

Generator::Generator(sc_core::sc_module_name name) : sc_core::sc_module(name) {
	SC_THREAD(thread);
}

