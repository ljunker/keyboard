#include "src/config.h"

#include "src/buttons.h"
#include "src/encoder.h"
#include "src/keyboard.h"


void setup() {

    Serial.begin(115200);

    buttonsBegin();
    encodersBegin();

    keyboardBegin();

    Serial.println(
        "Macropad gestartet"
    );
}


void loop() {

    buttonsUpdate();
    encodersUpdate();


    // ----------------------------------------------
    // Taster
    // ----------------------------------------------

    for (
        size_t i = 0;
        i < BUTTON_COUNT;
        i++
    ) {

        const auto button =
            static_cast<ButtonId>(i);

        if (buttonPressed(button)) {

            keyboardExecute(
                BUTTON_ACTIONS[i]
            );
        }
    }


    // ----------------------------------------------
    // Encoder
    // ----------------------------------------------

    for (
        size_t i = 0;
        i < ENCODER_COUNT;
        i++
    ) {

        const auto encoder =
            static_cast<EncoderId>(i);

        const int8_t movement =
            encoderMovement(encoder);


        if (movement < 0) {

            keyboardExecute(
                ENCODER_LEFT_ACTIONS[i]
            );
        }


        if (movement > 0) {

            keyboardExecute(
                ENCODER_RIGHT_ACTIONS[i]
            );
        }
    }
}