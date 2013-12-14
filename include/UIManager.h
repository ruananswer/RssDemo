#ifndef __UI_MANAGER_H__
#define __UI_MANAGER_H__

#include <OgreSingleton.h>
#include <Ogre.h>

#include <MyGUI.h>
#include <MyGUI_OgrePlatform.h>

namespace RssApp
{
	class UIManager:public Ogre::Singleton<UIManager>
	{
	public:
		UIManager();
		~UIManager();
		bool bootUI(const Ogre::RenderWindow *wnd, Ogre::SceneManager *mgr);
		void windowResized(Ogre::RenderWindow* rw);
	protected:

		void initialiseUI(const Ogre::RenderWindow* wnd);
	private:

		MyGUI::Gui*          mDemoGUI;
		MyGUI::OgrePlatform* mPlatform;
	};
}
#endif