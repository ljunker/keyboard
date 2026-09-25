#include "encoder.h"

namespace {

    uint8_t previousState[ENCODER_COUNT] = {};
    int accumulator[ENCODER_COUNT] = {};
    int movement[ENCODER_COUNT] = {};

    constexpr int8_t TRANSITION_TABLE[16] = {
        0, -1,  1,  0,
        1,  0,  0, -1,
        -1,  0,  0,  1,
        0,  1, -1,  0
    };

    size_t indexOf(EncoderId encoder) {
        return static_cast<size_t>(encoder);
    }

    uint8_t readEncoderState(size_t index) {
        const auto a = static_cast<uint32_t>(
            digitalRead(ENCODER_PINS[index].pinA)
        );

        const auto b = static_cast<uint32_t>(
            digitalRead(ENCODER_PINS[index].pinB)
        );

        return static_cast<uint8_t>(
            (a << 1U) | b
        );
    }

}

void encodersBegin() {
    for (size_t i = 0; i < ENCODER_COUNT; ++i) {
        pinMode(
            ENCODER_PINS[i].pinA,
            INPUT_PULLUP
        );

        pinMode(
            ENCODER_PINS[i].pinB,
            INPUT_PULLUP
        );

        previousState[i] = readEncoderState(i);
        accumulator[i] = 0;
        movement[i] = 0;
    }
}

void encodersUpdate() {
    for (size_t i = 0; i < ENCODER_COUNT; ++i) {
        movement[i] = 0;

        const uint8_t currentState =
            readEncoderState(i);

        if (currentState == previousState[i]) {
            continue;
        }

        const auto transition =
            static_cast<uint8_t>(
                (
                    static_cast<uint32_t>(
                        previousState[i]
                    ) << 2U
                )
                |
                static_cast<uint32_t>(
                    currentState
                )
            );

        accumulator[i] +=
            static_cast<int>(
                TRANSITION_TABLE[transition]
            );

        previousState[i] = currentState;

        if (accumulator[i] >= 4) {
            movement[i] = ENCODER_DIRECTION[i];
            accumulator[i] = 0;
        } else if (accumulator[i] <= -4) {
            movement[i] = -ENCODER_DIRECTION[i];
            accumulator[i] = 0;
        }
    }
}

int encoderMovement(EncoderId encoder) {
    return movement[indexOf(encoder)];
}