#pragma once

struct GLFWwindow;

class GraphicsEngine
{
public:
	GraphicsEngine(int width, int height, const char* title);
	~GraphicsEngine();

	int run();

private:
	int start();
	int update();
	int draw();
	int end();

	bool getGameOver();

private:
	GLFWwindow* m_window = nullptr;
	int m_width, m_height;
	const char* m_title;
};

