#ifndef CUSTOMCONTAINER_TIMER_HPP
#define CUSTOMCONTAINER_TIMER_HPP

#include <gui_generated/containers/CustomContainer_timerBase.hpp>

class CustomContainer_timer : public CustomContainer_timerBase
{
public:
    CustomContainer_timer();
    virtual ~CustomContainer_timer() {}

    virtual void initialize();
    virtual void init();
    virtual void start();
    virtual void finish();
    virtual int sec();
    virtual int msec();
protected:
    virtual void ticker();
    int timer_count = 0;
    int count_flag = 0;
};

#endif // CUSTOMCONTAINER_TIMER_HPP
