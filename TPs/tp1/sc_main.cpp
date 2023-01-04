/********************************************************************
 * Copyright (C) 2009 by Ensimag and Verimag			    *
 * Initial author: Matthieu Moy					    *
 ********************************************************************/

#include "ensitlm.h"
#include "generator.h"
#include "memory.h"
#include "bus.h"
#include "LCDC.h"

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
  Memory mem("Memory", 0x15400);
	Bus bus("Bus");
  LCDC lcdc("LCDC", sc_core::sc_time(1.0 / 25, sc_core::SC_SEC));

  sc_core::sc_signal<bool> display_intr;

  /* port mapping */
	bus.map(mem.socket, 0x10000000, 0x15400);
  bus.map(lcdc.target_socket, 0x20000000, 3*4);

	/* connect components to the bus */
	gen.socket.bind(bus.target);
	bus.initiator.bind(mem.socket);
  bus.initiator.bind(lcdc.target_socket);
  lcdc.initiator_socket.bind(bus.target);

  lcdc.display_intr(display_intr);
  gen.get_intr(display_intr);

	/* and start simulation */
	sc_core::sc_start();

	return 0;
}
