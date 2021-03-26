#include "Swarm.h"

Swarm::Swarm(): lastTime(0) {
	m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
	delete[] m_pParticles;
}

void Swarm::update(int elapsed) {
	// stores the time it took between each call to this function to ensure that the speed is constant regardless of the speed of the computer
	int interval = elapsed - lastTime;

	for(int i = 0; i < NPARTICLES; i++) {
		m_pParticles[i].update(interval);
	}

	lastTime = elapsed;
}