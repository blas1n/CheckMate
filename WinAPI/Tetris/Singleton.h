#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <cstdlib>

template <class T>
class Singleton {
private:
	static T* mInstance;

protected:
	Singleton() {}
	Singleton(const Singleton& s) {}
	virtual ~Singleton() {}

public:
	static T* GetInstance() {
		if (mInstance == nullptr)
			mInstance = new T;

		return mInstance;
	};

	static void DestroyInstance() {
		if (mInstance != nullptr) {
			delete mInstance;
			mInstance = nullptr;
		}
	};
};

template<class T>
T* Singleton<T>::mInstance;

#endif