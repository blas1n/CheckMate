#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite()
	: m_pBitmap(nullptr),
	m_name(0),
	m_size(0) {}

Sprite::Sprite(const LPWSTR name) : Sprite() {
	LoadSprite(name);
}

Sprite::Sprite(const Sprite& other) : Sprite() {
	LoadSprite(other.GetName());
}

void Sprite::Draw(Graphics& graphics, int x, int y) const {
	graphics.DrawImage(m_pBitmap, x, y);
}

bool Sprite::LoadSprite(const LPWSTR name) {
	m_name = name;

	auto hResource = FindResource(GameDirector::GetGameDirector()->GetHInstance(), m_name, TEXT("PNG"));
	if (!hResource) return false;

	m_size = SizeofResource(GameDirector::GetGameDirector()->GetHInstance(), hResource);
	auto hGlobal = LoadResource(GameDirector::GetGameDirector()->GetHInstance(), hResource);
	auto pData = LockResource(hGlobal);

	auto hBuffer = GlobalAlloc(GMEM_MOVEABLE, m_size);
	auto pBuffer = GlobalLock(hBuffer);
	CopyMemory(pBuffer, pData, m_size);
	GlobalUnlock(hBuffer);

	IStream* pStream;
	CreateStreamOnHGlobal(hBuffer, TRUE, &pStream);
	m_pBitmap = Bitmap::FromStream(pStream);
	pStream->Release();

	return m_pBitmap->GetLastStatus() == Ok;
}

HBITMAP Sprite::GetHBitmap() const noexcept {
	HBITMAP hBitmap;
	m_pBitmap->GetHBITMAP(Color(0, 0, 0), &hBitmap);
	return hBitmap;
}

LPWSTR Sprite::GetName() const noexcept {
	return m_name;
}

DWORD Sprite::GetSize() const noexcept {
	return m_size;
}

bool Sprite::Empty() const noexcept {
	return m_pBitmap == nullptr;
}

Color Sprite::GetColor() const noexcept {
	return m_color;
}

void Sprite::SetColor(Color color) noexcept {
	m_color = color;
}