/*
 * \copyright Copyright 2014
 * \license @{
 * Licensed under the Apache License, Version 2.0 (the "License");
 * @}
 */

#include "command/ceiling_fan_off_command.h"

namespace command {
CeilingFanOffCommand::CeilingFanOffCommand(CeilingFan *ceiling_fan) :
    ceiling_fan_(ceiling_fan) {
}

CeilingFanOffCommand::~CeilingFanOffCommand() {
}

void CeilingFanOffCommand::execute() {
  prev_speed_ = ceiling_fan_->speed();
  ceiling_fan_->off();
}

void CeilingFanOffCommand::undo() {
  if (prev_speed_ == CeilingFan::HIGH) {
    ceiling_fan_->high();
  } else if (prev_speed_ == CeilingFan::MEDIUM) {
    ceiling_fan_->medium();
  } else if (prev_speed_ == CeilingFan::LOW) {
    ceiling_fan_->low();
  } else if (prev_speed_ == CeilingFan::OFF) {
    ceiling_fan_->off();
  }
}
}  // namespace command
