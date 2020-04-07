#include "MainMenuState.hpp"
#include "CharacterListState.hpp"

#include "Globals.hpp"

#include <SFWS/SFWS.hpp>

#include <SFUI/SFUI.hpp>
#include <SFUI/Theme.hpp>

#include <SFML/Graphics.hpp>

#include <iostream>

void MainMenuState::Init(AppEngine* appEngine)
{
	app = appEngine;

	std::cout << "Initialising MainMenuState." << std::endl;

	SFUI::Theme::windowBgColor = app->windowDecorations.colors.windowBackground;

	menu = new SFUI::Menu(*app->window);
	menu->setPosition(sf::Vector2f(app->windowDecorations.sizes.left + 10, app->windowDecorations.sizes.top + app->windowDecorations.sizes.titlebar + 8));

	characterSheetSpriteButtonTexture.loadFromFile(GBL::DIR::textures + "interface/buttons/charactersheetbutton.png");
	campaignSpriteButtonTexture.loadFromFile(GBL::DIR::textures + "interface/buttons/campaignbutton.png");

	buildHomeInterface(&app->windowDecorations, *menu);
}

void MainMenuState::Cleanup()
{
	std::cout << "Cleaning up MainMenuState." << std::endl;
	std::cout << "MainMenuState cleaned up." << std::endl;
}

void MainMenuState::Pause()
{
	std::cout << "MainMenuState paused." << std::endl;
}

void MainMenuState::Resume()
{
	std::cout << "MainMenuState resumed." << std::endl;
}

void MainMenuState::HandleEvents()
{
	sf::Event event;
	while (app->window->pollEvent(event))
	{
		app->windowDecorations.HandleEvents(event);

		if (event.type == sf::Event::EventType::Closed)
			app->windowDecorations.getWindow()->close();

		int id = menu->onEvent(event);
		switch (id)
		{
		case CALLBACKS::CHARACTER_LIST:
			app->ChangeState(new CharacterListState);
			return;
		case CALLBACKS::OPEN_RELEASE_NOTES:
			system("start https://github.com/kennyrkun/wearerocking/releases");
			break;
		case CALLBACKS::OPEN_DOCUMENTATION:
			system("start https://github.com/kennyrkun/wearerocking/wiki");
			break;
		};
	}
}

void MainMenuState::Update()
{
	// HACK: this is a workaround for decorations not being used directly by the app
	// TODO: this might cause problems if we have to hide the window for whatever reason
	if (!app->window->isOpen())
	{
		app->Quit();
		return;
	}
}

void MainMenuState::Draw()
{
	app->window->clear(SFUI::Theme::windowBgColor);

	app->window->draw(*menu);

	app->windowDecorations.Draw();
	app->window->display();
}

void MainMenuState::buildHomeInterface(SFWS* interface, SFUI::Menu& menu)
{
	menu.setPosition(sf::Vector2f(interface->sizes.left + 10, interface->sizes.top + interface->sizes.titlebar + 10));

	menu.addLabel("Utilities");

	SFUI::HorizontalBoxLayout* playerTools = menu.addHorizontalBoxLayout();

	SFUI::SpriteButton* characterSheetButton = new SFUI::SpriteButton(characterSheetSpriteButtonTexture);
	playerTools->add(characterSheetButton, CHARACTER_LIST);

	SFUI::SpriteButton* campaignButton = new SFUI::SpriteButton(campaignSpriteButtonTexture);
	playerTools->add(campaignButton);

	menu.addLabel("Documentation");
	SFUI::HorizontalBoxLayout* hbox1 = menu.addHorizontalBoxLayout();
	hbox1->addButton("Release Notes", OPEN_RELEASE_NOTES);
	SFUI::HorizontalBoxLayout* hbox2 = menu.addHorizontalBoxLayout();
	hbox2->addButton("Documentation", OPEN_DOCUMENTATION);

	menu.addLabel("Utilities");
	menu.addButton("Create a Campaign", CREATE_A_CAMPAIGN);
	menu.addButton("Manage content", MANAGE_CONTENT);

	menu.addHorizontalBoxLayout();
	menu.addButton("Application Settings", APPLICATION_SETTINGS);
}
