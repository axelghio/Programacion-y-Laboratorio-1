#include "sectores.h"
typedef struct
{
    int dia, mes, anio;
} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int ocupado;
    eFecha fechaNac;
    int idSector;

} eEmpleado;

/** \brief                  SUMA DOS OPERANDOS.
 * \param numeroX float     PRIMER OPERANDO.
 * \param numeroY float     SEGUNDO OPERANDO.
 * \return float            RESULTADO DE LA SUMA.
 */
float sumar(float numeroX, float numeroY);

/** \brief                  RESTA DOS OPERANDOS.
 * \param numeroX float     PRIMER OPERANDO.
 * \param numeroY float     SEGUNDO OPERANDO.
 * \return float            RESULTADO DE LA RESTA.
 */
float restar(float numeroX, float numeroY);

/** \brief                  DIVIDE ENTRE DOS OPERANDOS, VERIFICA SI SE INGRESA 0.
 * \param numeroX float     PRIMER OPERANDO.
 * \param numeroY float     SEGUNDO OPERANDO
 * \return float            DEVUELVE RESULTADO DE DIVISION.
 */
float dividir(float numeroX, float numeroY);

/** \brief                  MULTIPLICA DOS OPERANDOS. VERIFICA QUE EL OPERANDOS B NO SEAN 0.
 * \param numeroX float     PRIMER OPERANDO.
 * \param numeroY float     SEGUNDO OPERANDO.
 * \return float            DEVUELVE RESULTADO DE MULTIPLICACION.
 */
float multiplicar(float numeroX, float numeroY);

/** \brief                  SACA FACTORIAL DEL NUMERO A QUE PEDIMOS.
 * \param numeroX int       NUMERO QUE NOS BRINDA EL USUARIO. VERIFICA SI EL NUMERO ES 0.
 * \return unsigned long    RESULTADO FACTORIAL NUMERO X. RETORNA EL RESULTADO FACTORIAL DEL NUMERO QUE NOS MANDO EL USUARIO.
 */
unsigned long factorial(int numero);

/** \brief                  PEDIR DATOS ENTEROS ANALIZARLOS VALIDARLOS Y MOSTRARLOS.
 * \param min int           DATO MINIMO A COMPARAR.
 * \param max int           DATO MAXIMO A COMPARAR.
 * \param dato int*         PUNTERO DATO.
 * \param intentos int      INTENTOS PARA REALIZAR OPERACION.
 * \param tipoDato char*    TIPO DE DATO A INGRESAR. Ejemplo: edad, numeros, letras, etc.
 * \param mensaje char*     MENSAJE A RECIBIR.
 * \param eMensaje char*    MENSAJE EN CASO DE ERROR.
 * \return int              DEVUELVE SI LA FUNCION FUNCIONO.
 */
int getData(int min, int max, int* dato, int intentos, char* tipoDato, char* mensaje, char* eMensaje);

/** \brief                  PEDIMOS UN MENSAJE Y EL INGRESO DE UN NUMERO ENTERO.
 * \param char* int         PUNTERO A CHAR QUE VA A SER EL MENSAJE QUE VAMOS A MOSTAR.
 * \return int              DEVUELVE EL ENTERO.
 */
int getInt(char* mensaje);

/** \brief                  PIDE UN FLOAT Y LO DEVUELVE
 * \param numero float      FLOAT A PEDIR.
 * \return float            DEVUELVE FLOAT.
 */
float getFloat(char* mensaje);

/** \brief                  PIDE UN CHAR Y LO DEVUELVE
 * \param texto char        CHAR A PEDIR.
 * \return char             DEVUELVE CHAR.
 */
char getChar(char* mensaje);

/** \brief                  PEDIMOS UN NUMERO VALIDAMOS QUE NO SEA O CONTENGA LETRAS.
 * \param cadena char*      PUNTERO A CADENA DONDE NOS INGRESARA LOS DATOS A ANALIZAR.
 * \return int              DEVUELVE SI FUNCIONO LA OPERACION.
 */
int esNumerico(char cadena[]);

/** \brief                  VALIDA QUE SOLO SEAN LETRAS LAS INGRESADAS.
 * \param cadena[] char     RECIBE UN PUNTERO A CADENA CON LA INFO DEL USUARIO.
 * \return int              DEVUELVE SI SE PUDO REALIZAR ACCION.
 */
int esSoloLetras(char cadena[]);

/** \brief                  VALIDA SI SE INGRESA ALFA NUMERICOS.
 * \param cadena[] char     RECIBE UN PUNTERO A CADENA CON LA INFO DEL USUARIO.
 * \return int              DEVUELVE SI PUDO REALIZAR ACCION.
 */
int esAlfaNumerico(char cadena[]);

/** \brief                  VALIDA SI ES TELEFONO.
 * \param cadena[] char     RECIBE UN PUNTERO A CADENA CON LA INFO DEL USUARIO.
 * \return int              DEVUELVE SI REALIZO OPERACION.
 */
int esTelefono(char cadena[]);

