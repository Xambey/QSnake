#ifndef DIRECTION_H
#define DIRECTION_H


class CommonDate //class, showing the direction of movement ItemSnake
{
protected:
    enum Direction
    {
        Right,
        Left,
        Up,
        Down,
        TurnRightUp,
        TurnLeftUp,
        TurnRightDown,
        TurnLeftDown,
        RightHead,
        LeftHead,
        UpHead,
        DownHead
    };
};

#endif // DIRECTION_H
