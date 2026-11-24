/**
 * Control de dos LED mediante comandos recibidos por comunicacion serial.
 *
 * Conexiones
 *   LED verde  pin digital 2 con resistencia de 220 ohmios a GND
 *   LED rojo   pin digital 3 con resistencia de 220 ohmios a GND
 *
 * Comunicacion serial a 9600 baudios.
 *
 * Comandos
 *   V  enciende el LED verde
 *   R  enciende el LED rojo
 *   A  enciende ambos LED
 *   0  apaga ambos LED
 *   Cualquier otro caracter se notifica como comando invalido.
 */

const unsigned long BAUDIOS = 9600;
const uint8_t PIN_LED_VERDE = 2;
const uint8_t PIN_LED_ROJO = 3;

/**
 * Fija el estado de ambos LED.
 *
 * @param verdeEncendido true para encender el LED verde, false para apagarlo
 * @param rojoEncendido  true para encender el LED rojo, false para apagarlo
 */
void establecerLeds(bool verdeEncendido, bool rojoEncendido) {
  digitalWrite(PIN_LED_VERDE, verdeEncendido ? HIGH : LOW);
  digitalWrite(PIN_LED_ROJO, rojoEncendido ? HIGH : LOW);
}

/**
 * Configura los pines de los LED como salidas y los deja apagados.
 */
void configurarLeds() {
  pinMode(PIN_LED_VERDE, OUTPUT);
  pinMode(PIN_LED_ROJO, OUTPUT);
  establecerLeds(false, false);
}

/**
 * Inicia la comunicacion serial, configura los LED e informa
 * que el sistema esta listo.
 */
void setup() {
  Serial.begin(BAUDIOS);
  configurarLeds();
  Serial.println("Comandos validos V, R, A, 0");
}

/**
 * Interpreta un comando y actualiza el estado de los LED.
 * Cada comando valido deja los LED en el estado indicado, sin
 * conservar el estado anterior. Responde por el monitor serial
 * con el resultado de la accion.
 *
 * @param comando caracter recibido por la comunicacion serial
 */
void ejecutarComando(char comando) {
  switch (comando) {
    case 'V':
      establecerLeds(true, false);
      Serial.println("LED verde encendido");
      break;
    case 'R':
      establecerLeds(false, true);
      Serial.println("LED rojo encendido");
      break;
    case 'A':
      establecerLeds(true, true);
      Serial.println("Ambos LED encendidos");
      break;
    case '0':
      establecerLeds(false, false);
      Serial.println("Ambos LED apagados");
      break;
    default:
      Serial.print("Comando invalido ");
      Serial.println(comando);
      break;
  }
}

/**
 * Lee un caracter del puerto serial si hay uno disponible y lo
 * ejecuta como comando. No bloquea la ejecucion cuando no hay datos.
 * Ignora los saltos de linea que envia el monitor serial.
 */
void atenderComandoSerial() {
  if (Serial.available() == 0) {
    return;
  }

  char comando = Serial.read();

  if (comando == '\n' || comando == '\r') {
    return;
  }

  ejecutarComando(comando);
}



void loop() {
  atenderComandoSerial();
}