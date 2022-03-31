#include "stdafx.h"
#include "Input.h"


static bool s_currentKeyStates[256] = { false };
static bool s_prevKeyStates[256] = { false };

bool isKeyDown(int keyCode)
{
	if (0x8000 & GetAsyncKeyState(keyCode))
	{
		return true;
	}
	else
	{
		return false;
	}

}
void UpdateInput()
{
	memcpy(s_prevKeyStates, s_currentKeyStates, sizeof(s_prevKeyStates));

	for (int keyCode = 0; keyCode < 255; ++keyCode)
	{
		if (isKeyDown(keyCode))
		{
			s_currentKeyStates[keyCode] = true;
		}
		else
		{
			s_currentKeyStates[keyCode] = false;
		}
		// 현재 키의 상태 값을 반환한다.
		// 0x8000 => 0b 1000 0000 0000 0000 => 눌린 상태
		// 0x8001 => 0b 1000 0000 0000 0001 => 계속 눌린 상태
		// 0x0001 => 사이엔 눌렸는데 지금은 뗌
		// 0x0000 => 지금은 안누름
		// 1. 현재 키가 눌렸는지 => MSB(Most significant Bit)가 set(1)
		// 2. 현재 키가 떼졌는지 => MSB가  0
		// 3. GetAsyncKeyState() ---- GetAsyncKeyStae()
		//	                      ↑ 요 사이에 눌렸는지 => LSB set
		GetAsyncKeyState(keyCode); 
	}

}

bool GetButtonDown(EKeyCode keyCode)
{
	
	if (false == s_prevKeyStates[keyCode] && s_currentKeyStates[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GetButtonUp(EKeyCode keyCode)
{
	if (s_prevKeyStates[keyCode] && false == s_currentKeyStates[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool GetButton(EKeyCode keyCode)
{
	if (s_prevKeyStates[keyCode] && s_currentKeyStates[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}