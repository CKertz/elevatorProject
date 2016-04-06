#pragma once
#include <vector>
#include <functional>
#include "Header.h"

using namespace std;

// compare class inspired by example (myComparison) given on this page: http://www.cplusplus.com/reference/queue/priority_queue/priority_queue/

class compare
{
	private:
		bool isUP;
	public:
		void changeIsUp(direction newDirection)
		{
			if (newDirection == UP)
				isUP = true;
			else
				isUP = false;
		}
		bool operator() (const int& leftHandSide, const int& rightHandSide) const
		{
			if (isUP) return (leftHandSide > rightHandSide);
			else return (leftHandSide < rightHandSide);
		}
};

//prioritize class based on the priority_queue class from the lecture slides

class prioritize
{
	private:
		vector<int> floors;
		compare current;
		direction currentDirection;
	public:
		prioritize() {}
		direction getCurrentDirection() { return currentDirection; }
		void changeDirection(direction newDirection)
		{
			currentDirection = newDirection;
			current.changeIsUp(newDirection);
		}
		void add(const int& floor)
		{
			floors.push_back(floor);
			int child = floors.size() - 1;
			int parent = (child - 1) / 2;
			while (parent >= 0 && current(floors[parent], floors[child]))
			{
				swap(floors[child], floors[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
		}
		void complete()
		{
			if (size() == 1)
			{
				floors.pop_back();
				return;
			}
			swap(floors[0], floors[size() - 1]);
			floors.pop_back();
			int parent = 0;

			while (true)
			{
				int leftChild = 2 * parent + 1;
				if (leftChild >= size())
					break;
				int rightChild = leftChild + 1;
				int maxChild = leftChild;
				if (rightChild < size() && current(floors[leftChild], floors[rightChild]))
					maxChild = rightChild;
				if (current(floors[parent], floors[maxChild]))
				{
					swap(floors[maxChild], floors[parent]);
					parent = maxChild;
				}
				else
					break;
			}
		}
		bool empty() const { return floors.empty(); }
		int size() const { return floors.size(); }
		const int& get() const { return floors.front(); }
};