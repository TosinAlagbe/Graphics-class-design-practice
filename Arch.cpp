#include "Simple_window.h"
#include "Graph.h"

struct Arch :Shape
{
	Arch(Point p, int w, int h, double ang)
		:w(w), h(h), a(ang)
	{
		add(Point(p.x - w, p.y - h));
	}

	void draw_lines() const;

private:
	int w;
	int h;
	double a;

};

void Arch::draw_lines() const
{
	if (color().visibility())
		fl_arc(point(0).x, point(0).y, w + w, h + h, 0, a);

}
