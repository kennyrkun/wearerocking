#include "CharacterListState.hpp"
#include "MainMenuState.hpp"

#include "Globals.hpp"

#include <SFWS/SFWS.hpp>

#include <SFUI/SFUI.hpp>
#include <SFUI/Theme.hpp>

#include <SFML/Graphics.hpp>

#include <experimental/filesystem>
#include <iostream>

namespace fs = std::experimental::filesystem;

void CharacterListState::Init(AppEngine* appEngine)
{
	app = appEngine;

	std::cout << "Initialising CharacterListState." << std::endl;

	SFUI::Theme::windowBgColor = app->windowDecorations.colors.windowBackground;

	menu = new SFUI::Menu(*app->window);
	menu->setPosition(sf::Vector2f(app->windowDecorations.sizes.left + 10, app->windowDecorations.sizes.top + app->windowDecorations.sizes.titlebar + 8));

	characterSheetSpriteButtonTexture.loadFromFile(GBL::DIR::textures + "charactersheetbutton.png");
	campaignSpriteButtonTexture.loadFromFile(GBL::DIR::textures + "campaignbutton.png");

	buildHomeInterface(&app->windowDecorations, *menu);
}

void CharacterListState::Cleanup()
{
	std::cout << "Cleaning up CharacterListState." << std::endl;
	std::cout << "CharacterListState cleaned up." << std::endl;
}

void CharacterListState::Pause()
{
	std::cout << "CharacterListState paused." << std::endl;
}

void CharacterListState::Resume()
{
	std::cout << "CharacterListState resumed." << std::endl;
}

void CharacterListState::HandleEvents()
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
		case CALLBACKS::BACK:
			app->ChangeState(new MainMenuState);
			return;
		};
	}
}

void CharacterListState::Update()
{
	// HACK: this is a workaround for decorations not being used directly by the app
	// TODO: this might cause problems if we have to hide the window for whatever reason
	if (!app->window->isOpen())
	{
		app->Quit();
		return;
	}
}

void CharacterListState::Draw()
{
	app->window->clear(SFUI::Theme::windowBgColor);

	app->window->draw(*menu);

	app->windowDecorations.Draw();
	app->window->display();
}

void CharacterListState::buildHomeInterface(SFWS* interface, SFUI::Menu& menu)
{
	menu.setPosition(sf::Vector2f(interface->sizes.left + 10, interface->sizes.top + interface->sizes.titlebar + 10));

	menu.addLabel("Character List");

	auto characterList = get_directories(GBL::DIR::base + "characters/");

	for (size_t i = 0; i < characterList.size(); i++)
	{
		menu.addButton(characterList[i], i);
	}

	menu.addButton("Back", CALLBACKS::BACK);
}

std::vector<std::string> CharacterListState::get_directories(const std::string& s)
{
	std::vector<std::string> r;
	for (auto& p : fs::directory_iterator(s))
		if (p.status().type() == fs::file_type::directory)
			r.push_back(p.path().string().substr(GBL::DIR::characters.length(), p.path().string().length()));
	return r;
}
