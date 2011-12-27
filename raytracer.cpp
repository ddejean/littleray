#include <iostream>
#include <cstdlib>
#include <sys/time.h>

#include "Context.h"
#include "ContextFactory.h"

int main(int argc, char **argv)
{
		Context *context;
		ContextFactory cF;

		try {
		context = cF.makeContext(argc, argv);
		} catch (...) {
			std::cout << "An error occurred during raytracer context creation, aborting." << std::endl;
			return EXIT_FAILURE;
		}

		if (context != 0) {
			/* Parsing successful */
			context->render();
			context->refresh();
			delete context;
		}

        return EXIT_SUCCESS;
}

