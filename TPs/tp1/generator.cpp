
#include "generator.h"

using namespace std;

void Generator::thread(void) {
	ensitlm::data_t val = 10;
	ensitlm::addr_t addr = 0x10000000;
  for (ensitlm::addr_t i=0; i < 10; i++)
		socket.write(addr+4*i, val);

	socket.write(addr+2, val);
	socket.write(3*addr, val);
}

Generator::Generator(sc_core::sc_module_name name) : sc_core::sc_module(name) {
	SC_THREAD(thread);
}

