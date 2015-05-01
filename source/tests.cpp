#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>

#include "point2D.hpp"
#include "circle.hpp"


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

TEST_CASE("Circle - construxtor","[circle()]")
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

int main(int argc, char *argv[])
{
    return Catch::Session().run(argc, argv);
}
