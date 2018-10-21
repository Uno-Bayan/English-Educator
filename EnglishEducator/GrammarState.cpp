#include "stdafx.h"
#include "GrammarState.h"

namespace EnglishEducator
{
	GrammarState::GrammarState(GameDataRef data) : _data(data)
	{
		
	}

	void GrammarState::Init()
	{	
		_background.setTexture(_data->assets.GetTexture("Game Background"));

		ellenBaker = new EllenBaker(_data);

		qAndA = new QandA(_data, GrammarStates::eNone);
	}

	void GrammarState::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
			if (_clock.getElapsedTime().asSeconds() > 0.2) // to avoid multiple clicks in one go
			{
				if (_data->input.IsSpriteClicked(ellenBaker->GetTextBoxSprite(), sf::Mouse::Left, _data->window))
				{
					ellenBaker->AdvanceText();
					_clock.restart();
				}
				if (_data->input.IsSpriteClicked(ellenBaker->GetTextBoxSprite(), sf::Mouse::Right, _data->window))
				{
					ellenBaker->RewindText();
					_clock.restart();
				}
				if (_data->input.IsSpriteClicked(ellenBaker->GetSimplePresent(), sf::Mouse::Left, _data->window))
				{
					/*_grammarState = eSimplePresent;*/
					_clock.restart();
					qAndA = new QandA(_data, eSimplePresent);
					ellenBaker->MakeChoicesAppear(false);
					ellenBaker->DeleteTopics();
					qAndA->MakeAnswersAppear(true);
					qAndA->AdvanceQandA();
				}
				if (_data->input.IsSpriteClicked(ellenBaker->GetSimplePresent2(), sf::Mouse::Left, _data->window))
				{
					_clock.restart();
					qAndA = new QandA(_data, eSimplePresent);
					ellenBaker->MakeChoicesAppear(false);
					ellenBaker->DeleteTopics();
					qAndA->MakeAnswersAppear(true);
					qAndA->AdvanceQandA();
				}
				if (_data->input.IsSpriteClicked(ellenBaker->GetSimplePast(), sf::Mouse::Left, _data->window))
				{
					_clock.restart();
					qAndA = new QandA(_data, eSimplePast);
					ellenBaker->MakeChoicesAppear(false);
					ellenBaker->DeleteTopics();
					qAndA->MakeAnswersAppear(true);
					qAndA->AdvanceQandA();
				}
				if (_data->input.IsSpriteClicked(ellenBaker->GetSimplePast2(), sf::Mouse::Left, _data->window))
				{
					_clock.restart();
					qAndA = new QandA(_data, eSimplePast2);
					ellenBaker->MakeChoicesAppear(false);
					ellenBaker->DeleteTopics();
					qAndA->MakeAnswersAppear(true);
					qAndA->AdvanceQandA();
				}
				if (_data->input.IsSpriteClicked(ellenBaker->GetSimpleFuture(), sf::Mouse::Left, _data->window))
				{
					_clock.restart();
					qAndA = new QandA(_data, eSimpleFuture);
					ellenBaker->MakeChoicesAppear(false);
					ellenBaker->DeleteTopics();
					qAndA->MakeAnswersAppear(true);
					qAndA->AdvanceQandA();
				}
				if (_data->input.IsSpriteClicked(ellenBaker->GetFutureContinuous(), sf::Mouse::Left, _data->window))
				{
					_clock.restart();
					qAndA = new QandA(_data, eFutureContinuous);
					ellenBaker->MakeChoicesAppear(false);
					ellenBaker->DeleteTopics();
					qAndA->MakeAnswersAppear(true);
					qAndA->AdvanceQandA();
				}
				if (_data->input.IsSpriteClicked(qAndA->GetA1Sprite(), sf::Mouse::Left, _data->window))
				{
					_clock.restart();
					if (qAndA->_a1Text == qAndA->_correctAnswerText)
					{
						qAndA->IncrementScore();
					}
					
					qAndA->AdvanceQandA();
					
				}
				if (_data->input.IsSpriteClicked(qAndA->GetA2Sprite(), sf::Mouse::Left, _data->window))
				{
					_clock.restart();
					if (qAndA->_a2Text == qAndA->_correctAnswerText)
					{
						qAndA->IncrementScore();
					}
					
					qAndA->AdvanceQandA();
				}
				if (_data->input.IsSpriteClicked(qAndA->GetA3Sprite(), sf::Mouse::Left, _data->window))
				{
					_clock.restart();
					if (qAndA->_a3Text == qAndA->_correctAnswerText)
					{
						qAndA->IncrementScore();
					}

					qAndA->AdvanceQandA();
				}
				if (_data->input.IsSpriteClicked(qAndA->GetA4Sprite(), sf::Mouse::Left, _data->window))
				{
					_clock.restart();
					if (qAndA->_a4Text == qAndA->_correctAnswerText)
					{
						qAndA->IncrementScore();
					}

					qAndA->AdvanceQandA();
				}
			}
		}
	}

	void GrammarState::Update(float dt)
	{
		ellenBaker->Animate(dt);
		qAndA->Update();
	}

	int GrammarState::GetGrammarState()
	{
		return _grammarState;
	}

	void GrammarState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_background);

		ellenBaker->Draw();

		qAndA->Draw();

		_data->window.display();
	}
}