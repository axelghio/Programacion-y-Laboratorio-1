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


/** \brief                  PEDIR DATOS ANALIZARLOS VALIDARLOS Y MOSTRARLOS.
 * \param min int           DATO MINIMO A COMPARAR.
 * \param max int           DATO MAXIMO A COMPARAR.
 * \param dato int*         PUNTERO DATO.
 * \param intentos int      INTENTOS PARA REALIZAR OPERACION.
 * \param tipoDato char*    TIPO DE DATO A INGRESAR. Ejemplo, edad, numeros, letras, etc.
 * \param mensaje char*     MENSAJE A RECIBIR.
 * \param eMensaje char*    MENSAJE EN CASO DE ERROR.
 * \return int              DEVUELVE SI LA FUNCION FUNCIONO.
 */
int getData(int min, int max, int* dato, int intentos, char* tipoDato, char* mensaje, char* eMensaje);

int getInt(int* dato,)
