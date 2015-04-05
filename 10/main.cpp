#include "Graph.h"

int main()
{
//	Graph<string> G;
//	Vertex<string>* v = new Vertex<string>();
//	v->SetID("Tampa");
//	G.InsertVertex(v);
//
//	v = new Vertex<string>();
//	v->SetID("Cali");
//	G.InsertVertex(v);
//
//	v = new Vertex<string>();
//	v->SetID("Germany");
//	G.InsertVertex(v);
//
//
//	vector<Vertex<string> >* temp = G.Vertices();
//	Vertex<string>* to   = &temp->operator[](0);
//	Vertex<string>* from = &temp->operator[](1);
//
//	G.InsertEdge(from, to, 6000);
//
//	G.EraseVertex("Tampa");
//
////	G.InsertEdge(G.Search("Germany"), to, 500);
//
//	temp = G.Vertices();
//	for(unsigned int index = 0; index < temp->size(); index++)
//	{
//		cout << "VERTICES: " << temp->operator[](index).GetID() << endl;
//	}
//
//
//	for(unsigned int index = 0; index < temp->size(); index++)
//	{
//		cout << "EDGES ON VERTEX " << temp->operator[](index).GetID() << ": "
//			 << temp->operator[](index).IncidentEdges()->size() << endl;
//	}
//
//
//	vector<Edge<string> >* rand = G.Edges();
//	cout << "TOTAL EDGES: " << rand->size();

	Graph<string> G;


	Vertex<string>* LA = new Vertex<string>();
	LA->SetID("Los Angeles");
	G.InsertVertex(*LA);

	Vertex<string>* SF = new Vertex<string>();
	SF->SetID("San Franciso");
	G.InsertVertex(*SF);

	Vertex<string>* SEA = new Vertex<string>();
	SEA->SetID("Seattle");
	G.InsertVertex(*SEA);

	Vertex<string>* DEN = new Vertex<string>();
	DEN->SetID("Denver");
	G.InsertVertex(*DEN);

	Vertex<string>* DAL = new Vertex<string>();
	DAL->SetID("Dallas");
	G.InsertVertex(*DAL);

	Vertex<string>* HOU = new Vertex<string>();
	HOU->SetID("Houston");
	G.InsertVertex(*HOU);

	Vertex<string>* KAN = new Vertex<string>();
	KAN->SetID("Kansas City");
	G.InsertVertex(*KAN);

	Vertex<string>* CHI = new Vertex<string>();
	CHI->SetID("Chicago");
	G.InsertVertex(*CHI);

	Vertex<string>* BOS = new Vertex<string>();
	BOS->SetID("Boston");
	G.InsertVertex(*BOS);

	Vertex<string>* NY = new Vertex<string>();
	NY->SetID("New York");
	G.InsertVertex(*NY);

	Vertex<string>* ATL = new Vertex<string>();
	ATL->SetID("Atlanta");
	G.InsertVertex(*ATL);

	Vertex<string>* MIA = new Vertex<string>();
	MIA->SetID("Miami");
	G.InsertVertex(*MIA);

	cout << "ADDING EDGES: " << endl;

	G.InsertEdge(LA, DEN, 1015);
	G.InsertEdge(LA, KAN, 1663);
	G.InsertEdge(LA, DAL, 1435);
	G.InsertEdge(LA, SF, 381);
	G.InsertEdge(SF, SEA, 807);
	G.InsertEdge(SF, DEN, 1267);
	G.InsertEdge(SEA, CHI, 2097);
	G.InsertEdge(SEA, DEN, 1331);
	G.InsertEdge(DEN, CHI, 1003);
	G.InsertEdge(DEN, KAN, 599);
	G.InsertEdge(CHI, BOS, 983);
	G.InsertEdge(BOS, NY, 214);
	G.InsertEdge(CHI, NY, 787);
	G.InsertEdge(KAN, NY, 1260);
	G.InsertEdge(KAN, ATL, 864);
	G.InsertEdge(KAN, DAL, 496);
	G.InsertEdge(DAL, HOU, 239);
	G.InsertEdge(DAL, ATL, 781);
	G.InsertEdge(HOU, ATL, 810);
	G.InsertEdge(HOU, MIA, 1187);
	G.InsertEdge(MIA, ATL, 661);
	G.InsertEdge(ATL, NY, 888);
	G.InsertEdge(NY, BOS, 214);

	G.DFS(LA);

	return 0;
}
