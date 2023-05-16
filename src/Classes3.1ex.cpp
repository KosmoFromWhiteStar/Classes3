#include "Classes3.1ex.h"
#include <vector>
int main()
{
	std::vector <Shape*> figure(3);
    figure[0] = new Circle(2);
    figure[1] = new Rectangle(2.5f, 1.9f);
    figure[2] = new Triangle(3,4,5);
    for(int i = 0; i < figure.size();i++)
    {
        std::cout << "--------------------\n";
        figure[i]->print_Params();
    }

    for (int i = 0; i < figure.size(); i++)
    {
        delete figure[i];
    }
    return 0;
}
