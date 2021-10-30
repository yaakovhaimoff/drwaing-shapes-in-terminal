#pragma once

#include "Board.h"
#include "Vertex.h"
#include "Triangle.h"
#include "Utilities.h"
#include "Rectangle.h"
#include <iostream>
#include <cmath>

class Hourglass
{
public:
    Hourglass(const Triangle &upper,
              const Triangle &lower);
    Hourglass(const Triangle &lower);

    double getLength() const;
    double getHeight() const;

    void draw(Board &board) const;
    Rectangle getBoundingRectangle() const;
    double getArea() const;
    double getPerimeter() const;
    Vertex getCenter() const;
    bool scale(double factor);

private:
    Rectangle m_boundingRectangle;
    bool isHourglass(const Triangle &upper,
                         const Triangle &lower);
    bool isUpperAndLower(const Triangle &upper,
                         const Triangle &lower);
    bool isVertexShared(const Triangle &upper,
                         const Triangle &lower);
    bool isLengthSame(const Triangle &upper,
                         const Triangle &lower);
    bool isVertexValid(const Triangle &upper,
                         const Triangle &lower);
    bool isUpperValid(const Rectangle boundingRectangle);
};
