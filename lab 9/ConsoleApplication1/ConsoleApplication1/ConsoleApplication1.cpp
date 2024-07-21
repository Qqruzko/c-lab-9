
#include <iostream>
#include <cmath>
class Triangle
{
public:
    int a, b, c;
    Triangle(int a_in, int b_in, int c_in)
    {
        a = a_in;
        b = b_in;
        c = c_in;
    }

    void ploschad()
    {
        
        

        try {
           
            if ((a > b + c) || (b  > a + c) || (c > a + b))
            {
                throw std::runtime_error("Одна сторона больше суммы двух других");
                
            }
            int p = a + b + c;
            int result = sqrt((p * (p - a) * (p - b) * (p - c)));
            std::cout << "Result: " << result << std::endl;
        }
        catch (const std::exception& e) {
            // Exception handling code
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";
    Triangle triangle1(2,2,2);
    triangle1.ploschad();
}

