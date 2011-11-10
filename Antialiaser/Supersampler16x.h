#ifndef SUPERSAMPLER16X_H_
#define SUPERSAMPLER16X_H_

#include "Antialiaser.h"

class Supersampler16x: public Antialiaser {

private:
	/* Current iterator position */
	unsigned int x;
	unsigned int y;

public:
	Supersampler16x();
	virtual ~Supersampler16x();

	/* Antialiaser implementation */
	double stepX(void);
	double stepY(void);
	double begin(void);
	double end(void);
	double contribution(void);
};

#endif /* SUPERSAMPLER16X_H_ */
