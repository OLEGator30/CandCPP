#include <stdio.h>

class FloatSequence
{
	float first;

	public:

	FloatSequence (float a): first(a) {}
	float operator[] (int) const;
	virtual float Elem (int) const =0;
	virtual ~FloatSequence() {}
};

class GeometricSequence : public FloatSequence
{
	float q;

	public:

	GeometricSequence (float a,float b): FloatSequence(a), q(b) {}
	virtual float Elem (int) const;
	GeometricSequence operator+ (GeometricSequence);
	virtual ~GeometricSequence() {}
};

class BadAddition
{
	float a,b;

	public:

	BadAddition (float A,float B): a(A), b(B) {}
	float Get1() const { return a; }
	float Get2() const { return b; } 
};


float FloatSequence::operator[] (int idx) const
{
	if (idx>0) return Elem(idx);
	else
		if (idx==0) return first;
		else throw idx;
}

float GeometricSequence::Elem (int idx) const
{
	float res=(*this)[0];

	for (int i=0;i<idx;++i)
		res*=q;

	return res;
}

GeometricSequence GeometricSequence::operator+ (GeometricSequence A)
{
	if (q!=A.q)
		throw BadAddition(q,A.q);
	return GeometricSequence((*this)[0]+A[0],q);
}

int main()
{
	try
	{
		GeometricSequence a(1,2);
		GeometricSequence b(0.25,2);
		GeometricSequence c(16,0.5);
		printf("%3.3f %3.3f %3.3f\n",a[0],b[3],c[2]);
		//printf("%3.3f\n",a[-6]);
		printf("%3.3f\n",(a+b)[1]);
		printf("%3.3f\n",(a+c)[1]);
	}
	catch (const BadAddition &x)
		{ printf("Bad addition: %3.3f %3.3f\n",x.Get1(),x.Get2()); }
	catch (int &idx)
		{	printf("Negative index: %d\n",idx); }
	return 0;
}
