#include "Graph.h"
#include "Simple_window.h"

#define PI 3.14159265

class Octagon : public Shape
{
public:
	Octagon(Point centre, int side_length);

	void draw_lines() const;
	void modify(Point, int);

	void set_centre(Point cent) { mid = cent; modify(cent, s_l); }
	void set_side(int ex) { s_l = ex; modify(mid, ex); }

	double cot(double x) const { return (cos(x) / sin(x)); }
	double rad(int side) { return (0.5*side*cot(PI / 8)); }

private:
	int s_l;
	Point mid;


};


void Octagon::modify(Point mid, int s_l)
{
	int pos = 0;
	for (double ang = 22.5; ang <= 337.5; ang += 45)
	{
		set_point(pos++, Point{
			int(mid.x + rad(s_l) * cos(ang*PI / 180))
			,   int(mid.y - rad(s_l) * sin(ang*PI / 180))
			});
	};

}

Octagon::Octagon(Point centre, int side_length)
	:mid(centre), s_l(side_length)
{
	for (int ang = 22.5; ang <= 337.5; ang += 45)
	{
		add(Point{ int(mid.x + rad(s_l) * cos(ang*PI / 180)),
			int(mid.y - rad(s_l) * sin(ang*PI / 180)) });
	};
}

void Octagon::draw_lines() const
{
	if (color().visibility())
	{
		for (unsigned int i = 1; i<number_of_points(); ++i)
		{
			fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);
		}
		fl_line(point(number_of_points() - 1).x, point(number_of_points() - 1).y,
			point(0).x, point(0).y);
	}
}


