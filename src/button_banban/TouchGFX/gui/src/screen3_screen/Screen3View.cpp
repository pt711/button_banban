#include <gui/screen3_screen/Screen3View.hpp>

Screen3View::Screen3View()
{

}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();
	gc = new GameController();
	gc->set_start_finish(&cc_start_finish);
	gc->set_move_button(&cc_move_button);
	gc->set_timer(&cc_timer);
	gc->set_MAP(&c_MAP);
	gc->set_me(&cc_me);
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
    delete(gc);
}

void Screen3View::handleTickEvent()
{
	gc->handleTickEvent();
}
