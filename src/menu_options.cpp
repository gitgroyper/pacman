#include "menu_options.h"

MenuOptions::MenuOptions():
	Menu("Options") {
	addMenuItem("back");
	addMenuItem("Stupid Small Screen", "Cool Size");
	addMenuItem("Music: weird", "Music: poop");
	addMenuItem("Sound: nein", "Sound: ?!/2");
}

MenuOptions::~MenuOptions() {
}

int MenuOptions::show() {
	updateMenuItemNames();
	draw();
	int event;
	while (!(event = eventloop()))
		SDL_Delay(Constants::MIN_FRAME_DURATION);
	return (event == 1 ? 1 : 0);
}

int MenuOptions::handleSelection() {
	if(selection == BACK)
		return 2;
	if(selection == FULLSCREEN)
		Screen::getInstance()->toggleFullscreen();
	else if(selection == SOUND)
		Sounds::getInstance()->toggleEnabled();
	else if(selection == MUSIC)
		Sounds::getInstance()->toggleMusicEnabled();
	updateMenuItemNames();
	draw();
	return 0;
}

void MenuOptions::updateMenuItemNames() {
	menuItems.at(FULLSCREEN)->setMenuItemAlt(Screen::getInstance()->isFullscreen());
	menuItems.at(SOUND)->setMenuItemAlt(!Sounds::getInstance()->isEnabled());
	menuItems.at(MUSIC)->setMenuItemAlt(!Sounds::getInstance()->isMusicEnabled());
}
