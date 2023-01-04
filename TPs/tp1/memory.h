/********************************************************************
 * Copyright (C) 2009 by Ensimag and Verimag			    *
 * Initial author: Matthieu Moy					    *
 ********************************************************************/

#include "ensitlm.h"
#include "bus.h"
#include <string>

struct Memory : sc_core::sc_module {

  Memory(sc_core::sc_module_name name, size_t byte_size);
  ~Memory();

  bool check_addr(const ensitlm::data_t &a);

	ensitlm::target_socket<Memory> socket;
	tlm::tlm_response_status write(const ensitlm::addr_t &a,
	                               const ensitlm::data_t &d);

	tlm::tlm_response_status read(const ensitlm::addr_t &a,
	                              /* */ ensitlm::data_t &d);

	SC_CTOR(Memory) { /* */	}

  private:
    size_t size;
    ensitlm::data_t* storage;
};
