#include "hud.h"
#include "graphics.h"

HUD::HUD() {}

HUD::HUD(Graphics &graphics, Player &player) {
	this->_player = player;
	this->_healthBarSprite = Sprite(graphics, "content/sprites/TextBox.png", 0, 40, 64, 8, 35, 70);
}

void HUD::update(int elapsedTime) {

}

void HUD::draw(Graphics &graphics) {
	this->_healthBarSprite.draw(graphics, this->_healthBarSprite.getX(), this->_healthBarSprite.getY());
}