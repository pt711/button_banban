#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
	gc = new GameController();
	gc->set_start_finish(&cc_start_finish);
	gc->set_move_button(&cc_move_button);
	gc->set_timer(&cc_timer);
	gc->set_MAP(&c_MAP);
	gc->set_me(&cc_me);
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
    delete(gc);
}

void Screen1View::handleTickEvent()
{
	gc->handleTickEvent();
}
