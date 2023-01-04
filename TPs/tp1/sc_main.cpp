/********************************************************************
 * Copyright (C) 2009 by Ensimag and Verimag			    *
 * Initial author: Matthieu Moy					    *
 ********************************************************************/

#include "ensitlm.h"
#include "generator.h"
#include "memory.h"
#include "bus.h"

int sc_main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	/*
	  +---------+	 +-------------+    +--------+
	  |	   +++	+-+	      +++  +++	     |
	  | Gen   | +--+ |  Bus   | +--+ |	Mem |
	  |	   +++	+-+	      +++  +++	     |
	  +---------+	 +-------------+    +--------+
	*/

	Generator gen("Generator1");
  Memory mem("Memory", 0x100);
	Bus bus("Bus");

  /* port mapping */
	bus.map(mem.socket, 0x10000000, 0x100000FF+1);

	/* connect components to the bus */
	gen.socket.bind(bus.target);
	bus.initiator.bind(mem.socket);

	/* and start simulation */
	sc_core::sc_start();


  ensitlm::data_t d=10;
  for (ensitlm::addr_t a=0; a < 0x100; a+=4) {
    if (mem.read(a, d) != tlm::TLM_OK_RESPONSE)
      std::cout << "ERROR at " << a << std::endl;
  }


	return 0;
}
