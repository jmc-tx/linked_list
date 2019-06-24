/***********************************************************
Name: Justen Crockett
Assignment: 03
Purpose:
***********************************************************/
#include "main.h"

int main() {

    srand(time(nullptr));

    // making number of test node data from
    // TEST_CASE_OFFSET to TEST_CASE_BASE + TEST_CASE_OFFSET (5 - 25)
    int num_tests = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[num_tests];
    char *data[num_tests];
    for (int i = 0; i < num_tests; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    List new_item;

    //filling arrays with test node data
    cout << "Making " << num_tests << " random test nodes..." << endl;
    make_test_cases(ids, data, num_tests);
    cout << "TEST NODES CREATED" << endl << endl;

    cout << "Adding test nodes to list..." << endl;
    for (int j = 0; j < num_tests; j++) {
        new_item.addNode(ids[j], data[j]);
    }
    cout << "ADDED " << new_item.getCount() << " RANDOM NODES" << endl << endl;

    new_item.printList(true);

    int search_id;
    cout << "(Testing delete node method) Enter ID to search for: ";
    cin >> search_id;
    new_item.deleteNode(search_id);
    cout << "Item Deleted." << endl;
    new_item.printList(true);

    int get_id;
    auto tempDataNode = new DataNode;
    cout << "(Testing get node method) Enter ID to search for: ";
    cin >> get_id;
    new_item.getNode(get_id, tempDataNode);
    cout << "\nID in Data Node: " << tempDataNode->id << "\tData in Data Node: " << tempDataNode->data << endl;

    return 0;
}