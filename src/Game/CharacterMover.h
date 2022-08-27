#pragma once

#include "ICharacterMover.h"
#include <vector>
#include <thread>
#include "src/Game/Character.h"

class CharacterMover : public ICharacterMover {
private:
	std::vector<CharacterPtr> character;
	std::thread moveThread;
	bool active;
public:
	CharacterMover() {
		this->character = std::vector<CharacterPtr>();
		active = true;
	}
	~CharacterMover() {
		active = false;
		if (moveThread.joinable()) {
			moveThread.join();
		}
	}
	void Start() {
		moveThread = std::thread(&CharacterMover::MoveCharacter, this);
	}

	void SetCharacter(std::vector<CharacterPtr> character) {
		this->character = character;
	}
private:
	void MoveCharacter() {
		while (active) {
			for(int i = 0; i < character.size(); ++i){
				auto moveDir = character.at(i)->MoveDirection();
				character.at(i)->Move(FVector2{(float)moveDir.x, (float)moveDir.y});
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(15));
		}
	}
};