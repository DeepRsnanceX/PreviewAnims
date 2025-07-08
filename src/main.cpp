#include <Geode/modify/GJGarageLayer.hpp>

using namespace geode::prelude;

class $modify(AnimsGarageLayer, GJGarageLayer) {
	bool init() {
		if (!GJGarageLayer::init()) return false;

		auto icon = this->getChildByID("player-icon");
		auto winSize = CCDirector::sharedDirector()->getWinSize();

		auto robotMenu = CCMenu::create();
		auto spiderMenu = CCMenu::create();

		return true;
	}
};