#pragma once

#include <list>
#include <string>
#include <memory>
#include "IComponent.h"

class Object {
private:
	using ComponentList = std::list<std::shared_ptr<IComponent>>;

	std::string m_name;
	ComponentList m_components;

public:
	Object(std::string);
	virtual ~Object() = default;

public:
	void Init();
	void Update();
	void Clear();

public:
	const std::string& GetName() const noexcept;

	template <class ComponentType>
	ComponentType GetComponent() {
		auto iter = m_components.begin();

		for (; iter != m_components.end(); iter++)
			if (dynamic_cast<ComponentType>(*iter)) break;

		if (iter != m_components.end())
			throw;

		return static_cast<ComponentType>(*iter);
	}

	template <class ComponentType>
	ComponentType AddComponent() {
		auto component = std::make_shared<ComponentType>();
		m_components.emplace_back(static_cast<std::shared_ptr<IComponent>>(component));
		return *component;
	}
};