#include "Misli.h"

#include "IApplication.h"
#include "Common/CmdLineArgs.h"
#include "Engine/SplashScreen.h"

extern Win32::IApplication* EntryApplication();

INT CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{

	auto EntryApp = EntryApplication();

	PerGameSettings GameSettings;
	EntryApp->SetupPerGameSettings();

	CmdLineArgs::ReadArguments();

	Logger logger;
	EntryApp->Initialize();

	SplashScreen::Open();

	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		// If there are Window messages then process them.
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			EntryApp->Update();
		}
	}

	return 0;
}