#include "stdafx.h"
#include "My_dll.h"
#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

class Complex : public FirstComplex
{
private:
	float re;
	float im;
public:
	Complex()
	{
		re = 0;
		im = 0;
	}
	Complex(float x, float y)
	{
		re = x;
		im = y;
	}
	~Complex()
	{
	}
	void Clear()
	{
		delete this;
	}
	void Out()
	{
		std::cout << re;
		if (im > 0) std::cout << "+";
		if (im != 0) std::cout << im << "i\n";
	}
	void Сonjugate()
	{
		im = im * (-1);
	}
	float GetRe()
	{
		return re;
	}
	float GetIm()
	{
		return im;
	}
	void SetReIm(float a, float b)
	{
		re = a;
		im = b;
	}
	FirstComplex* Plus(FirstComplex* B)
	{
		FirstComplex* C = new Complex;
		C->SetReIm(GetRe() + B->GetRe(), GetIm() + B->GetIm());
		return C;
	}
	virtual FirstComplex* Plus(float B)
	{
		FirstComplex* C = new Complex;
		C->SetReIm(GetRe() + B, GetIm());
		return C;
	}
	FirstComplex* Minus(FirstComplex* B)
	{
		FirstComplex* C = new Complex;
		C->SetReIm(GetRe() - B->GetRe(), GetIm() - B->GetIm());
		return C;
	}
	FirstComplex* Minus(float B)
	{
		FirstComplex* C = new Complex;
		C->SetReIm(GetRe() - B, GetIm());
		return C;
	}
	FirstComplex* Multiply(FirstComplex* B)
	{
		FirstComplex* C = new Complex;
		C->SetReIm((GetRe()*B->GetRe()) - (GetIm()*B->GetIm()), ((GetRe()*B->GetIm()) + (GetIm()*B->GetRe())));
		return C;
	}
	FirstComplex* Multiply(float B)
	{
		FirstComplex* C = new Complex;
		C->SetReIm((GetRe()*B), (GetIm()*B));
		return C;
	}
	FirstComplex* Divide(FirstComplex* B)
	{
		FirstComplex* C = new Complex;
		float x, y;
		x = ((GetRe()*B->GetRe() + GetIm()*B->GetIm()) / (B->GetRe()*B->GetRe() + B->GetIm()*B->GetIm()));
		y = ((GetIm()*B->GetRe() - GetRe()*B->GetIm()) / (B->GetRe()*B->GetRe() + B->GetIm()*B->GetIm()));
		C->SetReIm(x, y);
		return C;
	}
	FirstComplex* Divide(float B)
	{
		FirstComplex* C = new Complex;
		C->SetReIm((GetRe()*B) / (B*B), (GetIm()*B) / (B*B));
		return C;
	}
	FirstComplex* Power(int Power)
	{
		FirstComplex* C = new Complex;
		C->SetReIm(GetRe(), GetIm());
		if (Power > 0)
		{
			for (int i = 1; i < Power; i++)
			{
				C = C->Multiply(this);
			}
		}
		return C;
	}
	void Write()//запись в двоичный файла комплексного числа
	{
		FirstComplex* C = new Complex;
		C->SetReIm(GetRe(), GetIm());
		ofstream f_bin("binIn.txt", ios::binary);
		f_bin.write((char*)&C, sizeof(Complex));
		f_bin.close();
	}
	FirstComplex* Read()//считывание из двоичного файла комплексного числа
	{
		FirstComplex* C = new Complex;
		C->SetReIm(GetRe(), GetIm());
		ifstream f_bin("binIn.txt", ios::binary | ios::app);
		f_bin.read((char*)&C, sizeof(Complex));
		f_bin.close();
		return C;
	}
};


extern "C" __declspec(dllexport) FirstComplex* __cdecl CreateClass()
{
	FirstComplex* A = new Complex;
	return A;
}




