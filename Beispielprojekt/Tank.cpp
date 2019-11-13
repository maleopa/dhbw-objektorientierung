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
		
	
	double winkel = 0;
	double g = 0;
	double x = 0;
	double y = 0;
	Gosu::Image panzerbild;

	

public:
	

	panzer() : x(x), y(y), winkel(winkel), panzerbild("panzer.png") {}

	
	void set_x() {
		this->x = this->x + this->g * sin(this->winkel);
	}

	void set_y() {
		this->y = this->y + this->g * cos(this->winkel);;
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
	void set_g(double g) {
		this->g = this->g +g;
	}
/*
	double get_betrag() {
		return this->betrag;
	}


	void set_betrag() {
		this->betrag = sqrt((this->get_x() * this->get_x()) + (this->get_y() * this->get_y()));
	}



	void set_betrag(double b) {
		this->betrag = this->betrag + b;
	}
*/	

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

void hoch_runter(panzer* p) {

	if (Gosu::Input::down(Gosu::KB_DOWN)) {
		p->set_g(-0.02);
	}
	else if (Gosu::Input::down(Gosu::KB_UP)) {
		p->set_g(0.02);
	}
}

void rechts_links(panzer* p) {
	if (Gosu::Input::down(Gosu::KB_RIGHT)) {
		p->set_winkel(2);
	}
	else if (Gosu::Input::down(Gosu::KB_LEFT)) {
		p->set_winkel(-2);
	}
}


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
		
		

		//cout << p1.get_betrag() << endl;
	
	
		hoch_runter(&p1);
		rechts_links(&p1);
		p1.set_x();
		p1.set_y();

		

	}
};


// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}
