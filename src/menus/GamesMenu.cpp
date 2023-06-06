#include "Page.h"
#include "UIMenu.h"

UIMenu GamesMenu("Games", [](UIMenu *menu) {
  menu->addItem("Snake", [](UIMenu *) {
    Page::Go(&SnakePage);
  });
});