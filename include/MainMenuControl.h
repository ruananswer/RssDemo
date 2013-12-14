#ifndef __MAINMENU_CONTROL_H__
#define __MAINMENU_CONTROL_H__

#include <MyGUI.h>
#include <BaseLayout/BaseLayout.h>

namespace RssApp
{
	class MainMenuControl: public wraps::BaseLayout, public MyGUI::Singleton<MainMenuControl>
	{
	public:
		MainMenuControl(MyGUI::Widget* _parent = nullptr);
		virtual ~MainMenuControl();

		void setVisible(bool _value);
	protected:
		void createMainMenu();
		void notifyPopupMenuAccept(MyGUI::MenuControl* _sender, MyGUI::MenuItem* _item);

		void widgetsUpdate();
		std::string getDescriptionString(MyGUI::Widget* _widget, bool _print_name, bool _print_type, bool _print_skin);

		void notifyChangeWidgets();
		void notifySettingsChanged(const MyGUI::UString& _sectionName, const MyGUI::UString& _propertyName);

		void updateRecentFilesMenu();
		void updateRecentProjectsMenu();
	private:
		MyGUI::MenuBar* mBar;
		MyGUI::MenuControl* mPopupMenuWidgets;
	};
}
#endif