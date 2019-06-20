#include "Aplication.h"
Aplication::Aplication(unsigned int x,unsigned int y):Enginer(x,y) {}
void Aplication::m_start() {
	int *i_tab_up;
	int i;
	int j;
	int ti;
	int tj;
	int temp;
	int tempSecond;
	int *section;
	int *i_tab_static;
	int i_size_up;
	int i_size_static;
	int size_section;
	std::ifstream file;
	file.open(FILE);
	if (file.good()) {
		file >> size_section;
		section = new int[size_section];
		for (i = 0; i < size_section; i++) {
			file >> temp;
			section[i] = temp;
		}
		file >> i_size_up;
		file >> i_size_static;
		i_tab_up = new int[i_size_up];
		i_tab_static = new int[i_size_static];
		ti = 0;
		tj = 0;
		for (i = 0; i < section[0]; i++) {
			file >> temp;
			file >> tempSecond;
			switch (tempSecond) {
			case 0:
				if (ti < i_size_up)
					i_tab_up[ti] = temp;
				ti++;
				break;
			case 1:
				if (tj < i_size_static)
					i_tab_static[tj] = temp;
				tj++;
				break;
			}
		}
	m_load_zasady(i_tab_up, i_size_up, i_tab_static, i_size_static);
	delete[] i_tab_up;
	delete[] i_tab_static;
	i_tab_up = new int[section[1]];
	for (i = 0; i < section[1]; i++) {
			file >> temp;
			file >> tempSecond;
			i_tab_up[i] = i_rzad * temp + tempSecond;
	}
	m_load_map(i_tab_up, section[1]);
	delete[] i_tab_up;
	
			file.close();
	}
	else {
		i_size_up = 1;
		i_size_static = 2;
		i_tab_up = new int[1];
		i_tab_static = new int[2];
		i_tab_up[0] = 3;
		i_tab_static[0] = 2;
		i_tab_static[1] = 3;
		m_load_zasady(i_tab_up, i_size_up, i_tab_static, i_size_static);
		delete[] i_tab_up;
		delete[] i_tab_static;
		i_size_up = 5;
		i_tab_up = new int[i_size_up];
		i_tab_up[0] = i_rzad * 2 + 3;
		i_tab_up[1] = i_rzad * 3 + 4;
		i_tab_up[2] = i_rzad * 4 + 4;
		i_tab_up[3] = i_rzad * 4 + 3;
		i_tab_up[4] = i_rzad * 4 + 2;
		m_load_map(i_tab_up, i_size_up);
		delete[] i_tab_up;
	}
}
Aplication::~Aplication() {}