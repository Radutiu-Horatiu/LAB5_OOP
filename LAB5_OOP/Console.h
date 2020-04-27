#pragma once
#include "Controller.h"
using namespace std;

class Console
{
private:

	Controller ctrl;

public:

	Console();
	~Console();

	/// <summary>	Shows the menu. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	void show_menu();

	/// <summary>	Shows the admin menu. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	void show_admin_menu();

	/// <summary>	Shows the user menu. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	void show_user_menu();
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// End of Console.h
////////////////////////////////////////////////////////////////////////////////////////////////////

