void Frowny::draw_lines() const
{
	Circle::draw_lines();
	if (color().visibility())
	{
		fl_arc(point(0).x + r / 2, point(0).y + r / 2, r / 8, r / 8, 0, 360);
		fl_arc(point(0).x + 1.3*r, point(0).y + r / 2, r / 8, r / 8, 0, 360);
		fl_arc(point(0).x + r / 2, point(0).y + r, r, r, 20, 160);
	}

}



void Smiley::draw_lines() const
{
	Circle::draw_lines();
	if (color().visibility())
	{
		fl_arc(point(0).x + r / 2, point(0).y + r / 2, r / 8, r / 8, 0, 360);
		fl_arc(point(0).x + 1.3*r, point(0).y + r / 2, r / 8, r / 8, 0, 360);
		fl_arc(point(0).x + r / 2, point(0).y + r / 2, r, r, 200, 340);
	}
}

class Hat_smiley : public Smiley
{
public:
	using Smiley::Smiley;

	void draw_lines() const;

private:
	int r = radius();


};
void Hat_smiley::draw_lines() const
{
	Smiley::draw_lines();
	Point head_point1{ int(point(0).x + r - r * cos(0.25*PI)), int(point(0).y + r - r * sin(0.25*PI)) };
	Point hat_height1{ head_point1.x , int(head_point1.y - 0.5*r) };
	Point head_point2{ int(point(0).x + r + r * cos(0.25*PI)), int(point(0).y + r - r * sin(0.25*PI)) };
	Point hat_height2{ head_point2.x , int(head_point2.y - 0.5*r) };

	if (color().visibility())
	{
		fl_line(head_point1.x, head_point1.y, hat_height1.x, hat_height1.y, hat_height2.x, hat_height2.y);
		fl_line(hat_height2.x, hat_height2.y, head_point2.x, head_point2.y);
	}

}

