#pragma once
#ifndef ENGINER_HPP
#define ENGINER_HPP
#include "Komorka.hpp"
#include <Windows.h>
#include <iostream>
#include <string>
class Enginer
{
protected:
	Komorka** K_tab;
	bool* b_tab_up;
	bool* b_tab_static;
	int i_kolumna, i_rzad;
	int** i_tab_position;
public:
	Enginer(unsigned int x,unsigned int y);
	Enginer(const Enginer &E); //nie ma implementacji, po to aby nie uyzwac konstruktora kopiujacego
	Enginer& operator=(const Enginer &E); //nie ma implementacji, po to aby nie uyzwac operatora przypisania
	int m_ile_sasiadow(int x,int y); //metoda zwraca ilosc sasiadow wzgledem pozycji podanej w argumentach
	void m_analiza_tablic();
	void m_load_zasady(int* i_tab_up, int size_up, int* i_tab_static, int size_static);
	void m_load_map(int* i_tab_start, int size);
	void m_procedura_analizy(int i_x, int i_y, int i_choice, int& size);
	void m_view();
	~Enginer();
};
static char C_massage[2];
//zmienne do lepszego obslugiwania konsoli
static HANDLE h;
static COORD pos = { 0,0 };
static DWORD Written;
#endif // ENGINER_HPP

