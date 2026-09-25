#pragma once

#include <Arduino.h>

// --------------------------------------------------
// Eingänge
// --------------------------------------------------

enum class ButtonId : uint8_t {
    Button1 = 0,
    Button2,
    Button3,
    Button4,
    Button5,
    Button6,
    Encoder1Button,
    Encoder2Button,
    Count
};

enum class EncoderId : uint8_t {
    Encoder1 = 0,
    Encoder2,
    Count
};

constexpr size_t BUTTON_COUNT =
    static_cast<size_t>(ButtonId::Count);

constexpr size_t ENCODER_COUNT =
    static_cast<size_t>(EncoderId::Count);


// --------------------------------------------------
// Encoder Hardware
// --------------------------------------------------

struct EncoderPins {
    uint8_t pinA;
    uint8_t pinB;
};


// --------------------------------------------------
// Actions
// --------------------------------------------------

enum class ActionType : uint8_t {
    None,
    Key,
    Shortcut,
    Consumer
};

enum Modifier : uint8_t {
    MOD_NONE  = 0,
    MOD_CTRL  = 1U << 0U,
    MOD_SHIFT = 1U << 1U,
    MOD_ALT   = 1U << 2U,
    MOD_GUI   = 1U << 3U
};

struct Action {
    ActionType type;
    uint16_t code;
    uint8_t modifiers;
};


// --------------------------------------------------
// Bluetooth
// --------------------------------------------------

extern const char *DEVICE_NAME;


// --------------------------------------------------
// Hardware-Konfiguration
// --------------------------------------------------

extern const uint8_t BUTTON_PINS[BUTTON_COUNT];

extern const EncoderPins ENCODER_PINS[ENCODER_COUNT];

extern const int ENCODER_DIRECTION[ENCODER_COUNT];


// --------------------------------------------------
// Belegung
// --------------------------------------------------

extern const Action BUTTON_ACTIONS[BUTTON_COUNT];

extern const Action ENCODER_LEFT_ACTIONS[ENCODER_COUNT];

extern const Action ENCODER_RIGHT_ACTIONS[ENCODER_COUNT];