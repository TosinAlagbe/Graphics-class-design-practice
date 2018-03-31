#include "Simple_window.h"
#include "Graph.h"

struct Arrow :Lines
{
	Arrow(Point p1, Point p2, int size);

	void draw_lines() const;

	int distance () const
	{
		double dis;
		dis = sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
		int c_dis = int(dis);
		return c_dis;
	}


private:
	int l;
	int s;
	Point p1;
	Point p2;
	char d;

};

Arrow::Arrow(Point p1, Point p2, int size)
	:p1{ p1 }, p2{ p2 }, s{ size }
{
	Lines::add(Point{ p1.x,p1.y }, Point{ p2.x,p2.y });
	if (p1.x < p2.x)
	{
		
		Lines::add(Point{ p2.x - s,p2.y - s }, Point{ p2.x,p2.y });
		Lines::add(Point{ p2.x - s,p2.y + s }, Point{ p2.x,p2.y });
	}
	if (p1.x == p2.x)
	{
		if (p1.y > p2.y)
		{
			Lines::add(Point{ p2.x - s,p2.y + s }, Point{ p2.x,p2.y });
			Lines::add(Point{ p2.x + s,p2.y + s }, Point{ p2.x,p2.y });
		}
		if (p1.y < p2.y)
		{
			Lines::add(Point{ p2.x - s,p2.y - s }, Point{ p2.x,p2.y });
			Lines::add(Point{ p2.x + s,p2.y - s }, Point{ p2.x,p2.y });
		}	
	}
	if (p1.x > p2.x)
	{
		Lines::add(Point{ p2.x +s,p2.y - s }, Point{ p2.x,p2.y });
		Lines::add(Point{ p2.x ,p2.y + s }, Point{ p2.x,p2.y });

	}	
	
}



void Arrow::draw_lines()const
{
	
	if (color().visibility())
	{
		for (int i = 1; i < number_of_points(); i += 2)
		{
			fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);		

		}
	
	}
}
