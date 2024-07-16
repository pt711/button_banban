#ifndef SCREEN_TITLEPRESENTER_HPP
#define SCREEN_TITLEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen_titleView;

class Screen_titlePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen_titlePresenter(Screen_titleView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Screen_titlePresenter() {}

private:
    Screen_titlePresenter();

    Screen_titleView& view;
};

#endif // SCREEN_TITLEPRESENTER_HPP
