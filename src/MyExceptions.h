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

class OverflowExpo : public std::exception
{
    const char* exceptie;
public:
    OverflowExpo() : exceptie("\nOverflow! Toate locurile din expozitie sunt ocupate...\n") {}
    OverflowExpo(const char* exceptie) : exceptie(exceptie) {}

    const char* what() const noexcept
    {
        return exceptie;
    }
};

class InvalidCarType : public std::exception
{
    const char* exceptie;
public:
    InvalidCarType() : exceptie("\nTip invalid! Incercati din nou... ") {}
    InvalidCarType(const char* exceptie) : exceptie(exceptie) {}

    const char* what() const noexcept
    {
        return exceptie;
    }
};