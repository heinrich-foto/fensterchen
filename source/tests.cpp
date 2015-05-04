#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>

#include "point2D.hpp"
#include "circle.hpp"
#include "rectangle.hpp"


// Test Case Aufgabe 2.3
// ======================
// - Der Default-Konstruktor erzeugt einen Punkt im Ursprung.
// - Die Methoden x() und y() geben den x- bzw. y-Wert des Punktes zurück.
// - Eine Methode translate(double, double) kann den Punkt verschieben.
// - Eine Methode rotate(double) rotiert den Punkt im Uhrzeigersinn um
//   den Punkt (0,0). Der Rotationswinkel wird im Bogenmaß angegeben.


TEST_CASE("Point2D() - Default-Konstruktor","[]")
{
    Point2D point{};
    REQUIRE(point.x() == Approx(0.0));
    REQUIRE(point.y() == Approx(0.0));
}

TEST_CASE("Point2D - Methoden x() und y()","[]")
{
    Point2D point{1.0,-1.0};
    REQUIRE(point.x()== 1.0);
    REQUIRE(point.y()==Approx(-1.0));
}


TEST_CASE("Point2D - rotate(double)","[]")
{
    Point2D point{0.3,0};
    point.translate(-0.2,0.1);
    REQUIRE(point.y() == Approx(0.1));
    REQUIRE(point.x() == Approx(0.1));
}

TEST_CASE("Point2D - translate(double, double)","[]")
{
    Point2D point{0.3,0.0};
    point.rotate(M_PI);
    REQUIRE(point.x() == Approx(-0.3));
    REQUIRE(point.y() == Approx( 0.0));
    point.rotate(M_PI/2);
    REQUIRE(point.x() == Approx( 0.0));
    REQUIRE(point.y() == Approx(-0.3));
    point.rotate(-M_PI/2);
    REQUIRE(point.x() == Approx(-0.3));
    REQUIRE(point.y() == Approx( 0.0));
    point.rotate(2*M_PI);
    REQUIRE(point.x() == Approx(-0.3));
    REQUIRE(point.y() == Approx( 0.0));
}

TEST_CASE("Circle - constructor","[circle()]")
{
    Circle c;
    REQUIRE(c.center().x() == Approx(0.0));
    REQUIRE(c.center().y() == Approx(0.0));
    REQUIRE(c.radius()     == Approx(0.1));
    REQUIRE(c.color().r_   == Approx(0.0));
    REQUIRE(c.color().g_   == Approx(0.0));
    REQUIRE(c.color().b_   == Approx(0.0));
}

TEST_CASE("Circle - radius","[circle.radius()]")
{
    Circle c;
    c.radius(0.2);
    REQUIRE(c.radius() == Approx(0.2));
}

TEST_CASE("Circle - translate","[circle.translat()]")
{
    Circle c{Point2D(0.3,0.0), 0.3};
    c.translate(-0.2, 0.1);
    REQUIRE(c.center().x() == Approx(0.1));
    REQUIRE(c.center().y() == Approx(0.1));
    REQUIRE(c.radius()     == Approx(0.3));
}

TEST_CASE("Cirlce - area","[circle.aria()]")
{
    Circle c;
    c.area(0.3);
    REQUIRE(c.area() == Approx(0.3));
}

TEST_CASE("Circle - circumference","[circle.circumference()]")
{
    Circle c{Point2D (0.3,0, Color{}) ,3.939};
    c.circumference(1.0);
    REQUIRE(c.radius() == Approx(0.15915));
    c.radius(393.9);
    REQUIRE(c.circumference() == Approx(2474.94));
}

TEST_CASE("Circle is inside","[circle.is_inside()]")
{
    Circle c {Point2D(3,3),1};
    REQUIRE(c.is_inside({2.5,2.5}));
}


TEST_CASE("Rectangle - constuctor","[rectangle()]")
{
    Rectangle rect{};
    REQUIRE(rect.width() == 0.1);
}

TEST_CASE("Rectangle - translate","[rectangle.translate()]")
{
    Rectangle rect{Point2D (0.2,0.1, Color (1.0,0.0,0.0)),0.2,0.2};
    rect.translate(0.1,0.2);
    REQUIRE(rect.fixpoint().x() == Approx(0.3));
    REQUIRE(rect.fixpoint().y() == Approx(0.3));
}

TEST_CASE("Rectangle - is inside","[rectangle.is_inside()]")
{
    Rectangle rect { Point2D{0.2,0.1,{1.0,0.0,0.0}},0.2,0.2};
    REQUIRE(rect.is_inside({0.3,0.2}));
}


int main(int argc, char *argv[])
{
    return Catch::Session().run(argc, argv);
}
