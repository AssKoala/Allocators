#pragma once

#include <concepts>
#include <type_traits>

template <typename T>
concept IntrusiveListCompatibleNode = requires(T t)
{
	{ t.next } -> std::same_as<T*&>;
};

template <IntrusiveListCompatibleNode T> class koala_intrusive_list
{
public:
	koala_intrusive_list();
	~koala_intrusive_list();

	void push_back(T* new_node);
	void push_front(T* new_node);

	void pop();
	T* front();

	size_t	size();
	bool	empty();

private:
	T* m_head;
};

/* Implementation */

template <IntrusiveListCompatibleNode T> koala_intrusive_list<T>::koala_intrusive_list()
{
	m_head = nullptr;
}

template <IntrusiveListCompatibleNode T> koala_intrusive_list<T>::~koala_intrusive_list()
{
	assert(m_head == nullptr);
}

template <IntrusiveListCompatibleNode T> void koala_intrusive_list<T>::push_back(T* new_node)
{
	if (m_head == nullptr)
	{
		m_head = new_node;
	}
	else
	{
		auto* current = m_head;
		while (current->next != nullptr) current = current->next;
		current->next = new_node;
	}
}

template <IntrusiveListCompatibleNode T> void koala_intrusive_list<T>::push_front(T* new_node)
{
	new_node->next = m_head;
	m_head = new_node;
}

template <IntrusiveListCompatibleNode T> void koala_intrusive_list<T>::pop()
{
	assert(m_head);

	if (m_head)
		m_head = m_head->next;
}

template <IntrusiveListCompatibleNode T> T* koala_intrusive_list<T>::front()
{
	return m_head;
}

template <IntrusiveListCompatibleNode T> size_t koala_intrusive_list<T>::size()
{
	auto* current = m_head;
	size_t size = 0;
	while (current) {
		current = current->next;
		size++;
	}
}

template <IntrusiveListCompatibleNode T> bool koala_intrusive_list<T>::empty()
{
	return m_head == nullptr;
}