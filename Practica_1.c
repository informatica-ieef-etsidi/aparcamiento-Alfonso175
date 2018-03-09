//DESARROLLADOR:: ALFONSO PINTO 
//EL PROGRAMA SE DEDICA A ASIGNAR LAS 2 PLAZAS DE UN APARCAMIENTO, MOSTRANDO EL DINERO QUE SE DEBE PAGAR 
//EN FUNCION DEL TIEMPO
#include<stdio.h>
#include<time.h>

void main() {
	
	char seleccion;
	float p1;
	float p2;
	p1 = 0;
	p2 = 0;

	int k;
	int i;
	k = 1;

	char m1[10];  //matricula del coche en la plaza 1
	char m2[10];  //matricula del coche en la plaza 2
	int t1i, t1f;
	int t2i, t2f;
	int k1, k2;


	do {
		printf("Bienvenido al programe de seleccion de aparcamiento \n");
		printf("Seleccion una de estas opciones \n");
		printf("R - Reservar plaza \n");
		printf("A - Abandonar plaza \n");
		printf("E - Estado del aparcamiento \n");
		scanf_s("%c", &seleccion);

		system("cls");


		switch (seleccion) {
		case 'r':
		case 'R':

			if (p1 == 0) {
				getchar();
				printf("Su plaza es la 1. Introduzca su matricula (de la forma 1111 AAA con las letras en mayusculas): \n");
				gets(m1);
				t1i = time(NULL);
				p1 = 1;
			}
			else if (p2 == 0) {
				getchar();
				printf("Su plaza es la 2. Introduzca su matricula (de la forma 1111 AAA con las letras en mayusculas):\n");
				gets(m2);
				t2i = time(NULL);
				p2 = 1;
			}
			else {
				getchar();
				printf("No quedan plazas libres \n");
				system("pause");
			}
			break;

		case 'a':
		case 'A':
			printf("Introduce el numero de plaza que te ha sido asiganado \n");
			scanf_s("%d", &i);
			getchar();
				if ((i == 1)&&(p1==1)) {
					p1 = 0;
					printf("Ha abandonado la plaza. Esperamos que vuelva pronto \n");
					t1f = time(NULL);
					printf("Tiene que pagar en total %.2f euros ",(t1f-t1i)*0.001);
					
				}
				else if ((i == 1) && (p1 == 0)) {
					printf("La plaza seleccionada esta libre, debe volver a introducir el numero de plaza \n");
				}
				else if ((i == 2)&&(p2==1)) {
					p2 = 0;
					printf("Ha abandonado la plaza. Esperamos que vuelva pronto \n");
					t2f = time(NULL);
					printf("Tiene que pagar en total %.2f euros ", (t2f - t2i)*0.001);
				}
				else if ((i == 2) && (p2 == 0)) {
					printf("La plaza seleccionada esta libre, debe volver a introducir el numero de plaza \n");
				}
				
			system("pause");
			break;

		case 'e':
		case 'E':
			getchar();
			if (p1 == 1) {
				printf("Plaza 1 - Ocupada - Matricula:  \n");
				puts(m1);
				t1f = time(NULL);
				printf("De momento debe pagar %.2f euros \n\n\n", (t1f - t1i)*0.001);
			}
			else {
				printf("Plaza 1 - Libre \n\n\n");
			}
			if (p2 == 1) {
				printf("Plaza 2 - Ocupada - Matricula:  \n");
				puts(m2);
				t2f = time(NULL);
				printf("De momento debe pagar %.2f euros \n\n\n", (t2f - t2i)*0.001);
			}
			else {
				printf("Plaza 2 - Libre \n\n\n");
			}
			system("pause");
			break;

		default:
			getchar();
			printf("Lo lamento, no ha seleccionado ninguno de los caracteres validos \n");
			system("pause");
			break;
		}
		system("cls");
	} while (k = 1);

	system("pause");
}

