#include "Particle.h"
#include <stdlib.h>
#include <math.h>
#include <SDL_stdinc.h>

Particle::Particle() {
	init();
}

void Particle::init() {
	m_x = 0;
	m_y = 0;
	m_Direction = (2 * M_PI * rand())/RAND_MAX;
	m_Speed = (0.04 * rand())/RAND_MAX;
	m_Speed *= m_Speed;
}

Particle::~Particle() {

}

void Particle::update(int interval) {
	m_Direction += interval * 0.0003;

	const double xSpeed = m_Speed * cos(m_Direction);
	const double ySpeed = m_Speed * sin(m_Direction);

	// multiply by interval to accurately update particle position regardless of the speed of the computer
	// if interval is really small it will decrease the impact of speed variable and vice versa
	m_x += xSpeed * interval;
	m_y += ySpeed * interval;

	if(m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
		init();
	}

	if(rand() < RAND_MAX/100) {
		init();
	}
}