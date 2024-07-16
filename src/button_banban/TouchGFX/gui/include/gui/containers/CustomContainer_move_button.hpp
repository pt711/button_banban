#ifndef CUSTOMCONTAINER_MOVE_BUTTON_HPP
#define CUSTOMCONTAINER_MOVE_BUTTON_HPP

#include <gui_generated/containers/CustomContainer_move_buttonBase.hpp>

class GameController;

class CustomContainer_move_button : public CustomContainer_move_buttonBase
{
public:
    CustomContainer_move_button();
    virtual ~CustomContainer_move_button() {}
    virtual void initialize();
    virtual void setParent(GameController *_gc);
protected:
    GameController *gc;
    virtual void up();
    virtual void down();
    virtual void right();
    virtual void left();
};

#endif // CUSTOMCONTAINER_MOVE_BUTTON_HPP
