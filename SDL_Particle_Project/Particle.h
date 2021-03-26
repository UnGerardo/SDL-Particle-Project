#pragma once
struct Particle {
	double m_x, m_y, m_Speed, m_Direction, m_xSpeed, m_ySpeed;

	public:
		Particle();
		virtual ~Particle();

		void update(int interval);
};

