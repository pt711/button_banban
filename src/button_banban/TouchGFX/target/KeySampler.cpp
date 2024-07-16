#include "KeySampler.hpp"
#include "main.h"

using namespace touchgfx;

void KeySampler::init()
{
}

bool KeySampler::sample(uint8_t& key)
{
    bool buttonPressed = false;

    // USERボタン
    if (HAL_GPIO_ReadPin(USER_BUTTON_GPIO_Port, USER_BUTTON_Pin) != GPIO_PIN_RESET)
    {
        buttonPressed = true;
        key = 1;
    }
    return buttonPressed;
}
