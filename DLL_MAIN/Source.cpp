
#include "My_dll.h"
#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;
typedef FirstComplex* (__cdecl *First_Complex_factory)();

void main()
{
	HINSTANCE hmodule = LoadLibrary("My_dll.dll");
	if (!hmodule)
	{
		std::cout << "Не удалось загрузить библиотеку!\n";
		return;
	}
	First_Complex_factory CreateClass = reinterpret_cast<First_Complex_factory>(GetProcAddress(hmodule, "CreateClass"));
	FirstComplex* A = CreateClass();
	FirstComplex* B = CreateClass();
	FirstComplex* C = CreateClass();
	FirstComplex* D = CreateClass();
	setlocale(LC_ALL, "Russian");
	ofstream f_bin("binIn.txt", ios::binary);
	f_bin.close();
	cout << "Введите комплексное число." << endl;
	cout << "Re: ";
	float a, b;
	cin >> a;
	cout << "Im: ";
	cin >> b;
	A->SetReIm(a, b);
	A->Out();
	A->Write();
	cout << endl;
	cout << "Введите комплексное число." << endl;
	cout << "Re: ";
	cin >> a;
	cout << "Im: ";
	cin >> b;
	B->SetReIm(a, b);
	B->Out();
	B->Write();
	cout << endl << "Результаты действий:" << endl;
	C = A->Plus(B);
	C->Out();
	C->Write();
	D = A->Minus(B);
	D->Out();
	D->Write();
	cout << endl<<"Чтение из файла:" << endl;
	A->Read();
	FreeLibrary(hmodule);
	system("pause");
}