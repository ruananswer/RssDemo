/************************************************************************/
/*  File Name: DemoMain.cpp
	@Function: main function
	@Author: ruan.answer
	@Create Time: 2013-11-25 20:30
	@Last Modify: 2013-12-03 21:40 */
/************************************************************************/
#include <iostream>
#include "AppDemo.h"

#define NO_DEBUG

#ifndef _DEBUG
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
#else
int main(int argc, char **argv)
#endif
{

	RssApp::AppDemo demo;
	try
	{
		demo.run();
	}
	catch(std::exception& e)
	{
		fprintf(stderr, "An exception has occurred: %s\n", e.what());
	}
	return 0;
}
