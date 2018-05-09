//DESARROLLADOR:: ALFONSO PINTO 
//EL PROGRAMA SE DEDICA A ASIGNAR LAS 2 PLAZAS DE UN APARCAMIENTO, MOSTRANDO EL DINERO QUE SE DEBE PAGAR 
//EN FUNCION DEL TIEMPO
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<Windows.h>
#define N 5
#define M 10

struct coches {
	char matriculas_C[8];
	int matC;
	float tC[2];
	int pC;
};
struct motos {
	char matriculas_M[8];
	int matM;
	float tM[2];
	int pM;
};
struct usuario {
	char usuario[M];
	char password[M];
};


void main() {

	FILE *fichero;

	char seleccion; //eleccion en el switch

	int k;//bucle infinito
	int i; //Para poner el estado de aparcamiento a cero
	int j;//Para adjudicar el aparcamiento
	int compara_plaza;//Es el numero de plaza que le fue asignado
	int g; //Los uso como contador para ver si las matriculas son iguales
	int aux;//Lo uso para quedarme con un indice
	int dif; //lo uso para ver la diferencia entre a y A para pasar las letras de la matricula a mayusculas


	char vehiculo; //moto o coche
	char auxiliar[M]; //vale para comprobar la contraseña
	int comparar; //para comparar cadenas de caracteres
	char busca[8];

	float importe_estancia;


	struct coches clientes_C[N];
	struct motos clientes_M[N];
	struct usuario usuario[M];

	for (i = 0; i < N; i++) {
		clientes_C[i].matC = 0;
		clientes_C[i].pC = i + 1;
	}
	for (i = 0; i < N; i++) {
		clientes_M[i].matM = 0;
		clientes_M[i].pM = i + 1;
	}

	k = 1;
	dif = 'A' - 'a';


	//INICIO DE LA LECTURA DEL FICHERO

	//PROCEDEMOS A LA LECTURA DEL FICHERO
	errno_t error;
	error = fopen_s(&fichero, "Usuario.txt", "r");

	if (error == 0) {
		printf("Iniciando el programa ....\n No toques ningun boton...\n");
		Sleep(2000); //	QUIERO QUE PAREZCA QUE HACE ALGO 
	}
	else {
		printf("Ha habido un error \n");
	}

	for (i = 0; i < 3; i++) { //VAMOS A LEER EL NOMBRE DEL USUARIO Y SU CONTRASEÑA
		fscanf_s(fichero, "%s", &usuario[i].usuario, M);
		fscanf_s(fichero, "%s", &usuario[i].password,M);
	}
	fclose(fichero);

	//INICIAMOS EL PROCESO DE PETICION DE CONTRASEÑAS

	printf("BIENVENIDO AL APARCAMIENTO inicio su sesion(3 intentos) \n");
	for (j = 0; j < 3; j++){
		printf("Introduce tu nombre(usuario): \n");
			gets(auxiliar);
			for (i = 0; i < 3; i++) {
				comparar = strcmp(auxiliar, usuario[i].usuario);
					if (comparar == 0) {
						printf("Introduce la contrasena: \n");
							gets(auxiliar);
							comparar = strcmp(auxiliar, usuario[i].password);
							if (comparar == 0) {
								i = 10;
								j = 10;
							}
							else {
								printf("Contrasena incorrecta \n");
							}
					}
					else if((comparar==1)&&(i==3)){
						printf("Usuarion erroneo \n");
						i = 10;
					}
			}
	}
	if (i < 10) {
		return;
	}


	system("cls"); 
	


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

			switch (vehiculo) {
			case 'c':
			case 'C':
				g = 0;
				getchar();
				for (j = 0; j < N; j++) {
					if (clientes_C[j].matC == 0) {
						printf("Intrduzca su matricula (formato 1111NNN sin espacios): \n");
						gets(clientes_C[j].matriculas_C);
						i = 4;
						while (clientes_C[j].matriculas_C[i] != '\0') {
							if (clientes_C[j].matriculas_C[i] >= 'a' && 'z' >= clientes_C[j].matriculas_C[i]) {
								clientes_C[j].matriculas_C[i] = (dif + clientes_C[j].matriculas_C[i]);
							}
							i++;
						}
						for (i = 0; i < 7; i++) {
							if ((((clientes_C[j].matriculas_C[i]>'9') || (clientes_C[j].matriculas_C[i]<'0')) && (i<4)) || (((clientes_C[j].matriculas_C[i]<'A') || (clientes_C[j].matriculas_C[i]>'Z')) && (i>4))) {
								g++;
							}
						}
						if (g != 0) {
							printf("El formato introducido no es correcto.");
							getchar();
							j = N + N;
						}
						else {
							printf("Su plaza es la %d", clientes_C[j].pC);
							getchar();
							clientes_C[j].matC = 1;
							clientes_C[j].tC[0] = time(NULL);
							j = N + N;
						}
					}

				}
				break;
			case 'm':
			case 'M':
				g = 0;
				getchar();
				for (j = 0; j < N; j++) {
					if (clientes_M[j].matM == 0) {
						printf("Intrduzca su matricula (formato 1111NNN sin espacios): \n");
						gets(clientes_M[j].matriculas_M);
						i = 4;
						while (clientes_M[j].matriculas_M[i] != '\0') {
							if (clientes_M[j].matriculas_M[i] >= 'a' && 'z' >= clientes_M[j].matriculas_M[i]) {
								clientes_M[j].matriculas_M[i] = (dif + clientes_M[j].matriculas_M[i]);
							}
							i++;
						}
						for (i = 0; i < 7; i++) {
							if ((((clientes_M[j].matriculas_M[i]>'9') || (clientes_M[j].matriculas_M[i]<'0')) && (i<4)) || (((clientes_M[j].matriculas_M[i]<'A') || (clientes_M[j].matriculas_M[i]>'Z')) && (i>4))) {
								g++;
							}
						}
						if (g != 0) {
							printf("El formato introducido no es correcto.");
							getchar();
							j = N + N;
						}
						else {
							printf("Su plaza es la %d", clientes_M[j].pM);
							getchar();
							clientes_M[j].matM = 1;
							clientes_M[j].tM[0] = time(NULL);
							j = N + N;
						}
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

			switch (vehiculo) {
			case 'c':
			case 'C':
				printf("Introduzca el numero de plaza que le fue asignada: \n");
				scanf_s("%d", &compara_plaza);

				for (j = 0; j < N; j++) {
					if (compara_plaza == clientes_C[j].pC) {
						clientes_C[j].tC[1] = time(NULL);
						importe_estancia = (clientes_C[j].tC[1] - clientes_C[j].tC[0]);
						clientes_C[j].matC = 0;
						printf("El importe ha pagar por su estancia es: %.2f euros. \n", importe_estancia*0.001);
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
						clientes_M[j].tM[1] = time(NULL);
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
					printf("Plaza: %d \n\n", clientes_C[j].pC);
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
			g = 0;
			printf("Introduce el tipo de vehiculo que desea buscar: \n");
			printf("C-Para coche \n");
			printf("M-Para moto \n");
			getchar();
			scanf_s("%c", &vehiculo);
			switch (vehiculo) {
			case 'c':
			case 'C':
				printf("Introduzca la matricula: \n");
				getchar();
				gets(busca);


				for (j = 0; j < N; j++) {
					for (i = 0; i < 8; i++) {
						if (clientes_C[j].matriculas_C[i] == busca[i]) {
							g++;
						}
						else {
							g = 0;
						}
						if (g == 8) {
							aux = j;
							i = i + i; //para salir del bucle
							j = N + N; //para salir del bucle
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
					for (i = 0; i < 8; i++) {
						if (clientes_M[j].matriculas_M[i] == busca[i]) {
							g++;
						}
						else {
							g = 0;
						}
						if (g == 8) {
							aux = j;
							i = i + i; //para salir del bucle
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

