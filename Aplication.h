#pragma once
#ifndef APLICATION_HPP
#define APLICATION_HPP
#include "Enginer.hpp"
#include <fstream>
#define FILE "config.ini"
class Aplication :public Enginer
{
public:
	Aplication(unsigned int x,unsigned int y);
	Aplication(const Aplication& A); 
	bool& operator=(const Aplication& A);
	virtual void m_gra()=0;
	void m_start();
	~Aplication();
};

#endif //APLICATION_HPP