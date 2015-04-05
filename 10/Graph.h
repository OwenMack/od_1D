#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <string>
#include <iostream>
using namespace std;

template <class type>
class Vertex;

template <class type>
class Edge
{
	public:
	Edge();
	Edge(Vertex<type>* newv1, Vertex<type>* newv2, int newWeight);
	~Edge();

	Edge& operator*();
	vector<Vertex<type> >* endVertices();
	Vertex<type>* opposite(Vertex<type>* theVert);
	bool isAdjacentTo(Edge otherEdge);
	bool isIncidentTo(Vertex<type>* theVert);
	void SetWeight(int newWeight);
	int  GetWeight();

	private:
	int weight;
	vector<Vertex<type> > verts;
};

template <class type>
Edge<type>::Edge() : weight(0)
{
}

template <class type>
Edge<type>::Edge(Vertex<type>* org, Vertex<type>* dest, int newWeight) : weight(newWeight)
{
	verts.push_back(*org);
	verts.push_back(*dest);
}

template <class type>
Edge<type>::~Edge()
{
}

template <class type>
Edge<type>& Edge<type>::operator *()
{
	return *this;
}

template <class type>
vector<Vertex<type> >* Edge<type>::endVertices()
{
	return &verts;
}

template <class type>
Vertex<type>* Edge<type>::opposite(Vertex<type>* theVert)
{
	if(verts.operator [](0) == *theVert)
	{
		return &verts.operator [](1);
	}
	else if(verts.operator [](1) == *theVert)
	{
		return &verts.operator [](0);
	}
}

template <class type>
bool Edge<type>::isAdjacentTo(Edge<type> otherEdge)
{
	Vertex<type>* verts1 = this->endVertices();
	Vertex<type>* verts2 = otherEdge.endVertices();
	bool isAdjacent = false;

	if(verts1[0] == verts2[0]
	|| verts1[0] == verts2[1]
	|| verts1[1] == verts2[0]
	|| verts1[1] == verts2[1])
	{
		isAdjacent = true;
	}

	return isAdjacent;
}

template <class type>
bool Edge<type>::isIncidentTo(Vertex<type>* theVert)
{
	vector<Vertex<type> >* endpoints = endVertices();
	bool isTrue = false;

	if(endpoints->operator [](1) == *theVert || endpoints->operator [](0) == *theVert)
	{
		isTrue = true;
	}
	return isTrue;
}

template <class type>
void Edge<type>::SetWeight(int newWeight)
{
	weight = newWeight;
}

template <class type>
int Edge<type>::GetWeight()
{
	return weight;
}

template <class type>
class Vertex
{
	public:
	Vertex();
	Vertex(type newKey);
	~Vertex();

	// Returns info at the vertex
	Vertex& operator*();
	bool operator == (const Vertex& theVert) const;
	bool operator != (const Vertex& theVert) const;
	// Returns all edges to the vertex
	vector<Edge<type> >* IncidentEdges();
	// Returns bool for if vertices are adjacent
	bool isAdjacentTo(Vertex theVert);

	void SetID(type newID);
	type GetID();
	void SetVisited(bool newVis);
	bool GetVisited();

	private:
	bool visited;
	type id;
	vector<Edge<type> > E;
};

template <class type>
Vertex<type>::Vertex() : visited(0)
{
}

template <class type>
Vertex<type>::Vertex(type newKey) : visited(0), id(newKey)
{
}

template <class type>
Vertex<type>::~Vertex()
{
}

template <class type>
Vertex<type>& Vertex<type>::operator*()
{
	return *this;
}

