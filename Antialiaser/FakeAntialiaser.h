#ifndef FAKEANTIALIASER_H_
#define FAKEANTIALIASER_H_

#include "Antialiaser.h"

class FakeAntialiaser: public Antialiaser {
public:
	FakeAntialiaser(void);
	virtual ~FakeAntialiaser(void);

	/* Antialiaser implementation */
	double stepX(void);
	double stepY(void);
	double begin(void);
	double end(void);
	double contribution(void);
};

#endif /* FAKEANTIALIASER_H_ */
