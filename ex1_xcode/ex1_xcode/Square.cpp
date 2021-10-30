#include <iostream>
#include "Square.h"

Rectangle defSquare = Rectangle(Vertex(20, 10), Vertex(30, 20));

// main constructor which the second construtor will go threw as well.
// we're restarting the values in the square members, and will
// only change them if the square will return false in the requirements.
// _____________________________________________________________
Square::Square(const Vertex &bottomLeft, const Vertex &topRight)
    : m_square(bottomLeft, topRight)
{
    if (!doubleEqual(distance(bottomLeft, Vertex(topRight.m_col, bottomLeft.m_row)),
                    distance(Vertex(topRight.m_col, bottomLeft.m_row), topRight)))
    {
        m_square = defSquare;
    }
}
// using rectangle function to get the left bottom of the square
// _______________________________________________
Square::Square(const Vertex &start, double length)
    : m_square(start, Vertex(length + start.m_row,
                             length + start.m_col)) {}
// ________________________________________________________
Vertex Square::getBottomLeft() const
{
    return m_square.getBottomLeft();
}
// using rectangle function to get the top right of the square
// _____________________________________________________
Vertex Square::getTopRight() const
{
    return m_square.getTopRight();
}
// _____________________________________________
double Square::getLength() const
{
    return abs(m_square.getBottomLeft().m_col - m_square.getTopRight().m_col);
}
// using rectangle function to draw the square
// __________________________________
void Square::draw(Board &board) const
{
    m_square.draw(board);
}
// ___________________________________________
Rectangle Square::getBoundingRectangle() const
{
    return Rectangle(m_square.getBottomLeft(), m_square.getTopRight());
}
// using rectangle function to get area of the square
// ___________________________
double Square::getArea() const
{
    return m_square.getArea();
}
// using rectangle function to get the perimeter of the square
// ___________________________________
double Square::getPerimeter() const
{
    return m_square.getPerimeter();
}
// using rectangle function to get the center of the square
// ______________________________
Vertex Square::getCenter() const
{
    return m_square.getCenter();
}
// using rectangle function to get the center of the square
// ______________________________
bool Square::scale(double factor)
{
    return m_square.scale(factor);
}
