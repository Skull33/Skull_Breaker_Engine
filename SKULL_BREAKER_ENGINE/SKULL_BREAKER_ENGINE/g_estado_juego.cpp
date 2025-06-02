#include "g_estado_juego.hpp"

int inicio_frames = 0;

estado_juego_t Init(const unsigned int ventana_ancho, const unsigned int ventana_altura, int fps_objetivo)
{
	estado_juego_t estado;
	estado.esta_en_modo_debug = false;
	estado.esta_corriendo = true;
	estado.pantalla_altura = ventana_altura;
	estado.pantalla_ancho = ventana_ancho;
	estado.FPS_objetivo = fps_objetivo;
	estado.objetivo_tiempo_frames = 1.0 / (double)estado.FPS_objetivo;
	estado.estan_los_fps_tapados = false;
	estado.delta = estado.objetivo_tiempo_frames;
	estado.esta_en_modo_debug = false;

	return estado;
}
void G_InicioFrame()
{
	inicio_frames = SDL_GetTicks();
}

void G_finalFrame(estado_juego_t* estado)
{
	estado->delta = (SDL_GetTicks() - inicio_frames) / 1000.0;

	if (estado->delta < estado->objetivo_tiempo_frames)
	{
		SDL_Delay((estado->objetivo_tiempo_frames - estado->delta) * 1000.0);
		estado->delta = estado->objetivo_tiempo_frames;
	}
}