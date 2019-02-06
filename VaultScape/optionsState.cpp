#include "optionsState.h"

void OptionsState::entry(VaultScape * game)
{
	//MessageBox(NULL, "I HAVE ARRIVED OPTIONS", "0", 0);
}

void OptionsState::handleInput(VaultScape * game, Input * input)
{
	if (input->isKeyDown(VK_ESCAPE))
	{
		this->exit(game);
		game->currentState.pop_back();
		game->currentState.back()->entry(game);
		input->clearAll();
	}
}

void OptionsState::update(VaultScape * game)
{
}

void OptionsState::ai(VaultScape * game)
{
}

void OptionsState::collisions(VaultScape * game)
{
}

void OptionsState::render(VaultScape * game)
{
}

void OptionsState::exit(VaultScape * game)
{
	//MessageBox(NULL, "I HAVE LEFT OPTIONS", "0", 0);
}
