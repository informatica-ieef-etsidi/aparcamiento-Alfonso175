//DESARROLLADOR:: ALFONSO PINTO 
//EL PROGRAMA SE DEDICA A ASIGNAR LAS 2 PLAZAS DE UN APARCAMIENTO, MOSTRANDO EL DINERO QUE SE DEBE PAGAR 
//EN FUNCION DEL TIEMPO
#include<stdio.h>
#include<time.h>
#include<string.h>
#define N 5

struct coches{
	char matriculas_C[8];
	int matC;
	float tC[2];
	int pC;
};
struct motos{
	char matriculas_M[8];
	int matM;
	float tM[2];
	int pM;
};


void main() {
	
	char seleccion; //eleccion en el switch

	int k;//bucle infinito
	int i; //Para poner el estado de aparcamiento a cero
	int j;//Para adjudicar el aparcamiento
	int compara_plaza;
	int g;
	int l;
	int aux;
	int dif;
	int m;

	char vehiculo; //moto o coche
	char busca[8];

	float importe_estancia;


	struct coches clientes_C[N];
	struct motos clientes_M[N];

	for (i = 0; i < N; i++) {
		 clientes_C[i].matC =  0 ;
		 clientes_C[i].pC = i + 1;
	}
	for (i = 0; i < N; i++) {
		clientes_M[i].matM = 0;
		clientes_M[i].pM = i + 1;
	}
	k = 1;
	g = 0;
	dif = 'A' - 'a';
	m = 0;

	//esta parte es para la hora 
	
		struct tm newtime;
		char am_pm[] = "AM";
		__time64_t long_time;
		char timebuf[26];
		errno_t err;

		// Get time as 64-bit integer.  
		_time64(&long_time);
		// Convert to local time.  
		err = _localtime64_s(&newtime, &long_time);
		if (err)
		{
			printf("Invalid argument to _localtime64_s.");
			exit(1);
		}
		if (newtime.tm_hour > 12)        // Set up extension.   
			strcpy_s(am_pm, sizeof(am_pm), "PM");
		if (newtime.tm_hour > 12)        // Convert from 24-hour   
			newtime.tm_hour -= 12;    // to 12-hour clock.   
		if (newtime.tm_hour == 0)        // Set hour to 12 if midnight.  
			newtime.tm_hour = 12;

		// Convert to an ASCII representation.   
		err = asctime_s(timebuf, 26, &newtime);
		if (err)
		{
			printf("Invalid argument to asctime_s.");
			exit(1);
		}
		//printf("%.19s %s\n", timebuf, am_pm);
		
	



	do {
		printf("Fecha y hora de apertura del programa %.19s %s\n", timebuf, am_pm);
		printf("Bienvenido al programe de seleccion de aparcamiento \n");
		printf("Seleccion una de estas opciones \n");
		printf("R - Reservar plaza \n");
		printf("A - Abandonar plaza \n");
		printf("E - Estado del aparcamiento \n");
		printf("B - Buscar vehiculo por matricula \n"); 
		printf("S - Salir del programa \n");

		scanf_s("%c", &seleccion);

		system("cls");
		

		switch (seleccion) {
			case 'r':
			case 'R':
				printf("Introduzca el tipo de vehiculo: \n");
				printf("C-Para coche \n");
				printf("M-Para moto \n");
				getchar();
				scanf_s("%c", &vehiculo);

					switch (vehiculo){
					case 'c':
					case 'C':
						getchar();
						for (j = 0; j < N; j++) {
							if (clientes_C[j].matC == 0) {
								clientes_C[j].matC = 1;
								clientes_C[j].tC[0] = time(NULL);
								printf("Intrduzca su matricula (formato 1111NNN sin espacios): \n");
								gets(clientes_C[j].matriculas_C);
								m = 4;
									while (clientes_C[j].matriculas_C[m] != '\0') {
										if (clientes_C[j].matriculas_C[m] >= 'a' && 'z' >= clientes_C[j].matriculas_C[m]) {
											clientes_C[j].matriculas_C[m] = (dif + clientes_C[j].matriculas_C[m]);
										}
										m++;
									}
								printf("Su plaza es la %d", clientes_C[j].pC);
								getchar();
								j = N + N;
							}
							
						}
						break;
					case 'm':
					case 'M':
						getchar();
						for (j = 0; j < N; j++) {
							if (clientes_M[j].matM == 0) {
								clientes_M[j].matM = 1;
								clientes_M[j].tM[0] = time(NULL);
								printf("Intrduzca su matricula (formato 1111NNN sin espacios): \n");
								gets(clientes_M[j].matriculas_M);
								m = 4;
								while (clientes_M[j].matriculas_M[m] != '\0') {
									if (clientes_M[j].matriculas_M[m] >= 'a' && 'z' >= clientes_M[j].matriculas_M[m]) {
										clientes_M[j].matriculas_M[m] = (dif + clientes_M[j].matriculas_M[m]);
									}
									m++;
								}
								printf("Su plaza es la %d \n", clientes_M[j].pM);
								getchar();
								j = N + N;
							}

						}
						break;

					default:
						getchar();
						printf("No ha hecho una seleccion permitida\n");
						break;
					}

				break;

			case 'a':
			case 'A':
				printf("Para poder sacar el vehiculo debe introducir el numero de plaza que le fue asignado. En caso de no acordarse de ella, puede \n");
				printf("encontrala buscando su vehiculo por matricula. \n");
				printf("Introduzca el tipo de vehiculo que desea retirar: \n");
				printf("C-Para coche \n");
				printf("M-Para moto \n");
				printf("X-Para salir al menu principal\n");
				getchar();
				scanf_s("%c", &vehiculo);
				
					switch (vehiculo){
						case 'c':
						case 'C':
							printf("Introduzca el numero de plaza que le fue asignada: \n");
							scanf_s("%d", &compara_plaza);
							
								for (j = 0; j < N; j++) {
									if (compara_plaza == clientes_C[j].pC) {
										clientes_C[j].tC[1] = time(NULL);
										importe_estancia = (clientes_C[j].tC[1] - clientes_C[j].tC[0]);
										clientes_C[j].matC = 0;
										printf("El importe ha pagar por su estancia es: %.2f euros. \n",importe_estancia*0.001);
										printf("Esperamos quye vuelva pronto\n");
										system("pause");
									}
								}
							break;

						case 'm':
						case 'M':
							printf("Introduce el numero de plaza que le fue asignada:");
							scanf_s("%d", &compara_plaza);

								for (j = 0; j < N; j++) {
									if (compara_plaza == clientes_M[j].pM) {
										clientes_M[j].tM[1]= time(NULL);
										importe_estancia = (clientes_M[j].tM[1] - clientes_M[j].tM[0]);
										clientes_M[j].matM = 0;
										printf("El importe ha pagar por su estancia es: %.2f euros. \n", importe_estancia*0.001);
										printf("Esperamos que vuelva pronto.");
										system("pause");
									}
								}

							break;

						case 'x':
						case 'X':
							break;
						default:
							break;
					}
				break;

			case 'e':
			case 'E':
				printf("El estado actual del aparcamiento es: \n\n");
				printf("COCHES: \n");

					for (j = 0; j < N; j++) {
						if (clientes_C[j].matC == 1) {
							printf("Matricula:");
							puts(clientes_C[j].matriculas_C);
							printf("Plaza: %d \n\n",clientes_C[j].pC);
						}
					}

					printf("MOTOS: \n");

						for (j = 0; j < N; j++) {
							if (clientes_M[j].matM == 1) {
								printf("Matricula:");
								puts(clientes_M[j].matriculas_M);
								printf("Plaza: %d\n\n", clientes_M[j].pM);
							}
						}

					system("pause");
					
				break;

			case 'b':
			case 'B':
				printf("Introduce el tipo de vehiculo que desea buscar: \n");
				printf("C-Para coche \n");
				printf("M-Para moto \n");
				getchar();
				scanf_s("%c", &vehiculo);
					switch (vehiculo){
						case 'c':
						case 'C':
							printf("Introduzca la matricula: \n");
							getchar();
							gets(busca);
							
							
								for (j = 0; j < N; j++) {
									for (l = 0; l < 8; l++) {
										if (clientes_C[j].matriculas_C[l] == busca[l]) {
											g++;
										}
										else {
											g = 0;
										}
										if (g == 8) {
											aux = j;
											l = l + l; //para salir del bucle
											j = N+N; //para salir del bucle
										}
									
									}
								}
								if (g == 8) {
									printf("Su matricula es: \n");
									puts(clientes_C[aux].matriculas_C);
									printf("Su plaza es la n %d \n", clientes_C[aux].pC);
									
								}
								else {
									printf("No hay coincidencias\n");
								}
								system("pause");
							break;

						case 'm':
						case 'M':
							printf("Introduzca la matricula: \n");
							getchar();
							gets(busca);


							for (j = 0; j < N; j++) {
								for (l = 0; l < 8; l++) {
									if (clientes_M[j].matriculas_M[l] == busca[l]) {
										g++;
									}
									else {
										g = 0;
									}
									if (g == 8) {
										aux = j;
										l = l + l; //para salir del bucle
										j = N + N; //para salir del bucle
									}

								}
							}
							if (g == 8) {
								printf("Su matricula es: \n");
								puts(clientes_M[aux].matriculas_M);
								printf("Su plaza es la n %d \n", clientes_M[aux].pM);

							}
							else {
								printf("No hay coincidencias\n");
							}
							system("pause");
							break;

						default:
							break;
					}



				break;


			case 's':
			case 'S':
				k = 73; //el 73 es un gran numero
				break;



			default:
			
				break;
		}
		system("cls");
	} while (k == 1);

	system("pause");
}

