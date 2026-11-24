# poli-iot-bluetooth-arduino


## Contenido del repositorio

| Archivo | Descripción |
|---|---|
| `sketch.ino` | Código fuente del programa para Arduino, documentado. |
| `diagram.json` | Archivo de configuración del circuito en Wokwi. |
| `wokwi-project.txt` | Archivo del proyecto generado por Wokwi. |
| `diagrama_fritzing_schem.png` | Diagrama esquemático del circuito completo en Fritzing, incluido el módulo HC-05. |

## Simulación en Wokwi

Enlace público del proyecto: https://wokwi.com/projects/481532964377801729

## Conexiones

| Origen | Destino | Función |
|---|---|---|
| 5V Arduino | VCC HC-05 | Alimentación del módulo |
| GND Arduino | GND HC-05 | Tierra común |
| TX HC-05 | D0 Arduino | Recepción de datos |
| RX HC-05 | D1 Arduino | Transmisión de datos |
| D2 Arduino | Resistencia de 220 Ω y ánodo del LED verde | Control del LED verde |
| D3 Arduino | Resistencia de 220 Ω y ánodo del LED rojo | Control del LED rojo |
| Cátodo de cada LED | GND Arduino | Retorno a tierra |

La comunicación serial funciona a 9600 baudios.

## Comandos

| Comando | Acción |
|---|---|
| `V` | Enciende el LED verde |
| `R` | Enciende el LED rojo |
| `A` | Enciende ambos LED |
| `0` | Apaga ambos LED |
| Otro caracter | Notifica comando inválido |

Cada comando válido deja los LED en el estado indicado, sin conservar el estado anterior.

## Cómo probar el proyecto

1. Abre el enlace de Wokwi.
2. Inicia la simulación con el botón verde.
3. Escribe un comando en el monitor serial y presiona Enter.
4. Observa el estado de los LED y el mensaje que responde el programa.

## Limitación de la simulación

Wokwi no incluye el módulo HC-05, por lo que la simulación no emula el enlace Bluetooth. Los comandos se envían desde el monitor serial de Wokwi, que se conecta al puerto serial del Arduino. El módulo HC-05 y sus conexiones se documentan en el diagrama de Fritzing incluido en este repositorio.
