#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "Vektor2d.h"

class panzer{
private:
		
	double x;
	double y;


public:
	Gosu::Image panzerbild;

	panzer(double x, double y, ) : x(x), y(y) {}

	void set_x(double x) {
		this->x = x;
	}

	void set_y(double y) {
		this->y = y;
	}

	double get_x() {
		return this->x;
	}
	double get_y() {
		return this->y;
	}



};


// Simulationsgeschwindigkeit
const double DT = 100.0;


double press = 0;

class GameWindow : public Gosu::Window
{
public:
	Gosu::Image panzer;
	GameWindow(): Window(800, 600), panzer("Panzer.png")
	{
		set_caption("PANZAAA");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		panzer.draw_rot(panzer.get_x(), panzer.y, 0.0,
			press, // Rotationswinkel in Grad
			0.5, 0.5 // Position der "Mitte" relativ zu x, y
		);

	}

	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
		panzer.x = input().mouse_x();
		panzer.y = input().mouse_y();



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
