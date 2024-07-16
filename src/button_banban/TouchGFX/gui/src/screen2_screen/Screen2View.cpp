#include <gui/screen2_screen/Screen2View.hpp>

Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
	gc = new GameController();
	gc->set_start_finish(&cc_start_finish);
	gc->set_move_button(&cc_move_button);
	gc->set_timer(&cc_timer);
	gc->set_MAP(&c_MAP);
	gc->set_me(&cc_me);
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
    delete(gc);
}

void Screen2View::handleTickEvent()
{
	gc->handleTickEvent();
}
