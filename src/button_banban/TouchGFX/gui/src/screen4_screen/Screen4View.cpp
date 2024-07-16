#include <gui/screen4_screen/Screen4View.hpp>

Screen4View::Screen4View()
{

}

void Screen4View::setupScreen()
{
    Screen4ViewBase::setupScreen();
	gc = new GameController();
	gc->set_start_finish(&cc_start_finish);
	gc->set_move_button(&cc_move_button);
	gc->set_timer(&cc_timer);
	gc->set_MAP(&c_MAP);
	gc->set_me(&cc_me);
}

void Screen4View::tearDownScreen()
{
    Screen4ViewBase::tearDownScreen();
    delete(gc);
}

void Screen4View::handleTickEvent()
{
	gc->handleTickEvent();
}
