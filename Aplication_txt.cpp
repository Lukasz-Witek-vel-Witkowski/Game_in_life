#include "Aplication_txt.h"
void f_screen(Aplication_txt* A);
Aplication_txt::Aplication_txt(unsigned int x,unsigned int y):Aplication(x,y) {
	m_start();
}
void Aplication_txt::m_gra() {

	while (true) {
		std::thread Screen(f_screen,this);
		m_analiza_tablic();
		Screen.join();
	}

}
Aplication_txt::~Aplication_txt() {}
void f_screen(Aplication_txt* A) {
	A->m_view();
}