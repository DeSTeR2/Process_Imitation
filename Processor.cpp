#include "Processor.h"


Processor::Processor()
{
	string s_State = "0000000000000000";
	for (int i = 0; i < registNum; i++) {
		this->registr[i] = s_State;
	}
	this->PC = 0;
	this->PS = 0;
	this->TC = 0;
}

void Processor::Command(string commandLine)
{
	allCommands += commandLine + '\n';
	string command;
	string s_r1, s_r2, s_r3;
	int r1, r2, r3;

	this->command = commandLine;

	int addTo = 0;
	for (char a : commandLine) {

		if (a == ' ') {
			addTo++;
			continue;
		}

		switch (addTo) {
		case 0:
			command += a;
			break;
		case 1:
			s_r1 += a;
			break;
		case 2: 
			s_r2 += a;
			break;
		case 3:
			s_r3 += a;
			break; 
		default:
			cout << "Break switch in Processor::Command\n";
			break;
		}
	}
	
	r1 = Str_To_Int(s_r1);
	r2 = Str_To_Int(s_r2);
	r3 = Str_To_Int(s_r3);

	if (command == "move") {

		if (s_r2[0] != 'R') {
			this->PC = r1;
			this->TC = 1;
			this->PS = bool(r2 < 0);
			Log();
			save(r1, ToBinary(r2));
			this->TC = 2;
			Log();
		}
		else {
			this->PC = r1;
			this->TC = 1;
			this->PS = bool(r2 < 0);
			Log();
			save(r1, r2);
			this->TC = 2;
			Log();
		}
	}

	if (command == "swap") {
		this->PC = r1;
		this->TC = 1;

		string A = "00";
		A[0] = s_r2[0];
		A[1] = s_r2[1];

		int posA = Str_To_Int(A);
		A[0] = s_r2[2];
		A[1] = s_r2[3];
		int posB = Str_To_Int(A);

		this->PS = bool(r2 < 0);
		Log();
		this->swap(r1, posA-1, posB-1);
		this->TC = 2;
		Log();
	}
	
}

void Processor::swap(int origin, int posA, int posB) {
	char buff = this->registr[origin][posA];
	this->registr[origin][posA] = this->registr[origin][posB];
	this->registr[origin][posB] = buff;
}

int Processor::Str_To_Int(string num)
{
	bool minus = bool(num[0] == '-');
	int ans = 0, step = 1;
	for (int i = num.size() - 1; i >= 0; i--) {
		if (num[i] >= '0' && num[i] <= '9') {
			ans += int(num[i] - '0') * step;
			step *= 10;
		}
	}
	if (minus) ans *= -1;
	return ans;
}

string Processor::ToBinary(int num)
{
	string ans="";

	bool minus = bool(num < 0);

	while (num) {
		ans = char(num % 2 + '0') + ans;
		num /= 2;
	}

	while (ans.size() != 16) ans = '0' + ans;

	if (minus) {
		for (int i = 0; i < ans.size(); i++) {
			if (ans[i] == '0') ans[i] = '1';
			else ans[i] = '0';
		}

		for (int i = ans.size() - 1; i >= 0; i--) {
			if (ans[i] == '1') ans[i] = '0';
			if (ans[i] == '0') {
				ans[i] = '1';
				break;
			}
		}
	}

	return ans;
}

void Processor::save(int origin, string num)
{
	this->registr[origin] = num;
}

void Processor::save(int origin, int from)
{
	this->registr[origin] = this->registr[from];
}

void Processor::Log()
{
	cout << "Current command: " << this->command << '\n';
	for (int i = 0; i < registNum; i++) {
		cout << 'R' << i << " = ";
		for (int j = 0; j < registr[i].size(); j++) {
			cout << registr[i][j];
			if ((j+1) % 4 == 0) cout << " ";
		}
		if (i < 3) {
			cout << "      ";
			if (i == 0) cout << "PS  = " << PS;
			if (i == 1) cout << "PC  = " << PC;
			if (i == 2) cout << "TC  = " << TC;
		}
		cout << '\n';
	}
	cout << "\n|----------------------------------------------------|\n\n";
}
