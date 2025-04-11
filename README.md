# Implementaci-n-Transversal-del-N-cleo-Concurrente
OBJETIVO: Cada equipo avanzará en la implementación práctica de su proyecto aplicando los conceptos de sincronización y candados, con retroalimentación inmediata.
 
FASE UNO: Implementación básica del mecanismo de concurrencia.
ACTIVIDAD: “From Design to Code”
Cada equipo trabajará en el núcleo concurrente de su proyecto, siguiendo las pautas según el tipo.
El proyecto seleccionado en nuestro caso es el que lleva el título de “Simulación de Videojuego Multijugador”; “Manejar múltiples jugadores en un servidor con lógico concurrente”.
Las técnicas a aplicar son las siguientes:
•	Hilos (std::thread) para cada cliente.
•	Mutex (std::mutex) para proteger el estado del juego.
El código realizado durante el desarrollo del proyecto fue el que presentaremos a continuación:
 
FASE DOS: Pruebas y Detección de Errores.
ACTIVIDAD: “Stress Testing & Debugging”
Cada equipo diseñará pruebas para forzar condiciones de carrera o deadlock.
Capturas de las pruebas realizadas:
 
	Checklist de Validación:
¿El sistema maneja correctamente la concurrencia?
R: Sí, sin embargo, puede resultar confuso al momento de manipular los “sleep” del programa, ya que, si los tiempos son alineados de manera incorrecta, los Clientes se reproducirán más rápidamente que las actualizaciones del juego o viceversa. El programa no presenta algún error que evite su reproducción, pero tiene que manejarse con cuidado.
¿Se observan comportamientos inesperados?
R: No necesariamente, el programa hace lo esperado, pero, como se ha mencionado en la pregunta anterior, la manipulación de los “tiempos de espera” pueden resultar en algo confuso e inesperado; dejando a un lado aquello, el programa presenta los puntos deseados.
 
FASE DOS: Refactorización y Planificación.
ACTIVIDAD: “Feedback en Círculo”
Cada equipo presenta su código a otro. El equipo observador da feedback usando el formato “Me gusta / Sugerencia”.
Sugerencias realizadas por el equipo al que presentamos nuestro código:
El equipo al que fue presentado el código nos enseñó una manera más dinámica de realizar el “juego”, a pesar de que las personas que visualizaron nuestro código reproducirse trabaja en Python, nos dejó saber una idea breve con la cual, utilizando una biblioteca como base, podemos reproducir el programa de manera interactiva; en fin, solo nos recordaron como tal que, el uso del Cliente y el Jugador deben ser independientes entre sí, cada uno debe tener su propio archivo y ambos deben mandarse a llamar entre ellos. Se tendrá en consideración para la refactorización del programa.
 
PLANIFICACIÓN:
Las actividades seleccionadas a futuro serán la actualización del programa, planeamos adjuntar un menú que nos permita seleccionar la cantidad de jugadores, al igual que tal vez sus nombres; se realizará una investigación para encontrar la manera de hacer el juego más interactivo y agradable visualmente.
