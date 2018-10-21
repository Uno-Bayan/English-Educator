#include "stdafx.h"
#include "GamePlayStartMenu.h"

namespace EnglishEducator
{
	GamePlayStartMenu::GamePlayStartMenu(GameDataRef data) : _data(data)
	{
		_data->assets.LoadTexture("Start Menu Button Background",
			START_MENU_BUTTON_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Grammar Button",
			START_MENU_GRAMMAR_BUTTON_FILEPATH);
		_data->assets.LoadTexture("Vocabulary Button",
			START_MENU_VOCABULARY_BUTTON_FILEPATH);
		_data->assets.LoadTexture("Olympiad Button",
			START_MENU_OLYMPIAD_BUTTON_FILEPATH);

		_startMenu.setTexture(_data->assets.GetTexture("Start Menu Button Background"));
		_grammar.setTexture(_data->assets.GetTexture("Grammar Button"));
		_vocabulary.setTexture(_data->assets.GetTexture("Vocabulary Button"));
		_olympiad.setTexture(_data->assets.GetTexture("Olympiad Button"));

		_startMenu.setPosition(0, 0);
		_grammar.setPosition(sf::Vector2f(_data->window.getSize().x / 6 * 1.5 -
			_grammar.getGlobalBounds().width / 2, _data->window.getSize().y / 5 -
			_grammar.getGlobalBounds().height / 2));
		_vocabulary.setPosition(sf::Vector2f(_data->window.getSize().x / 6 * 3 -
			_vocabulary.getGlobalBounds().width / 2, _data->window.getSize().y / 5 -
			_vocabulary.getGlobalBounds().height / 2));
		_olympiad.setPosition(sf::Vector2f(_data->window.getSize().x / 6 * 4.5 -
			_olympiad.getGlobalBounds().width / 2, _data->window.getSize().y / 5 -
			_olympiad.getGlobalBounds().height / 2));

	}
	void GamePlayStartMenu::Draw()
	{
		_data->window.draw(_startMenu);
		_data->window.draw(_grammar);
		_data->window.draw(_vocabulary);
		_data->window.draw(_olympiad);
	}

	const sf::Sprite &GamePlayStartMenu::GetBackgroundSprite() const
	{
		return _startMenu;
	}

	const sf::Sprite &GamePlayStartMenu::GetGrammarSprite() const
	{
		return _grammar;
	}

	const sf::Sprite &GamePlayStartMenu::GetVocabularySprite() const
	{
		return _vocabulary;
	}

	const sf::Sprite &GamePlayStartMenu::GetOlympiadSprite() const
	{
		return _olympiad;
	}
}