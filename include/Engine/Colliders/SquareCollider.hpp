/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** SquareCollider
*/

#ifndef SQUARECOLLIDER_HPP_
#define SQUARECOLLIDER_HPP_

class SquareCollider {
    public:
        SquareCollider() {}
        SquareCollider(float, float, float, float);
        ~SquareCollider() = default;
        float GetUp();
        float GetDown();
        float GetLeft();
        float GetRight();
        void SetUp(float);
        void SetDown(float);
        void SetLeft(float);
        void SetRight(float);
    protected:
    private:
        float _up;
        float _down;
        float _left;
        float _right;
};

#endif /* !SQUARECOLLIDER_HPP_ */
