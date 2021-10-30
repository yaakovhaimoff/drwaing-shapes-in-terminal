#include <iostream>
#include <string>
#include <string_view>
#include <array>

#include "macros.h"
#include "Vertex.h"
#include "Board.h"

#define RECTANGLE           1
#define TRIANGLE            1
#define SQUARE              1
#define HOURGLASS           1

#if RECTANGLE
#include "Rectangle.h"
void printInfo(const Rectangle&);
#endif

#if TRIANGLE
#include "Triangle.h"
void printInfo(const Triangle&);
#endif

#if SQUARE
#include "Square.h"
void printInfo(const Square&);
#endif

#if HOURGLASS
#include "Hourglass.h"
void printInfo(const Hourglass&);
#endif

void waitForEnter();
Vertex readVertex(std::string_view vertexName, std::string_view shapeName);

template <typename Shape>
void useShape(Shape& shape, std::string_view shapeName);

template <typename Shape>
void draw(const Shape& shape, Board&);

template <typename Shape>
void printGenericInfo(const Shape& shape, std::string_view shapeName);

int main()
{
#if RECTANGLE
    {
        static constexpr auto shapeName = std::string_view("rectangle");

        const auto vertices = std::array<Vertex, 2>
        {
            readVertex("bottom-left", shapeName),
            readVertex("top-right", shapeName)
        };

        std::cin.ignore(); // ignore the enter

        auto rectangle = Rectangle(vertices.data());
        useShape(rectangle, shapeName);
    }
#endif // RECTANGLE

#if TRIANGLE
    {
        static constexpr auto shapeName = std::string_view("triangle");

        const auto vertices = std::array<Vertex, 3>
        {
            readVertex("first", shapeName),
            readVertex("second", shapeName),
            readVertex("third", shapeName)
        };

        std::cin.ignore(); // ignore the enter

        auto triangle = Triangle(vertices.data());
        useShape(triangle, shapeName);
    }
#endif // TRIANGLE

#if SQUARE
    {
        static constexpr auto shapeName = std::string_view("square");

        const auto bottomLeft = readVertex("bottom-left", shapeName);
        const auto topRight   = readVertex("top-right", shapeName);

        std::cin.ignore(); // ignore the enter

        auto square = Square(bottomLeft, topRight);
        useShape(square, shapeName);
    }
#endif // SQUARE

#if HOURGLASS
    {
        static constexpr auto shapeName = std::string_view("hourglass");
        static constexpr auto partOfTheShapeName = std::string_view("lower triangle of the hourglass");

        const auto vertices = std::array<Vertex, 3>
        {
            readVertex("first", partOfTheShapeName),
            readVertex("second", partOfTheShapeName),
            readVertex("third", partOfTheShapeName)
        };

        std::cin.ignore(); // ignore the enter

        auto hourglass = Hourglass(Triangle(vertices.data()));
        useShape(hourglass, shapeName);
    }
#endif // HOURGLASS
}

#if RECTANGLE
void printInfo(const Rectangle& rectangle)
{
    static constexpr auto shapeName = std::string_view("rectangle");

    const auto printVertex = [](const Vertex& v, std::string_view vertexName)
    {
        std::cout << "The " << vertexName << " vertex of the " << shapeName
            << " is: " << v << '\n';
    };

    printVertex(rectangle.getBottomLeft(), "bottom-left");
    printVertex(rectangle.getTopRight(), "top-right");
}
#endif // RECTANGLE

#if TRIANGLE
void printInfo(const Triangle& triangle)
{
    static constexpr auto shapeName = std::string_view("triangle");

    std::cout << "The vertices of the " << shapeName << " are:\n";
    for (int i = 0; i < 3; ++i)
    {
        std::cout << triangle.getVertex(i) << '\n';
    }

    std::cout << "The length of each side of the " << shapeName << " is: "
        << triangle.getLength() << '\n';
}
#endif // TRIANGLE

#if SQUARE
void printInfo(const Square& square)
{
    static constexpr auto shapeName = std::string_view("square");

    const auto printVertex = [](const Vertex& v, std::string_view vertexName)
    {
        std::cout << "The " << vertexName << " vertex of the " << shapeName
            << " is: " << v << '\n';
    };

    printVertex(square.getBottomLeft(), "bottom-left");
    printVertex(square.getTopRight(), "top-right");

    std::cout << "The length of each side of the " << shapeName << " is: "
        << square.getLength() << '\n';
}
#endif // SQUARE

#if HOURGLASS
void printInfo(const Hourglass& hourglass)
{
    static constexpr auto shapeName = std::string_view("hourglass");

    std::cout << "The length of each side of the " << shapeName << " is: "
        << hourglass.getLength() << '\n';

    std::cout << "The height of the " << shapeName << " is: "
        << hourglass.getHeight() << '\n';
}
#endif // HOURGLASS

void waitForEnter()
{
    std::cout << "Press Enter to continue...\n";
    auto line = std::string();
    std::getline(std::cin, line);
}

Vertex readVertex(std::string_view vertexName, std::string_view shapeName)
{
    std::cout << "Please enter x and y coordinates for the " << vertexName
        << " vertex of the " << shapeName << ":\n";
    auto v = Vertex();
    std::cin >> v;
    return v;
}

template<typename Shape>
void useShape(Shape& shape, std::string_view shapeName)
{
    auto board = Board();
    auto print = [&]
    {
        draw(shape, board);
        printInfo(shape);
        printGenericInfo(shape, shapeName);
        waitForEnter();
    };

    print();

    board.clear();
    std::cout << "Now scaled by factor of 2:\n\n";
    if (shape.scale(2))
    {
        print();
    }
    else
    {
        std::cout << "Scaling failed!\n";
        waitForEnter();
    }
}

template<typename Shape>
void draw(const Shape& shape, Board& board)
{
    shape.draw(board);
    board.print();
    waitForEnter();

    std::cout << "Now with the bounding rectangle:\n";
    auto boundingRect = shape.getBoundingRectangle();
    boundingRect.draw(board);
    board.print();
    waitForEnter();
}

template<typename Shape>
void printGenericInfo(const Shape& shape, std::string_view shapeName)
{
    std::cout << "The perimeter of the " << shapeName << " is: " <<
        shape.getPerimeter() << '\n';

    std::cout << "The area of the " << shapeName << " is: " <<
        shape.getArea() << '\n';

    std::cout << "The center of the " << shapeName << " is: " <<
        shape.getCenter() << '\n';
}
