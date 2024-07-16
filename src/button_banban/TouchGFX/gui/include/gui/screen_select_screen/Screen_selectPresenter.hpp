#ifndef SCREEN_SELECTPRESENTER_HPP
#define SCREEN_SELECTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen_selectView;

class Screen_selectPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen_selectPresenter(Screen_selectView& v);

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

    virtual ~Screen_selectPresenter() {}

private:
    Screen_selectPresenter();

    Screen_selectView& view;
};

#endif // SCREEN_SELECTPRESENTER_HPP
