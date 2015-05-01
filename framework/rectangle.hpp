#ifndef BUW_RECTANGLE_HPP
#define BUW_RECTANGLE_HPP

#include <iostream>
#include "point2D.hpp"
#include "color.hpp"

/* Uebung 2 */


class Window; // include weglassbar. - Vorwärtsdeklaration, wenn größe nicht bekannt sein muss.

class Rectangle {
public:
    Rectangle();										// Standart Konstruktor
    Rectangle(Point2D const& leftdowncorner); // const& bei built in typen weglassen.
    Rectangle(Point2D const& leftdowncorner,
              double const& lenght_x,
              double const& lenght_y);
    ~Rectangle();										// Destruktor
    
    void center(Point2D const& centerPoint);			// Mittelpunkt
    Point2D center() const;
    
    void fixpoint(Point2D const& leftdowncorner);
    Point2D fixpoint()const;
    
    void width(double const& lenght_x);
    double width() const;
    
    void height(double const& lenght_y);
    double height() const;
    
    
    void draw(Window & win) const;
    void draw(Window & win, Color const& color) const;
    
    void color(Color const& colorValue);			// Setzt Farbe
    Color color() const;							// Gibt Farbe zurück
    
    void translate(double const& x_transition, double const& y_transition);
    
    float area() const;
    
    float circumference() const;
    
    bool is_inside(Point2D point) const;
    
    //float distance(Point2D const& pointA, Point2D const& PointB);
    
private:
    Point2D 	leftdowncorner_;
    double		lenght_x_; 			// width
    double		lenght_y_;			// height
    Color 		color_;
};

#endif // BUW_RECTANGLE_HPP