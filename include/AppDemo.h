/************************************************************************/
/*  File Name: AppDemo.h
	@Function:  
	@Author: ruan.answer
	@Create Time: 2013-11-25 22:00
	@Last Modify: 2013-12-05 15:02-add VideoTexture */
/************************************************************************/
#ifndef __APP_DEMO_H__
#define __APP_DEMO_H__

#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreOverlay.h>
#include <OgreOverlayElement.h>
#include <OgreOverlayManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>
#include <OgreWindowEventUtilities.h>
#include <OgreHardwarePixelBuffer.h>

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

//HOG
#include <core/core_c.h>
#include <gl/glut.h>
#include <imgproc/imgproc.hpp>
#include <objdetect/objdetect.hpp>
#include <ml.h>
#include <WinBase.h>

#include <SdkTrays.h>
#include <SdkCameraMan.h>

namespace RssApp
{
	class AppDemo : public Ogre::Singleton<AppDemo>, public OIS::KeyListener, public OIS::MouseListener, public Ogre::WindowEventListener  // public Ogre::FrameListener,
	{
	public:
		AppDemo();
		virtual ~AppDemo();

		bool initOgre(Ogre::String wndTitle);
		void updateOgre(double timeSinceLastFrame);

		bool keyPressed(const OIS::KeyEvent &keyEventRef);
		bool keyReleased(const OIS::KeyEvent &keyEventRef);

		bool mouseMoved(const OIS::MouseEvent &evt);
		bool mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
		bool mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id);

		void windowResized(Ogre::RenderWindow* rw);

		void run();

	//protected:
		void initOIS();
		void setupResources();
		void initDemo();
		virtual void createScene();

		AppDemo(const AppDemo&);
		AppDemo& operator= (const AppDemo&); 

		Ogre::Root*					mRoot;
		Ogre::RenderWindow*			mRenderWnd;
		Ogre::Log*					mLog;
		Ogre::Timer*				mTimer;

		OIS::Mouse*					mMouse;
		OIS::Keyboard*				mKeyboard;
		OIS::InputManager*			mInputMgr;

		Ogre::SceneManager*			mSceneMgr;
		Ogre::Camera*				mCamera;

		std::string					mWorkDirectory;

		bool				 mShutDown;
	};
}

#endif