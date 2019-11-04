#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "Vektor2d.h"

// Simulationsgeschwindigkeit
const double DT = 100.0;

double x = 0;
double y = 0;
double press = 0;

class GameWindow : public Gosu::Window
{
public:
	Gosu::Image panzer;
	GameWindow()
		: Window(800, 600)
		, panzer("Panzer.png")
	{
		set_caption("PANZAAA");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		panzer.draw_rot(x, y, 0.0,
			press, // Rotationswinkel in Grad
			0.5, 0.5 // Position der "Mitte" relativ zu x, y
		);

	}

	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
		x = input().mouse_x();
		y = input().mouse_y();



		if (input().down(Gosu::KB_LEFT)) {
			press += 10;
		}
		else if (input().down(Gosu::KB_RIGHT)) {
			press -= 10;
		}

	}
};

// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}
