#include <Geode/modify/GJGarageLayer.hpp>
#include <Geode/ui/BasedButtonSprite.hpp>

using namespace geode::prelude;

class $modify(AnimsGarageLayer, GJGarageLayer) {
	struct Fields {
		CCMenu* robotMenu = CCMenu::create();
		CCMenu* spiderMenu = CCMenu::create();
	};

	static void onModify(auto& self) {
        (void) self.setHookPriorityBeforePre("GJGarageLayer::onSelect", "hiimjustin000.more_icons");
    }

	void runRobotNoneAnim(CCObject* sender){
		auto animTarget = as<SimplePlayer*>(this->getChildByID("player-icon"))->m_robotSprite;
		animTarget->runAnimation("idle");
	}
	void runRobotIdle01Anim(CCObject* sender) {
		auto animTarget = as<SimplePlayer*>(this->getChildByID("player-icon"))->m_robotSprite;
		animTarget->runAnimation("idle01");
	}
	void runRobotRunAnim(CCObject* sender) {
		auto animTarget = as<SimplePlayer*>(this->getChildByID("player-icon"))->m_robotSprite;
		animTarget->runAnimation("run");
	}
	void runRobotRun2Anim(CCObject* sender) {
		auto animTarget = as<SimplePlayer*>(this->getChildByID("player-icon"))->m_robotSprite;
		animTarget->runAnimation("run2");
	}
	void runRobotRun3Anim(CCObject* sender) {
		auto animTarget = as<SimplePlayer*>(this->getChildByID("player-icon"))->m_robotSprite;
		animTarget->runAnimation("run3");
	}

	// Spider animations
	void runSpiderIdleAnim(CCObject* sender) {
		auto animTarget = as<SimplePlayer*>(this->getChildByID("player-icon"))->m_spiderSprite;
		animTarget->runAnimation("idle");
	}
	void runSpiderIdle01Anim(CCObject* sender) {
		auto animTarget = as<SimplePlayer*>(this->getChildByID("player-icon"))->m_spiderSprite;
		animTarget->runAnimation("idle01");
	}
	void runSpiderWalkAnim(CCObject* sender) {
		auto animTarget = as<SimplePlayer*>(this->getChildByID("player-icon"))->m_spiderSprite;
		animTarget->runAnimation("walk");
	}
	void runSpiderRunAnim(CCObject* sender) {
		auto animTarget = as<SimplePlayer*>(this->getChildByID("player-icon"))->m_spiderSprite;
		animTarget->runAnimation("run");
	}
	void runSpiderRun2Anim(CCObject* sender) {
		auto animTarget = as<SimplePlayer*>(this->getChildByID("player-icon"))->m_spiderSprite;
		animTarget->runAnimation("run2");
	}

