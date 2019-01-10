#include "Sprite.h"

Sprite::Sprite(const LPWSTR name) : Sprite() {
	LoadSprite(name);
}

Sprite::Sprite(const Sprite& other) : Sprite() {
	LoadSprite(other.GetName());
}

void Sprite::Draw(const Utility::Vector2& pos, const Utility::Vector2& scale, const float& angle) const {
	GameDirector::GetGameDirector().GetRenderManager().RenderImage(m_pBitmap, pos, scale, angle);
}

bool Sprite::LoadSprite(const LPWSTR name) {
	m_name = name;

	auto hInstance = GameDirector::GetGameDirector().GetHInstance();

	auto hResource = FindResource(hInstance, m_name, TEXT("PNG"));
	if (!hResource) return false;

	m_size = SizeofResource(hInstance, hResource);
	auto hGlobal = LoadResource(hInstance, hResource);
	auto pData = LockResource(hGlobal);

	auto hBuffer = GlobalAlloc(GMEM_MOVEABLE, m_size);
	auto pBuffer = GlobalLock(hBuffer);
	CopyMemory(pBuffer, pData, m_size);
	GlobalUnlock(hBuffer);

	IStream* pStream;
	CreateStreamOnHGlobal(hBuffer, TRUE, &pStream);
	m_pBitmap = Gdiplus::Bitmap::FromStream(pStream);
	pStream->Release();

	return m_pBitmap && m_pBitmap->GetLastStatus() == Gdiplus::Ok;
}

HBITMAP Sprite::GetHBitmap() const noexcept {
	HBITMAP hBitmap;
	m_pBitmap->GetHBITMAP(Gdiplus::Color(0, 0, 0), &hBitmap);
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