#pragma once
class GraphicsEngine
{
public:
	GraphicsEngine();
	~GraphicsEngine();

	int run();

private:
	int start();
	int update();
	int end();

	bool getGameOver();

private:
	GLFWwindow* m_window;
};

