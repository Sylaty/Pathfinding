#include <iostream>
#include <vector>
const int GRAPH_SIZE = 10;
const char CURSOR_CHAR = 'X';
const char PLAYER_CHAR = 'O';
const char OBSTACLE_CHAR = '#';
const char EMPTY_CHAR = ' ';
const char PATH_CHAR = '+';
const char VISITED_CHAR = '*';
std::vector<std::vector<char>> Map = {
    {' ',' ',' ','#','#','#',' ',' ','#','#'},
    {' ','#',' ','#',' ',' ',' ',' ',' ','#'},
    {'#','#',' ','#','#',' ','#','#',' ','#'},
    {' ',' ',' ',' ',' ',' ','#','#',' ','#'},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {' ',' ',' ',' ',' ',' ','#','#',' ','#'},
    {' ',' ',' ',' ',' ',' ',' ','#',' ','#'},
    {' ',' ',' ',' ',' ',' ',' ','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'!','#',' ',' ',' ',' ',' ',' ',' ',' '},
};



struct Tile
{
    int col, row;
    bool obstactle;
};
template<typename T>
struct Node
{
    T* data;

    bool visited;
    Node* cameFrom;

    std::vector<Node*> neighbors;
};
std::vector<Node<Tile>> nodes;

std::vector<std::vector<Tile>> Graph = std::vector<std::vector<Tile>>();

void BuildGraph() {
    for (int y = 0; y < Map.size(); y++)
    {
        for (int x = 0; x < Map[y].size(); x++)
        {
            Tile* tile = new Tile();
            tile->col = y;
            tile->row = x;
            if (Map[y][x] == EMPTY_CHAR) {
                tile->obstactle = false;
            }
            else if (Map[y][x] == OBSTACLE_CHAR)
            {
                tile->obstactle == true;
            }
            Node<Tile>* node = new Node<Tile>();
            node->data = tile;

            for (int i = 0; i < nodes.size(); i++)
            {
                if (nodes[i].data->obstactle == false)
                {
                    if (nodes[i].data->col == node->data->col + 1) {
                        bool isCurrentNighbors = false;
                        node->neighbors.push_back(&nodes[i]);
                        for (int k = 0; k < nodes[i].neighbors.size(); k++)
                        {
                            if (nodes[i].neighbors[k] == node) {
                                isCurrentNighbors = true;
                            }
                        }
                        if (isCurrentNighbors == false) {
                            nodes[i].neighbors.push_back(node);
                        }
                    }
                    if (nodes[i].data->col <= node->data->col - 1) {
                        bool isCurrentNighbors = false;
                        node->neighbors.push_back(&nodes[i]);
                        for (int k = 0; k < nodes[i].neighbors.size(); k++)
                        {
                            if (nodes[i].neighbors[k] == node) {
                                isCurrentNighbors = true;
                            }
                        }
                        if (isCurrentNighbors == false) {
                            nodes[i].neighbors.push_back(node);
                        }
                    }
                    if (nodes[i].data->row <= node->data->row + 1) {
                        bool isCurrentNighbors = false;
                        node->neighbors.push_back(&nodes[i]);
                        for (int k = 0; k < nodes[i].neighbors.size(); k++)
                        {
                            if (nodes[i].neighbors[k] == node) {
                                isCurrentNighbors = true;
                            }
                        }
                        if (isCurrentNighbors == false) {
                            nodes[i].neighbors.push_back(node);
                        }
                    }
                    if (nodes[i].data->row <= node->data->row - 1) {
                        bool isCurrentNighbors = false;
                        node->neighbors.push_back(&nodes[i]);
                        for (int k = 0; k < nodes[i].neighbors.size(); k++)
                        {
                            if (nodes[i].neighbors[k] == node) {
                                isCurrentNighbors = true;
                            }
                        }
                        if (isCurrentNighbors == false) {
                            nodes[i].neighbors.push_back(node);
                        }
                    }
                }
            }

            nodes.push_back(*node);
        }
    }
}
void DisplayGraph() {
    for (int i = 0; i < Map.size(); i++)
    {
        for (int j = 0; j < Map[i].size(); j++)
        {
            char currentCharToDisplay = Map[i][j];
            std::cout << currentCharToDisplay << " ";
        }
        std::cout << std::endl;
    }
}
void IniNeighbors() {

}

void Pathfinding() {

}


int main()
{
    BuildGraph();
    DisplayGraph();
    for (int i = 0; i < nodes.size(); i++)
    {
        std::cout << "xO : " << nodes[i].data->col << " yO : " << nodes[i].data->row << std::endl;
        for (int j = 0; j < nodes[i].neighbors.size(); j++)
        {
            std::cout << "x : " << nodes[i].neighbors[j]->data->col << " y : " << nodes[i].neighbors[j]->data->row << std::endl;
        }
    }
    std::cout << "Hello World!\n";
}