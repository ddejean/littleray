#ifndef SUPERSAMPLER4X_H_
#define SUPERSAMPLER4X_H_

#include "Antialiaser.h"

class Supersampler4x : public Antialiaser {
public:
	Supersampler4x(void);
	virtual ~Supersampler4x(void);

	/* Antialiaser implementation */
	double stepX(void);
	double stepY(void);
	double begin(void);
	double end(void);
	double contribution(void);
};

#endif /* SUPERSAMPLER4X_H_ */
