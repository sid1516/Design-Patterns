#include <iostream>
#include <memory>
#include <vector>

struct Circle;
struct Square;
struct Triangle;
struct ShapeVisitor
{
    virtual ~ShapeVisitor() = default;
    virtual void visit(const Circle&) const = 0;
    virtual void visit(const Square&) const = 0;
    virtual void visit(const Triangle&) const = 0;
};

struct Draw : ShapeVisitor
{
    void visit(const Circle&) const override
    {
        std::cout << "Drawing a circle.\n";
    }
    void visit(const Square&) const override
    {
        std::cout << "Drawing a square.\n";
    }
    void visit(const Triangle&) const override
    {
        std::cout << "Drawing a triangle.\n";
    }
};

struct Print : ShapeVisitor
{
    void visit(const Circle&) const override
    {
        std::cout << "Printing a circle.\n";
    }
    void visit(const Square&) const override
    {
        std::cout << "Printing a square.\n";
    }
    void visit(const Triangle&) const override
    {
        std::cout << "Printing a triangle.\n";
    }
};

struct Shape
{
    virtual ~Shape() = default;
    virtual void accept(const ShapeVisitor&) = 0;
};

struct Circle : Shape
{
    void accept(const ShapeVisitor& shape_visitor) override
    {
        shape_visitor.visit(*this);
    }
};
struct Square : Shape
{
    void accept(const ShapeVisitor& shape_visitor) override
    {
        shape_visitor.visit(*this);
    }
};

struct Triangle : Shape
{
    void accept(const ShapeVisitor& shape_visitor) override
    {
        shape_visitor.visit(*this);
    }
};

int main()
{
    using Shapes = std::vector<std::unique_ptr<Shape>>;
    Shapes shapes;
    shapes.emplace_back(std::make_unique<Circle>());
    shapes.emplace_back(std::make_unique<Square>());
    shapes.emplace_back(std::make_unique<Triangle>());

    for(const auto& shape : shapes)
    {
        shape -> accept(Draw{});
        shape -> accept(Print{});
    }

}
