#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "Vektor2d.h"

using namespace std;

class panzer {
private:
		
	double x = 0;
	double y = 0;
	Gosu::Image panzerbild;

public:
	

	panzer() : x(x), y(y), panzerbild("panzer.png") {}

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

	void draw_panzer() {
		panzerbild.draw_rot(this->x, this->y, 0,5, 0.5, 0.5);
	}



};


// Simulationsgeschwindigkeit
const double DT = 100.0;
double press = 0;



class GameWindow : public Gosu::Window
{
public:
	panzer p1;
	//Gosu::Image panzer;
	//GameWindow() : Window(800, 600), panzer("Panzer.png")
	GameWindow(): Window(800, 600)
	{
		set_caption("P");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		p1.draw_panzer();

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
