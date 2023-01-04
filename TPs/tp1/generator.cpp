
#include "generator.h"
#include "LCDC_registermap.h"

using namespace std;

void Generator::thread(void) {

  const ensitlm::addr_t base_mem = 0x10000000;
  const ensitlm::addr_t size_mem = 0x15400;
  const ensitlm::addr_t base_lcdc = 0x20000000;

  for (ensitlm::addr_t a=base_mem; a < base_mem+size_mem; a+=4)
    socket.write(a, 0x00FFFFFF);

  socket.write(base_lcdc + LCDC_ADDR_REG, base_mem);
  socket.write(base_lcdc + LCDC_START_REG , 1);
}

Generator::Generator(sc_core::sc_module_name name) : sc_core::sc_module(name) {
	SC_THREAD(thread);
}

