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
	double x;
	double y;
	double v;
	Gosu::Image panzerbild;

public:
	

	panzer(double xa, double ya, double wa, double va) : x(xa), y(ya), winkel(wa),v(va), panzerbild("tank2.png") {}

	
	void move() {
		this->x = this->x + this->v * cos((this->winkel-90)/180*3.14);
		this->y = this->y + this->v * sin((this->winkel-90) / 180 * 3.14);
	}
	
	void set_v(double v){
		this->v = v;
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

class rakete {
private:

	double winkel = 0;
	double x;
	double y;
	double v;
	Gosu::Image raketenbild;

public:


	rakete(double xa, double ya, double wa, double va) : x(xa), y(ya), winkel(wa), v(va), raketenbild("rakete2.png") {}

	void move() {
		this->x = this->x + this->v * cos((this->winkel - 90) / 180 * 3.14);
		this->y = this->y + this->v * sin((this->winkel - 90) / 180 * 3.14);
	}

	void set_v(double v) {
		this->v = v;
	}
	void set_x(double x) {
		this->x = x;
	}
	void set_y(double y) {
		this->y = y;
	}
	
	void set_winkel(double w){
		this->winkel = w;
	}

	void draw_rakete() {
		raketenbild.draw_rot(this->x, this->y, 0.4, this->winkel, 0.5, 1.0);
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
		p->set_v(-2);
	}
	else if (Gosu::Input::down(Gosu::KB_UP)) {
		p->set_v(2);
	}
	else {
		p->set_v(0);
	}
}

void rechts_links(panzer* p) {
	if (Gosu::Input::down(Gosu::KB_RIGHT)) {
		p->set_winkel(2);
	}
	else if (Gosu::Input::down(Gosu::KB_LEFT)) {
		p->set_winkel(-2);
	}
	else {
		p->set_winkel(0);
	}
}

void abschuss_move(rakete* r, panzer* p) {

	if (Gosu::Input::down(Gosu::KB_SPACE)) {
		r->set_v(5);
		r->set_winkel(p->get_winkel());
		r->set_x(p->get_x());
		r->set_y(p->get_y());
	}
	
}




// Simulationsgeschwindigkeit
const double DT = 100.0;


class GameWindow : public Gosu::Window
{
public:
	panzer p1;
	rakete r1;

	
	GameWindow(): p1(300, 400, 0, 0), r1(-10, -10, 0, 0), Window(800, 600)
	{
		set_caption("Panzer");
		
	}
	
	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		p1.draw_panzer();
		r1.draw_rakete();
		
		
		


	}

	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
		
		

		//cout << p1.get_betrag() << endl;
	
		//cout << p1.get_x()<<" "<<p1.get_y() << endl;
		hoch_runter(&p1);
		rechts_links(&p1);
		
	
		abschuss_move(&r1, &p1);
		p1.move();
		r1.move();
		
		
		

		
		

		

	}
};


// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}
