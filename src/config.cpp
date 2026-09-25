#include "config.h"

#include <HID_Keyboard.h>


// --------------------------------------------------
// Bluetooth
// --------------------------------------------------

const char *DEVICE_NAME = "Pico Macropad";


// --------------------------------------------------
// GPIO-Belegung
// --------------------------------------------------

// Button1 ... Button6
// Encoder1-Taster
// Encoder2-Taster

const uint8_t BUTTON_PINS[BUTTON_COUNT] = {
    2,
    3,
    4,
    5,
    6,
    7,
    10,
    13
};


// Encoder A/B

const EncoderPins ENCODER_PINS[ENCODER_COUNT] = {
    {8, 9},
    {11, 12}
};


// Falls ein Encoder später falsch herum läuft:
// 1 zu -1 ändern.

const int ENCODER_DIRECTION[ENCODER_COUNT] = {
    1,
    1
};


// --------------------------------------------------
// Tastenbelegung
// --------------------------------------------------
//
// Standard:
// Button 1 -> F13
// Button 2 -> F14
// Button 3 -> F15
// Button 4 -> F16
// Button 5 -> F17
// Button 6 -> F18
//
// Encoder 1 drücken -> Mute
// Encoder 2 drücken -> Play/Pause
//

const Action BUTTON_ACTIONS[BUTTON_COUNT] = {

    {
        ActionType::Key,
        KEY_F13,
        MOD_NONE
    },

    {
        ActionType::Key,
        KEY_F14,
        MOD_NONE
    },

    {
        ActionType::Key,
        KEY_F15,
        MOD_NONE
    },

    {
        ActionType::Key,
        KEY_F16,
        MOD_NONE
    },

    {
        ActionType::Key,
        KEY_F17,
        MOD_NONE
    },

    {
        ActionType::Key,
        KEY_F18,
        MOD_NONE
    },

    {
        ActionType::Consumer,
        KEY_MUTE,
        MOD_NONE
    },

    {
        ActionType::Consumer,
        KEY_PLAY_PAUSE,
        MOD_NONE
    }
};


// --------------------------------------------------
// Encoder-Drehung
// --------------------------------------------------

// Encoder 1: Lautstärke

// Encoder 2: vorheriger/nächster Titel

const Action ENCODER_LEFT_ACTIONS[ENCODER_COUNT] = {

    {
        ActionType::Consumer,
        KEY_VOLUME_DECREMENT,
        MOD_NONE
    },

    {
        ActionType::Consumer,
        KEY_SCAN_PREVIOUS,
        MOD_NONE
    }
};


const Action ENCODER_RIGHT_ACTIONS[ENCODER_COUNT] = {

    {
        ActionType::Consumer,
        KEY_VOLUME_INCREMENT,
        MOD_NONE
    },

    {
        ActionType::Consumer,
        KEY_SCAN_NEXT,
        MOD_NONE
    }
};