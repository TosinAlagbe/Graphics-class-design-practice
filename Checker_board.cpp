#include "Graph.h"
#include "Simple_window.h"

class Group : public Shape
{
public:
	Group(const Group&) = delete;
	Shape &operator=(const Shape&) = delete;
	virtual void bond();

protected:
	Group() {};
	Simple_window w{ Point{ 100,10 }, 1200, 1000, " " };
	
	Vector_ref<Graph_lib::Rectangle>rect;
	Vector_ref<Circle>circ;
	Vector_ref<Octagon>oct;

};

void Group::bond()
{
	for (int i = 0; i < rect.size(); ++i)
	{
		w.attach(rect[i]);
	}

	for (int i = 0; i < circ.size(); ++i)
	{
		w.attach(circ[i]);
	}


	w.wait_for_button();


}

class Checker_board : public Group
{
public:
	Checker_board(Point lcorner, int length);
	void bond() override;


private:
	Point lcorner;
	int l;
	double s = ((l - lcorner.x) / 8);
	int r = int(s / 3);

	Simple_window w{ Point{ 100,10 }, 1200, 1000, "checkers" };

	void init_grid();
	void red_circle();
	void blue_circle();
	
	void alt(double init, double limit, Color::Color_type col);
};

Checker_board::Checker_board(Point lcorner, int length)
	:lcorner{ lcorner }, l{ length }
{
	init_grid();
	red_circle();
	blue_circle();
}


void Checker_board::alt(double init, double limit, Color::Color_type col)
{
	
	for (double j = init; j < limit; j += s)
	{
		if (fmod(j - lcorner.y, 2) == 0)
		{
			for (double i = lcorner.x; i < (lcorner.x + 8 * s); i += (2 * s))
			{
				circ.push_back(new Circle{ Point{ int(i + s / 2) ,int(j + s / 2) },r });
				circ[circ.size() - 1].set_color(col);
				
			}
		}
		else
		{
			for (double i = lcorner.x + s; i < (lcorner.x + 8 * s); i += (2 * s))
			{
				circ.push_back(new Circle{ Point{ int(i + s / 2) ,int(j + s / 2) },r });
				circ[circ.size() - 1].set_color(col);
			}
		}
	}

}


void Checker_board::bond()
{
	for (int i = 0; i < rect.size(); ++i)
	{
		w.attach(rect[i]);
	}

	for (int i = 0; i < circ.size(); ++i)
	{
		w.attach(circ[i]);
	}


	w.wait_for_button();

}

void Checker_board::red_circle()
{
	alt(lcorner.y, lcorner.y + 3 * s, Color::red);
	
}

void Checker_board::blue_circle()
{
	alt(lcorner.y + 5*s, lcorner.y + 8 * s, Color::blue);
	
}

void Checker_board::init_grid()
{
	for (double j = lcorner.y; j < (lcorner.y + 8 * s); j += s)
	{
		if (fmod(j - lcorner.y, 2) == 0)
		{
			for (double i = lcorner.x; i < (lcorner.x + 8 * s); i += s)
			{
				if (fmod(i - lcorner.x, 2) == 0)
				{
					rect.push_back(new Graph_lib::Rectangle{ Point{ int(i) ,int(j) },int(s),int(s) });
					rect[rect.size() - 1].set_fill_color(Color::black);

				}
				else
				{
					rect.push_back(new Graph_lib::Rectangle{ Point{ int(i) ,int(j) },int(s),int(s) });
					rect[rect.size() - 1].set_fill_color(Color::white);

				}
			}
		}
		else
		{
			for (double i = lcorner.x ; i < (lcorner.x + 8 * s); i +=  s)
			{
				if (fmod(i - (lcorner.x ), 2) == 0)
				{
					rect.push_back(new Graph_lib::Rectangle{ Point{ int(i) ,int(j) },int(s),int(s) });
					rect[rect.size() - 1].set_fill_color(Color::white);

				}
				else
				{
					rect.push_back(new Graph_lib::Rectangle{ Point{ int(i) ,int(j) },int(s),int(s) });
					rect[rect.size() - 1].set_fill_color(Color::black);

				}
		
			}
		}
	}
}

