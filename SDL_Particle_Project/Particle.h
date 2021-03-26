#pragma once
struct Particle {
	Particle();
	virtual ~Particle();

	void update(int interval);

	double m_x, m_y, m_Speed, m_Direction;

	private:
		void init();
};

