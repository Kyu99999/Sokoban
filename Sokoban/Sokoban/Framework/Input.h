#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef enum Keycode
{
	W = 'w',
	A = 'a',
	S = 's',
	D = 'd',
}EKeycode;
/// <summary>
/// �Է� ���¸� ������Ʈ�Ѵ�.
/// </summary>
void UpdateInput();
/// <summary>
/// ���� �����ӿ� ��ư�� �������� üũ�Ѵ�.
/// </summary>
/// <param name="KeyCode">���� Ű �ڵ�</param>
/// <returns>�����ٸ� true, �ƴϸ� false</returns>
bool GetButtonDown(EKeyCode keyCode);
/// <summary>
/// ���� �����ӿ� ��ư�� �������� üũ�Ѵ�.
/// </summary>
/// <param name="keyCode">����Ű�ڵ�</param>
/// <returns>�´ٸ� true, �ƴϸ� false</returns>
void GetButtonUp(EKeyCode keyCode);
/// <summary>
/// ��ư�� ��� ���ȴ��� üũ�Ѵ�.
/// </summary>
/// <param name="keyCode">���� Ű �ڵ�</param>
/// <returns>�����ٸ� true, �ƴϸ� false</returns>
void GetButton(EKeyCode keyCode);
