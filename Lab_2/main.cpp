#include <iostream>

class Square
{
    int m_a;

public:
    Square(int a)
    {
        std::cout << "SSS(Class created)\n" << std::endl;
        setA(a);
    }
    Square(const Square& other)
    {
        std::cout << "SSS(Class copyed)\n" << std::endl;
        m_a = other.m_a;
    }

    ~Square()
    {
        std::cout << "SSS(Class deleted)\n" << std::endl;
    }

    
    // Setters
    void setA(int a)
    {
        if (a >= 500 || a <= 0)
        {
            std::cout <<"Wrong A!\n" << std::endl;
            m_a = -1;
            return;
        }
        m_a = a;
    }

    // Getters
    int getA()
    {
        if (m_a > 0 && m_a < 500)
        {
            return m_a;
        }
        else
        {
            std::cout << "Wrong A!\n" << std::endl;
        }
    }

    // Funcs
    float Diag()
    {
        if (m_a > 0 && m_a < 500)
        {
            float d = m_a * pow(2, 0.5);
            return d;
        }
        else
        {
            std::cout << "Wrong A!\n" << std::endl;
        }
    }
    void Info()
    {
        if (m_a > 0 && m_a < 500)
        {
            std::cout << "Side: " << m_a << "\tDiagonal: " << m_a * pow(2, 0.5)<< "\n" << std::endl;
        }
        else
        {
            std::cout << "Wrong A!\n" << std::endl;
        }
    }
};

class Circle
{
    float m_r;

public:
    Circle(Square s)
    {
        std::cout << "CCC(Class created)\n" << std::endl;
        m_r = s.Diag() / 2;
    }
    Circle(const Circle& other)
    {
        std::cout << "CCC(Class copyed)\n" << std::endl;
        m_r = other.m_r;
    }

    ~Circle()
    {
        std::cout << "CCC(Class deleted)\n" << std::endl;
    }

    // Getters
    float getR()
    {
        return m_r;
    }

    // Funcs
    float Sqr()
    {
        float sqr = acos(-1) * m_r * m_r;
        return sqr;
    }
};

int main()
{
    Square s(12);
    s.Info();

    Circle c(50);
    std::cout << c.Sqr() << std::endl;

    return 0;
}