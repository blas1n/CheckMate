#pragma once

#include "stdafx.h"
#include "GameDirector.h"
#include "RenderManager.h"
#include "Vector2.h"

class Sprite {
private:
	Gdiplus::Bitmap* m_pBitmap;
	LPWSTR m_name;
	DWORD m_size;

public:
	Sprite() = default;
	Sprite(const LPWSTR);
	Sprite(const Sprite&);

public:
	void Draw(const Utility::Vector2&, const Utility::Vector2&, const float&) const;

public:
	bool LoadSprite(const LPWSTR name);

public:
	HBITMAP GetHBitmap() const noexcept;
	LPWSTR GetName() const noexcept;
	DWORD GetSize() const noexcept;
	bool Empty() const noexcept;
};