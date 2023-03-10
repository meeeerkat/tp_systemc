/********************************************************************
 * Copyright (C) 2009 by Ensimag and Verimag			    *
 * Initial author: Matthieu Moy					    *
 ********************************************************************/

#include "ensitlm.h"
#include "bus.h"

struct Generator : sc_core::sc_module {
	ensitlm::initiator_socket<Generator> socket;
	sc_core::sc_in<bool> get_intr;

	void thread(void);

	SC_CTOR(Generator);
};
