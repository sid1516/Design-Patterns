#include <iostream>
#include <vector>
#include <variant>

struct Circle {};
struct Square {};
struct Triangle {};

struct Draw
{
    void operator()(const Circle& circle) const
    {
        std::cout << "Drawing a circle.\n";
    }
    void operator()(const Square& square) const
    {
        std::cout << "Drawing a square.\n";
    }
    void operator()(const Triangle& triangle) const
    {
        std::cout << "Drawing a triangle.\n";
    }
};

struct Print
{
    void operator()(const Circle& circle) const
    {
        std::cout << "Printing a circle.\n";
    }
    void operator()(const Square& square) const
    {
        std::cout << "Printing a square.\n";
    }
    void operator()(const Triangle& triangle) const
    {
        std::cout << "Printing a triangle.\n";
    }
};

int main()
{
    using Shape = std::variant<Circle, Square, Triangle>;

    std::vector<Shape> shapes;
    shapes.emplace_back(Circle{});
    shapes.emplace_back(Square{});
    shapes.emplace_back(Triangle{});

    for(const auto& shape : shapes)
    {
        std::visit(Draw{}, shape);
        std::visit(Print{}, shape);
    }
}
