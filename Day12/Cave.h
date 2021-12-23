#ifndef DAY12_CAVE_H
#define DAY12_CAVE_H

#include <string>
#include <vector>
#include <deque>

using namespace std;

class Cave {
protected:
	string _name;
public:
	vector<Cave*> neighbors;
	Cave(string name);

	/**
	 * \brief Add a cave vertex to its neighbor list
	 * \param c the cave to be added
	 */
	void connectCave(Cave& c);

	/**
	 * \brief Returns if this cave vertex can be visited
	 * \return always true
	 */
	virtual bool canBeVisited();

	/**
	 * \brief Searchs the numbers of paths from this cave vertex to another cave vertex
	 * \param destination the name of the destination cave vertex
	 * \param call_stack the history of the visited caves in order from the start
	 * \return the number of paths
	 */
	virtual int search_paths(const string& destination, deque<string> call_stack);
};


class TinyCave : public Cave{
	bool wasVisited;
public:
	TinyCave(const string& name);

	/**
	 * \brief Returns if this cave vertex can be visited
	 * \return true if the cave wasn't previously visited
	 */
	bool canBeVisited() override;

	/**
	 * \brief Searchs the numbers of paths from this cave vertex to another cave vertex
	 * \param destination the name of the destination cave vertex
	 * \param call_stack the history of the visited caves in order from the start
	 * \return the number of paths
	 */
	int search_paths(const string& destination, deque<string> call_stack) override;
};

// ===[ Part 2 ]===

class TinyCave2 : public Cave{
	int visited_count;
	int limit;
public:
	static bool twice_cave;

	TinyCave2(const string& name);

	/**
	 * \brief Returns if this cave vertex can be visited
	 * \return true if the cave wasn't previously visited
	 */
	bool canBeVisited() override;

	/**
	* \brief Searchs the numbers of paths from this cave vertex to another cave vertex
	* \param destination the name of the destination cave vertex
	* \param call_stack the history of the visited caves in order from the start
	* \return the number of paths
	*/
	int search_paths(const string& destination, deque<string> call_stack) override;
};

#endif //DAY12_CAVE_H
