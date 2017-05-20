#pragma once
#include <assert.h>
#include <stdio.h>

namespace mem
{
	class Link
	{
	public:
		Link() : next(this), prev(this) {}
		Link* next;
		Link* prev;
	};

	class LinkedList
	{
	public:
		LinkedList() : root(), current(&root) {}
		
		Link* Top() 
		{
			if (root.next != &root)
			{
				return root.next;
			}
			return nullptr;
		}

		void PushFront(Link* link)
		{
			InsertBefore(link, root.next);
		}

		void PushBack(Link* link)
		{
			InsertBefore(link, &root);
		}

		void Remove(Link* link)
		{
			link->next->prev = link->prev;
			link->prev->next = link->next;
		}

		template <typename T>
		void Apply(T t)
		{
			Link* link = root.next;
			while (link != &root)
			{
				t(link);
				link = link->next;
			}
		}

		void Clear()
		{
			root.next = &root;
			root.prev = &root;
		}

		template <typename Comparison>
		Link* FindNext(Comparison comparison)
		{
			Link* link = current->next;
			while (link != current)
			{
				if (link != &root && comparison(link))
				{
					current = link->next;
					return link;
				}
				link = link->next;
			}
			return nullptr;
		}

		template <typename Comparison>
		Link* Find(Comparison comparison)
		{
			Link* link = root.next;
			while (link != &root)
			{
				if (comparison(link))
				{
					return link;
				}
				link = link->next;
			}
			return nullptr;
		}

		void InsertBefore(Link* insert, Link* link)
		{
			assert(insert != nullptr);
			if (link == nullptr)
			{
				link = &root;
			}

			insert->next = link;
			insert->prev = link->prev;

			link->prev->next = insert;
			link->prev = insert;
		}

		Link* GetRoot()
		{
			return &root;
		}

		int GetSize() const 
		{
			int size = 0;
			Link* link = root.next;
			while (link != &root)
			{
				size++;
				link = link->next;
			}
			return size;
		}
	private:
		Link root;
		Link* current;
	};
}