#ifndef SCREEN_SELECTVIEW_HPP
#define SCREEN_SELECTVIEW_HPP

#include <gui_generated/screen_select_screen/Screen_selectViewBase.hpp>
#include <gui/screen_select_screen/Screen_selectPresenter.hpp>

class Screen_selectView : public Screen_selectViewBase
{
public:
    Screen_selectView();
    virtual ~Screen_selectView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREEN_SELECTVIEW_HPP
