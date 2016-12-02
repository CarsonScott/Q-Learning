#include "Table.hpp"

Table createTable(int height, int width, float value)
{
    Table table;
    for(int y = 0; y < height; y++)
    {
        table.push_back(std::vector<float>());
        for(int x = 0; x < width; x++)
        {
            table.back().push_back(value);
        }
    }
    return table;
}
