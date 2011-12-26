#ifndef CONTEXT_H_
#define CONTEXT_H_

#include "Scene.h"
#include "Displays/Display.h"

class Context {
private:
	Scene *scene;
	Display *display;

public:
	Context(Scene *s, Display *d);
	~Context(void);
	void render(void);
	void refresh(void);
};

#endif /* CONTEXT_H_ */

