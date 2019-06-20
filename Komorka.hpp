#pragma once
#ifndef KOMORKA_HPP
#define KOMORKA_HPP
class Komorka {
	bool* b_stan;
public:
	Komorka();
	Komorka(bool b);
	Komorka(const Komorka& K);
	Komorka& operator=(const Komorka& K);
	bool operator==(const Komorka &K);
	void m_shift_stan();
	bool* m_set_stan();
	int m_set_stanint();
	bool m_what();
	~Komorka();
};

#endif //KOMORKA_HPP