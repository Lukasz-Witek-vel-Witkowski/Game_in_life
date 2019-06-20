#pragma once
#ifndef APLICATION_API_HPP
#define APLIACTION_API_HPP
#include "Aplication.h"
class Aplication_api : public Aplication {
public:
	HDC _hdc;
	HBRUSH _MyBrush, _BgBrush;
	Aplication_api(unsigned int x,unsigned int y);
	Aplication_api(const Aplication_api& A);
	Aplication_api& operator=(const Aplication_api& A);
	void InitAPI(HWND& hwnd);
	void m_wiev();
	void m_gra();
	void m_gra(HWND& hwnd);
	~Aplication_api();
};
const static int dx, dy;
#endif // !APLICATION_API_HPP
