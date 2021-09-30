#include "GraphicsEngine.h"

int main() 
{
	GraphicsEngine* engine = new GraphicsEngine();

	int exitcode = engine->run();

	delete engine;

	return 0;
}