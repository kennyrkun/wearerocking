#ifndef MAIN_MENU_STATE_HPP
#define MAIN_MENU_STATE_HPP

#include "AppState.hpp"

#include <VGUI/VGUI.hpp>
#include <SFUI/Layouts/Menu.hpp>

class MainMenuState : public AppState
{
public:
	void Init(AppEngine* app);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents();
	void Update();
	void Draw();

private:
	AppEngine* app;

	SFUI::Menu* menu;

	sf::Texture characterSheetSpriteButtonTexture;
	sf::Texture campaignSpriteButtonTexture;

	void buildHomeInterface(VGUI* interface, SFUI::Menu& menu);

	// TODO: make these follow the normal style for Enums
	enum CALLBACKS
	{
		CHARACTER_LIST,

		OPEN_DOCUMENTATION,
		OPEN_RELEASE_NOTES,

		CREATE_A_CAMPAIGN,
		MANAGE_CONTENT,

		APPLICATION_SETTINGS,

		QUIT
	};
};

#endif // !MAIN_MENU_STATE_HPP