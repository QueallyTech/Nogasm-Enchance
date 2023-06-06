#include "Page.h"
#include "UIMenu.h"
#include "UpdateHelper.h"
#include "UserInterface.h"

static void buildMenu(UIMenu *menu) {
  menu->addItem("Automatic Edging", &RunGraphPage);

  menu->addItem(&EdgingSettingsMenu);
  menu->addItem(&EdgingOrgasmSettingsMenu);
  menu->addItem(&UISettingsMenu);
  menu->addItem(&NetworkMenu);
  menu->addItem(&GamesMenu);
  menu->addItem(&UpdateMenu);

  menu->addItem("System Info", [](UIMenu *) {
    UI.toastNow(String("S/N: ") + Hardware::getDeviceSerial() + "\n" + "Version: " VERSION);
  });
}

UIMenu MainMenu("Main Menu", &buildMenu);
