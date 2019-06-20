#include "Aplication_api.h"
Aplication_api::Aplication_api(unsigned int x,unsigned int y) : Aplication(x, y) {}
Aplication_api::~Aplication_api() {}
void Aplication_api::m_wiev() {
	for (int i = 0; i<i_kolumna; i++) {
		for (int j = 0; j<i_rzad; j++) {
			if (K_tab[i][j].m_what()) (HBRUSH)::SelectObject(_hdc, _BgBrush);
			else (HBRUSH)::SelectObject(_hdc, _MyBrush);
			Rectangle(_hdc, i*dx, j*dy, i*dx + dx, j*dy + dy);
			/*  lub tak:
			if(T[i][j]) Rectangle( _hdc, i*dx, j*dy, i*dx+dx, j*dy+dy );
			else        Ellipse( _hdc, i*dx, j*dy, i*dx+dx, j*dy+dy );
			*/
		}
	}
}
void Aplication_api::InitAPI(HWND& hwnd)
{
	// Brush
	_hdc = GetDC(hwnd);
	_MyBrush = ::CreateSolidBrush(0x00fff000);
	_BgBrush = ::CreateSolidBrush(0x00000fff);
}
void Aplication_api::m_gra(HWND& hwnd) {
//InitAPI(hwnd);
	for (int i = 0; i<1; i++) {
		m_wiev();
		m_analiza_tablic();
		Sleep(500);
	}
}
void Aplication_api::m_gra() {}