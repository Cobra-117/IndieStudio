/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** kjhgfd
*/

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include "./indie.hpp"

class Exceptions : std::exception
{
    public:
        Exceptions(std::string const &message) {
            _message = message;
        };
        const char *what() const noexcept override {
            return _message.data();
        }
    private:
        std::string _message;
};

#endif
