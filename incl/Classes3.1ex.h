#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>

struct Bounding_Box_Dimensions
{
    double x = 0, y = 0;
};
class Shape
{
public:
    virtual double square() = 0; // возвращает площадь конкретной фигуры;
    virtual Bounding_Box_Dimensions dimensions() = 0; // размеры описывающего прямоугольника;
    virtual std::string type() = 0; // название конкретного типа, например, вернуть строку Triangle для класса Triangle;
    void print_Params()
    {
        std::cout << "Type: " << this->type() << std::endl;
        std::cout << "Square: " << this->square() << std::endl;
        std::cout << "Width: " << this->dimensions().x << std::endl;
        std::cout << "Height: " << this->dimensions().y << std::endl;
    }
};

// сюда можно будет передавать любые фигуры:


class Circle: public Shape
{
private:
    double rad = 0;
public:
    Circle(double in_rad) : rad(in_rad)
    {
        if(in_rad < 0 || in_rad > 50)
        {
            std::cerr << "Invalid num or bigger than 50";
        }
    }
    double square() override
    {
        double result = M_PI *std::pow(rad, 2);
        return result;
    }
    Bounding_Box_Dimensions dimensions() override
    {
        Bounding_Box_Dimensions temp{rad*2, temp.x};
        return temp;
    }
    std::string type() override
    {
        return "Circle";
    }
};

class Rectangle : public Shape
{
    double x, y;
public:
    Rectangle(double in_x, double in_y): x(in_x), y(in_y)
    {
        if(in_x < 0 || in_y < 0)
        {
            std::cerr << "We dont work with imaginary unit" << std::endl;
        }

    }
    double square() override
    {
        return (this->x * this->y);
    }
    Bounding_Box_Dimensions dimensions() override
    {
        Bounding_Box_Dimensions temp {x,y};
        return temp;
    }
    std::string type() override
    {
        return "Rectangle";
    }
};

class Triangle: public Shape
{
    double a, b, c;
    double p = (a + b + c)/2;
public:
    Triangle(double in_a, double in_b, double in_c): a(in_a), b(in_b), c(in_c )
    {
        if(in_a < 0 || in_b < 0 || in_c < 0)
        {
            std::cerr << "We dont work with imaginary unit" << std::endl;
        }

    }
    double square() override
    {
        return std::sqrt(p * (p - a) * (p - b) * (p - c));
    }
    Bounding_Box_Dimensions dimensions() override
    {
        Bounding_Box_Dimensions temp {};
        temp.x = (a * b * c / (4 * sqrt(p*(p - a)*(p - b)*(p - c))) * 2);
        temp.y = temp.x;
        return temp;
    }
    std::string type() override
    {
        return "Triangle";
    }
};
