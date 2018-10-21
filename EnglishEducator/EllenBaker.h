#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Game.h"
#include <vector>

namespace EnglishEducator
{
	class EllenBaker
	{
	public:
		EllenBaker(GameDataRef data);

		void Animate(float dt);

		void AdvanceText();
		void RewindText();
		void ChangeText();

		const sf::Sprite &GetTextBoxSprite() const;
		const sf::Sprite &GetSimplePresent() const;
		const sf::Sprite &GetSimplePresent2() const;
		const sf::Sprite &GetSimplePast() const;
		const sf::Sprite &GetSimplePast2() const;
		const sf::Sprite &GetSimpleFuture() const;
		const sf::Sprite &GetFutureContinuous() const;

		void MakeChoicesAppear(bool);

		void DeleteTopics();

		void Draw();

	private:
		GameDataRef _data;
		sf::Sprite _ellenBakerSprite;
		sf::Sprite _textBox;
		std::vector<sf::Texture> _animationFrames;

		unsigned int _animationIterator;

		unsigned int _textNum = 0;

		sf::Clock _clock;

		sf::Text _text;
		sf::Text _text2;

		// Topic Sprites
		sf::Sprite *_simplePresent = new sf::Sprite();
		sf::Sprite *_simplePresent2 = new sf::Sprite();
		sf::Sprite *_simplePast = new sf::Sprite();
		sf::Sprite *_simplePast2 = new sf::Sprite();
		sf::Sprite *_simpleFuture = new sf::Sprite();
		sf::Sprite *_futureContinuous = new sf::Sprite();

		bool _makeChoicesAppear = true;
	};
}