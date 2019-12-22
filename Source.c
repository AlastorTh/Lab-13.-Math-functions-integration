#include <stdio.h>
#include <locale.h>
#include <math.h>


#define PI 3.14159265


double Func1(double x) 
{
	return x + log(x + 0.5) - 0.5;
}

double Func2(double x) 
{
	return exp(-x) * cos(PI * x / 4);
}
void RootSeek() 
{
	double eps = 0.001; 
	double A = 0; 
	double B = 2; 
	double mid = (A + B) / 2; //
	while (fabs(Func1(mid)) > eps) 
	{
		mid = (A + B) / 2;
		if (fabs(Func1(mid))) 
		{
			if ((Func1(A) / Func1(mid)) < 0) 
			{
				B = mid;
			}
			if ((Func1(mid) / Func1(B)) < 0) 
			{
				A = mid;
			}
		}

	}
	printf("%s%f%s%f\n\n", "������ ��������� = ", mid, " �������� ������� = ", Func1(mid));
	return;
}

double countSum(int n, double A, double B) 
{
	double Sum = 0;
	int i = 0;
	double h = ((B - A) / n);
	for (i = 0; i < n - 1; i++)
	{
		Sum += Func2(A + h * i + h / 2) * h;

	}
	return Sum;
}

void Integration() 
{
	double A = 0;
	double B = 2;
	double eps = 0.0005;
	int n = 10; 
	while (fabs(countSum(n, A, B) - countSum(n - 1, A, B)) > eps) 
	{
		n++;
		printf("%s%d", "��� N = ", n);
		printf("%s%f\n", " �������� ��������� = ", countSum(n, A, B));
	}
	printf("%s%f\n\n", "\n�������� �������� ��������� = ", countSum(n, A, B));
	return;
}





int main()
{
	setlocale(LC_ALL, "Rus");
	system("color F0");
	RootSeek();
	
	printf("%s\n\n", "���������� ���������: ");
	Integration();

	return 0;
}