struct Box : Lines
{
	Box(Point p, int length, int width, int radius);
	
	void draw_lines() const;

private:
	int l;
	int w;
	Point p;
	int r;

};

Box::Box(Point p, int length, int width, int radius)
	:p{ p }, l{ length }, w{ width }, r{ radius }
{
	Lines::add(Point{ p.x + r,p.y }, Point{ p.x + l - r - r,p.y });
	Lines::add(Point{ p.x, p.y + r }, Point{ p.x,p.y + w - r - r });
	Lines::add(Point{ p.x + r, p.y + w - r }, Point{ p.x + l - r - r,p.y + w - r });
	Lines::add(Point{ p.x + l - r,p.y + r }, Point{ p.x + l - r,p.y + w - r - r });
}

void Box::draw_lines() const
{
	if (color().visibility())
	{
		for (int i = 1; i < 8; i += 2)
		{
			fl_line(point(i-1).x, point(i-1).y, point(i).x, point(i).y);		
		}		
	}
	if (color().visibility())
	{
		fl_arc(p.x + l - r - r - r, p.y, r + r, r + r, 0, 90);
		fl_arc(p.x, p.y, r + r, r + r, 90, 180);
		fl_arc(p.x, p.y + w - r - r - r, r + r, r + r, 180, 270);
		fl_arc(p.x+l-r-r-r, p.y+w-r-r-r, r + r, r + r, 270, 0);		
	}
}
