#include "keyboard.h"

#include <KeyboardBLE.h>
#include <HID_Keyboard.h>


namespace {

void pressModifiers(uint8_t modifiers) {

    if (
        (
            static_cast<uint32_t>(modifiers)
            &
            static_cast<uint32_t>(MOD_CTRL)
        ) != 0U
    ) {
        KeyboardBLE.press(KEY_LEFT_CTRL);
    }

    if (
        (
            static_cast<uint32_t>(modifiers)
            &
            static_cast<uint32_t>(MOD_SHIFT)
        ) != 0U
    ) {
        KeyboardBLE.press(KEY_LEFT_SHIFT);
    }

    if (
        (
            static_cast<uint32_t>(modifiers)
            &
            static_cast<uint32_t>(MOD_ALT)
        ) != 0U
    ) {
        KeyboardBLE.press(KEY_LEFT_ALT);
    }

    if (
        (
            static_cast<uint32_t>(modifiers)
            &
            static_cast<uint32_t>(MOD_GUI)
        ) != 0U
    ) {
        KeyboardBLE.press(KEY_LEFT_GUI);
    }
}


void executeKeyboardAction(
    const Action &action
) {

    pressModifiers(action.modifiers);

    KeyboardBLE.press(
        static_cast<uint8_t>(
            action.code
        )
    );

    delay(10);

    KeyboardBLE.releaseAll();
}


void executeConsumerAction(
    const Action &action
) {

    KeyboardBLE.consumerPress(
        action.code
    );

    delay(10);

    KeyboardBLE.consumerRelease();
}

}


void keyboardBegin() {

    KeyboardBLE.begin(
        DEVICE_NAME,
        DEVICE_NAME,
        KeyboardLayout_de_DE
    );
}


void keyboardExecute(
    const Action &action
) {

    switch (action.type) {

        case ActionType::None:
            return;


        case ActionType::Key:
        case ActionType::Shortcut:

            executeKeyboardAction(action);

            return;


        case ActionType::Consumer:

            executeConsumerAction(action);

            return;
    }
}