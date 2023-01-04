
#include "generator.h"

using namespace std;

void Generator::thread(void) {
	ensitlm::data_t val = 1;
	ensitlm::addr_t addr = 4;
	while (true) {
		cout << "Entrer un nombre" << endl;
		cin >> val;
		cout << "Entrer une adresse" << endl;
		cin >> addr;
		cout << "je vais envoyer : " << std::dec << val << " a l'addresse " << std::dec << addr << endl;
		socket.write(addr, val);
	}
}

Generator::Generator(sc_core::sc_module_name name) : sc_core::sc_module(name) {
	SC_THREAD(thread);
}

