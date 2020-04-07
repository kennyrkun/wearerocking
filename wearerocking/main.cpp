#include "AppEngine.hpp"

#include "MainMenuState.hpp"
#include "SettingsParser.hpp"
#include "Globals.hpp"

#include <SFUI/Theme.hpp>

int main()
{
	SFUI::Theme::loadFont(GBL::DIR::fonts + "tahoma.ttf");
	SFUI::Theme::loadTexture(GBL::DIR::textures + "interface/window/vgui.png");
	SFUI::Theme::textCharacterSize = 11;
	SFUI::Theme::click.textColor = sf::Color::White;
	SFUI::Theme::click.textColorHover = sf::Color::White;
	SFUI::Theme::click.textColorFocus = sf::Color::White;
	SFUI::Theme::input.textColor = sf::Color::White;
	SFUI::Theme::input.textColorHover = sf::Color::White;
	SFUI::Theme::input.textColorFocus = sf::Color::White;
	SFUI::Theme::label.textColor = sf::Color::White;
	SFUI::Theme::label.textColorHover = sf::Color::White;
	SFUI::Theme::label.textColorFocus = sf::Color::White;
	SFUI::Theme::PADDING = 2.f;

	AppSettings settings;
	settings.window.verticalSync = false;

	AppEngine app;

	app.Init("wearerocking", settings);

	SettingsParser VGUIConfParser;

	if (VGUIConfParser.loadFromFile(GBL::DIR::resources + "vgui.conf"))
	{
		std::vector<int> colors;

		if (VGUIConfParser.get("windowBackground", colors))
			app.windowDecorations.colors.windowBackground = sf::Color(colors[0], colors[1], colors[2]);

		if (VGUIConfParser.get("borderBlack", colors))
			app.windowDecorations.colors.borderBlack = sf::Color(colors[0], colors[1], colors[2]);

		if (VGUIConfParser.get("borderWhite", colors))
			app.windowDecorations.colors.borderWhite = sf::Color(colors[0], colors[1], colors[2]);

		if (VGUIConfParser.get("border", colors))
			app.windowDecorations.colors.border = sf::Color(colors[0], colors[1], colors[2]);

		app.windowDecorations.setColours();

		if (VGUIConfParser.get("text", colors))
		{
			SFUI::Theme::click.textColor = sf::Color(colors[0], colors[1], colors[2]);
			SFUI::Theme::click.textColorFocus = sf::Color(colors[0], colors[1], colors[2]);
			SFUI::Theme::click.textColorHover = sf::Color(colors[0], colors[1], colors[2]);

			SFUI::Theme::input.textColor = sf::Color(colors[0], colors[1], colors[2]);
			SFUI::Theme::input.textColorFocus = sf::Color(colors[0], colors[1], colors[2]);
			SFUI::Theme::input.textColorHover = sf::Color(colors[0], colors[1], colors[2]);
		}

		std::string interfaceTexture = GBL::DIR::textures + "interface/window/vgui.png";
		VGUIConfParser.get("interfacetexture", interfaceTexture);

		SFUI::Theme::loadTexture(interfaceTexture);
	}

	app.PushState(new MainMenuState);

	while (app.Running())
	{
		app.HandleEvents();
		app.Update();
		app.Draw();
	}

	app.Cleanup();

	return EXIT_SUCCESS;
}
