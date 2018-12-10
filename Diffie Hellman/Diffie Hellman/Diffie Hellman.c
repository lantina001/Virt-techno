#include<stdio.h> 
#include<math.h> 

/*Functie a a^m mod n te berekenen*/
int bereken(int a, int m, int n)
{
	int e;
	int x = 1;

	while (m > 0)
	{
		e = m % 2;
	
		if (e == 1)
			x = (x*a) % n;
		a = a * a % n;

		m = m / 2;
	}

	return x;
}

int main()
{
	
	int p = 23; //module	
	int g = 5; // base		

	int a, b;	// a - Geheime sleutel van Alice, b - Geheime sleutel van Bob.
	int A, B;	// A - Publieke sleutel van Alice, B - Publieke sleutel van Bob

	// Een geheime int voor Alice haar Privésleutel
	a = 6;		

	// berekening van Alice haar Publieke sleutel 
	A = bereken(g, a, p);

	// Een geheime int voor Bob zijn Privésleutel
	b = 15;		

	// berekening van Bob zijn Publieke sleutel
	B = bereken(g, b, p);

	// Alice and Bob wisselen hun publieke sleutel met elkaar uit
	int keyA = bereken(B, a, p);
	int keyB = bereken(A, b, p);

	printf("De geheime sleutel van Alice is %d\nBob's Secret Key is %d", keyA, keyB);

	return 0;
}
