#ifndef __SDHelper_h
#define __SDHelper_h

#include <Arduino.h>
#include <ArduinoJson.h>
#include <SD.h>

namespace SDHelper {
  void printDirectory(File dir, int numTabs, String &out);
  void printDirectoryJson(File dir, JsonVariant files);
  void printFile(File file, String &out);
}

#endif