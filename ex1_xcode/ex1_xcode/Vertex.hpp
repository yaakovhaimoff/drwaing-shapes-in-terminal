#pragma once

#include <iosfwd>


struct Vertex
{
    double m_col = 0; // x
    double m_row = 0; // y
    
    // Constructors
    Vertex() = default;
    Vertex(double col, double row) : m_col(col), m_row(row) {}

    // Services
    bool isHigherThan(const Vertex &other) const;
    bool isToTheRightOf(const Vertex &other) const;
    bool isValid() const;
};

std::istream &operator>>(std::istream &istr, Vertex &v);
std::ostream &operator<<(std::ostream &ostr, const Vertex &v);
