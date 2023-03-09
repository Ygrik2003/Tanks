#include "MainWindow.h"


MainWindow::MainWindow()
{
	sf::RenderWindow window(sf::VideoMode(COUNT_HORIZONTAL_CELLS * SIZE_CELL.x + 10, COUNT_VERTICAL_CELLS * SIZE_CELL.y), "Tanks!", sf::Style::Titlebar | sf::Style::Close);

}

MainWindow* MainWindow::GetInstance()

{
	if (instance == nullptr)
	{
		instance = new MainWindow();
	}
	return instance;
}