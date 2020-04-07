#ifndef CHARACTER_LIST_STATE_HPP
#define CHARACTER_LIST_STATE_HPP

#include "AppState.hpp"

#include <SFUI/Layouts/Menu.hpp>

#include <string>
#include <vector>

class SFWS;

class CharacterListState : public AppState
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

	void buildHomeInterface(SFWS* interface, SFUI::Menu& menu);

	std::vector<std::string> get_directories(const std::string& s);

	// TODO: make these follow the normal style for Enums
	enum CALLBACKS
	{
		BACK = -2,
	};
};

#endif // !CHARACTER_LIST_STATE_HPP
