#include <gui/containers/CustomContainer_timer.hpp>

CustomContainer_timer::CustomContainer_timer()
{
}

void CustomContainer_timer::initialize()
{
    CustomContainer_timerBase::initialize();
    init();
}

void CustomContainer_timer::init()
{
    timer_count = 0;
    count_flag = 0;
	Unicode::snprintf(text_timerBuffer, TEXT_TIMER_SIZE, "%02d.%02d", 0, 0);
	text_timer.invalidate();
}

void CustomContainer_timer::start()
{
	count_flag = 1;
}

void CustomContainer_timer::finish()
{
	count_flag = 2;
}

int CustomContainer_timer::sec()
{
	return (int)timer_count / 60;
}

int CustomContainer_timer::msec()
{
	return (int)(int(timer_count / 0.6) % 100);
}
void CustomContainer_timer::ticker()
{
    //  6 Ticks = 0.1秒
    // 60 Ticks = 1.0秒
    //  1 Ticks = 1/60秒
    // 10 Ticks = 1/6秒
	// sec  = timer_count / 60;
	// msec = int(timer_count / 0.6) % 100;

    if(count_flag == 1)
    {
		timer_count++;
		Unicode::snprintf(text_timerBuffer, TEXT_TIMER_SIZE, "%02d.%02d", sec(), msec());
		text_timer.invalidate();
    }
}
