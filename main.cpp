#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>

#include "bezier.h"

int screen_height = 500;
int screen_width = 500;


int main(){
	srand (time(NULL));

	float x1 = rand() % 500;
	float y1 = rand() % 500;
	float x2 = rand() % 500;
	float y2 = rand() % 500;
	float x3 = rand() % 500;
	float y3 = rand() % 500;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;


	sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "SFML", sf::Style::Default, settings);

	sf::Clock clock;
	float time_elapsed = 1;

	while (window.isOpen())
	{
		sf::Time dt = clock.restart();
		float delta = dt.asSeconds();
		time_elapsed += delta;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		int resolution = time_elapsed*time_elapsed;

		float * arr = bezier(x1, y1, x2, y2, x3, y3, resolution);

		sf::VertexArray line(sf::LinesStrip, resolution);

		for(int i = 0; i < resolution; i++){

			float h = (float) i / (float) resolution;

			int x = arr[i*2];
			int y = arr[i*2 + 1];

			//std::cout << x << ", " << y << std::endl;
			line[i].position = sf::Vector2f(x, y);

		}

		window.draw(line);
		delete[] arr;

		window.display();

		std::cout << "Render frame in " << delta << " s" << std::endl;
	}

	return 0;
}
