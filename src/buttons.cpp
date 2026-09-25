#include "buttons.h"


namespace {

constexpr uint32_t DEBOUNCE_MS = 20;


bool stableState[BUTTON_COUNT] = {};
bool rawState[BUTTON_COUNT] = {};

bool pressedEvent[BUTTON_COUNT] = {};
bool releasedEvent[BUTTON_COUNT] = {};

uint32_t lastChange[BUTTON_COUNT] = {};


size_t indexOf(ButtonId button) {
    return static_cast<size_t>(button);
}

}


void buttonsBegin() {

    for (size_t i = 0; i < BUTTON_COUNT; i++) {

        pinMode(
            BUTTON_PINS[i],
            INPUT_PULLUP
        );

        const bool pressed =
            digitalRead(BUTTON_PINS[i]) == LOW;

        stableState[i] = pressed;
        rawState[i] = pressed;

        pressedEvent[i] = false;
        releasedEvent[i] = false;

        lastChange[i] = millis();
    }
}


void buttonsUpdate() {

    const uint32_t now = millis();

    for (size_t i = 0; i < BUTTON_COUNT; i++) {

        pressedEvent[i] = false;
        releasedEvent[i] = false;

        const bool currentRaw =
            digitalRead(BUTTON_PINS[i]) == LOW;


        // Rohzustand hat sich geändert
        if (currentRaw != rawState[i]) {

            rawState[i] = currentRaw;
            lastChange[i] = now;
        }


        // Zustand lange genug stabil?
        if (
            stableState[i] != rawState[i]
            &&
            now - lastChange[i] >= DEBOUNCE_MS
        ) {

            stableState[i] = rawState[i];

            if (stableState[i]) {
                pressedEvent[i] = true;
            } else {
                releasedEvent[i] = true;
            }
        }
    }
}


bool buttonPressed(ButtonId button) {

    return pressedEvent[indexOf(button)];
}


bool buttonReleased(ButtonId button) {

    return releasedEvent[indexOf(button)];
}


bool buttonIsDown(ButtonId button) {

    return stableState[indexOf(button)];
}