#pragma once

#include "Board.h"
#include "Vertex.h"
#include "Rectangle.h"
#include "Utilities.h"
#include "Rectangle.h"
#include <cmath>

class Triangle
{
public:
    Triangle(const Vertex vertcies[3]);
    Triangle(const Vertex &v0,
             const Vertex &v1, double height);
    Vertex getVertex(int index) const;
    double getLength() const;
    double getHeight() const;

    void draw(Board &board) const;
    Rectangle getBoundingRectangle() const;
    double getArea() const;
    double getPerimeter() const;
    Vertex getCenter() const;
    bool scale(double factor);

private:
    Vertex m_triangleVertex0;
    Vertex m_triangleVertex1;
    Vertex m_triangleVertex2;
    Vertex getLeftVertexForBounding() const;
    Vertex getRightVertexForBounding() const;
    bool isTriangle(const Vertex v0, const Vertex v1, const Vertex v2) const;
    bool isTriangleVertexValid(const Vertex v0, const Vertex v1, const Vertex v2) const;
    bool isTriangleLengthValid(const Vertex v0, const Vertex v1, const Vertex v2) const;
};
