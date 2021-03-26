#pragma once
struct Particle {
	double m_x, m_y, m_Speed, m_Direction;

	public:
		Particle();
		virtual ~Particle();

		void update();
};

