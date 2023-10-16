#define B 13
#define A 12
#define F 11
#define G 10
#define E 7
#define D 6
#define C 5
#define BOTON_INCREMENTAR 4
#define BOTON_DECREMENTAR 3
#define BOTON_REINICIAR 2
#define display_unidad A4
#define display_decena A5

int contador = 0;
int contadorDigito = 0;
int decena;
int unidad;
unsigned long tiempoAnterior = 0;
int intervaloDeTiempo = 200;

void encenderSegmento(int sf, int sa, int sb, int sg, int se, int sd, int sc);
void encenderDisplay(int estadoDecena, int estadoUnidades);

/**
 * @brief funcion que setea los pines de los display y los botones
 */
void setup()
{
    pinMode(A,OUTPUT);
    pinMode(B,OUTPUT);
    pinMode(C,OUTPUT);
    pinMode(D,OUTPUT);
    pinMode(E,OUTPUT);
    pinMode(F,OUTPUT);
    pinMode(G,OUTPUT);
    pinMode(BOTON_INCREMENTAR, INPUT_PULLUP);
    pinMode(BOTON_DECREMENTAR, INPUT_PULLUP);
    pinMode(BOTON_REINICIAR, INPUT_PULLUP);
    pinMode(display_unidad, OUTPUT);
    pinMode(display_decena, OUTPUT);
    Serial.begin(9600);

}

/**
 * @brief comienzo del contador numerico 
 */
void loop()
{
    unsigned long tiempoActual = millis();
    if (tiempoActual - tiempoAnterior >= intervaloDeTiempo) {
    tiempoAnterior = tiempoActual;

    if (digitalRead(BOTON_INCREMENTAR) == LOW)
    {
        contador = contador + 1;
        if(contador > 99)
        {
        contador = 0;
        }
    }

    if(digitalRead(BOTON_DECREMENTAR) == LOW)
    {
        contador = contador - 1;
        if(contador < 0)
        {
        contador = 99;
        }
    }
    if(digitalRead(BOTON_REINICIAR) == LOW)
    {
        contador = 0;
        decena = 0;
        unidad = 0;
    }
    }
    decena = contador / 10;
    unidad = contador % 10;

    SeleccionarNumero(decena);
    encenderDisplay(0,1);
    delay(10);
    encenderDisplay(1,1);

    SeleccionarNumero(unidad);
    encenderDisplay(1,0);
    delay(10);
    encenderDisplay(1,1);
}

/**
 * @brief funcion establece el estado de los display
 * @param sa posicion display A.
 * @param sb posicion display B.
 * @param sc posicion display C.
 * @param sd posicion display D.
 * @param se posicion display E.
 * @param sf posicion display F.
 * @param sg posicion display G.
 */
void encenderSegmento(int sf, int sa, int sb, int sg, int se, int sd, int sc)
{
    digitalWrite(F, sf);
    digitalWrite(A, sa);
    digitalWrite(B, sb);
    digitalWrite(G, sg);
    digitalWrite(E, se);
    digitalWrite(D, sd);
    digitalWrite(C, sc);
}

/**
 * @brief se establece el orden de display a utilizar
 * @param numero entero que representa el numero a listar
 */
void SeleccionarNumero(int numero)
{
    switch(numero)
    {
    case 0:
        encenderSegmento(1,1,1,0,1,1,1); 
        break;
    case 1: 
        encenderSegmento(0,0,1,0,0,0,1); 
        break;
    case 2: 
        encenderSegmento(0,1,1,1,1,1,0); 
        break;
    case 3: 
        encenderSegmento(0,1,1,1,0,1,1); 
        break;
    case 4: 
        encenderSegmento(1,0,1,1,0,0,1); 
        break;
    case 5: 
        encenderSegmento(1,1,0,1,0,1,1); 
        break;
    case 6: 
        encenderSegmento(1,1,0,1,1,1,1); 
        break;
    case 7: 
        encenderSegmento(0,1,1,0,0,0,1); 
        break;
    case 8:
        encenderSegmento(1,1,1,1,1,1,1); 
        break;
    case 9: 
        encenderSegmento(1,1,1,1,0,1,1); 
        break;
    }
}


/**
 * @brief establece el encendido de los display
 * @param estadoDecena estado del display de decenas
 * @param estadoUnidades estado del display de unidades
 */
void encenderDisplay(int estadoDecena, int estadoUnidades)
{
    digitalWrite(display_decena, estadoDecena);
    digitalWrite(display_unidad, estadoUnidades);
}


