#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "DEFINITIONS.h"

namespace EnglishEducator
{
	class GamePlayStartMenu
	{
	public:
		GamePlayStartMenu(GameDataRef data);

		void Draw();

		const sf::Sprite &GetBackgroundSprite() const;
		const sf::Sprite &GetGrammarSprite() const;
		const sf::Sprite &GetVocabularySprite() const;
		const sf::Sprite &GetOlympiadSprite() const;

	private:
		GameDataRef _data;

		sf::Sprite _startMenu;
		sf::Sprite _grammar;
		sf::Sprite _vocabulary;
		sf::Sprite _olympiad;
	};
}