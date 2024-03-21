#pragma once
#include <string>
#include <iostream>
using namespace std;


/*
	Варіант лаби:
		3-адресний процесор Результат розміщується у 1-му операнді
		16-бітні

		Перестановка значень пари бітів у 1-му операнді. Номери бітів задаються 2-м операндом 
		у вигляді AABB, де AA та BB є номерами бітів 
		(з ведучими нулями для доповнення до двозначного числа). 
		2-й операнд представляється у регістрі для безстекової реалізації.

		save - треба оформити зберегти якесь число на якийсь регістр
		
*/

/*
	Доповняльний код повинен бути для від'ємних чисел йомайо 
*/

class Processor
{
	string registr[64]; // регістри данних 
	bool PS = 0; // 0 - number is plus, 1 - number is minus
	int PC = 0; // register number
	int TC = 0; // tact number

	int registNum = 3;
	string command;

	int Str_To_Int(string num);
	string ToBinary(int num);

	void save(int origin, string num);
	void save(int origin, int from);
	void swap(int origin, int posA, int posB);

	void Log();

public:
	string allCommands;


	Processor();
	void Command(string command);

};

