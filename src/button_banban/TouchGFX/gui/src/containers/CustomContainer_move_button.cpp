#include <gui/containers/CustomContainer_move_button.hpp>
#include "gui/common/GameController.h"

CustomContainer_move_button::CustomContainer_move_button()
{

}

void CustomContainer_move_button::initialize()
{
    CustomContainer_move_buttonBase::initialize();
}

void CustomContainer_move_button::setParent(GameController *_gc)
{
	gc = _gc;
}

void CustomContainer_move_button::up()
{
	gc->up();
}

void CustomContainer_move_button::down()
{
	gc->down();
}

void CustomContainer_move_button::right()
{
	gc->right();
}

void CustomContainer_move_button::left()
{
	gc->left();
}
