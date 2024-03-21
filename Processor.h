#pragma once
#include <string>
#include <iostream>
using namespace std;


/*
	������ ����:
		3-�������� �������� ��������� ���������� � 1-�� �������
		16-���

		������������ ������� ���� ��� � 1-�� �������. ������ ��� ��������� 2-� ��������� 
		� ������ AABB, �� AA �� BB � �������� ��� 
		(� �������� ������ ��� ���������� �� ����������� �����). 
		2-� ������� ��������������� � ������ ��� ���������� ���������.

		save - ����� �������� �������� ����� ����� �� ������ ������
		
*/

/*
	������������ ��� ������� ���� ��� ��'����� ����� ������ 
*/

class Processor
{
	string registr[64]; // ������� ������ 
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

