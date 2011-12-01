#ifndef ANTIALIASER_H_
#define ANTIALIASER_H_

class Antialiaser {
public:
	virtual ~Antialiaser() {};

	/*
	 * Provides the current step, and
	 * forward the current cursor
	 */
	virtual double stepX(void) = 0;
	virtual double stepY(void) = 0;

	/* Provides the limits */
	virtual double begin(void) = 0;
	virtual double end(void) = 0;

	/* Give the contribution coefficient for the current position */
	virtual double contribution(void) = 0;

};

#endif /* ANTIALIASER_H_ */
