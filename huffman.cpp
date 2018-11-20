// huffman.cpp
//

#include "huffman.h"

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
  // TODO
}

freq_info* build_tree(tree_queue& q) {
  // TODO
  return NULL;
}

map<char, string> build_encoding_table(freq_info* root) {
  // TODO
  return map<char, string>();
}

string encode(map<char, string> enc_table, string input) {
  // TODO
  return "";
}

string decode(freq_info* root, string input) {
  // TODO
  return "";
}
