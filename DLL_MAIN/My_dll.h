#pragma once

class FirstComplex
{
public:
	virtual void Out() = 0;
	virtual void SetReIm(float a, float b) = 0;
	virtual float GetRe() = 0;
	virtual float GetIm() = 0;
	virtual FirstComplex* Plus(FirstComplex* B) = 0;
	virtual FirstComplex* Minus(FirstComplex* B) = 0;
	virtual void Read() = 0;
	virtual void Write() = 0;
};