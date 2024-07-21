
#include <iostream>

class time_error : public std::exception
{
public:
    time_error(const std::string& message) : message{ message }
    {}
    const char* what() const noexcept override
    {
        return message.c_str();     
    }
private:
    std::string message;   
};

class Time
{
public:
    Time(int hours, int minutes, int seconds)
    {
        if (minutes > 60)    
            throw time_error("Invalid minutes");
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }
    void print() const
    {
        std::cout << "hours: " << hours << "\tminutes: " << minutes << "\tseconds: " << seconds << std::endl;
    }
private:
    int hours,  minutes,  seconds;
};

void testTime(int hours, int minutes, int seconds)
{
    try
    {
        Time person{ hours, minutes, seconds};   
        person.print();
    }
    catch (const time_error& err) 
    {
        std::cout << "Person error: " << err.what() << std::endl;
    }
    catch (const std::exception&)  
    {
        std::cout << "Something wrong" << std::endl;
    }
}
int main()
{
    testTime(35,60,23);  
    
}