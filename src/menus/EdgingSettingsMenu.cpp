#include "Hardware.h"
#include "OrgasmControl.h"
#include "UIInput.h"
#include "UIMenu.h"

UIInput MotorMaxSpeedInput("Motor Max Speed", [](UIMenu *ip) {
  UIInput *input = (UIInput *) ip;
  input->setMax(255);
  input->setValue(Config.motor_max_speed);
  input->setStep(1);

  input->onOpen([](UIMenu *) {
    OrgasmControl::pauseControl();
  });

  input->onClose([](UIMenu *) {
    OrgasmControl::resumeControl();
  });

  input->onChange([](int value) {
    Config.motor_max_speed = value;
    Hardware::setMotorSpeed(value);
  });

  input->onConfirm([](int value) {
    Config.motor_max_speed = value;
    saveConfigToSd(0);
  });
});

UIInput MotorStartSpeedInput("Motor Start Speed", [](UIMenu *ip) {
  UIInput *input = (UIInput *) ip;
  input->setMax(255);
  input->setStep(1);
  input->setValue(Config.motor_start_speed);
  input->onChange([](int value) {
    Config.motor_start_speed = value;
  });
  input->onConfirm([](int) {
    saveConfigToSd(0);
  });
});

UIInput MotorRampTimeInput("Motor Ramp Time", [](UIMenu *ip) {
  UIInput *input = (UIInput *) ip;
  input->setMax(180);
  input->setStep(5);
  input->setValue(Config.motor_ramp_time_s);
  input->onChange([](int value) {
    Config.motor_ramp_time_s = value;
  });
  input->onConfirm([](int) {
    saveConfigToSd(0);
  });
});

UIInput EdgeDelayInput("Edge Delay", [](UIMenu *ip) {
  UIInput *input = (UIInput *) ip;
  input->setMax(60);
  input->setStep(1);
  input->setValue(Config.edge_delay / 1000);
  input->onChange([](int value) {
    Config.edge_delay = value * 1000;
  });
  input->onConfirm([](int) {
    saveConfigToSd(0);
  });
});

UIInput MaxAdditionalDelayInput("Maximum Additional Delay", [](UIMenu *ip) {
  UIInput *input = (UIInput *) ip;
  input->setMax(60);
  input->setStep(1);
  input->setValue(Config.max_additional_delay / 1000);
  input->onChange([](int value) {
    Config.max_additional_delay = value * 1000;
  });
  input->onConfirm([](int) {
    saveConfigToSd(0);
  });
});

UIInput MinimumOnTimeInput("Minimum On Time", [](UIMenu *ip) {
  UIInput *input = (UIInput *) ip;
  input->setMax(5000);
  input->setStep(100);
  input->setValue(Config.minimum_on_time);
  input->onChange([](int value) {
    Config.minimum_on_time = value;
  });
  input->onConfirm([](int) {
    saveConfigToSd(0);
  });
});

UIInput ArousalLimitInput("Arousal Limit", [](UIMenu *ip) {
  UIInput *input = (UIInput *) ip;
  input->setMax(1023);
  input->setStep(16);
  input->setValue(Config.sensitivity_threshold);
  input->onChange([](int value) {
    Config.sensitivity_threshold = value;
  });
  input->onConfirm([](int) {
    saveConfigToSd(0);
  });
});

UIInput SensorSensitivityInput("Sensor Sensitivity", [](UIMenu *ip) {
  UIInput *input = (UIInput *) ip;
  input->setMax(255);
  input->setStep(1);
  input->setValue(Config.sensor_sensitivity);
  input->setPollPeriod(1000 / 30);
  input->getSecondaryValue([](int value) {
    return Hardware::getPressure();
  });
  input->onChange([](int value) {
    Config.sensor_sensitivity = value;
    Hardware::setPressureSensitivity(value);
  });
  input->onConfirm([](int) {
    saveConfigToSd(0);
  });
});

static void setVibrateMode(UIMenu *menu, int m) {
  VibrationMode mode = (VibrationMode) m;

  Serial.print("Setting mode to: ");
  switch (mode) {
    case VibrationMode::Depletion:
      Serial.println("Depletion");
      break;
    case VibrationMode::Enhancement:
      Serial.println("Enhancement");
      break;
    case VibrationMode::RampStop:
      Serial.println("RampStop");
      break;
    case VibrationMode::Pattern:
      Serial.println("Pattern");
      break;
  }

  Config.vibration_mode = mode;
  saveConfigToSd(0);
  menu->rerender();
}

static void add_vibration_item(UIMenu *menu, std::string label, VibrationMode mode) {
  std::string text = "";
  if (Config.vibration_mode == mode) {
    text += "X";
  } else {
    text += " ";
  }
  text += " " + label;

  menu->addItem(text, &setVibrateMode, (int) mode);
}

static void buildVibrationModeMenu(UIMenu *menu) {
  add_vibration_item(menu, "Depletion", VibrationMode::Depletion);
  add_vibration_item(menu, "Enhancement", VibrationMode::Enhancement);
  add_vibration_item(menu, "Ramp-Stop", VibrationMode::RampStop);
  add_vibration_item(menu, "Pattern", VibrationMode::Pattern);
}

UIMenu VibrationModeMenu("Vibration Mode", &buildVibrationModeMenu);

static void setPatternMode(UIMenu *menu, int m) {
  PatternMode mode = (PatternMode) m;

  Serial.print("Setting pattern to: ");
  switch (mode) {
    case PatternMode::Step:
      Serial.println("Step");
      break;
    case PatternMode::Wave:
      Serial.println("Wave");
      break;
    case PatternMode::Sawtooth:
      Serial.println("Sawtooth");
      break;
  }

  Config.pattern_mode = mode;
  saveConfigToSd(0);
  menu->rerender();
}

static void add_pattern_item(UIMenu *menu, std::string label, PatternMode mode) {
  std::string text = "";
  if (Config.pattern_mode == mode) {
    text += "X";
  } else {
    text += " ";
  }
  text += " " + label;

  menu->addItem(text, &setPatternMode, (int) mode);
}

static void buildPatternModeMenu(UIMenu *menu) {
  add_pattern_item(menu, "Step", PatternMode::Step);
  add_pattern_item(menu, "Wave", PatternMode::Wave);
  add_pattern_item(menu, "Sawtooth", PatternMode::Sawtooth);
}

UIMenu PatternModeMenu("Pattern Mode", &buildPatternModeMenu);

static void buildMenu(UIMenu *menu) {
  menu->addItem(&VibrationModeMenu);
  menu->addItem(&PatternModeMenu);
  menu->addItem(&MotorMaxSpeedInput);
  menu->addItem(&MotorStartSpeedInput);
  menu->addItem(&MotorRampTimeInput);
  menu->addItem(&EdgeDelayInput);
  menu->addItem(&MaxAdditionalDelayInput);
  menu->addItem(&MinimumOnTimeInput);
  menu->addItem(&ArousalLimitInput);
  menu->addItem(&SensorSensitivityInput);
}

UIMenu EdgingSettingsMenu("Edging Settings", &buildMenu);
