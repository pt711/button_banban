#include <gui/containers/CustomContainer_me.hpp>


// 移動時に潰れアニメ用
const int HIDE_DURATION = 6; // 100 ms (6 Ticks)
int hide_counter = 0;

CustomContainer_me::CustomContainer_me()
{
}

void CustomContainer_me::initialize()
{
    CustomContainer_meBase::initialize();
}

void CustomContainer_me::blink()
{
	// img_1を消してimg_2を見せる
	img_1.setVisible(false);
	img_1.invalidate();
    hide_counter = HIDE_DURATION;
}

void CustomContainer_me::ticker()
{
	// image1を再表示まで少し待つ処理
    if (hide_counter > 0)
    {
    	hide_counter--;
        if (hide_counter == 0)
        {
        	img_1.setVisible(true);
        	img_1.invalidate();
        }
    }
}