template <class type>
bool Vertex<type>::operator ==(const Vertex<type>& theVert) const
{
	if(this->id == theVert.id)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class type>
bool Vertex<type>::operator !=(const Vertex<type>& theVert) const
{
	if(this->id != theVert.id)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class type>
vector<Edge<type> >* Vertex<type>::IncidentEdges()
{
	return &E;
}

template <class type>
bool Vertex<type>::isAdjacentTo(Vertex theVert)
{
	vector<Edge<type> > currentEdgeVector = this->IncidentEdges();
	Edge<type> tempEdge;
	Vertex<type>* endpoints;

	int  index = 0;
	bool found = false;

	while(!found && index < currentEdgeVector.size())
	{
		tempEdge = currentEdgeVector.operator[](index);
		endpoints = tempEdge.endVertices();

		if(endpoints[0] == theVert || endpoints[1] == theVert)
		{
			found = false;
		}
		index++;
	}
	return found;
}

template <class type>
void Vertex<type>::SetID(type newKey)
{
	id = newKey;
}

template <class type>
type Vertex<type>::GetID()
{
	return id;
}

template <class type>
void Vertex<type>::SetVisited(bool newVis)
{
	visited = newVis;
}

template <class type>
bool Vertex<type>::GetVisited()
{
	return visited;
}

template <class type>
class Graph
{
	public:
	Graph();
	~Graph();
	void InsertVertex(Vertex<type> newVert);
	void InsertEdge(Vertex<type>* from, Vertex<type>* to, int weight);
	void DFS(Vertex<type>* curVert);
//	void EraseVertex(type key);
//	void EraseEdge(Edge<type> theEdge);

	vector<Vertex<type> >* Vertices();
	vector<Edge<type> >*   Edges();
	Vertex<type> Search(type key);

	private:
	vector<Vertex<type> > vertices;
	vector<Edge<type> >   edges;
};

template <class type>
Graph<type>::Graph()
{
}

template <class type>
Graph<type>::~Graph()
{
}

template <class type>
void Graph<type>::InsertVertex(Vertex<type> newVert)
{
	vertices.push_back(newVert);
}

template <class type>
void Graph<type>::InsertEdge(Vertex<type>* from, Vertex<type>* to, int weight)
{
	Edge<type>* newEdge = new Edge<type>(from, to, weight);
	from->IncidentEdges()->push_back(*newEdge);
	to->IncidentEdges()->push_back(*newEdge);
	edges.push_back(*newEdge);
}

template <class type>
void Graph<type>::DFS(Vertex<type>* curVert)
{
	cout << curVert->GetID() << endl;
	curVert->SetVisited(true);

	int smallest = 11111;
	int jndex = 0;
	vector<Edge<type> > tempVector = *curVert->IncidentEdges();
	Edge<type> tempEdge;
	for(int index = 0; index < tempVector.size(); index++)
	{
		tempEdge = tempVector.operator [](index);

		if(smallest < tempEdge.GetWeight())
		{
			smallest = tempEdge.GetWeight();
			jndex = index;
		}
	}
	curVert = tempVector.operator [](jndex);





//	cout << "blarg" << endl;
//	cout << curVert->GetID() << endl;
//	curVert->SetVisited(true);
//	vector<Edge<type> >* tempVector = curVert->IncidentEdges();
//	int lowestWeight = 9000;
//	cout << "blarg1" << endl;
//	for(unsigned int index = 0; index < tempVector->size(); index++)
//	{
//		cout << "blarg2" << endl;
//		if(tempVector->operator [](index).GetWeight() < lowestWeight
//		   && !tempVector->operator [](index).opposite(curVert)->GetVisited())
//		{
//			lowestWeight = tempVector->operator [](index).GetWeight();
//			curVert = tempVector->operator [](index).opposite(curVert);
//		}
//	}
//	DFS(curVert);
}

//template <class type>
//void Graph<type>::EraseVertex(type key)
//{
//	Vertex<type>* toDelete;
//	bool found = false;
//	int  index = 0;
//
//	// Finds vertex to delete
//	while(!found && index < vertices.size())
//	{
//		if(vertices.operator[](index).GetID() == key)
//		{
//			toDelete = &vertices.operator[](index);
//			found    = true;
//		}
//		index++;
//	}
//
//	if(found)
//	{
//		Vertex<type>* deleteFrom;
//		// Searches for edges connecting to deleted vertex
//		for(int jndex = 0; jndex < edges.size(); jndex++)
//		{
//			Edge<type>* tempEdge = &edges.operator[](jndex);
//
//			if(tempEdge->isIncidentTo(toDelete))
//			{
//				// Gets vertex that must have an edge deleted
//				deleteFrom  	   = tempEdge->opposite(toDelete);
//				vector<Edge<type> >* edgeVector = deleteFrom->IncidentEdges();
//				Edge<type>* 		 tempEdge2;
//
//				for(unsigned int tndex = 0; tndex < edgeVector->size(); tndex++)
//				{
//					tempEdge2 = &edgeVector->operator[](tndex);
//
//					if(tempEdge2->opposite(deleteFrom) == toDelete)
//					{
//						for(unsigned int yndex = tndex; yndex < edgeVector->size(); yndex++)
//						{
//							edgeVector->operator[](yndex) = edgeVector->operator[](yndex + 1);
//						}
//						edgeVector->pop_back();
//					}
//				}
//
//				// Deletes incident edge from edges vector
//				for(unsigned int kndex = jndex - 1; kndex < edges.size(); kndex++)
//				{
//					edges.operator[](kndex) = edges.operator[](kndex + 1);
//				}
//				edges.pop_back();
//			}
//		}
//
//		// Deletes vertex
//		for(unsigned int jndex = index - 1; jndex < vertices.size() - 1; jndex++)
//		{
//			vertices.operator[](jndex) = vertices.operator[](jndex + 1);
//		}
//		vertices.pop_back();
//	}
//}

template <class type>
vector<Vertex<type> >* Graph<type>::Vertices()
{
	return &vertices;
}

template <class type>
vector<Edge<type> >* Graph<type>::Edges()
{
	return &edges;
}

template <class type>
Vertex<type> Graph<type>::Search(type key)
{
	unsigned int index = 0;
	bool found = false;
	Vertex<type> returnVal;

	while(!found && index < vertices.size())
	{
		if(vertices.operator [](index).GetID() == key)
		{
			returnVal = vertices.operator [](index);
			cout << vertices.operator[](index).IncidentEdges()->size() << endl;
			found = true;
		}
		index++;
	}
	cout << returnVal.IncidentEdges()->size() << endl;
	return returnVal;
}
#endif
