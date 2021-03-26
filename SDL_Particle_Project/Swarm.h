#pragma once

#include "Particle.h"

class Swarm {
	public:
		Swarm();
		virtual ~Swarm();

		const Particle* const getParticles() { return m_pParticles; };
		void update(int elapsed);

		const static int NPARTICLES = 5000;

	private:
		Particle* m_pParticles;
		int lastTime;
};

