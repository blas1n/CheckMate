#pragma once

#include "stdafx.h"
#include "GameDirector.h"
#include <combaseapi.h>

class Sprite {
private:
	Bitmap* m_pBitmap;
	LPWSTR m_name;
	DWORD m_size;
	Color m_color;

public:
	Sprite();
	Sprite(const LPWSTR);
	Sprite(const Sprite&);
	~Sprite() = default;

public:
	void Draw(Graphics&, int, int) const;

public:
	bool LoadSprite(const LPWSTR name);

public:
	HBITMAP GetHBitmap() const noexcept;
	LPWSTR GetName() const noexcept;
	DWORD GetSize() const noexcept;
	bool Empty() const noexcept;

public:
	Color GetColor() const noexcept;
	void SetColor(Color) noexcept;
};