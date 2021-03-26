#include "Particle.h"
#include <stdlib.h>
#include <math.h>
#include <SDL_stdinc.h>

Particle::Particle(): m_x(0), m_y(0) {
	m_Direction = (2 * M_PI * rand())/RAND_MAX;
	m_Speed = (0.001 * rand())/RAND_MAX;
}

Particle::~Particle() {

}

void Particle::update() {
	double xSpeed = m_Speed * cos(m_Direction);
	double ySpeed = m_Speed * sin(m_Direction);

	m_x += xSpeed;
	m_y += ySpeed;
}