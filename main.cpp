
#include "Funciones_clases_y_metodos.h"

int main()
{
	infija2posfija ip2;
	char str[] = "54/(33+23)-765";
	char str1[] = "76x235/(37+89)";
	char str2[] = "2^3x45-6/(2+3)";
	char str4[] = "(312+542)x5/56";
	char str5[] = "29x657/(68+23)";
	//char str0[] = "              ";
	
	
	int ww = 1;
	while (ww == 1) {
	int op;

	char str0[] = "                   ";

	
	cout << "       EJEMPLOS      " << endl;
	cout << "---------------------" << endl;
	cout << "1 >>>> 23-765+(54/33)" << endl;
	cout << "2 >>>> 76x235/(37+89)" << endl;
	cout << "3 >>>> 2^3x45-6/(2+3)" << endl;
	cout << "4 >>>> 5/56x(312+542)" << endl;
	cout << "5 >>>> 29x657/(68+23)" << endl;
	cout << "---------------------" << endl;
	cout << "6 >>>> Introducir una"  << endl;
	cout << "       Expresión" << endl;
	cout << "7 >>>> Salir" << endl;
	
	cin >> op;
	
	switch (op) {
		case 1:
			ip2.i2p(str);
			break;
		case 2:
			ip2.i2p(str1);
			break;
		case 3:
			ip2.i2p(str2);
			break;
		case 4:
			ip2.i2p(str4);
			break;
		case 5:
			ip2.i2p(str5);
			break;
		case 6:
			cout << "Introduzca una expresión de no mas de 14 carácteres." << endl;
			cout << "              ." << endl;

			cin >> str0;

			if (str0[16] != ' ') {
				cout << "ERROR2: has escrito demasiados caracteres." << endl;
			}else {

				cout << endl;
				
				ip2.i2p(str0);
			}

			
			break;

		case 7:
			cout << "Fin del programa" << endl;
			ww = 0;
			break;


		default:
			cout << "ERROR1: Opción incorrecta." << endl;
			cout << "introduzca una opción correcta" << endl;
			break;
	}
	}

	
	return 0;
}

