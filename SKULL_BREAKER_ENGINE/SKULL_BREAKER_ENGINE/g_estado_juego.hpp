#ifndef G_ESTADO_JUEGO_H
#define G_ESTADO_JUEGO_H

#define SLD_MAIN_HANDLED

#ifdef _WIN64
	#include<SDL3/SDL.h>
#endif // _WIN64

#include "Typedef.hpp"

typedef struct estado_juego
{
	unsigned int pantalla_ancho;
	unsigned int pantalla_altura;
	double FPS_objetivo;
	double objetivo_tiempo_frames;
	double delta;
	bool esta_corriendo;
	bool esta_pausado;
	bool estan_los_fps_tapados;
	bool mostrar_mapa_de_estados;
	bool esta_en_modo_debug;
	
} estado_juego_t;

estado_juego_t Init(const unsigned int vantana_ancho, const unsigned int vventana_altura, int fps_objetivo);
void G_InicioFrame();
void G_finalFrame(estado_juego_t* estado);


#endif // !G_ESTADO_JUEGO_H
