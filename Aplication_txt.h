#pragma once
#ifndef APLICATION_TXT_HPP
#define APLICATION_TXT_HPP
#include "Aplication.h"
#include <thread>
class Aplication_txt :public Aplication {
public:
	Aplication_txt(unsigned int x,unsigned int y);
	Aplication_txt(const Aplication_txt& A);
	Aplication_txt& operator=(const Aplication_txt& A);
	void m_gra();
	~Aplication_txt();
};
#endif // !APLICATION_TXT_HPP
