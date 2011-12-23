#ifndef CONTEXTFACTORY_H_
#define CONTEXTFACTORY_H_

#include <getopt.h>
#include "Context.h"

class ContextFactory {
private:
	/* Display help for program argument */
	void help(void);
public:
	Context *makeContext(int argc, char **argv);
};

#endif /* CONTEXTFACTORY_H_ */
