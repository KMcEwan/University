/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by Kirsty McEwan, Lauren McNally, Matthew McMahon Wood as a group assignment for the Game Physics module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "Grid.h"
#include <iostream>
#include <algorithm>

Grid::Grid(int cellSize, int cellWidth, int cellHeight) : CellSize(cellSize), CellWidth(cellWidth), CellHeight(cellHeight)
{
	Cols = cellWidth / cellSize;
	Rows = cellHeight / cellSize;
}

Grid::~Grid()
{
	for (auto it = ObjectBucks.begin(); it != ObjectBucks.end(); it++)
	{
		it->second.clear();  
	}
	ObjectBucks.clear();
}

Indices Grid::computerCellIndices(vec2 position)
{
	int x = position.x / Cols;
	int y = position.y / Rows;
	return Indices(x, y);
}

vector<Object*> Grid::ReturnNeighbours(Object * obj)
{
	vector<Object*>Neighbours;

	Indices cellIndex = computerCellIndices(obj->getPosition());
	Neighbours.insert(Neighbours.end(), ObjectBucks[cellIndex].begin(), ObjectBucks[cellIndex].end());

	Indices ComputeEast(cellIndex.first + 1, cellIndex.second);
	if (ObjectBucks.count(ComputeEast) > 0)
	{
		Neighbours.insert(Neighbours.end(), ObjectBucks[ComputeEast].begin(), ObjectBucks[ComputeEast].end());
	}
	
	Indices ComputeSouthEast(cellIndex.first + 1, cellIndex.second);
	if (ObjectBucks.count(ComputeSouthEast) > 0)
	{
		Neighbours.insert(Neighbours.end(), ObjectBucks[ComputeSouthEast].begin(), ObjectBucks[ComputeSouthEast].end());
	}

	Indices ComputeSouth(cellIndex.first + 1, cellIndex.second);
	if (ObjectBucks.count(ComputeSouth) > 0)
	{
		Neighbours.insert(Neighbours.end(), ObjectBucks[ComputeSouth].begin(), ObjectBucks[ComputeSouth].end());
	}

	return Neighbours;
}

void Grid::AddObject(Object * obj)
{
	Indices cellIndex = computerCellIndices(obj->getPosition());
	ObjectBucks[cellIndex].push_back(obj);
}

void Grid::ClearGrid()
{
	ObjectBucks.clear();
}
