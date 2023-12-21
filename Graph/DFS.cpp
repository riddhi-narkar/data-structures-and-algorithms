// the graph input is in the form of a adjacency list, as they decrese the time complexity

class Node
{
    int colour; // -1 = white, 0 = grey, 1 = black
    Node predecessor;
    unsigned int distance;
};
