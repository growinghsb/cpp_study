#include "HashMap.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	srand(time(nullptr));

	HashMap<int, int> myHashMap(rand() % 1000, 10);

	myHashMap.insert(rand() % 1000, 10);
	myHashMap.insert(makeHashPair(rand() % 1000, 10));
	myHashMap.insert(rand() % 1000, 10);
	myHashMap.insert(makeHashPair(rand() % 1000, 10));
	myHashMap.insert(rand() % 1000, 10);
	myHashMap.insert(rand() % 1000, 10);
	myHashMap.insert(makeHashPair(rand() % 1000, 10));
	myHashMap.insert(rand() % 1000, 10);
	myHashMap.insert(rand() % 1000, 10);
	myHashMap.insert(rand() % 1000, 10);
	myHashMap.insert(rand() % 1000, 10);
	myHashMap.insert(rand() % 1000, 10);

	myHashMap.printMap();

	HashPair<int, int> resultPair = myHashMap.get(31);

	return 0;
}