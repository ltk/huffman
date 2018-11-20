// huffman.cpp
//

#include "huffman.h"
#include <iostream>

using namespace std;

freq_info* create_leaf(char symbol, int count) {
  freq_info* leaf = new freq_info;
  leaf->symbol = symbol;
  leaf->count = count;
  leaf->left = NULL;
  leaf->right = NULL;
  leaf->is_leaf = true;
  return leaf;
}

freq_info* combine_nodes(freq_info* left, freq_info* right) {
  freq_info* internal = new freq_info;
  internal->symbol = NULL;
  internal->count = left->count + right->count;
  internal->left = left;
  internal->right = right;
  internal->is_leaf = false;

  return internal;
}

void increment_lookup(map<char, int>& lookup, char symbol) {
  if (lookup[symbol] == NULL) {
    lookup[symbol] = 1;
  } else {
    lookup[symbol] = lookup[symbol] + 1;
  }
}

void load_queue(const map<char, int>& lookup, tree_queue& q) {
  map<char, int>::const_iterator i = lookup.begin();
 
	while (i != lookup.end()) {
		char symbol = i->first;
		int count = i->second;
    cout << "Adding " << symbol << " with count " << count << endl;
		freq_info* node = create_leaf(symbol, count);
    q.push(node);
		i++;
	}

  cout << "Done adding. Size is " << q.size() << " sym is " << q.top()->symbol << endl;
}

freq_info* build_tree(tree_queue& q) {
  bool done = false;
  freq_info *left = NULL;
  freq_info *right = NULL;

  while(true) {
    // If there is only one item in the queue, it's the complete tree!
    if (q.size() == 1) {
      return q.top();
    }

    // Otherwise, there are 2+ items in the queue, and we have more tree combining to do.
    left = q.top();
    q.pop();

    right = q.top();
    q.pop();

    freq_info* new_node = combine_nodes(left, right);
    q.push(new_node);
  }
}

void traverse_tree(map<char, string> *table, freq_info* cursor, string path) {
  if (cursor->is_leaf) {
    // Add to map.
    cout << "Adding to map " << cursor->symbol << endl;
    table->insert(pair<char,string>(cursor->symbol, path));
  } else {
    // traverse down
    traverse_tree(table, cursor->left, path + LEFT_CHAR);
    traverse_tree(table, cursor->right, path + RIGHT_CHAR);
  }
}

map<char, string> build_encoding_table(freq_info* root) {
  map<char, string> table = map<char, string>();

  traverse_tree(&table, root, "");

  return table;
}

string encode(map<char, string> enc_table, string input) {
  // TODO
  return "";
}

string decode(freq_info* root, string input) {
  // TODO
  return "";
}
