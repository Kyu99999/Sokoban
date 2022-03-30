#include "stdafx.h"
#include "Input.h"


static bool s_currnetKeyStates[256] = { false };
static bool s_prevKeyStates[256] = { false };
void UpdateInput()
{


}

bool GetButtonDown(EKeyCode keycode)
{
	if (false == s_prevKeyStates[keycode] && s_currentKeyStates[keycode])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GetButtonUp(EKeyCode keycode)
{
	if (s_prevKeyState[keycode] && false == s_currentKeyStates[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool GetButton(EKeyCode keycode)
{
	if (s_prevKeyState[keycode] && false == s_currentKeyStates[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}