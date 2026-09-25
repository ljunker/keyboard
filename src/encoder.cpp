#include "encoder.h"


namespace {

uint8_t previousState[ENCODER_COUNT] = {};

int8_t accumulator[ENCODER_COUNT] = {};

int8_t movement[ENCODER_COUNT] = {};


// Quadratur-State-Machine
//
// Index:
//
// vorheriger Zustand << 2 | neuer Zustand
//
// Ergebnis:
//
// -1 / +1 = gültiger Schritt
//  0      = keine Bewegung oder ungültiger Übergang

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

    const uint8_t a =
        digitalRead(
            ENCODER_PINS[index].pinA
        );

    const uint8_t b =
        digitalRead(
            ENCODER_PINS[index].pinB
        );

    return (a << 1) | b;
}

}


void encodersBegin() {

    for (size_t i = 0; i < ENCODER_COUNT; i++) {

        pinMode(
            ENCODER_PINS[i].pinA,
            INPUT_PULLUP
        );

        pinMode(
            ENCODER_PINS[i].pinB,
            INPUT_PULLUP
        );

        previousState[i] =
            readEncoderState(i);

        accumulator[i] = 0;
        movement[i] = 0;
    }
}


void encodersUpdate() {

    for (size_t i = 0; i < ENCODER_COUNT; i++) {

        movement[i] = 0;

        const uint8_t currentState =
            readEncoderState(i);

        if (currentState == previousState[i]) {
            continue;
        }

        const uint8_t transition =
            (previousState[i] << 2)
            | currentState;

        accumulator[i] +=
            TRANSITION_TABLE[transition];

        previousState[i] = currentState;


        // Ein kompletter Quadratur-Schritt
        if (accumulator[i] >= 4) {

            movement[i] =
                1 * ENCODER_DIRECTION[i];

            accumulator[i] = 0;

        } else if (accumulator[i] <= -4) {

            movement[i] =
                -1 * ENCODER_DIRECTION[i];

            accumulator[i] = 0;
        }
    }
}


int8_t encoderMovement(EncoderId encoder) {

    return movement[indexOf(encoder)];
}