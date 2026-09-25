#pragma once

#include <Arduino.h>

#include "config.h"


void encodersBegin();

void encodersUpdate();

int8_t encoderMovement(EncoderId encoder);