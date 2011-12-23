#include <iostream>
#include <sys/time.h>

#include "Context.h"
#include "ContextFactory.h"

int main(int argc, char **argv)
{
		Context *context;
		ContextFactory cF;

		context = cF.makeContext(argc, argv);

		if (context != 0) {
			/* Parsing successful */
			context->render();
			context->refresh();
			delete context;
		}

        return 0;
}

