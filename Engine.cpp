#include "Enginer.hpp"

void f_option_clear(HANDLE& h, COORD& pos, DWORD& Written);
void f_clear(HANDLE& h, COORD& pos, DWORD& Written);
Enginer::Enginer(unsigned int x,unsigned int y) {
	b_tab_up = new bool[9];
	b_tab_static = new bool[9];
	this->i_kolumna = x+2;
	this->i_rzad = y+2;
		K_tab = new Komorka*[i_kolumna];
		i_tab_position = new int*[i_kolumna*i_rzad];
	int i;
	for (i = 0; i < i_kolumna*i_rzad;i++) { //zoptymalizowac
		i_tab_position[i] = new int[2];
	}
	for (i = 0;i < i_kolumna;i++)
	{
		K_tab[i] = new Komorka[i_rzad];
	}
	for (i = 0; i < 9; i++) {
		b_tab_static[i] = false;
		b_tab_up[i] = false;
	}
}
Enginer::~Enginer() {
	int i;
	for (i = 0;i < i_kolumna;i++)
	{
		delete[] K_tab[i];
	}
	for (i = 0; i < i_kolumna*i_rzad; i++) {
		delete[] i_tab_position[i];
	}
	delete[] K_tab;
	delete[] i_tab_position;
	delete[] b_tab_up;
	delete[] b_tab_static;
}
void Enginer::m_analiza_tablic() {
	int i;
	int j;
	int i_choice;
	int size = 0;
	for (i = 1; i < i_kolumna-1;i++) {
		for (j = 1;j < i_rzad-1;j++) {
			i_choice = m_ile_sasiadow(i, j);
			m_procedura_analizy(i, j, i_choice, size);
		}
	}
	for (i = 0; i < size; i++) {
		K_tab[i_tab_position[i][1]][i_tab_position[i][2]].m_shift_stan();
	}
}
int Enginer::m_ile_sasiadow(int x, int y) {
	int i = (*K_tab[x - 1][y].m_set_stan()) //poz 8
		+ (*K_tab[x + 1][y].m_set_stan()) //poz 2
		+ (*K_tab[x][y - 1].m_set_stan()) //poz 4
		+ (*K_tab[x][y + 1].m_set_stan()) //poz 6
		+ (*K_tab[x - 1][y - 1].m_set_stan()) //poz 1
		+ (*K_tab[x - 1][y + 1].m_set_stan()) //poz 3
		+ (*K_tab[x +1][y-1].m_set_stan()) //poz 7
		+ (*K_tab[x + 1][y + 1].m_set_stan()); //poz 9
		return i;
}
void Enginer::m_load_zasady(int* i_tab_up, int size_up, int* i_tab_static, int size_static) {
	int i;
		for (i = 0; i < size_up;i++) {
			if(i_tab_up[i]>=0&& i_tab_up[i]<9) //warunek aby nie wyjsc poza tablice bool_up
			b_tab_up[i_tab_up[i]] = true;
		}
		for (i = 0; i < size_static;i++) {
			if (i_tab_static[i] >= 0 && i_tab_static[i]<9) //warunek aby nie wyjsc poza tablice bool_static
			b_tab_static[i_tab_static[i]] = true;
		}
}
void Enginer::m_procedura_analizy(int i_x, int i_y, int i_choice, int& size) {
	if ((*K_tab[i_x][i_y].m_set_stan())==true)
	{
		if (b_tab_static[i_choice]==false) { //jezeli warunki dla zywej komorki nie sia spelnione komorka umiera
			i_tab_position[size][1] = i_x;
			i_tab_position[size][2] = i_y;
			size++;
		}
	}
	else {
		if (b_tab_up[i_choice]==true) { //jezeli warunki dla nie zywej komorki sa spelnione komorka ozywa
			i_tab_position[size][1] = i_x;
			i_tab_position[size][2] = i_y;
			size++;
		}
	}
}
void Enginer::m_view() {
	int i;
	int j;
	std::string screen;
	screen.resize(i_rzad+1);
	f_option_clear(h, pos, Written);
	for (i = 0; i < i_kolumna; i++) {
		for (j = 0; j < i_rzad; j++) {
			switch (K_tab[i][j].m_set_stanint()) {
			case 0:	screen[j] = ' '; break;
			case 1: screen[j] = 'X'; break;
			}
		} 
		screen[j] = '\n';
		printf(screen.c_str());
	}
	Sleep(180);
	f_clear(h, pos, Written);
}
void f_option_clear(HANDLE& h, COORD& pos, DWORD& Written) {
	system("cls");

	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = FALSE;
	::SetConsoleCursorInfo(hConsoleOut, &hCCI);
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
void f_clear(HANDLE& h, COORD& pos, DWORD& Written) {
	FillConsoleOutputCharacter(h, ' ', 0 * 0, pos, &Written);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Enginer::m_load_map(int* i_tab_start, int size) {
	std::cout << "Ile zasad\n";
	int i;
	int i_x;
	int i_y;
	for (i = 0; i < size; i++) {
		i_x = i_tab_start[i] / i_rzad;
		i_y = i_tab_start[i] % i_rzad;
		K_tab[i_x][i_y].m_shift_stan(); //ustaw na zywe
	}
}