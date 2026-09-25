#pragma once

#include <Arduino.h>

#include "config.h"


void buttonsBegin();

void buttonsUpdate();

bool buttonPressed(ButtonId button);

bool buttonReleased(ButtonId button);

bool buttonIsDown(ButtonId button);