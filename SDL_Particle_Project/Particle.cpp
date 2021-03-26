#include "Particle.h"
#include <stdlib.h>
#include <math.h>
#include <SDL_stdinc.h>

Particle::Particle(): m_x(0), m_y(0) {
	m_Direction = (2 * M_PI * rand())/RAND_MAX;
	m_Speed = (0.0001 * rand())/RAND_MAX;
	m_xSpeed = m_Speed * cos(m_Direction);
	m_ySpeed = m_Speed * sin(m_Direction);
}

Particle::~Particle() {

}

void Particle::update(int interval) {
	// multiply by interval to accurately update particle position regardless of the speed of the computer
	// if interval is really small it will decrease the impact of speed variable and vice versa
	m_x += m_xSpeed * interval;
	m_y += m_ySpeed * interval;
}