#include <stdio.h>

class scanner
{
	enum States { H, A, B };
	States St;

	public:

	scanner(): St(H) {}
	void newchar(int c);
};

void scanner::newchar(int c)
{
	switch (St)
	{
		case H:
			if ((c!='0')&&(c!='1'))
				throw 1;
			St=B;
			break;
		case B:
			if ((c!='0')&&(c!='1')&&(c!='.'))
				throw 1;
			else if (c=='.')
				St=A;
			break;
		case A:
			if ((c!=EOF)&&(c!='0')&&(c!='1'))
				throw 1;
	}
}

int main()
{
	int c;
	scanner scan;

	try
	{
		do
		{
			c=getchar();
			scan.newchar(c);
		} while (c!=EOF);
	}
	catch (...) { printf("!!\n"); return 1;}

	printf("success\n");
	return 0;
}
