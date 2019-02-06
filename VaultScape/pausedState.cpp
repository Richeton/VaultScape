#include "pausedState.h"
#include "optionsState.h"
#include "quitState.h"

void PausedState::entry(VaultScape * game)
{
	//MessageBox(NULL, "I HAVE ARRIVED PAUSED", "0", 0);
	background = game->backgroundPaused;

	buttonImage = game->buttonImage;
	font = game->buttonFont;

	// Resume Button
	Button resumeBt;
	resumeBt.setNextState(NULL);
	resumeBt.setText("Resume");
	resumeBt.setImage(buttonImage);
	resumeBt.setFont(*font);
	resumeBt.setPos((GAME_WIDTH - ButtonNS::BUTTON_WIDTH) / 2, (GAME_HEIGHT - ButtonNS::BUTTON_HEIGHT) / 6 * 2);
	buttonList.push_back(resumeBt);

	// Options Button
	Button optionsBt;
	optionsBt.setNextState(new OptionsState());
	optionsBt.setText("Options");
	optionsBt.setImage(buttonImage);
	optionsBt.setFont(*font);
	optionsBt.setPos((GAME_WIDTH - ButtonNS::BUTTON_WIDTH) / 2, (GAME_HEIGHT - ButtonNS::BUTTON_HEIGHT) / 6 * 3);
	buttonList.push_back(optionsBt);

	// Quit to Menu Button
	Button quitMenuBt;
	quitMenuBt.setNextState(NULL);
	quitMenuBt.setText("Quit to Menu");
	quitMenuBt.setImage(buttonImage);
	quitMenuBt.setFont(*font);
	quitMenuBt.setPos((GAME_WIDTH - ButtonNS::BUTTON_WIDTH) / 2, (GAME_HEIGHT - ButtonNS::BUTTON_HEIGHT) / 6 * 4);
	buttonList.push_back(quitMenuBt);

	// Quit Game Button
	Button quitGameBt;
	quitGameBt.setNextState(new QuitState());
	quitGameBt.setText("Quit Game");
	quitGameBt.setImage(buttonImage);
	quitGameBt.setFont(*font);
	quitGameBt.setPos((GAME_WIDTH - ButtonNS::BUTTON_WIDTH) / 2, (GAME_HEIGHT - ButtonNS::BUTTON_HEIGHT) / 6 * 5);
	buttonList.push_back(quitGameBt);

}

void PausedState::handleInput(VaultScape * game, Input * input)
{
	// Keyboard Inputs

	// Escape Key
	if (input->isKeyDown(VK_ESCAPE))
	{
		this->exit(game);
		game->currentState.pop_back();
		game->currentState.back()->entry(game);
		input->clearAll();
	}

	// Mouse Input
	for (int i = 0; i < buttonList.size(); i++)
	{
		if (buttonList[i].mouseOnButton(*input))
		{
			buttonList[i].setSelectedMouse(true);
		}
		else if (!buttonList[i].mouseOnButton(*input) && !buttonList[i].getSelectedKeyboard())
		{
			buttonList[i].setSelectedMouse(false);
		}
	}

	if (input->getMouseLButton())
	{
		for (int i = 0; i < buttonList.size(); i++)
		{
			if (buttonList[i].getSelectedMouse())
			{
				//changeState(game, buttonList[i].getNextState());
				GameState * nextGameState = buttonList[i].getNextState();
				if (nextGameState != NULL)
				{
					this->exit(game);
					game->currentState.push_back(nextGameState);
					game->currentState.back()->entry(game);
					nextGameState = NULL;
					input->clear(inputNS::MOUSE);
					break;
				}
				else if (i == 0) 
				{
					this->exit(game);
					game->currentState.pop_back();
					game->currentState.back()->entry(game);
					input->clear(inputNS::MOUSE);
					break;
				}
				else 
				{				
					this->exit(game);
					game->currentState.pop_back();
					game->currentState.pop_back();
					game->currentState.back()->entry(game);
					input->clear(inputNS::MOUSE);
					break;
				}
			}
		}
	}
}

void PausedState::update(VaultScape * game)
{
}

void PausedState::ai(VaultScape * game)
{
}

void PausedState::collisions(VaultScape * game)
{
}

void PausedState::render(VaultScape * game)
{
	// Accessing of Running State's render(), followed by a transparency background
	game->currentState[game->currentState.size() - 2]->render(game);
	background.draw();

	// Displaying of Button
	for (int i = 0; i < buttonList.size(); i++)
	{
		buttonList[i].getImage().draw();
		buttonList[i].getImage().printText(buttonList[i].getFont(), buttonList[i].getText());
	}
}

void PausedState::exit(VaultScape * game)
{
	//MessageBox(NULL, "I HAVE LEFT PAUSED", "0", 0);
}
