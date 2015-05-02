#include "rectangle.hpp"
#include "Point2D.hpp"
#include "Color.hpp"
#include "window.hpp"
#include <cmath>
//#include "v2.hpp"

/* Uebung 2 */

/*	Color 		color_;
	Point2D 		leftdowncorner_;
	double			lenght_x_; 			// width
	double			lenght_y_;			// height */

Rectangle::Rectangle():
leftdowncorner_{0,0},
lenght_x_(0.1),
lenght_y_(0.1),
color_{}
{ }
Rectangle::Rectangle(Point2D const& leftdowncorner):
leftdowncorner_{leftdowncorner},
lenght_x_(0.1),
lenght_y_(0.1),
color_{}
{
    color_ = leftdowncorner_.color();
}
Rectangle::Rectangle(Point2D const& leftdowncorner,
                     double const& lenght_x,
                     double const& lenght_y) :
leftdowncorner_{leftdowncorner},
lenght_x_(lenght_x),
lenght_y_(lenght_y),
color_{}
{
    if (lenght_y<0) lenght_y_=0;
    if (lenght_x<0) lenght_x_=0;
    color_ = leftdowncorner_.color();
}

Rectangle::~Rectangle() {
    //std::cout << "Rectangle destroyed <-- " << leftdowncorner_ << std::endl;
}

void Rectangle::center(Point2D const& centerPoint)
{
    // Verschiebt das Rechteck.
    double x = centerPoint.x()- ( lenght_x_ /2);
    double y = centerPoint.y()- ( height() /2);
    leftdowncorner_ = Point2D (x,y,Color(leftdowncorner_.color()));
    
}
Point2D Rectangle::center() const
{
    double x = leftdowncorner_.x()+ (lenght_x_/2);
    double y = leftdowncorner_.y()+ (lenght_y_/2);
    return Point2D(x,y,Color( color_ ));
}
void Rectangle::fixpoint(Point2D const& leftdowncorner)
{
    leftdowncorner_=leftdowncorner;
}
Point2D Rectangle::fixpoint()const
{
    return leftdowncorner_;
}

void Rectangle::width(double const& lenght_x) {
    if (lenght_x > 0) lenght_x_ = lenght_x;
}
double Rectangle::width() const {
    return lenght_x_;
}

void Rectangle::height(double const& lenght_y) {
    if (lenght_y>0) lenght_y_=lenght_y;
}
double Rectangle::height() const {
    return lenght_y_;
}


void Rectangle::draw(Window & win) const {
    // this -> nicht notwendig, weil Classe Kennt seine Membermethoden.
    draw(win,color_);
}

void Rectangle::draw(Window & win, Color const& color) const
{
    double x = leftdowncorner_.x();
    double y = leftdowncorner_.y();
    double h = lenght_y_;
    double w = lenght_x_;
    
    win.drawLine(x,y,x,y+h,color.r_,color.g_,color.b_);
    win.drawLine(x,y+h,x+w,y+h,color.r_,color.g_,color.b_);
    win.drawLine(x+w,y+h,x+w,y,color.r_,color.g_,color.b_);
    win.drawLine(x+w,y,x,y,color.r_,color.g_,color.b_);
}

void Rectangle::color(Color const& colorValue)			// Setzt Farbe
{
    color_=colorValue;
}
Color Rectangle::color() const							// Gibt Farbe zurück
{
    return color_;
}
void Rectangle::translate(double const& x_transition, double const& y_transition)
{
    double x = leftdowncorner_.x()+x_transition;
    double y = leftdowncorner_.y()+y_transition;
    leftdowncorner_= Point2D(x,y,color_);
}

float Rectangle::area() const
{
    return lenght_x_ * lenght_y_;
}

float Rectangle::circumference() const
{
    return 2* lenght_y_ + 2* lenght_x_;
}

bool Rectangle::is_inside(Point2D point) const
{
    if ( (leftdowncorner_.x()<= point.x()) && (leftdowncorner_.x() + lenght_x_ >= point.x()) && (leftdowncorner_.y() <= point.y()) && (leftdowncorner_.y()+lenght_y_ >= point.y()) )
    {
        return true;	
    }
    else
    {
        return false;
    }
}