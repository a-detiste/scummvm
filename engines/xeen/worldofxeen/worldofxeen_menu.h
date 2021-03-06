/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef XEEN_WORLDOFXEEN_WORLDOFXEEN_MENU_H
#define XEEN_WORLDOFXEEN_WORLDOFXEEN_MENU_H

#include "xeen/xeen.h"
#include "xeen/dialogs/dialogs.h"

namespace Xeen {
namespace WorldOfXeen {

class MenuContainerDialog;

class MainMenuContainer {
private:
	uint _animateCtr;
	uint _frameCount;
	SpriteResource _backgroundSprites;
	MenuContainerDialog *_dialog;
protected:
	/**
	 * Draws the main menu background
	 */
	void draw();

	/**
	 * Called when the menu screen is first shown
	 */
	virtual void display() = 0;

	/**
	 * Shows the main menu dialog
	 */
	virtual void showMenuDialog() = 0;
public:
	/**
	 * Show the main menu for the correct game
	 */
	static void show();
public:
	/**
	 * Constructor
	 */
	MainMenuContainer(const Common::String &spritesName, uint frameCount);

	/**
	 * Destructor
	 */
	virtual ~MainMenuContainer();

	/**
	 * Execute the menu
	 */
	void execute();

	/**
	 * Sets the dialog being displayed in the menu
	 */
	void setOwner(MenuContainerDialog *dlalog) {
		_dialog = dlalog;
	}
};

class CloudsMainMenuContainer : public MainMenuContainer {
protected:
	/**
	 * Called when the menu screen is first shown
	 */
	virtual void display();

	/**
	 * Shows the main menu dialog
	 */
	virtual void showMenuDialog();
public:
	CloudsMainMenuContainer();
};

class DarkSideMainMenuContainer : public MainMenuContainer {
private:
	SpriteResource _background;
protected:
	/**
	 * Called when the menu screen is first shown
	 */
	virtual void display();

	/**
	* Shows the main menu dialog
	*/
	virtual void showMenuDialog();
public:
	DarkSideMainMenuContainer();
};

class WorldOfXeenMainMenuContainer : public MainMenuContainer {
protected:
	/**
	 * Called when the menu screen is first shown
	 */
	virtual void display();

	/**
	* Shows the main menu dialog
	*/
	virtual void showMenuDialog();
public:
	WorldOfXeenMainMenuContainer();
};

class MenuContainerDialog : public ButtonContainer {
protected:
	MainMenuContainer *_owner;
public:
	/**
	 * Constructor
	 */
	MenuContainerDialog(MainMenuContainer *owner) : ButtonContainer(g_vm), _owner(owner) {}

	/**
	 * Destructor
	 */
	virtual ~MenuContainerDialog() {
		_owner->setOwner(nullptr);
	}

	/**
	 * Draws the dialog
	 */
	virtual void draw() = 0;

	/**
	 * Handles events
	 */
	virtual bool handleEvents() = 0;
};

class MainMenuDialog : public MenuContainerDialog {
public:
	/**
	 * Constructor
	 */
	MainMenuDialog(MainMenuContainer *owner) : MenuContainerDialog(owner) {}

	/**
	 * Destructor
	 */
	virtual ~MainMenuDialog() {}

	/**
	 * Draws the dialog
	 */
	virtual void draw() = 0;

	/**
	 * Handles events
	 */
	virtual bool handleEvents();

};

class CloudsMenuDialog : public MainMenuDialog {
private:
	SpriteResource _buttonSprites;
private:
	/**
	 * Loads buttons for the dialog
	 */
	void loadButtons();
public:
	/**
	 * Constructor
	 */
	CloudsMenuDialog(MainMenuContainer *owner);

	/**
	 * Destructor
	 */
	virtual ~CloudsMenuDialog();

	/**
	 * Draws the dialog
	 */
	virtual void draw();

	/**
	 * Handles events
	 */
	virtual bool handleEvents();
};

class DarkSideMenuDialog : public MainMenuDialog {
private:
	SpriteResource _buttonSprites;
	bool _firstDraw;
private:
	/**
	 * Loads buttons for the dialog
	 */
	void loadButtons();
public:
	/**
	 * Constructor
	 */
	DarkSideMenuDialog(MainMenuContainer *owner);

	/**
	 * Destructor
	 */
	virtual ~DarkSideMenuDialog();

	/**
	 * Draws the dialog
	 */
	virtual void draw();

	/**
	 * Handles events
	 */
	virtual bool handleEvents();
};

class WorldMenuDialog : public MainMenuDialog {
private:
	SpriteResource _buttonSprites;
private:
	/**
	* Loads buttons for the dialog
	*/
	void loadButtons();
public:
	/**
	 * Constructor
	 */
	WorldMenuDialog(MainMenuContainer *owner);

	/**
	* Destructor
	*/
	virtual ~WorldMenuDialog();

	/**
	 * Draws the dialog
	 */
	virtual void draw();

	/**
	 * Handles events
	 */
	virtual bool handleEvents();
};

class OtherOptionsDialog : public MenuContainerDialog {
private:
	SpriteResource _buttonSprites;
private:
	/**
	* Loads buttons for the dialog
	*/
	void loadButtons();
public:
	/**
	 * Constructor
	 */
	OtherOptionsDialog(MainMenuContainer *owner);

	/**
	 * Destructor
	 */
	virtual ~OtherOptionsDialog();

	/**
	 * Draws the dialog
	 */
	virtual void draw();

	/**
	 * Handles events
	 */
	virtual bool handleEvents();
};

} // End of namespace WorldOfXeen
} // End of namespace Xeen

#endif /* XEEN_WORLDOFXEEN_WORLDOFXEEN_MENU_H */
