#pragma once

class FirstComplex
{
public:
	virtual void Clear() = 0;
	virtual void Out() = 0;
	virtual void Ñonjugate() = 0;
	virtual void SetReIm(float a, float b) = 0;
	virtual float GetRe() = 0;
	virtual float GetIm() = 0;
	virtual FirstComplex* Plus(FirstComplex* B) = 0;
	virtual FirstComplex* Plus(float B) = 0;
	virtual FirstComplex* Minus(FirstComplex* B) = 0;
	virtual FirstComplex* Minus(float B) = 0;
	virtual FirstComplex* Multiply(FirstComplex* B) = 0;
	virtual FirstComplex* Multiply(float B) = 0;
	virtual FirstComplex* Divide(FirstComplex* B) = 0;
	virtual FirstComplex* Divide(float B) = 0;
	virtual FirstComplex* Power(int Power) = 0;
	virtual FirstComplex* Read() = 0;
	virtual void Write() = 0;
};