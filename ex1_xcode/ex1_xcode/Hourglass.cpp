#include "Hourglass.h"


// we're creating a rectangle to repesent our Hourglass.
// with the rectangle bottomLeft and topRight we're able to repesent
// and by then draw the hourglass. as will be shown later in this file.

// intializing the rectangle with the  vertcies of lower and upper.
// ________________________________________
Hourglass::Hourglass(const Triangle &upper, const Triangle &lower)
    : m_boundingRectangle(lower.getVertex(0), upper.getVertex(1))
{
    // if it's not a rectangle will set to fefault hourglass data
    if (!isHourglass(upper, lower))
    {
        m_boundingRectangle = Rectangle(Vertex(20, 20), Vertex(30, 20 + (2 * sqrt(75))));
    }
}
// ________________________________________
Hourglass::Hourglass(const Triangle &lower)
    : m_boundingRectangle(lower.getVertex(0),
                          Vertex(lower.getVertex(1).m_col, lower.getVertex(0).m_row +
                                                               (2 * lower.getHeight())))
{
    // we've got a lower triangle that is valid, new we'll only need to check
    //  if the upper triangle vertex topRight is valid.
    Vertex upper = Vertex(lower.getVertex(1).m_col, lower.getVertex(0).m_row +
                                                      (2 * lower.getHeight()));
    if (!lower.getVertex(0).isValid() || !upper.isValid())
    {
        m_boundingRectangle = Rectangle(Vertex(20, 20), Vertex(30, 20 + (2 * sqrt(75))));
    }
}
// the length of the hourglass will be length of the rectangle
// that is repersenting our hourglass.
// ________________________________
double Hourglass::getLength() const
{
    return abs(m_boundingRectangle.getTopRight().m_col - m_boundingRectangle.getBottomLeft().m_col);
}
// the hight of the hourglass will be the hieght of the rectangle
// _________________________________
double Hourglass::getHeight() const
{
    return m_boundingRectangle.getHeight();
}
// we'll first draw the x of the rectangle, then we'll draw the top line and
// the lower line.
// _____________________________________
void Hourglass::draw(Board &board) const
{
    board.drawLine(m_boundingRectangle.getBottomLeft(), m_boundingRectangle.getTopRight());
    board.drawLine(Vertex(m_boundingRectangle.getBottomLeft().m_col, m_boundingRectangle.getTopRight().m_row),
                   Vertex(m_boundingRectangle.getTopRight().m_col, m_boundingRectangle.getBottomLeft().m_row));
    board.drawLine(m_boundingRectangle.getBottomLeft(),
                   Vertex(m_boundingRectangle.getTopRight().m_col, m_boundingRectangle.getBottomLeft().m_row));
    board.drawLine(m_boundingRectangle.getTopRight(),
                   Vertex(m_boundingRectangle.getBottomLeft().m_col, m_boundingRectangle.getTopRight().m_row));
}
// our rectangle is the bounding rectagle itself.
// ______________________________________________
Rectangle Hourglass::getBoundingRectangle() const
{
    return m_boundingRectangle;
}
// ______________________________
double Hourglass::getArea() const
{
    return getLength() * (getHeight()/2);
}
// ___________________________________
double Hourglass::getPerimeter() const
{
    return 6 * getLength();
}
// the center of the rectangle is the center of the hourglass
// ________________________________
Vertex Hourglass::getCenter() const
{
    return m_boundingRectangle.getCenter();
}
// the scale of the bounding rectangle is scale of the hourglass.
// _________________________________
bool Hourglass::scale(double factor)
{
    return m_boundingRectangle.scale(factor);
}
// checking for hourglass requirements
// ______________________________________________
bool Hourglass::isHourglass(const Triangle &upper,
                            const Triangle &lower)
{
    return isUpperAndLower(upper, lower) && isVertexShared(upper, lower) &&
           isLengthSame(upper, lower) && isVertexValid(upper, lower);
}
// ______________________________________________
bool Hourglass::isVertexValid(const Triangle &upper,
                              const Triangle &lower)
{
    return upper.getVertex(1).isValid() && lower.getVertex(0).isValid();
}
// __________________________________________________
bool Hourglass::isUpperAndLower(const Triangle &upper,
                                const Triangle &lower)
{
    return upper.getVertex(0).isHigherThan(upper.getVertex(2)) &&
           lower.getVertex(2).isHigherThan(lower.getVertex(0));
}
// __________________________________________________
bool Hourglass::isVertexShared(const Triangle &upper,
                               const Triangle &lower)
{
    return doubleEqual(upper.getVertex(2).m_col, lower.getVertex(2).m_col) &&
           doubleEqual(upper.getVertex(2).m_row, lower.getVertex(2).m_row);
}
// __________________________________________________
bool Hourglass::isLengthSame(const Triangle &upper,
                             const Triangle &lower)
{
    return doubleEqual(distance(upper.getVertex(0), upper.getVertex(1)),
                       distance(lower.getVertex(0), lower.getVertex(1)));
}
