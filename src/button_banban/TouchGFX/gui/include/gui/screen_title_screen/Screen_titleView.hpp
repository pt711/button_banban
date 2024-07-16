#ifndef SCREEN_TITLEVIEW_HPP
#define SCREEN_TITLEVIEW_HPP

#include <gui_generated/screen_title_screen/Screen_titleViewBase.hpp>
#include <gui/screen_title_screen/Screen_titlePresenter.hpp>

class Screen_titleView : public Screen_titleViewBase
{
public:
    Screen_titleView();
    virtual ~Screen_titleView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREEN_TITLEVIEW_HPP
