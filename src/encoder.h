#pragma once

#include <Arduino.h>

#include "config.h"


void encodersBegin();

void encodersUpdate();

int encoderMovement(EncoderId encoder);