/** \brief                  ORDENA UN ARRAY
 * \param cadena[] char     RECIBE UNA CADENA SEA CUAL SEA.
 * \param largoCadena int   RECIBE UN LARGO DE LA CADENA.
 * \param signo char        RECIBE UN SIGNO PARA SABER DE QUE MANERA QUEREMOS ORDENARLA, EJ.: <  menor, >  mayor.
 * \return int              DEVUELVE ENTERO PARA SABER SI SE PUDO REALIZAR ACCION.
 */
int burbujeo(char cadena[],int largoCadena,char signo);

/** \brief                  RECIVE UN VECTOR DE CADENA Y LO SETEA EN SU ESTADO OCUPADO EN '0'.
 * \param vec[] eEmpleado   EL VECTOR A RECIBIR.
 * \param tam int           EL TAMA�O DE ESE VECTOR.
 * \return void             NO RETORNA NADA.
 */
void inicializarEmpleados(eEmpleado vec[], int tam);

/** \brief                  ESTA FUNCION LO QUE HACE ES MOSTRAR UN MENU ABM.
 * \return int              RETORNA OPCION INGRESADA.
 */
int menu();

/** \brief                  IMPRIME UN EMPLEADOS QUE SE HAYA CARGADO PREVIAMENTE.
 * \param emp eEmpleado     RECIBE la variable emp de la estructura eEmpleado.
 * \return void
 */
void mostrarEmpleado(eSector sector, int tam, int id, char desc[], eEmpleado emp);

/** \brief                  IMPRIME UNA LISTA DE EMPLEADOS QUE SE HAYAN CARGADO PREVIAMENTE.
 * \param vec[] eEmpleado   RECIBE VECTOR A RECORRER CON LOS EMPLEADOS CARGADOS PREVIAMENTE.
 * \param tam int           TAMA�O DEL VECTOR A RECORRER.
 * \return void             NO RETORNA NADA.
 */
void mostrarEmpleados(eEmpleado vec[], int tam);

void mostrarEmpleadoOrden(eEmpleado emp);

void mostrarEmpleadosOrdenados(eEmpleado vec[], int tam);

/** \brief                  ESTA FUNCION LO QUE HACES ES BUSCAR ESPACIO LIBRE PARA AGREGAR UN NUEVO EMPLEADO.
 * \param vec[] eEmpleado   RECIBE UN VECTOR ARRAY DE LA ESTRUCTURA eEMPLEADOS.
 * \param tam int           RECIBE EL TAMA�O DE ESE VECTOR.
 * \return int              RETORNA EL INDICE DEL VECTOR A DONDE SE VA A CARGAR EL NUEVO EMPLEADO.
 */
int buscarLibre(eEmpleado vec[], int tam);

/** \brief                  ESTA FUNCION BUSCA POR ESTADO Y LEGAJO.
 * \param vec[] eEmpleado   RECIBE VECTOR DE LA ESTRUCTURA eEMPLEADOS.
 * \param tam int           RECIBE UN TAMA�O DE ESE VECTOR.
 * \param legajo int        RECIBE UN LEGAJO QUE ES EL ID DE LA PERSONA A BUSCAR.
 * \return int              RETORNA EL ID LEGAJO DE ESA PERSONA SI SE ENCONTRO.
 */
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);

/** \brief                  FUNCION PRINCIPAL QUE INGRESA UN NUEVO USUARIO AL ABM EMPLEADOS.
 * \param vec[] eEmpleado   RECIBE UN VEC EMPLEADOS DE LA ESTRUCTURA eEMPLEADOS.
 * \param tam int           RECIBE EL TAMA�O DE DICHO VECTOR.
 * \return void             NO RETORNA NADA.
 */
void altaEmpleado(eEmpleado vec[], int tam);

void listaSector();

/** \brief                  FUNCION QUE DA DE BAJA A UN EMPLEADO.
 * \param eEmpleado vec[]   RECIBE UN VEC DE LA ESTRUCTURA eEMPLEADO.
 * \param int tam           RECIBE TAMA�O DE VEC.
 * \param int legajo        RECIBE LEGAJO DE PERSONA A BUSCAR PARA LA BAJA.
 * \return void             NO DEVUELVE NADA.
 */
void bajaEmpleado(eEmpleado vec[], int tam);

/** \brief                  FUNCION QUE VA A PEDIR UN LEGADO Y VA A DEJAR MODIFICARLO.
 * \param vec[] eEmpleado   RECIBE VECTOR EMPLEADOS.
 * \param tam int           RECIBE TAMA�O DE VECTOR
 * \return void             NO DEVUELVE NADA.
 */
void modificarEmpleado(eEmpleado vec[], int tam);


/** \brief
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void listar(eEmpleado vec[], int tam);

/** \brief                  MUESTRA UN SUBMENU PARA LA MODIFICACION DE EMPLEADOS.
 * \return int              DEVUELVE INDICE DEL MENU.
*/
int menuMod();

int ordenarEmpleados(eEmpleado vec[], int tam);

int opcionOrdenar();