	bool init() {
		if (!GJGarageLayer::init()) return false;

		auto fields = m_fields.self();

		auto winSize = CCDirector::sharedDirector()->getWinSize();

		fields->robotMenu->setID("robot-anims-menu"_spr);
		fields->spiderMenu->setID("spider-anims-menu"_spr);

		fields->robotMenu->setPosition({winSize.width / 2, winSize.height - 16.f});
		fields->spiderMenu->setPosition({winSize.width / 2, winSize.height - 16.f});

		fields->robotMenu->setContentSize({205.f, 45.f});
		fields->spiderMenu->setContentSize({205.f, 45.f});

		fields->robotMenu->setScale(0.5f);
		fields->spiderMenu->setScale(0.5f);

		fields->robotMenu->setLayout(
            RowLayout::create()
                ->setGap(4.f)
                ->setAxisAlignment(AxisAlignment::Center)
                ->setAxisReverse(true)
                ->setCrossAxisOverflow(false)
        );
		fields->spiderMenu->setLayout(
            RowLayout::create()
                ->setGap(4.f)
                ->setAxisAlignment(AxisAlignment::Center)
                ->setAxisReverse(true)
                ->setCrossAxisOverflow(false)
        );

		// labels
		auto robotStopLabel = CCLabelBMFont::create("none", "bigFont.fnt", 20, kCCTextAlignmentCenter);
		auto robotIdleLabel = CCLabelBMFont::create("idle", "bigFont.fnt", 20, kCCTextAlignmentCenter);
		auto robotRun1Label = CCLabelBMFont::create("run 1", "bigFont.fnt", 20, kCCTextAlignmentCenter);
		auto robotRun2Label = CCLabelBMFont::create("run 2", "bigFont.fnt", 20, kCCTextAlignmentCenter);
		auto robotRun3Label = CCLabelBMFont::create("run 3", "bigFont.fnt", 20, kCCTextAlignmentCenter);

		auto spiderStopLabel = CCLabelBMFont::create("none", "bigFont.fnt", 20, kCCTextAlignmentCenter);
		auto spiderIdleLabel = CCLabelBMFont::create("idle", "bigFont.fnt", 20, kCCTextAlignmentCenter);
		auto spiderWalkLabel = CCLabelBMFont::create("walk", "bigFont.fnt", 20, kCCTextAlignmentCenter);
		auto spiderRunLabel = CCLabelBMFont::create("run", "bigFont.fnt", 20, kCCTextAlignmentCenter);
		auto spiderRun2Label = CCLabelBMFont::create("run2", "bigFont.fnt", 20, kCCTextAlignmentCenter);

		// sprs
		auto robotStopSpr = CircleButtonSprite::create(robotStopLabel, CircleBaseColor::Gray, CircleBaseSize::Small);
		auto robotIdleSpr = CircleButtonSprite::create(robotIdleLabel, CircleBaseColor::Gray, CircleBaseSize::Small);
		auto robotRun1Spr = CircleButtonSprite::create(robotRun1Label, CircleBaseColor::Gray, CircleBaseSize::Small);
		auto robotRun2Spr = CircleButtonSprite::create(robotRun2Label, CircleBaseColor::Gray, CircleBaseSize::Small);
		auto robotRun3Spr = CircleButtonSprite::create(robotRun3Label, CircleBaseColor::Gray, CircleBaseSize::Small);

		auto spiderStopSpr = CircleButtonSprite::create(spiderStopLabel, CircleBaseColor::Gray, CircleBaseSize::Small);
		auto spiderIdleSpr = CircleButtonSprite::create(spiderIdleLabel, CircleBaseColor::Gray, CircleBaseSize::Small);
		auto spiderWalkSpr = CircleButtonSprite::create(spiderWalkLabel, CircleBaseColor::Gray, CircleBaseSize::Small);
		auto spiderRunSpr = CircleButtonSprite::create(spiderRunLabel, CircleBaseColor::Gray, CircleBaseSize::Small);
		auto spiderRun2Spr = CircleButtonSprite::create(spiderRun2Label, CircleBaseColor::Gray, CircleBaseSize::Small);

		auto r_stopButton = CCMenuItemSpriteExtra::create(robotStopSpr, this,
			menu_selector(AnimsGarageLayer::runRobotNoneAnim)
		);
		auto r_idleButton = CCMenuItemSpriteExtra::create(robotIdleSpr, this,
			menu_selector(AnimsGarageLayer::runRobotIdle01Anim)
		);
		auto r_run1Button = CCMenuItemSpriteExtra::create(robotRun1Spr, this,
			menu_selector(AnimsGarageLayer::runRobotRunAnim)
		);
		auto r_run2Button = CCMenuItemSpriteExtra::create(robotRun2Spr, this, 
			menu_selector(AnimsGarageLayer::runRobotRun2Anim)
		);
		auto r_run3Button = CCMenuItemSpriteExtra::create(robotRun3Spr, this,
			menu_selector(AnimsGarageLayer::runRobotRun3Anim)
		);

		auto s_stopButton = CCMenuItemSpriteExtra::create(spiderStopSpr, this,
			menu_selector(AnimsGarageLayer::runSpiderIdleAnim)
		);
		auto s_idleButton = CCMenuItemSpriteExtra::create(spiderIdleSpr, this,
			menu_selector(AnimsGarageLayer::runSpiderIdle01Anim)
		);
		auto s_walkButton = CCMenuItemSpriteExtra::create(spiderWalkSpr, this,
			menu_selector(AnimsGarageLayer::runSpiderWalkAnim)
		);
		auto s_runButton = CCMenuItemSpriteExtra::create(spiderRunSpr, this,
			menu_selector(AnimsGarageLayer::runSpiderRunAnim)
		);
		auto s_run2Button = CCMenuItemSpriteExtra::create(spiderRun2Spr, this,
			menu_selector(AnimsGarageLayer::runSpiderRun2Anim)
		);


		fields->robotMenu->addChild(r_stopButton);
		fields->robotMenu->addChild(r_idleButton);
		fields->robotMenu->addChild(r_run1Button);
		fields->robotMenu->addChild(r_run2Button);
		fields->robotMenu->addChild(r_run3Button);

		fields->spiderMenu->addChild(s_stopButton);
		fields->spiderMenu->addChild(s_idleButton);
		fields->spiderMenu->addChild(s_walkButton);
		fields->spiderMenu->addChild(s_runButton);
		fields->spiderMenu->addChild(s_run2Button);

		fields->robotMenu->updateLayout();
		fields->spiderMenu->updateLayout();

		this->addChild(fields->robotMenu);
		this->addChild(fields->spiderMenu);

		auto gameManager = GameManager::sharedState();
        auto lastSelectedIcon = gameManager->m_playerIconType;

		if (m_selectedIconType == IconType::Robot || lastSelectedIcon == IconType::Robot) {
			fields->robotMenu->setVisible(true);
			fields->spiderMenu->setVisible(false);
		} else if (m_selectedIconType == IconType::Spider || lastSelectedIcon == IconType::Spider) {
			fields->robotMenu->setVisible(false);
			fields->spiderMenu->setVisible(true);
		} else {
			fields->robotMenu->setVisible(false);
			fields->spiderMenu->setVisible(false);
		}

		return true;
	}

	void onSelect(CCObject* sender) {
		GJGarageLayer::onSelect(sender);

		auto fields = m_fields.self();

		if (m_selectedIconType == IconType::Robot) {
			fields->robotMenu->setVisible(true);
			fields->spiderMenu->setVisible(false);
		} else if (m_selectedIconType == IconType::Spider) {
			fields->robotMenu->setVisible(false);
			fields->spiderMenu->setVisible(true);
		} else {
			fields->robotMenu->setVisible(false);
			fields->spiderMenu->setVisible(false);
		}

	}
};