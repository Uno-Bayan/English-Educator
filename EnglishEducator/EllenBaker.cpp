#include "stdafx.h"
#include "EllenBaker.h"

namespace EnglishEducator
{
	EllenBaker::EllenBaker(GameDataRef data) : _data(data)
	{
		_animationIterator = 0;

		// pushes back all textures to texture vector
		_data->assets.LoadTexture("Teacher Frame 1", TEACHER_FRAME_1_FILEPATH);
		_data->assets.LoadTexture("Teacher Frame 2", TEACHER_FRAME_2_FILEPATH);
		_data->assets.LoadTexture("Teacher Frame 3", TEACHER_FRAME_3_FILEPATH);
		_data->assets.LoadTexture("Teacher Frame 4", TEACHER_FRAME_4_FILEPATH);
		_data->assets.LoadTexture("Teacher Frame 5", TEACHER_FRAME_5_FILEPATH);
		_data->assets.LoadTexture("Teacher Frame 6", TEACHER_FRAME_6_FILEPATH);
		_data->assets.LoadTexture("Teacher Frame 7", TEACHER_FRAME_7_FILEPATH);
		_data->assets.LoadTexture("Teacher Frame 8", TEACHER_FRAME_8_FILEPATH);
		_data->assets.LoadTexture("Teacher Frame 9", TEACHER_FRAME_9_FILEPATH);
		
		_data->assets.LoadTexture("Text Box", TEXT_BOX_FILEPATH);

		_data->assets.LoadTexture("Simple Present", SIMPLE_PRESENT_FILEPATH);
		_data->assets.LoadTexture("Simple Present 2", SIMPLE_PRESENT_2_FILEPATH);
		_data->assets.LoadTexture("Simple Past", SIMPLE_PAST_FILEPATH);
		_data->assets.LoadTexture("Simple Past 2", SIMPLE_PAST_2_FILEPATH);
		_data->assets.LoadTexture("Simple Future", SIMPLE_FUTURE_FILEPATH);
		_data->assets.LoadTexture("Future Continuous", FUTURE_CONTINUOUS_FILEPATH);
		
		_animationFrames.push_back(_data->assets.GetTexture("Teacher Frame 1"));
		_animationFrames.push_back(_data->assets.GetTexture("Teacher Frame 2"));
		_animationFrames.push_back(_data->assets.GetTexture("Teacher Frame 3"));
		_animationFrames.push_back(_data->assets.GetTexture("Teacher Frame 4"));
		_animationFrames.push_back(_data->assets.GetTexture("Teacher Frame 5"));
		_animationFrames.push_back(_data->assets.GetTexture("Teacher Frame 6"));
		_animationFrames.push_back(_data->assets.GetTexture("Teacher Frame 7"));
		_animationFrames.push_back(_data->assets.GetTexture("Teacher Frame 8"));
		_animationFrames.push_back(_data->assets.GetTexture("Teacher Frame 9"));

		_ellenBakerSprite.setTexture(_animationFrames.at(_animationIterator));
		_ellenBakerSprite.setPosition(-50, -45);

		_textBox.setTexture(_data->assets.GetTexture("Text Box"));
		_textBox.setPosition(300, 50);

		_text.setFont(_data->assets.GetFont("Wunderland"));
		_text.setString("This game was made purely for the education of my sister");
		_textNum++;	// text num is now 1
		_text.setCharacterSize(36);
		_text.setFillColor(sf::Color::Black);
		_text.setOrigin(_text.getGlobalBounds().width / 2,
			_text.getGlobalBounds().height / 2);
		_text.setPosition(_data->window.getSize().x / 5 * 3,
			_data->window.getSize().y / 4 * 1 - 60);

		_text2.setFont(_data->assets.GetFont("Wunderland"));
		_text2.setString("(Left-Click to Continue, Right-Click to Go Back)");
		_text2.setCharacterSize(24);
		_text2.setFillColor(sf::Color::Red);
		_text2.setOrigin(_text.getGlobalBounds().width / 2,
			_text.getGlobalBounds().height / 2);
		_text2.setPosition(_data->window.getSize().x / 5 * 3+ 170,
			_data->window.getSize().y / 4 * 1 + 80);

		_simplePresent->setTexture(_data->assets.GetTexture("Simple Present"));
		_simplePresent2->setTexture(_data->assets.GetTexture("Simple Present 2"));
		_simplePast->setTexture(_data->assets.GetTexture("Simple Past"));
		_simplePast2->setTexture(_data->assets.GetTexture("Simple Past 2"));
		_simpleFuture->setTexture(_data->assets.GetTexture("Simple Future"));
		_futureContinuous->setTexture(_data->assets.GetTexture("Future Continuous"));

		_simplePresent->setPosition(sf::Vector2f(400, 80));
		_simplePresent2->setPosition(sf::Vector2f(400, 150));
		_simplePast->setPosition(sf::Vector2f(400, 220));

		_simplePast2->setPosition(sf::Vector2f(700, 80));
		_simpleFuture->setPosition(sf::Vector2f(700, 150));
		_futureContinuous->setPosition(sf::Vector2f(700, 220));
	}

