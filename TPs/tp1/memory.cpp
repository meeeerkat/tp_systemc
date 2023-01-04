/********************************************************************
 * Copyright (C) 2009 by Ensimag and Verimag			    *
 * Initial author: Matthieu Moy					    *
 ********************************************************************/

#include "memory.h"

using namespace std;


tlm::tlm_response_status Memory::write(const ensitlm::addr_t &a,
                                       const ensitlm::data_t &d) {
  std::cout << name() << ": write " << std::hex << a << " " << std::dec << d << endl;
	return tlm::TLM_OK_RESPONSE;
}

tlm::tlm_response_status Memory::read(const ensitlm::addr_t &a,
                                      /* */ ensitlm::data_t &d) {
  std::cout << name() << ": read " << std::hex << a << " " << std::dec << d << endl;
	return tlm::TLM_OK_RESPONSE;
}
