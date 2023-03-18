// homework3-8-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

class forbidden_length_exception : public std::exception
{
public:
    const char* what() const override
    {
        return "Вы ввели слово запретной длины! До свидания";
    }
};

int function(std::string str, int forbidden_length)
{
    if (str.size() == forbidden_length) throw forbidden_length_exception();
    return str.size();
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int forbidden_length;
    std::string str;
    std::cout << "Введите запретную длину :";
    std::cin >> forbidden_length;

    try
    {
        while (true)
        {
            std::cout << "Введите слово: ";
            std::cin >> str;
            std::cout << "Длина слова \"" << str << "\" равна " << function(str, forbidden_length) << std::endl;
        }
    }
    catch (const forbidden_length_exception& ex)
    {
        std::cout << ex.what();
    }

}
