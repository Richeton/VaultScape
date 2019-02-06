#include "mainMenuState.h"
#include "runningState.h"
#include "optionsState.h"
#include "quitState.h"


void MainMenuState::entry(VaultScape * game)
{
	background = game->backgroundMainMenu;
	buttonImage = game->buttonImage;
	font = game->buttonFont;

	// Start Game Button
	Button startGameBt;
	startGameBt.setNextState(new RunningState());
	startGameBt.setText("Start Game");
	startGameBt.setImage(buttonImage);
	startGameBt.setFont(*font);
	startGameBt.setPos( (GAME_WIDTH - ButtonNS::BUTTON_WIDTH)/2 , (GAME_HEIGHT - ButtonNS::BUTTON_HEIGHT)/6*3);
	buttonList.push_back(startGameBt);

	// Options Button
	Button optionsBt;
	optionsBt.setNextState(new OptionsState());
	optionsBt.setText("Options");
	optionsBt.setImage(buttonImage);
	optionsBt.setFont(*font);
	optionsBt.setPos((GAME_WIDTH - ButtonNS::BUTTON_WIDTH) / 2, (GAME_HEIGHT - ButtonNS::BUTTON_HEIGHT) / 6 * 4);
	buttonList.push_back(optionsBt);

	// Quit Game Button
	Button quitGameBt;
	quitGameBt.setNextState(new QuitState());
	quitGameBt.setText("Quit Game");
	quitGameBt.setImage(buttonImage);
	quitGameBt.setFont(*font);
	quitGameBt.setPos((GAME_WIDTH - ButtonNS::BUTTON_WIDTH) / 2, (GAME_HEIGHT - ButtonNS::BUTTON_HEIGHT) / 6 * 5);
	buttonList.push_back(quitGameBt);
	
	buttonList[0].setSelectedKeyboard(true);
}




void MainMenuState::handleInput(VaultScape * game, Input * input)
{
	// Keyboard Inputs
	if (input->isKeyDown(VK_DOWN))
	{		
		for (int i = 0; i < buttonList.size(); i++)
		{
			if (buttonList[i].getSelectedKeyboard() == true)
			{
				buttonList[i].setSelectedKeyboard(false);
				if (i != buttonList.size() - 1)
					buttonList[i + 1].setSelectedKeyboard(true);
				else
					buttonList[0].setSelectedKeyboard(true);
				input->clear(inputNS::KEYS_DOWN);
				break;
			}
			else
			{
				continue;
			}
		}
	}

	if (input->isKeyDown(VK_UP))
	{
		for (int i = 0; i < buttonList.size(); i++)
		{
			if (buttonList[i].getSelectedKeyboard() == true)
			{
				buttonList[i].setSelectedKeyboard(false);
				if (i != 0)
					buttonList[i - 1].setSelectedKeyboard(true);
				else
					buttonList[buttonList.size() - 1].setSelectedKeyboard(true);
				input->clear(inputNS::KEYS_DOWN);
				break;
			}
			else
			{
				continue;
			}
		}
	}

	if (input->isKeyDown(ENTER_KEY))
	{
		for (int i = 0; i < buttonList.size(); i++)
		{
			if (buttonList[i].getSelectedKeyboard() == true) 
			{
				//changeState(game, buttonList[i].getNextState());
				GameState * nextGameState = buttonList[i].getNextState();
				this->exit(game);
				game->currentState.push_back(nextGameState);
				nextGameState->entry(game);
				nextGameState = NULL;
				input->clear(inputNS::KEYS_DOWN);
				break;
			}
		}		
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
				this->exit(game);
				game->currentState.push_back(nextGameState);
				nextGameState->entry(game);
				nextGameState = NULL;
				input->clear(inputNS::MOUSE);
				break;
			}
		}
	}
}

void MainMenuState::render(VaultScape * game)
{
	background.draw();
	for (int i = 0; i < buttonList.size(); i++)
	{
		buttonList[i].getImage().draw();
		buttonList[i].getImage().printText(buttonList[i].getFont(),buttonList[i].getText());
	}

}

void MainMenuState::update(VaultScape * game)
{
}

void MainMenuState::exit(VaultScape * game)
{
	buttonList.clear();
	//MessageBox(NULL, "I HAVE LEFT MENU", "0", 0);
}

/*
inline void changeState(Game * game, GameState * gameState)
{
	this->exit(game);
	game->currentState.push(gameState);
	gameState.entry(game);
}
*/