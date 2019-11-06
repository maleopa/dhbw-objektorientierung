#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "Vektor2d.h"

using namespace std;

class panzer{
private:
		
	double x = 0;
	double y = 0;
	Gosu::Image panzerbild;

public:

	panzer(double x, double y, string img) : x(x), y(y), panzerbild(img) {}

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

	Gosu::Image get_bild() {
		return this->panzerbild;
	}



};





panzer p1( 0, 0, "Panzer.png" );

// Simulationsgeschwindigkeit
const double DT = 100.0;
double press = 0;



class GameWindow : public Gosu::Window
{
public:
	//Gosu::Image panzer;
	//GameWindow() : Window(800, 600), panzer("Panzer.png")
	GameWindow(): Window(800, 600), p1.get_bild()
	{
		set_caption("PANZAAA");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		panzer.draw_rot(p1.get_x(), p1.get_y(),
			press, // Rotationswinkel in Grad
			0.5, 0.5 // Position der "Mitte" relativ zu x, y
		);

	}

	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
		p1.set_x(input().mouse_x());
		p1.set_y(input().mouse_y());



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
