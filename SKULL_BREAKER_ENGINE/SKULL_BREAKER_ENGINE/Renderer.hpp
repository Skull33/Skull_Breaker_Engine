#ifndef RENDERER_H
#define RENDERER_H

#define SDL_MAIN_HANDLED

#ifdef _WIN64
	#include<SDL3/SDL.h>
#endif // _WIN64

#include <stdio.h>
#include"Typedef.hpp"
#include "p_jugador.hpp"
#include "g_estado_juego.hpp"
//#include "utilidades.hpp"

typedef struct planos
{
	int tope[1024];
	int base[1024];
} plano_t;

typedef struct paredes
{
	_2D_t a;
	_2D_t b;
	double portal_altura_tope;
	double portal_altura_base;
	bool es_portal;
} pared_t;

typedef struct sector
{
	int id;
	pared_t paredes[10];
	int numero_paredes;
	int altura;
	int elevacion;
	double distancia_sector_jugador;
	unsigned int color;
	unsigned int color_piso;
	unsigned int color_techo;

	plano_t piso_portales;
	plano_t techo_portales;
	plano_t pisos;
	plano_t techos;
} sector_t;

typedef struct cola_sectores
{
	sector_t sectores[1024];
	int numero_sectores;
} cola_sectores_t;

void inicializar(SDL_Window* ventana, estado_juego_t* estado);
void apagado();
void renderer(jugador_t* jugador, estado_juego_t* estado);
void dibujarParedes(jugador_t* jugador, estado_juego_t* estado);
sector_t crearSector(int altura, int elevacion, unsigned int color, unsigned int color_techo, unsigned int color_piso);
void Sectores_mas_paredes(sector_t* sector, pared_t* vertices);
void agregar_SECTOR_a_la_cola(sector_t* sector);
pared_t crear_pared(int ax, int ay, int bx, int by);
pared_t crear_portales(int ax, int ay, int bx, int by, int th, int bh);

#endif // !RENDERER_H
