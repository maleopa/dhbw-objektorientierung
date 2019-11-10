#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>
#include <math.h>

#include "Vektor2d.h"

using namespace std;

class panzer {
private:
		
	double x = 0;
	double y = 0;
	double winkel = 0;
	Gosu::Image panzerbild;

public:
	

	panzer() : x(x), y(y), winkel(winkel), panzerbild("panzer.png") {}

	void set_x(double x, double w) {
		this->x = x*cos(w);
	}

	void set_y(double y, double w) {
		this->y = y*sin(w);
	}

	void set_winkel(double w) {
		double neu_winkel = this->winkel + w;
		if (neu_winkel > 359) {
			this->winkel = 360 - neu_winkel;
		}
		else if (neu_winkel < 0) {
			this->winkel = 360 + neu_winkel;
		}
		else {
			this->winkel = neu_winkel;
		}

	}

	double get_x() {
		return this->x;
	}
	double get_y() {
		return this->y;
	}

	double get_winkel() {
		return this->winkel;
	}



	void draw_panzer() {
		panzerbild.draw_rot(this->x, this->y, 0.5, this->winkel, 0.5, 0.5);
	}



};

class hintergrund {
private:
	double x=0;
	double y=0;
	Gosu::Image hbild;

public:

	hintergrund() : hbild() {}

	void draw_hintergund() {
		hbild.draw_rot(this->x, this->y,0,0);
	}
};

// Simulationsgeschwindigkeit
const double DT = 100.0;



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

	double y_achse(double a) {

		if (input().down(Gosu::KB_DOWN)) {
			a += 3.5;
		}
		else if (input().down(Gosu::KB_UP)) {
			a -= 3.5;
		}
		return a;
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
		
		
		
		
		
		
		//p1.set_y(y_achse(p1.get_y()))

		p1.set_x(y_achse(p1.get_x()),p1.get_winkel());
		p1.set_y(y_achse(p1.get_y()), p1.get_winkel());

		cout << p1.get_winkel() << endl;


		if (input().down(Gosu::KB_RIGHT)) {
			p1.set_winkel(2);
		}
		else if (input().down(Gosu::KB_LEFT)) {
			p1.set_winkel(-2);
		}

	}
};


// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}
