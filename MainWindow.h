#pragma once
#include "base.h"
#include "SFML/Window.hpp"
#include <SFML/Graphics.hpp>


class MainWindow
{
protected:
	MainWindow();

	static MainWindow* instance;

public:
	static MainWindow* GetInstance();

};

MainWindow* MainWindow::instance = nullptr;

