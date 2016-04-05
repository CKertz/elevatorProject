#pragma once
#include <vector>
#include <functional>

using namespace std;

//priorityQueue class based on example given in slides and source code from Blackboard

template < typename itemType, typename compare = less<itemType> >

class priorityUpQueue
{ 
	private:
		vector<itemType> data;
		compare comp;
	public:
		priorityUpQueue() {}
		void push(const itemType& item)
		{
			data.push_back(item);
			int child = size() - 1; 
			int parent = (child - 1) / 2;
			while (parent >= 0 && comp(data[parent], data[child]))
			{
				swap(data[child], data[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
		}
		void pop()
		{
			if (size() == 1) { data.pop_back(); return; }
			swap(data[0], data[size() - 1]);
			data.pop_back();
			int parent = 0;
			while (true)
			{
				int leftChild = 2 * parent + 1;
				if (leftChild >= size())
					break;
				int rightChild = leftChild + 1;
				int maxChild = leftChild;
				if (rightChild < size() && comp(data[leftChild], data[rightChild]))
					maxChild = rightChild;
				if (comp(data[parent], data[maxChild]))
				{
					swap(data[maxChild], data[parent]);
					parent = maxChild;
				}
				else
					break;
			}
		}
		bool empty() const { return data.empty(); }
		int size() const { return data.size(); }
		const itemType& top() const { return data.front(); }
};

template < typename itemType, typename compare = greater<itemType> >

class priorityDownQueue
{
private:
	vector<itemType> data;
	compare comp;
public:
	priorityDownQueue() {}
	void push(const itemType& item)
	{
		data.push_back(item);
		int child = size() - 1;
		int parent = (child - 1) / 2;
		while (parent >= 0 && comp(data[parent], data[child]))
		{
			swap(data[child], data[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
	}
	void pop()
	{
		if (size() == 1) { data.pop_back(); return; }
		swap(data[0], data[size() - 1]);
		data.pop_back();
		int parent = 0;
		while (true)
		{
			int leftChild = 2 * parent + 1;
			if (leftChild >= size())
				break;
			int rightChild = leftChild + 1;
			int maxChild = leftChild;
			if (rightChild < size() && comp(data[leftChild], data[rightChild]))
				maxChild = rightChild;
			if (comp(data[parent], data[maxChild]))
			{
				swap(data[maxChild], data[parent]);
				parent = maxChild;
			}
			else
				break;
		}
	}
	bool empty() const { return data.empty(); }
	int size() const { return data.size(); }
	const itemType& top() const { return data.front(); }
};