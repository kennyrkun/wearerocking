#ifndef CHARACTER_EDIT_STATE_HPP
#define CHARACTER_EDIT_STATE_HPP

#include "AppState.hpp"

#include <VGUI/VGUI.hpp>
#include <SFUI/Layouts/Menu.hpp>

class CharacterEditState : public AppState
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
		GOTO_CHARACTER_SHEETS,
		OPEN_MODEL_VIEWER,
		OPEN_FACE_POSER,
		OPEN_ITEM_TEST,

		OPEN_DOCUMENTATION,
		OPEN_RELEASE_NOTES,

		CREATE_A_MOD,
		REFRESH_SDK_CONTENT,
		RESET_GAME_CONFIGURATIONS,
		EDIT_GAME_CONFIGURATIONS,

		APPLICATION_SETTINGS,

		QUIT
	};
};

#endif // !CHARACTER_EDIT_STATE_HPP