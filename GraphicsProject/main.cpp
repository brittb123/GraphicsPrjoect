#include "GraphicsEngine.h"

int main() 
{
	GraphicsEngine* engine = new GraphicsEngine(720, 1280, "Graphics");

	int exitcode = engine->run();

	delete engine;

	return 0;
}