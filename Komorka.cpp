#include "Komorka.hpp"

Komorka::Komorka() { 
	b_stan = new bool(false); 
}
Komorka::Komorka(bool b_value) {
	b_stan = new bool;
	*b_stan = b_value;
}
Komorka::~Komorka() {
	delete b_stan;
}
/*Komorka::Komorka(const Komorka& K) {
	if (this != &K) *this = K; 
}
Komorka& Komorka::operator=(const Komorka& K) {
	if (this == &K) return *this;
	if (*this == K) return *this;
	this->b_stan = K.b_stan;
	return *this;
}*/
bool Komorka::operator==(const Komorka &K) {
	return b_stan == K.b_stan;
}
void Komorka::m_shift_stan() {
	if (*b_stan==true) { *b_stan = false; }
	else
		*b_stan = true; 
}
bool* Komorka::m_set_stan() {
	return b_stan;
}
int Komorka::m_set_stanint() {
	if (*b_stan==true) return 1;
	else return 0;
}
bool Komorka::m_what() {
	return *b_stan;
}