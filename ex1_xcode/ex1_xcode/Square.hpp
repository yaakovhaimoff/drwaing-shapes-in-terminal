#pragma once
#include "Board.h"
#include "Vertex.h"
#include "Rectangle.h"

class Square
{
public:
    Square(const Vertex &bottomLeft, const Vertex &topRight);
    Square(const Vertex &start, double length);

    Vertex getBottomLeft() const;
    Vertex getTopRight() const;
    double getLength() const;

    void draw(Board &board) const;
    Rectangle getBoundingRectangle() const;
    double getPerimeter() const;
    double getArea() const;
    Vertex getCenter() const;
    bool scale(double factor);

private:
    Rectangle m_square;
};
