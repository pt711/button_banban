#ifndef APPLICATION_USER_GAMECONTROLLER_H_
#define APPLICATION_USER_GAMECONTROLLER_H_

#include "main.h"
#include "stm32u5xx_hal.h"

#include "gui/common/Position.h"

#include <touchgfx/mixins/MoveAnimator.hpp>
#include <gui/containers/CustomContainer_me.hpp>
#include <gui/containers/CustomContainer_move_button.hpp>
#include <gui/containers/CustomContainer_timer.hpp>
#include <gui/containers/CustomContainer_start_finish.hpp>

#include <gui/containers/CustomContainer_block1.hpp>

class CustomContainer_move_button;
class CustomContainer_start_finish;

class GameController {
public:
	GameController();
	virtual ~GameController();

	void set_me(touchgfx::MoveAnimator< CustomContainer_me > *_cc_me);
	void set_move_button(CustomContainer_move_button *_cc_move_button);
	void set_timer(CustomContainer_timer *_cc_timer);
	void set_MAP(touchgfx::Container *_c_MAP);
	void set_start_finish(CustomContainer_start_finish *_cc_start_finish);

	void handleTickEvent();
	void init();
	void button_tick();
	bool button_check(int read, int* count);

	void update_map(int b_pos_x_new, int b_pos_y_new, int type);
	void move(int check);

	void start();
	void finish();
	void retry();
	void screen_button(bool state);

	void up();
	void down();
	void left();
	void right();


    uint16_t T_TIME_FINISH_SIZE;
    touchgfx::Unicode::UnicodeChar* t_time_finishBuffer;

protected:
    Position *p; // 自キャラ制御
    int init_flag = 0; // 初期化用フラグ
    int start_flag = 0; // スタートしてるかフラグ
	touchgfx::MoveAnimator< CustomContainer_me > *cc_me;
    CustomContainer_move_button *cc_move_button;
    CustomContainer_timer *cc_timer;
    CustomContainer_start_finish *cc_start_finish;
    touchgfx::Container *c_MAP;
};

#endif /* APPLICATION_USER_GAMECONTROLLER_H_ */
