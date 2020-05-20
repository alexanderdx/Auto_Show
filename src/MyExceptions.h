#pragma once

#include <exception>

class InvalidCombustibil : public std::exception
{
    const char* exceptie;
public:
    InvalidCombustibil() : exceptie("\nCombustibil invalid! Introduceti unul din cele afisate...\n") {}
    InvalidCombustibil(const char* exceptie) : exceptie(exceptie) {}

    const char* what() const noexcept
    {
        return exceptie;
    }
};

class InvalidCutieViteze : public std::exception
{
    const char* exceptie;
public:
    InvalidCutieViteze() : exceptie("\nCutie de viteze invalida! Introduceti una din cele afisate...\n") {}
    InvalidCutieViteze(const char* exceptie) : exceptie(exceptie) {}

    const char* what() const noexcept
    {
        return exceptie;
    }
};