#include "UIManager.h"
#include "AppDemo.h"
#include "CommandManager.h"
#include "MainMenuControl.h"
#include "VideoTexture.h"

using namespace RssApp;

template<> UIManager* Ogre::Singleton<UIManager>::msSingleton = 0;

UIManager:: UIManager()
{
	mDemoGUI = new MyGUI::Gui();
	mPlatform = new MyGUI::OgrePlatform();
}

UIManager::~UIManager()
{
	delete CommandManager::getInstancePtr();
	delete MainMenuControl::getInstancePtr();
	delete VideoTexture::getSingletonPtr();

	mDemoGUI->shutdown();
	delete mDemoGUI;
	mDemoGUI = nullptr;
	mPlatform->shutdown();
	delete mPlatform;
	mPlatform = nullptr;
}

bool UIManager::bootUI(const Ogre::RenderWindow* wnd, Ogre::SceneManager* mgr)
{
	if(!mPlatform) 
		return false;
	mPlatform->initialise(const_cast<Ogre::RenderWindow*>(wnd),  const_cast<Ogre::SceneManager*>(mgr));
	if(!mDemoGUI)
		return false;
	mDemoGUI->initialise("MyGUI_Core.xml");
	initialiseUI(wnd);
	return true;
}

void UIManager::initialiseUI(const Ogre::RenderWindow* wnd)
{
	new CommandManager();
	new MainMenuControl();
	new VideoTexture();
}

void UIManager::windowResized(Ogre::RenderWindow* rw)
{
}