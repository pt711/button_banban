#ifndef CUSTOMCONTAINER_START_FINISH_HPP
#define CUSTOMCONTAINER_START_FINISH_HPP

#include <gui_generated/containers/CustomContainer_start_finishBase.hpp>

class GameController;

class CustomContainer_start_finish : public CustomContainer_start_finishBase
{
public:
    CustomContainer_start_finish();
    virtual ~CustomContainer_start_finish() {}
    virtual void initialize();
    virtual void setParent(GameController *_gc);
    virtual void init();
    virtual void finish(int sec, int msec);
protected:
    GameController *gc;
    virtual void start();
    virtual void retry();
    virtual void toggle_screen_button_1();
    virtual void toggle_screen_button_2();
    virtual void tick();
    virtual int sec();
    virtual int msec();
    int timer_count = 0;
    int count_flag = 0;
};

#endif // CUSTOMCONTAINER_START_FINISH_HPP
