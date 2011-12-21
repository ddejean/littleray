#ifndef CONTEXTFACTORY_H_
#define CONTEXTFACTORY_H_

#include "Context.h"

class ContextFactory {
public:
	Context *makeContext(int argc, char **argv);
};

#endif /* CONTEXTFACTORY_H_ */
