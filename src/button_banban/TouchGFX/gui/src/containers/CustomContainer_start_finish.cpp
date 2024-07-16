#include <gui/containers/CustomContainer_start_finish.hpp>
#include "gui/common/GameController.h"
#include <random>

CustomContainer_start_finish::CustomContainer_start_finish()
{

}

void CustomContainer_start_finish::initialize()
{
    CustomContainer_start_finishBase::initialize();
}

void CustomContainer_start_finish::setParent(GameController *_gc)
{
	gc = _gc;
}

void CustomContainer_start_finish::init()
{
	// 画面表示初期化
	c_start.setVisible(true);
	c_finish.setVisible(false);
	setVisible(true);
	invalidate();
}

void CustomContainer_start_finish::start()
{
	// スタート非表示
	c_start.setVisible(false);

	// カウントダウン表示
	count_flag = 1;
	timer_count = 1 * 60; // 1sec
	c_countdown.setVisible(true);
	invalidate();
}

void CustomContainer_start_finish::finish(int sec, int msec)
{
	// 飛び出すキャラ初期化
	ga1.setXY(-220, -220);
	ga2.setXY(-220, -220);
	ga3.setXY(-220, -220);

	gb1.setXY(800, -220);
	gb2.setXY(800, -220);
	gb3.setXY(800, -220);

	gc1.setXY(-200, 500);
	gc2.setXY(-200, 500);
	gc3.setXY(-200, 500);

	gd1.setXY(800, 500);
	gd2.setXY(800, 500);
	gd3.setXY(800, 500);

	// finish表示
	Unicode::snprintf(t_time_finishBuffer, T_TIME_FINISH_SIZE, "%02d.%02d", sec, msec);
	c_finish.setVisible(true);

	// 左上
	touchgfx::MoveAnimator< touchgfx::Image > *m_ga = nullptr;
	switch(rand()%4) {
	case 0:
		// 画像無し
		break;
	case 1:
		m_ga = &ga1;
		break;
	case 2:
		m_ga = &ga2;
		break;
	case 3:
		m_ga = &ga3;
		break;
	}
	if (m_ga != nullptr)
	{
		m_ga->clearMoveAnimationEndedAction();
		m_ga->startMoveAnimation(-50, -50, 30, touchgfx::EasingEquations::elasticEaseOut, touchgfx::EasingEquations::elasticEaseOut);
	}

	// 右上
	touchgfx::MoveAnimator< touchgfx::Image > *m_gb = nullptr;
	switch(rand()%4) {
	case 0:
		// 画像無し
		break;
	case 1:
		m_gb = &gb1;
		break;
	case 2:
		m_gb = &gb2;
		break;
	case 3:
		m_gb = &gb3;
		break;
	}
	if (m_gb != nullptr)
	{
		m_gb->clearMoveAnimationEndedAction();
		m_gb->startMoveAnimation(615, -37, 30, touchgfx::EasingEquations::elasticEaseOut, touchgfx::EasingEquations::elasticEaseOut);
	}

	// 左下
	touchgfx::MoveAnimator< touchgfx::Image > *m_gc = nullptr;
	switch(rand()%4) {
	case 0:
		// 画像無し
		break;
	case 1:
		m_gc = &gc1;
		break;
	case 2:
		m_gc = &gc2;
		break;
	case 3:
		m_gc = &gc3;
		break;
	}
	if (m_gc != nullptr)
	{
		m_gc->clearMoveAnimationEndedAction();
		m_gc->startMoveAnimation(-69, 250, 30, touchgfx::EasingEquations::elasticEaseOut, touchgfx::EasingEquations::elasticEaseOut);
	}

	// 右下
	touchgfx::MoveAnimator< touchgfx::Image > *m_gd = nullptr;
	switch(rand()%4) {
	case 0:
		// 画像無し
		break;
	case 1:
		m_gd = &gd1;
		break;
	case 2:
		m_gd = &gd2;
		break;
	case 3:
		m_gd = &gd3;
		break;
	}
	if (m_gd != nullptr)
	{
		m_gd->clearMoveAnimationEndedAction();
		m_gd->startMoveAnimation(615, 290, 30, touchgfx::EasingEquations::elasticEaseOut, touchgfx::EasingEquations::elasticEaseOut);
	}

	setVisible(true);
	invalidate();
}

void CustomContainer_start_finish::retry()
{
	// スタート表示
	c_start.setVisible(true);
	count_flag = 0;
	gc->retry();
}

void CustomContainer_start_finish::toggle_screen_button_1()
{
	bool new_state = tb_screen_button.getState();
	l_screen_button.setVisible(!new_state);
	l_screen_button.invalidate();
	gc->screen_button(new_state);
}

void CustomContainer_start_finish::toggle_screen_button_2()
{
	tb_screen_button.forceState(!tb_screen_button.getState());
	tb_screen_button.invalidate();
	toggle_screen_button_1();
}

int CustomContainer_start_finish::sec()
{
	return (int)timer_count / 60;
}

int CustomContainer_start_finish::msec()
{
	return (int)(int(timer_count / 0.6) % 100);
}
void CustomContainer_start_finish::tick()
{
    if(count_flag == 1)
    {
		timer_count--;
		if (timer_count <= 0)
		{
			count_flag = 0;
			c_countdown.setVisible(false);
			setVisible(false);
			invalidate();
			gc->start();
		}
		else
		{
			Unicode::snprintf(t_countdownBuffer, T_COUNTDOWN_SIZE, "-%01d.%02d", sec(), msec());
			t_countdown.invalidate();
		}
    }
}
