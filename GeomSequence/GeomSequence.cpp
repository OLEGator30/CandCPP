#include <stdio.h>

class FloatSequence
{

}

class GeometricSequence
{

}

class BadAddition
{

}

int main()
{
	try
	{
		GeometricSequence a(1,2);
		GeometricSequence b(0.25,2);
		GeometricSequence c(16,0.5);
		printf("%3.3f %3.3f %3.3f\n",a[0],b[3],c[2]);
		printf("%3.3f\n",(a+b)[1]);
		printf("%3.3f\n",(a+c)[1]);
	}
	catch(const BadAddition &x)
	{
		printf("Bad addition: %3.3f %3.3f\n",x.Get1(),x.Get2());
	}
	return 0;
}
