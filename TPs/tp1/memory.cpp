/********************************************************************
 * Copyright (C) 2009 by Ensimag and Verimag			    *
 * Initial author: Matthieu Moy					    *
 ********************************************************************/

#include "memory.h"

using namespace std;


Memory::Memory(sc_core::sc_module_name name, size_t byte_size) : sc_core::sc_module(name) {
  this->size = byte_size/sizeof(ensitlm::data_t);
  storage = new ensitlm::data_t[this->size]; // malloc(sizeof(ensitlm::data_t) * this->size)
}

Memory::~Memory() {
  delete [] storage;
}

bool Memory::check_addr(const ensitlm::data_t &a) {
  return a%4 == 0 && a/4 < size;
}

tlm::tlm_response_status Memory::write(const ensitlm::addr_t &a,
                                       const ensitlm::data_t &d) {
  if (check_addr(a) == false)
    return tlm::TLM_ADDRESS_ERROR_RESPONSE;

  storage[a/4] = d;
  std::cout << name() << ": write " << std::hex << a << " " << std::dec << d << endl;
	return tlm::TLM_OK_RESPONSE;
}

tlm::tlm_response_status Memory::read(const ensitlm::addr_t &a,
                                      /* */ ensitlm::data_t &d) {
  if (check_addr(a) == false)
    return tlm::TLM_ADDRESS_ERROR_RESPONSE;

  d = storage[a/4];
  std::cout << name() << ": read " << std::hex << a << " " << std::dec << d << endl;
	return tlm::TLM_OK_RESPONSE;
}
