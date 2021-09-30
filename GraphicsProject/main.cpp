#include "GraphicsEngine.h"

int main() 
{
	GraphicsEngine* engine = new GraphicsEngine(1280, 720, "Graphics");

	int exitcode = engine->run();

	delete engine;

	return 0;
}