	void EllenBaker::Animate(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > TEACHER_ANIMATION_DURATION)
		{
			if (_animationIterator < _animationFrames.size() - 1)
			{
				_animationIterator++;
			}
			else
			{
				_animationIterator = 0;
			}

			_ellenBakerSprite.setTexture(_animationFrames.at(_animationIterator));

			_clock.restart();
		}
	}

	void EllenBaker::AdvanceText()
	{
		if (_textNum < 6)
		{
			_textNum++;
			ChangeText();
		}
	}

	void EllenBaker::RewindText()
	{
		if (_textNum > 1)
		{
			_textNum--;
			ChangeText();
		}
	}

	void EllenBaker::ChangeText()
	{
		switch (_textNum)
		{
		case 1:
			_text.setString("This game was made\npurely for the education\nof my sister");
			break;
		case 2:
			_text.setString("Text Num 2");
			break;
		case 3:
			_text.setString("Text Num 3");
			break;
		case 4:
			_text.setString("Text Num 4");
			break;
		case 5:
			_text.setString("Text Num 5");
			break;
		case 6:
			_text.setString("");
			break;
		}
	}

	const sf::Sprite &EllenBaker::GetTextBoxSprite() const
	{
		return _textBox;
	}

	const sf::Sprite &EllenBaker::GetSimplePresent() const
	{
		return *_simplePresent;
	}

	const sf::Sprite &EllenBaker::GetSimplePresent2() const
	{
		return *_simplePresent2;
	}

	const sf::Sprite &EllenBaker::GetSimplePast() const
	{
		return *_simplePast;
	}

	const sf::Sprite &EllenBaker::GetSimplePast2() const
	{
		return *_simplePast2;
	}

	const sf::Sprite &EllenBaker::GetSimpleFuture() const
	{
		return *_simpleFuture;
	}

	const sf::Sprite &EllenBaker::GetFutureContinuous() const
	{
		return *_futureContinuous;
	}

	void EllenBaker::MakeChoicesAppear(bool trueOrFalse)
	{
		_makeChoicesAppear = trueOrFalse;
	}

	void EllenBaker::DeleteTopics()
	{
		delete _simplePresent;
		delete _simplePresent2;
		delete _simplePast;
		delete _simplePast2;
		delete _simpleFuture;
		delete _futureContinuous;
	}

	void EllenBaker::Draw()
	{
		_data->window.draw(_ellenBakerSprite);

		_data->window.draw(_textBox);
		_data->window.draw(_text);
		_data->window.draw(_text2);

		if (_textNum == 6 && _makeChoicesAppear == true)
		{
			_data->window.draw(*_simplePresent);
			_data->window.draw(*_simplePresent2);
			_data->window.draw(*_simplePast);
			_data->window.draw(*_simplePast2);
			_data->window.draw(*_simpleFuture);
			_data->window.draw(*_futureContinuous);
		}
	}
}