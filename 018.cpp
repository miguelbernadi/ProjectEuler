#include "include/Tree.h"
#include "include/fs.h"
#include <iostream>
#include <string>

template <typename _T>
void populate_tree(std::string filename, TriangleTree<_T>* tree)
{
    File mf = File(filename);
    std::ifstream* ifs = mf.getIStream();
    unsigned int i;
    while(*ifs >> i)
    {
        tree->add(i);
    }
}

int compare(unsigned int i, unsigned int ii)
{
    if(i > ii)
    {
       return 1;
    }
    else if(i < ii)
    {
       return 2;
    }
    else
    {
       return 0;
    }
}

template <typename _T>
unsigned int traverse_tree(TriangleTree<_T>* tree)
{
    unsigned int sum = 0;
    unsigned int room = 0;
    for(unsigned int i = 0; i < tree->lastFloor(); ++i)
    {
	sum += tree->at(i, room)->content();
        if(i < tree->lastFloor() - 1)
        {
            switch ( compare( tree->at(i + 1, room)->content(), tree->at(i + 1, room + 1)->content() ) )
            {
                case 2:
                    ++room;
                    break;
                case 0:
                    std::cout << "Mierda!" << std::endl;
                    break;
                default:
                    break;
            }
        }
    }
    return sum;
}

int main()
{
    std::string filename = "data/018.dat";
    TriangleTree<int>* tree = new TriangleTree<int>();
    populate_tree(filename, tree);

    std::cout << traverse_tree(tree) << std::endl;    
    return 0;
}
