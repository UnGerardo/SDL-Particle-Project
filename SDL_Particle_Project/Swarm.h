#pragma once

#include "Particle.h"

class Swarm {
	public:
		Swarm();
		virtual ~Swarm();

		const Particle* const getParticles() { return m_pParticles; };
		void update();

		const static int NPARTICLES = 5000;

	private:
		Particle* m_pParticles;
};

