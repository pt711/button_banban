#include "gui/common/GameController.h"
#include <gui/containers/CustomContainer_move_button.hpp>

// チャタリングとみなすTicks
const int CHATTERING_TICKS = 1;

GameController::GameController()
{
	init_flag = 0;
}
GameController::~GameController()
{
	delete(p);
}

// フレーム単位に呼び出し
void GameController::handleTickEvent()
{
	// 初期化
	if(init_flag == 0)
	{
		init_flag = 1;
		init();
	}

	if(start_flag == 1)
	{
		// 物理ボタン
		button_tick();
	}
}

// 物理ボタン
void GameController::button_tick()
{
	// retry
    if(HAL_GPIO_ReadPin(USER_BUTTON_GPIO_Port, USER_BUTTON_Pin) != GPIO_PIN_RESET) retry();

    // サイドの上側
    // Left
    static int count_PG15 = 0;
    if(button_check(HAL_GPIO_ReadPin(PG15_INPUT_GPIO_Port, PG15_INPUT_Pin), &count_PG15)) left();
    // Right
    static int count_PG12 = 0;
    if(button_check(HAL_GPIO_ReadPin(PG12_INPUT_GPIO_Port, PG12_INPUT_Pin), &count_PG12)) right();
    // Up
    static int count_PG10 = 0;
    if(button_check(HAL_GPIO_ReadPin(PG10_INPUT_GPIO_Port, PG10_INPUT_Pin), &count_PG10)) up();
    // Down
    static int count_PG9 = 0;
    if(button_check(HAL_GPIO_ReadPin(PG9_INPUT_GPIO_Port, PG9_INPUT_Pin), &count_PG9)) down();

    // サイドの下側
    // Left
    static int count_PF2 = 0;
    if(button_check(HAL_GPIO_ReadPin(PF2_INPUT_GPIO_Port, PF2_INPUT_Pin), &count_PF2)) left();
    // Right
    static int count_PE3 = 0;
    if(button_check(HAL_GPIO_ReadPin(PE3_INPUT_GPIO_Port, PE3_INPUT_Pin), &count_PE3)) right();
    // Up
    static int count_PE2 = 0;
    if(button_check(HAL_GPIO_ReadPin(PE2_INPUT_GPIO_Port, PE2_INPUT_Pin), &count_PE2)) up();
    // Down
    static int count_PD7 = 0;
    if(button_check(HAL_GPIO_ReadPin(PD7_INPUT_GPIO_Port, PD7_INPUT_Pin), &count_PD7)) down();

    // 裏のCN4
    // Left
    static int count_PB5 = 0;
    if(button_check(HAL_GPIO_ReadPin(PB5_INPUT_GPIO_Port, PB5_INPUT_Pin), &count_PB5)) left();
    // Right
    static int count_PB0 = 0;
    if(button_check(HAL_GPIO_ReadPin(PB0_INPUT_GPIO_Port, PB0_INPUT_Pin), &count_PB0)) right();
    // Up
    static int count_PB6 = 0;
    if(button_check(HAL_GPIO_ReadPin(PB6_INPUT_GPIO_Port, PB6_INPUT_Pin), &count_PB6)) up();
    // Down
    static int count_PB15 = 0;
    if(button_check(HAL_GPIO_ReadPin(PB15_INPUT_GPIO_Port, PB15_INPUT_Pin), &count_PB15)) down();

    // 裏のCN6
    // Left
    static int count_PA8 = 0;
    if(button_check(HAL_GPIO_ReadPin(PA8_INPUT_GPIO_Port, PA8_INPUT_Pin), &count_PA8)) left();
    // Right
    static int count_PB11 = 0;
    if(button_check(HAL_GPIO_ReadPin(PB11_INPUT_GPIO_Port, PB11_INPUT_Pin), &count_PB11)) right();
    // Up
    static int count_PA2 = 0;
    if(button_check(HAL_GPIO_ReadPin(PA2_INPUT_GPIO_Port, PA2_INPUT_Pin), &count_PA2)) up();
    // Down
    static int count_PA3 = 0;
    if(button_check(HAL_GPIO_ReadPin(PA3_INPUT_GPIO_Port, PA3_INPUT_Pin), &count_PA3)) down();
}

// ボタン押しっぱなしとチャタリングをチェック
bool GameController::button_check(int read, int* count)
{
    if(read != GPIO_PIN_RESET)
    {
    	if(*count <= 0) {
    		*count = CHATTERING_TICKS;
    		return true;
    	}
    }
    else if(*count > 0) *count -= 1;
	return false;
}

void GameController::set_me(touchgfx::MoveAnimator< CustomContainer_me > *_cc_me)
{
	cc_me = _cc_me;
}
void GameController::set_move_button(CustomContainer_move_button *_cc_move_button)
{
	cc_move_button = _cc_move_button;
}
void GameController::set_timer(CustomContainer_timer *_cc_timer)
{
	cc_timer = _cc_timer;
}
void GameController::set_MAP(touchgfx::Container *_c_MAP)
{
	c_MAP = _c_MAP;
}
void GameController::set_start_finish(CustomContainer_start_finish *_cc_start_finish)
{
	cc_start_finish = _cc_start_finish;
}

void GameController::update_map(int b_pos_x_new, int b_pos_y_new, int type)
{
	p->update_map(b_pos_x_new, b_pos_y_new, type);
}

void GameController::init()
{
	cc_move_button->setParent(this);
	cc_start_finish->setParent(this);

    // 自キャラ
	int pos_x = cc_me->getX();
	int pos_y = cc_me->getY();
	p = new Position(pos_x, pos_y);

	// 画面表示初期化
	cc_start_finish->init();

	// 障害物
	Drawable *c1 = c_MAP->getFirstChild();

	while(1) {

		// 子要素無くなったら終わり
		if(!c1) break;

		int type = ((CustomContainer_block1 *)c1)->type;

		// ブロックなど
		if(type != 0) {
			int b_pos_x_new = c1->getX();
			int b_pos_y_new = c1->getY();
			update_map(b_pos_x_new, b_pos_y_new, type);
		}

		// 次の子要素を参照
		c1 = c1->getNextSibling();
	}
}

void GameController::up()
{
	move(p->up());
}
void GameController::down()
{
	move(p->down());
}
void GameController::left()
{
	move(p->left());
}
void GameController::right()
{
	move(p->right());
}

// 移動
void GameController::move(int check)
{
	// 移動先が移動不可以外
	if(check != 1) {
		int pos_x = p->pos_x;
		int pos_y = p->pos_y;
		cc_me->clearMoveAnimationEndedAction();
		cc_me->startMoveAnimation(pos_x, pos_y, 2, touchgfx::EasingEquations::expoEaseInOut, touchgfx::EasingEquations::expoEaseInOut);

		// ゴール
		if(check == 9) finish();
	}

	// 潰れるアニメ
	cc_me->blink();
}

// スタート
void GameController::start()
{
	start_flag = 1;

	// タイマー開始
	cc_timer->start();
}

// ゴール
void GameController::finish()
{
	start_flag = 0;

	// タイマー終了
	cc_timer->finish();

	// finish画面表示
	cc_start_finish->finish(cc_timer->sec(), cc_timer->msec());
}

// リセット
void GameController::retry()
{
	cc_timer->init();
	p->retry();
	cc_me->setXY(p->pos_x, p->pos_y);
	init_flag = 0;
	start_flag = 0;
}

// スクリーンボタン表示/非表示
void GameController::screen_button(bool state)
{
	cc_move_button->setVisible(state);
	cc_move_button->invalidate();
}
